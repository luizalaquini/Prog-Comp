// Aplicando tecnica Backtracking
/* Backtracking é uma técnica que tenta evitar a avaliação de todas as possibilidades
de solução para o problema em questão */

#include <iostream>
using namespace std;

int X = 12;
int N = 5;
int S[5] = {1, 2, 3, 4, 5};

bool combs[5];

bool solve(int begin, int n, int somaAtual) {
	if (begin >= n) {
		if (somaAtual == X)
      return true;
    return false;
  } else if (somaAtual > X) {
    return false;   
  } else {
		combs[begin] = false;
		bool without = solve(begin + 1, n, somaAtual);
		combs[begin] = true;
		bool with = solve(begin + 1, n, somaAtual + S[begin]);
    return with or without;
	}
}

int main() {
	cout << solve(0, N, 0) << endl;
  return 0;
}