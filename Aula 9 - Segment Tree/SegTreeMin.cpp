/*Uma Segment Tree (Árvore de Segmentos) é uma Árvore Binária projetada em um ARRAY, onde:
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

#include<iostream>
#include<climits>

using namespace std;

void buildRec(int* T, int*A, int node, int start, int end) {
    if(start == end) {
        T[node] = A[start];
    } else {
        int mid = (start + end) / 2;
        buildRec(T, A, 2 * node, start, mid);
        buildRec(T, A, 2 * node + 1, mid+1, end);
        T[node] = min(T[2 * node], T[2 * node + 1]);    //# <======= IMPORTANTE
    }
}
void build(int *T, int *A, int n) {
    buildRec(T, A, 1, 0, n-1);
}

int queryRec(int *T, int node, int start, int end, int l, int r) {
    if(r < start or end < l) {
        return INT_MAX;                                 //# <======= IMPORTANTE
    }
    if(l <= start and end <= r){
        return T[node];
    }
    int mid = (start + end) / 2;
    int p1 = queryRec(T, 2 * node, start, mid, l, r);
    int p2 = queryRec(T, 2 * node + 1, mid + 1, end, l, r);
    return min(p1, p2);                                 //# <======= IMPORTANTE
}
int query(int* T, int n, int l, int r) {
    return queryRec(T, 1, 0, n-1, l, r);
}

void updateRec(int* T, int* A, int node, int start, int end, int idx, int val) {
    if(start == end) {
        A[idx] += val;
        T[node] += val;
    } else {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid) {
            updateRec(T, A, 2 * node, start, mid, idx, val);
        } else {
            updateRec(T, A, 2 * node + 1, mid + 1, end, idx, val);
        }
        T[node] = min(T[2 * node], T[2 * node + 1]);    //# <======= IMPORTANTE
    }
}
void update(int *T, int *A, int n, int idx, int val) {
    updateRec(T, A, 1, 0, n - 1, idx, val);
}

//# Exemplo
int main() {
    int n = 6;
    int A[] = {1, 3, 5, 7, 9, 11};  //# valores
    int T[4*n] = {};                //# local da SegTree

    build(T, A, n); //# Constrói a SegTree

    update(T, A, n, 2, -1); //# Subtrai 1 de A[2]

    //#for (int i = 1; i < 4 * n; i++) 
    //#  cout << i << " " << T[i] << endl;

    cout << query(T, n, 2, 3);  //#Mínimo dos elementos A[2, ..., 3]

    return 0;
}