#include <iostream>
using namespace std;

int main (){
    int n; // Size of the matrix (n < 100)

    while (n!=0) {
        cin >> n;
        if(n==0) break;

        int mat[n][n];

        /*Leitura  da matriz*/
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                cin >> mat[i][j];
            }   
        }

        /*Calculo da soma das linhas e das colunas*/
        int somalinha[n], somacoluna[n]; // vetor com valores de cada linha
        int somaLinha=0, somaColuna=0; // valores totais

        for (int i=0, cont; i<n; i++) {
            cont = 0;
            for (int j=0; j<n; j++, cont++){
                if (cont==0){
                    somalinha[i]=0;
                }
                //cout << "somalinha " << somalinha[i] << " mat " << mat[i][j] << endl; // teste
                somalinha[i]+=mat[i][j];  
            }  
            somaLinha += somalinha[i]; 
        }
        for (int j=0, cont; j<n; j++){
            cont = 0;
            for (int i=0; i<n; i++, cont++){
                if (cont==0){
                    somacoluna[j]=0;
                }
                //cout << "somacoluna " << somacoluna[j] << " mat " << mat[i][j] << endl; // teste
                somacoluna[j]+=mat[i][j];  
            }  
            somaColuna += somacoluna[j]; 
        }

        /*cout << "somalinha: "; // IMPRIME SOMAS
        for (int i=0; i<n; i++){
            cout << somalinha[i] << " ";
        }
        cout << "\ntotal = " << somaLinha;
        cout << "\nsomacoluna: ";
        for (int j=0; j<n; j++){
            cout << somacoluna[j] << " ";
        }
        cout << "\ntotal = " << somaColuna << endl;*/

        /*Análise das somas*/
        int guardai = -1, guardaj = -1; // inteiros auxiliares que guardarão os valores de i e j
        int erro = 0;

        for (int i=0, j=0; i<n; i++, j++){
            if (somalinha[i] % 2 != 0){
                erro++;
                guardai = i;
            }
            if (somacoluna[j] % 2 != 0){
                erro++;
                guardaj = j;
            }    
        }

        /*Impressão dos resultados*/
        if (erro==0){
            cout << "OK" << endl;
        } else if (erro==2 && somaLinha % 2 != 0 && somaColuna % 2 != 0){
            cout << "Change bit (" << guardai+1 << "," << guardaj+1 << ")" << endl;
        }
        else {
            cout << "Corrupt" << endl;
        }
    } 

    /*for (int i=0; i<n; i++){ // IMPRIME MATRIZ
        for (int j=0; j<n; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";   
    }*/

    return 0;
}