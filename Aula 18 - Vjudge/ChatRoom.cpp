#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main (){

    char s[101]; // word
    
    cin >> s;

    int i=0;
    int cont=0; // counts the letters 1-5 (h-o)
    bool stop = false;

    while(s[i] != '\n' && cont!=5 && !stop){
        //cout << "entrou\n";

        for(; i<100; i++){
            if(s[i]=='h'){ 
                cont++;
                break;
            }
        }
        for(i+=1; i<100; i++){
            if(s[i]=='e'){ 
                cont++;
                break;
            }
        }
        for(i+=1; i<100; i++){
            if(s[i]=='l'){ 
                cont++;
                break;
            }
        }
        for(i+=1; i<100; i++){
            if(s[i]=='l'){ 
                cont++;
                break;
            }
        }
        for(i+=1; i<100; i++){
            if(s[i]=='o'){ 
                cont++;
                break;
            }
        }
        stop = true;
    }
    if(cont==5){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}