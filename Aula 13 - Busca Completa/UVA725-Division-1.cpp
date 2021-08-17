// Busca Completa / Busca Exaustiva / Força Bruta 
/* Consiste em enumerar todos os possíveis candidatos da solução e checar cada 
candidato para saber se ele satisfaz o enunciado do problema */
// Para entradas pequenas

#include <iostream>
#include <algorithm>

using namespace std;

//# [1, 2, 3, 4, 5] -> 12345
int intValue(int *v) {
    return v[4] + 10 * (v[3] + 10 * (v[2] + 10 * (v[1] + 10 * (v[0]))));
}

void solve(int *v, int N) {
  bool found = false;
  do {
      int num = intValue(v); //# pega o inteiro relacionado aos primeiros 5
      int den = intValue(v + 5); //# pega o inteiro relacionado aos próximos 5 dígitos
      if (N * den == num) {
        printf("%05d / %05d = %d\n", num, den, N);
        found = true;
      }
  } while (next_permutation(v, v + 10)); //# ajuda a gerar todas as permutações dos 10 dígitos
  if (not found)
    printf("There are no solutions for %d.\n", N);
}

int main () {
  int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  solve(digits, 62);
  return 0;
}
