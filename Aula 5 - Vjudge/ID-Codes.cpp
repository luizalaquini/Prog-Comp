#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	while (true) {
		char cod[7];
		
        cin >> cod;
        if (strcmp(cod, "#") == 0) return 0;

		int L = strlen(cod);

		if (next_permutation(cod, cod + L))
            cout << cod << endl;
		else
            cout << "No Sucessor" << endl;
    }
    return 0;
}