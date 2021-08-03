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
//# Interface para atualizar A[idx], fazendo A[idx] += val
//# 'T' é a SegTree
//# 'A' é o vetor original com os elementos
//# 'n' é o tamanho de 'A'
//# 'idx' é o índice do elemento a ser atualizado
//# 'val' é o valor a ser somado a A[idx]
void update(int *T, int *A, int n, int idx, int val) { //# A[idx] = A[idx] + val
    updateRec(T, A, 1, 0, n - 1, idx, val);
}

//# Exemplo
int main() {
  int n = 6;
  int A[] = {1, 3, 5, 7, 9, 11}; //# valores
  int T[4*n] = {0};              //# local da SegTree

  build(T, A, n);                //# Constrói a SegTree

  update(T, A, n, 2, -1);        //# Subtrai 1 de A[2] // A[i] = A[i] + x
  //# 1, 3, 4, 7, 9, 11

  //#for (int i = 1; i < 4 * n; i++) 
  //#  cout << i << " " << T[i] << endl;

  cout << query(T, n, 2, 3);     //#Soma dos elementos A[2, ..., 3]

  return 0;
}