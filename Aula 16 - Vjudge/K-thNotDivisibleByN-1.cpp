#include <iostream>
using namespace std;

int main (){
    int t; // number of test cases (1≤t≤1000) 

    cin >> t;

    while (t--){
        int n, k; // (2≤n≤10^9) and (1≤k≤10^9).

        cin >> n >> k;

        int aux = k/n; 
        int find = k - aux;
        int i = k;

        // Loop to find the k-th non divisible number by n
        while (find != k) {
            i++;
            if (i % n != 0) find++;
        }
        cout << i << endl;
    }
    
    return 0;
}