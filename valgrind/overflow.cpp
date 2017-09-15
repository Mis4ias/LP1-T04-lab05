#include <iostream>
using namespace std;
//Local de acesso da variavel double mutio grande
void stack_overflow(void) {
	//double crazy[1048576];
	double crazy[2];
}
//Alocaçao de um vetor tipo int, mas nao tem a liberação do espaço
int main()
{
    int * v1 = new int[10];
    v1[10] = 3;
	stack_overflow();
    delete[] v1;
	return 1;
}


