#ifndef __AGENDA_H__
#define __AGENDA_H__

#include "contacts.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

const size_t max_size = 2;

class Agenda {
	private:
		std::vector<Contact> _contact;
	
	public:
		Agenda (){
			this->_contact.reserve(max_size);	
		}
		
		void set_contacts(){
			for(size_t t=0;t<max_size;t++){
				std::unique_ptr<Contact> individual = create_contact();
				//this->_contact.push_back(*individual);
				this->_contact[t] = *individual;
			}
		}	
		void del_contact(size_t pos){
			this->_contact.erase(this->_contact.begin() + pos-1);
		}
		
		
		friend std::ostream& operator <<(std::ostream& out, Agenda& right_object){
			for(size_t k=0;k<max_size;k++){
				std::cout<<"<Contato>"<<std::endl;
				out<<right_object._contact[k].getName()<<" -- ";
				out<<right_object._contact[k].getDay()<<"/";
				out<<right_object._contact[k].getMonth()<<"/";
				out<<right_object._contact[k].getYear()<<std::endl;
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
			for(size_t k=0; k < max_size; k++){
				stream<<"<Contato>"<<std::endl;
				stream<<this->_contact[k].getName()<<" -- ";
				stream<<this->_contact[k].getDay()<<"/";
				stream<<this->_contact[k].getMonth()<<"/";
				stream<<this->_contact[k].getYear()<<std::endl;
			}
			stream.close();
		}
		

};
#endif //__AGENDA_H__
