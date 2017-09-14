#include <iostream>
using namespace std;
//Problemas de leak, isso acontece pois não há a liberacao do espaço alocado, precisamente pelo vetor v1
int main()
{
    int * v1 = new int[10];
	int v2[30];
	delete[] v1;
	return 1;
}


