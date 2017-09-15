#include <iostream>
using namespace std;
//Variavel v1[3] não inicializada.
//Sem liberação do espaço usado pelo vetor.
int main()
{
    int * v1 = new int[10];
    v1[3] = 5;
	if (v1[3] == 5) {
    	cout << "Ok Google" << endl;
    }
    delete[] v1;
	return 1;
}


