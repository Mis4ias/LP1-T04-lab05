#include "agenda.h"
#include <memory>
#include <vector>



int main(){
	
	Agenda data;
	std::cout<<"====* Insira os dados dos seus contatos *===="<<std::endl;
	data.set_contacts();
	std::cout<<data;

return EXIT_SUCCESS;
}
