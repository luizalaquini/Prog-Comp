#include <iostream>
#include <set>
using namespace std;

int main () {
    set<int> myset;

    // inserindo alguns valores no set
    for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50
    myset.insert(15);
    myset.insert(35);

    // inserindo os mesmos valores no set
    for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50

    // imprimindo (itera de forma ordenada)
    for (int i : myset)
        cout << i << endl;

    // myset.find retorna o iterador do elemento custo log(N)
    // ou myset.end() retorna que chegou ao final da busca sem resultados
    auto it = myset.find(20); // buscando o 20 
    if (it != myset.end())
        cout << "Found 20!" << endl;

    it = myset.find(25); // buscando o 25
    if (it != myset.end())
        cout << "Found 25!" << endl;

    myset.erase(10);  // remover existindo ou não no conjunto
    myset.erase(15);
    
    for (auto i : myset)
        cout << i << endl;
}