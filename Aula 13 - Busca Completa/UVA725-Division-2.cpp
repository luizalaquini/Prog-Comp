#include <cstdio>
#include <set>
#include <utility>
#include <cmath>
#include <iostream>

using namespace std;

bool alldiff(int n, int m) {
	if (n >= 100000)
		return false;

	int c, mask = 0;
	for (int i = 0; i < 5; i++) {
		c = (int)(n / pow(10, i)) % 10;
		if ((mask >> c) % 2)
			return false;
		mask |= 1 << c;
	}
	for (int i = 0; i < 5; i++) {
		c = (int)(m / pow(10, i)) % 10;
		if ((mask >> c) % 2)
			return false;
		mask |= 1 << c;
	}
	return true;
}

void solve(int n) {
  bool found = false;
  for (int den = 1234; den < 98765 / n + 1; den++) {
	  int num = den * n;
		if (alldiff(num, den)) {
				printf("%05d / %05d = %d\n", num, den, n);
				found = true;
		}
	}
	if (!found)
    printf("There are no solutions for %d.\n", n);
}

int main() {
	int n = 62;
  solve(n);
	return 0;
}