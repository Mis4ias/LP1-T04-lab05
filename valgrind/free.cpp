#include <iostream>
using namespace std;
//Doble Free
//Resolve-se deletand a linha 10 que deleta novamente o ponteiro do ponteiro
int main()
{
    int * v1 = new int[10];
    int * v2 = v1;
    free(v1);
    //free(v2);
    return 1;
}


