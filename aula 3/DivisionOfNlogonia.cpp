#include <iostream>
using namespace std;

int main(){
    int K; // Number of queries that will be made (0 < K ≤ 10^3)
    
    do{
        int N, M; // Coordinates of the division point (−10^4 < N, M < 10^4)

        cin >> K;
        if (K==0){
            return 0;
        }

        cin >> N >> M;

        for (int i=0; i<K; i++){
            int X, Y; // Coordinates of a residence (−10^4 ≤ X, Y ≤ 10^4)

            cin >> X >> Y;

            //cout << "K=" << K << " N=" << N << " M=" << M << " X=" << X << " Y=" << Y << endl; TESTE

            if (X==N || Y==M){
                cout << "divisa" << endl;
            } else if (X>N && Y>M){
                cout << "NE" << endl;
            } else if (X>N && Y<M){
                cout << "SE" << endl;
            } else if (X<N && Y>M){
                cout << "NO" << endl;
            } else if (X<N && Y<M){
                cout << "SO" << endl;
            }
        }
    } while (K!=0);
    
    return 0;    
}