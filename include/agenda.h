#ifndef __AGENDA_H__
#define __AGENDA_H__

#include "contacts.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <locale>
size_t size;
size_t max_size = 30;
class Agenda {
	private:
		std::vector<Contact> _contact;
	
	public:
		/** @brief Default constructor*/
		Agenda (){
			this->_contact.reserve(max_size);	
		}
		/** @brief push max_size contacts */		
		void set_contacts(){
			std::cout<<"Após o uso dessa função use a de adicionar contatos(2)."<<std::endl;
			std::cout<<"Quantos contatos deseja adicionar: ";
			std::cin>>size;
			std::cin.sync();
			std::cin.ignore();
			for(size_t t=0;t<size;t++){
				std::unique_ptr<Contact> individual = create_contact();
				this->_contact[t] = *individual;
			}
		}
		
		/** @brief push only one contact */
		void add_contact(){
			for(size_t i = size; i<size+1; i++){
				std::unique_ptr<Contact> individual = move(create_contact());
				this->_contact[i] = *individual;	
			}
		size+=1;
		}	
		
		void del_contact(size_t pos){
			this->_contact.erase(this->_contact.begin() + pos);
		}
		
		
		friend std::ostream& operator <<(std::ostream& out, Agenda& right_object){
			for(size_t k=0;k<size;k++){
				std::cout<<"<Contato>"<<std::endl;
				out<<right_object._contact[k].getName()<<" -- ";
				out<<right_object._contact[k].getDay()<<"/";
				out<<right_object._contact[k].getMonth()<<"/";
				out<<right_object._contact[k].getYear()<<std::endl;
				out<<std::endl;
			}
		return out;
		}
		
		
		void save_file(){
			std::fstream stream;
			std::string path = "./";
			std::string file_name;
			
			std::cout<<"Nome do arquivo: ";
			std::getline(std::cin, file_name);
			path += file_name+".dat";

			stream.open(path, std::fstream::out);
			for(size_t k=0; k < size; k++){
				stream<<this->_contact[k].getName()<<";";
				stream<<this->_contact[k].getDay();
				stream<<";"<<this->_contact[k].getMonth();
				stream<<";"<<this->_contact[k].getYear();
				stream<<std::endl;
			}
			stream.close();
			std::cout<<std::endl;
			std::cout<<"Aquivo salvo em: "<<path<<std::endl;
			std::cout<<std::endl;
		}
		

};
#endif //__AGENDA_H__
