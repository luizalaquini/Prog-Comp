#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
// Function to find the K-th not divisible by N
void kthNonDivisible(int N, int K) {
     
    // Lowest possible value
    int L = 1;
   
    // Highest possible value
    int H = INT_MAX;
   
    // To store the future answer
    int ans = 0;
 
    // Using binary search
    while (L <= H) {
         
        // Calculating mid value
        int mid = (L + H) / 2;
 
        // Sol would have the value by subtracting all multiples of n till mid
        int sol = mid - mid / N;
 
        // Check if sol is greater than k
        if (sol > K){
            // H should be reduced to find minimum possible value
            H = mid - 1;
        }
       
        // Check if sol is less than k then L will be mid+1
        else if (sol < K) {
            L = mid + 1;
        }
       
        // Check if sol is equal to k
        else {
            // ans will be mid
            ans = mid;
           
            // H would be reduced to find any more possible value
            H = mid - 1;
        }
    }
   
    // Print the answer
    cout << ans << endl;
}
 
int main() {
    int t; // number of test cases (1≤t≤1000) 

    cin >> t;

    while (t--){
        int n, k; // (2≤n≤10^9) and (1≤k≤10^9).

        cin >> n >> k;

        kthNonDivisible(n, k);
    }
 
    return 0;
}