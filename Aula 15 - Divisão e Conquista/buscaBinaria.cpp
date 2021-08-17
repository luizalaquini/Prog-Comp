/* Busca Binária: divide uma entrada em duas metades
Obejtivo é achar um elemento específico
Vai testando por partes e, se necessário, dividindo mais */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    int myints[] = {1,2,3,4,5,4,3,2,1};
    vector<int> v(myints, myints+9); //# 1 2 3 4 5 4 3 2 1
    
    //# using default comparison:
    sort (begin(v), end(v)); //# ordenação antes da busca binária
    cout << "looking for a 10... ";
    
    //# retorna true se o elemento está no vetor e false caso contrário
    if (binary_search(begin(v), end(v), 10))
        cout << "found!\n"; else cout << "not found.\n";

    return 0;
}