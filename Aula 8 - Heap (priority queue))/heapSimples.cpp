#include <iostream>
#include <queue>

using namespace std;

int main () {
    priority_queue<int> pq; // padrão, assume que os elementos são comparados com '<' 
                            // para inverter: priority_queue<int, vector<int>, greater<int>> pq;
                            // O operador de comparação '<' é substituído pelo '>'
                    
    pq.push(30);              // 'push' insere um novo elemento
    pq.push(100);             // nosso custo é lg(n)
    pq.push(25);
    pq.push(40);

    // {30, 100, 25, 40}
    cout << pq.top() << endl; // 'top' retorna o máximo mas NÃO remove
                              // custo constante

    pq.pop();               // 'pop' remove o máximo e NÃO o retorna
                            // custo lg(n)
    // {30, 25, 40}

    cout << pq.top() << endl;

    // Executamos remoções n vezes => O(nlg(n))
    while (!pq.empty()) {          // 'empty' retorna 'true' se 'pq' estiver vazia
        cout << pq.top() << endl;
        pq.pop();
    } // Se imprimirmos o elemento de maior prioridade e em seguida removê-lo em um loop, estaremos ordenando o vetor! (Heap Sort)

    return 0;
}