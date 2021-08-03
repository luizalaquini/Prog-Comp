#include <iostream>
using namespace std;

int main (){
    int N; // number of students (1<=N<=100)
    int T; // number of test cases (T<=50)

    cin >> T;

    for (int i=0; i<T; i++){
        cin >> N;
        int c[N]; // speed in m/s (1<=c<=10000)
        int s = 1; // speed of the clown (max c)

        for (int j=0; j<N; j++){
            cin >> c[j];
            if (c[j] > s){
                s = c[j];
            }
        }

        cout << "Case " << (i+1) << ": " << s <<endl; 
    }

    return 0;
}