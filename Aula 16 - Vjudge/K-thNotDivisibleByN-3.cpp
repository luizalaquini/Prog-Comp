#include <bits/stdc++.h>
 
using namespace std;
// Function to find the K-th not divisible by N
int kthNonDivisible(int n, int k) {
    return k + floor((k - 1) / (n - 1));
}
 
int main() {
   int t; // number of test cases (1≤t≤1000) 

    cin >> t;

    while (t--){
        int n, k; // (2≤n≤10^9) and (1≤k≤10^9).

        cin >> n >> k;

        cout << kthNonDivisible(n, k) << endl;
    }
 
    return 0;
}