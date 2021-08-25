// Runtime Error on test 1

#include <iostream>
#include <algorithm>
using namespace std;

void swap (char* s, int id1, int id2){
    char aux = s[id1];
    s[id1] = s[id2];
    s[id2] = aux;
}

int main (){
    char* a; // pasha's number (1 ≤ a ≤ 10^18)
    int k; // max swaps (0 ≤ k ≤ 100)
    bool change = false;

    cin >> a >> k;

    for (int i=0; k>0; i++){
        if (a[i] < a[i+1]){
            swap(a, i, i+1);
            k--;
            change = true;
        }
        if(change){
            int j=i;
            while (j>0 && k>0){
                if (a[j] > a[j-1]){
                    swap(a, j, j-1);
                    k--;
                }
                else {
                    change = false;
                    break;
                }
                j--;
            }
        }
    }

    cout << a << endl;

    return 0;
}