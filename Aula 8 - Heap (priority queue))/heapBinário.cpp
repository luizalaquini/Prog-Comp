#include <iostream>
#include <queue>

using namespace std;

/*Se a questão pedir os n menores elementos de uma entrada grande*/
void n_menores(vector<int>& v, int n) {
    priority_queue<int> menores; //#n menores elementos vistos até então
    for (int i : v) {            //#iterando sobre os elementos do fluxo
      if (menores.size() < n) {  //#se ainda não vi n elementos
        menores.push(i);         //#posso só inserir
      } else {
        if (i < menores.top()) { //#compara o elemento com o de maior prioridade
          menores.pop();         //#se for menor, a gente remove o maior e inseri i na fila
          menores.push(i);
        }
      }
    }
    //#apenas imprimindo o resultado
    while(menores.size() != 0) {
        cout << menores.top() << endl;
        menores.pop();
    }
}

int main () {

    //#prioridade vai ser um número inteiro
    //#objeto vai ser uma string
    priority_queue<pair<int, string>> pq;
    
    //#se quisermos fazer a mesma coisa, mas pares com menores elementos
    //#têm maior prioridade
    //#priority_queue<pair<int, string>, 
    //#               vector<pair<int, string>>,
    //#               greater<pair<int, string>>> pq;

    pq.push(make_pair(4, "D"));
    pq.push(make_pair(1, "A"));
    pq.push(make_pair(2, "B"));
    pq.push(make_pair(5, "E"));
    pq.push(make_pair(3, "C"));
    
    while (!pq.empty()) {          
        auto e = pq.top(); // e é o par de maior prioridade
        cout << e.first << " " << e.second << endl;
        pq.pop();
    }

    return 0;
}