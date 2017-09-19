#ifndef __AGENDA_H__
#define __AGENDA_H__

#include "contacts.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <locale>
const size_t max_size = 2;

size_t break_p(std::string path){
	size_t bp = 0;
	std::fstream file;
	std::string buffer;
	file.open(path, std::fstream::in);
	std::getline(file, buffer, '\n');
	file.close();
	for(std::string::iterator ik = buffer.begin(); ik != buffer.end(); ik++){
		if(*ik == ';') bp += 1;
	}
return bp;
}

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
		
		void read_file(){
			std::fstream stream;
			std::string path = "./";
			std::string file_name;
			std::string buffer;
			
			std::cout<<"Nome do arquivo: ";
			std::getline(std::cin, file_name);
			path += file_name+".dat";
		
			std::vector<std::string> arg;	
			stream.open(path, std::fstream::in);
			if(stream.is_open()){
				while(!stream.eof()){
					std::getline(stream, buffer, '\n');
					std::string sub;
					for(std::string::iterator it = buffer.begin(); it != buffer.end(); it++){
						if(*it == ';' || *it == '\n') {
							arg.push_back(sub); 
							sub.clear();
						}else sub+= *it;
					}
				}
			
			}
			stream.close();
			std::cout<<std::endl;	
			for(size_t i=0; i<arg.size();i++){
				std::cout<<i<<"   "<<arg[i]<<std::endl;
			
			}
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
				stream<<this->_contact[k].getName()<<";";
				stream<<this->_contact[k].getDay();
				stream<<";"<<this->_contact[k].getMonth();
				stream<<";"<<this->_contact[k].getYear()<<";endl;";
				stream<<std::endl;
			}
			stream.close();
		}
		

};
#endif //__AGENDA_H__
