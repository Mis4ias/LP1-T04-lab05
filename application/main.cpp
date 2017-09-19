#include "agenda.h"
#include <memory>
#include <vector>



int main(){
	
	Agenda data;
	data.read_file();	
	std::cout<<"====* Insira os dados dos seus contatos *===="<<std::endl;
//	data.set_contacts();
	std::cout<<data;
//	data.save_file();
return EXIT_SUCCESS;
}
