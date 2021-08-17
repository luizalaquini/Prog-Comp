/* Uma Segment Tree (Árvore de Segmentos) é uma Árvore Binária projetada em um ARRAY, onde:
*
* [Em se tratando da árvore:]
* Cada folha da árvore representa um elemento do array
* Cada nó interno da árvore representa um segmento do array (essa representação é dada pela soma dos elementos!), portanto:
    * O nó raiz representa todo o array (soma de todos os elementos)
    * Se um nó interno da árvore representa  A[i,…,j]  ( i<j ), então:
        * O filho à esquerda representa a primeira metade dos elementos A[i,…,(i+j/2)]
        * O filho à direita representa a segunda metade dos elementos A[(i+j/2)+1,…,j]
*OBS: Não mexemos na ordem dos elementos do array
*
* [Em se tratando do array:]
* Em seu pior caso terá tamanho array[4*n]
* A raíz da árvore fica na posição array[1]
* Se um nó da árvore fica em array[i], então:
    * O filho à esquerda fica em array[2i]
    * O filho à direita fica em array[2i + 1] 
*/

#include <iostream>
using namespace std;

//# Método Recursivo
//# Constrói uma SegTree 'T' a partir de um array 'A'
//# O primeiro elemento de 'A' está em 'start'
//# O último elemento de 'A' está em 'end'
//# O nó atual da árvore sendo analisado é 'node'
void buildRec(int* T, int* A, int node, int start, int end) {
    if(start == end) {
        //# Folha representa um elemento único 
        T[node] = A[start];
    } else {
        int mid = (start + end) / 2;
        //# Chamada recursiva para filho à esquerda 
        buildRec(T, A, 2 * node, start, mid);
        //# Chamada recursiva para filho à direita
        buildRec(T, A, 2 * node + 1, mid+1, end);
        //# Nó interno tem a SOMA dos dois filhos 
        T[node] = T[2 * node] + T[2 * node + 1];        //# <======= IMPORTANTE
    }
}
//# Interface para a construção da árvore
//# 'T' é o vetor que armazenará a árvore
//# 'A' é o vetor com os dados originais
//# 'n' é o número de elemento em 'A'. 'T' deve ter tamanho '2n'
//# Complexidade de tempo: O(n)
//# Complexidade de espaço: O(n)
void build(int *T, int *A, int n) {
    buildRec(T, A, 1, 0, n-1); //# A raíz tem nó 1 e representa o segmento A[0, ..., n-1]
}

//# Função recursiva pela busca da soma de A[l, ..., r]
//# 'T' é a SegTree
//# 'node' é o nó atual da SegTree sendo inspecionado
//# 'start' é o início do intervalo representado em 'node'
//# 'end' é o fim do intervalo representado em 'node'
//# 'l' é o limite inferior da busca
//# 'r' é o limite superior da busca
int queryRec(int *T, int node, int start, int end, int l, int r) {
    if(r < start or end < l) {
        //# [start, end] está fora de [l, r] -- não há interseção
        return 0;                                       //# <======= IMPORTANTE
    }
    if(l <= start and end <= r){
        //# [start, end] está contido em [l, r] 
        return T[node];
    }
    //# [start, end] e [l, r] têm interseção 
    int mid = (start + end) / 2;
    int p1 = queryRec(T, 2 * node, start, mid, l, r);
    int p2 = queryRec(T, 2 * node + 1, mid + 1, end, l, r);
    return (p1 + p2);                                  //# <======= IMPORTANTE
}
//# Interface para a busca: Soma dos elementos A[l, ..., r]
//# 'T' é a SegTree
//# 'n' é o número de elementos no vetor 'A'
//# 'l' limite inferior da busca
//# 'r' limite superior da busca
int query(int* T, int n, int l, int r) { //#Soma(A[l, ..., r])
    return queryRec(T, 1, 0, n-1, l, r);
}

//# Função Recursiva para atualizar A[idx], fazendo A[idx] += val
//# 'T' é a SegTree
//# 'A' é o vetor original com os elementos
//# 'node' é o nó atual da SegTree sendo inspecionado
//# 'start' é o início do intervalo representado por 'node' 
//# 'end' é o fim do intervalo representado por 'node' 
//# 'idx' é o índice do elemento a ser atualizado
//# 'val' é o valor a ser somado a A[idx]
void updateRec(int* T, int* A, int node, int start, int end, int idx, int val) {
    if(start == end) {
        //# Nó folha, atualiza A e T
        A[idx] += val;
        T[node] += val;
    } else {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid) {
            //# idx está no filho à esquerda 
            updateRec(T, A, 2 * node, start, mid, idx, val);
        } else {
            //# idx está no filho à direita 
            updateRec(T, A, 2 * node + 1, mid + 1, end, idx, val);
        }
        //# Faz atualização do nó pai 
        T[node] = T[2 * node] + T[2 * node + 1];        //# <======= IMPORTANTE
    }
}
//# Interface para atualizar A[idx]
//# 'T' é a SegTree
//# 'A' é o vetor original com os elementos
//# 'n' é o tamanho de 'A'
//# 'idx' é o índice do elemento a ser atualizado
//# 'val' é o valor a ser somado a A[idx]
void update(int *T, int *A, int n, int idx, int val) { //# A[idx] = A[idx] + val
    updateRec(T, A, 1, 0, n - 1, idx, val);
}

int main (){
    int N; // number of potmeters, numbered 1 to N (0 <= N <= 200000)
    
    cin >> N;

    int aux=0; // auxiliar pra resolver problema de espaço 

    for(int i=1; N!=0; i++){
        
        int A[N]; // Array of potmeters
        int T[4*N]; //# local da SegTree

        for (int j=0; j<N; j++){
            cin >> A[j];
        }

        build(T, A, N); //# Constrói a SegTree

        char action;
        if(action=='E') return 0;

        if(aux!=0) cout << endl;

        cout << "Case " << i << ":" << endl;

        while (action!='E'){
            cin >> action;
            
            if (action=='S'){ // set potmeter x to r Ohms
                int x, r; // x is valid; 0 <= r <= 1000

                cin >> x >> r;

                update(T, A, N, (x-1), (r-query(T, N, (x-1), (x-1)))); 

            } else if (action=='M'){ // measure the resistance between the left terminal of potmeter x and the right terminal of potmeter y
                int x, y; // both numbers valid; x <= y
                int r; // resistance

                cin >> x >> y;

                r = query(T, N, (x-1), (y-1));

                cout << r << endl;
            }
        }
        cin >> action; //ignore N
        cin >> action; //ignore D

        cin >> N;

        aux++;
    }
    
    return 0;
}