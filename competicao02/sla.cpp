#include <iostream>
using namespace std;
// Define uma macro que pega a variável x
// #x transforma o nome da variável em "x"
#define DUMP(x) #x

int main() {
    int minhaVariavel = 42;
    
    // Imprime: minhaVariavel = 42
    cout<< DUMP(minhaVariavel);
    
    return 0;
}