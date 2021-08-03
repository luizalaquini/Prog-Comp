#include <iostream>
using namespace std;

int main (){
    int T; // Number of test cases (T < 20)

    cin >> T;

    for (int i=0; i<T; i++){
        int a, b, c; // Salaries in the range [1000, 10000]
        int x; // Who survives

        cin >> a >> b >> c;

        if (a>b && a<c || a<b && a>c){
            x = a;
        } else if (b>a && b<c || b<a && b>c){
            x = b;
        } else {
            x = c;
        }

        cout << "Case " << (i+1) << ": " << x << endl;
    }

    return 0;
}