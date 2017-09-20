#include "agenda.h"
#include <memory>
#include <vector>



int main(){
	
	Agenda data;
	std::cout<<"====* Insira os dados dos seus contatos *===="<<std::endl;
	data.set_contacts();
//	data.del_contact(1);
	std::cout<<data;
//	data.save_file();
return EXIT_SUCCESS;
}
