/* Busca Binária - Função lower_bound() :
Dado um iterator x, a função retorna o primeiro elemento do vetor [first, last]
que é >= x 
Caso todos os elementos sejam menores que x, retorna last */

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main () {
    int myints[] = {10,20,30,30,20,10,10,20};
    vector<int> v(myints,myints+8); //# 10 20 30 30 20 10 10 20
    sort (v.begin(), v.end());      //# 10 10 10 20 20 20 30 30

    //# Estamos buscando um elemento que seja >= x
    auto l1 = lower_bound(v.begin(), v.end(), 20);  //# aponta para primeiro 20
    auto l2 = lower_bound(v.begin(), v.end(), 100); //# aponta pra v.end()
    auto l3 = lower_bound(v.begin(), v.end(), 25);  //# aponta para o primeiro 30 
    cout << "Found 20: " << (l1 != v.end()) << endl;
    cout << "Found 100: " << (l2 != v.end()) << endl;
    cout << "Found 25: " << (l3 != v.end()) << endl;
    cout << "Where is 20: " << (l1 - v.begin()) << endl;
    cout << "Lower bound of 25: " << (l3 - v.begin()) << endl;
    return 0;
}

// OUTRAS FUNÇÕES:

/* Função upper_bound() :
Dado um iterator x, a função retorna o primeiro elemento do vetor [first, last]
que é > x 
Caso todos os elementos sejam menores que x, retorna last */

/* Função equal_range() :
Retorna os limites de um intervalo que inclui todos os elementos em [first, last)
que são iguais a x */