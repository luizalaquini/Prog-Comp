// Usando operações com bits para gerar subconjuntos
// Funciona para gerar todos os subconjuntos de um conjunto de até 64 elementos
// Solução possui custo 2^N 

#include<iostream>
#define ULL unsigned long long int

using namespace std;

int N = 3;
int S[3] = {1,2,3};
int X = 5;

bool solve() {
	for (ULL i = 0; i < (1LLU << N); i++) { //# todos subconjuntos
    int sum = 0;
		for (int j = 0; j < N; j++) {
  		if (i & (1 << j)) {
			  sum += S[j];
		  }
	  }
    if (sum == X) {
			return true;
		}
  }
  return false;
}

int main() {
	bool found = solve();

