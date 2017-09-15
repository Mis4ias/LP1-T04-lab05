#include "personal_data.h"
#include <memory>
#include <vector>


const size_t n = 2;
void _input(std::vector<Pessoa> &p){
	for(size_t t=0;t<n;t++){
		std::unique_ptr<Pessoa> individual = create_human();
		p.push_back(*individual);
	}
}
void _print(std::vector<Pessoa> &p){
	for(size_t k=0;k<n;k++){
		std::cout<<p[k].getName()<<" -- ";
		std::cout<<p[k].getDay()<<"/";
		std::cout<<p[k].getMonth()<<"/";
		std::cout<<p[k].getYear()<<std::endl;
	}	
}

int main(){
	std::vector<Pessoa> people;
	people.reserve(n);
	_input(people);
	_print(people);	

return EXIT_SUCCESS;
}
