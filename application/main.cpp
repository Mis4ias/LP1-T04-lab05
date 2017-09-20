#include "agenda.h"
#include <memory>
#include <vector>
unsigned menu(){
	unsigned choice;
	std::cout<<"Setar Contatos iniciais........1"<<std::endl;
	std::cout<<"Adicionar um novo contato......2"<<std::endl;
	std::cout<<"Listar contatos................3"<<std::endl;
	std::cout<<"Exportar para um arquivo CSV...4"<<std::endl;
	std::cout<<"Exit program...................0"<<std::endl;
	std::cin>>choice;
	std::cin.sync();
	std::cin.ignore();
return choice;	
}


int main(){
	
	unsigned c;
	bool run(true);
	Agenda data;
	while(run){
		c = menu();
		if(c == 1) data.set_contacts();
		if(c == 2) data.add_contact();
		if(c == 3) std::cout<<data;
		if(c == 4) data.save_file();
		if(c == 0) run = false;
	}
	
return EXIT_SUCCESS;
}
