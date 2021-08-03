#include <iostream> 
#include <map>
using namespace std;

int main () {

    // tipo da chave, tipo do valor
    map<char,int> mymap;

    // Versão 1
    // Inserir criandos pares
    mymap.insert(pair<char,int>('a',100));
    mymap.insert(pair<char,int>('z',200));
    mymap.insert(pair<char,int>('z',300)); // [não muda o existente]
    // Nesse ponto, a chave z está associada ao valor 200!

    // Versão 1.5
    mymap.insert(make_pair('y', 1));

    // Versão 2
    mymap['c'] = 400;
    mymap['d'] = 500;
    mymap['d'] = 600; // Se a chave já existir, considera a nova
    // Nesse ponto, a chave d está associada ao valor 600!

    // imprimindo o map
    for (auto& i : mymap) // cada elemento, i, do map é um par
        cout << i.first << " -> " << i.second << endl;
        // i.first é a chave
        // i.second é o valor

    cout << endl;

    /*// mais conveniente
    for (auto& [k, v] : mymap)
        cout << k << " -> " << v << endl;
        // k é a chave
        // v é o valor*/

    // retorna o iterador do elemento se ele existir
    // ou myset.end()
    auto it = mymap.find('a');
    if (it != mymap.end())
        cout << "Found! Value = " << it->second << endl;

    it = mymap.find('b');
    if (it != mymap.end())
        cout << "Found! Value = " << it->second << endl;
}
// os elementos no map são percorridos em ordem de acordo com as chaves!