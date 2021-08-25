#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int main (){
    string s, r;

    cin >> s;

    r = s;
    reverse(r.begin(), r.end());

    if(s!=r) { // Não é palíndromo
        cout << s.size() << endl;
    } else {// É palíndromo
        for(int i=0; s==r; i++){
            s[i] = s[i+1];
            r = s;
            reverse(r.begin(), r.end());
        }
        cout << s.size() << endl;
    }

    

    cout << s << "\n" << r << endl;
}