/* Busca Ternária: divide uma entrada em 3 partes 
Objetivo é achar max ou min
Vai testando por partes e, se necessário, dividindo mais */

#include <iostream>

int S[100005];
int D[100005];
int N;

using namespace std;

double f(double T) {
    double minn, maxx, tmp;

    minn = S[0] * T + D[0] * 1.0;
    maxx = S[0] * T + D[0] * 1.0;

    for(int i = 1; i < N; i++) {
        tmp = S[i] * T + (double) D[i];
        if(tmp > maxx)
        maxx = tmp;
        else if(tmp < minn)
        minn = tmp;
    }
    return maxx - minn;
}

double TernarySearch(double K) {
    double l = 0.0;
    double r = K ;
    double m1, m2;
    double f1, f2; 

    for(int iter = 0; iter < 200; iter++) {
        m1 = l + (r-l) / 3.0;
        m2 = r - (r-l) / 3.0;

        f1 = f(m1);
        f2 = f(m2);

        if(f1 > f2)
        l = m1 ;
        else
        r = m2;
    }
    double fl = f(l);
    double fr = f(r);
    return fl <= fr? fl: fr;
}

int main() {
    int i, k;
    double K;
    cin >> N;
    cin >> k;
    K = k * 1.0;
    for(i = 0; i < N; i++) {
        cin >> S[i];
        cin >> D[i];
    }
    printf("%lf\n",TernarySearch(K));
    return 0;
}