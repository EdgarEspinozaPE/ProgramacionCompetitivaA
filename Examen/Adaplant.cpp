#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void build(int pos, int izq, int der,int arbol[100000],int plantas[100000]) {
    if (izq == der) {
        arbol[pos] = plantas[izq];
        return;
    }
    int mid = (izq + der) / 2;
    build(2 * pos, izq, mid,arbol,plantas);
    build(2 * pos+1, mid+1, der, arbol, plantas);
    arbol[pos] = min(arbol[2 * pos], arbol[2 * pos + 1]);
}

int query(int pos, int izq, int der, int i, int j,int arbol[100000]) {
    if (izq > der || izq > j || der < i) return 10000000;
    if (izq >= i && der <= j) {
        return arbol[pos];
    }
    int mid = (izq + der) / 2;
    return min(query(2 * pos, izq, mid, i, j,arbol), query(2 * pos + 1, mid + 1, der, i, j,arbol));
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N, K, aux;
        int plantas[100000];
        int arbol[100000];
        int r = 0;
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            cin >> aux;
            plantas[i]=aux;
        }
        build(1, 1, N, arbol,plantas);
        for (int i = 1; i <= N; i++) {
            int menor= min(query(1, 1, N, max(1, i - K - 1), max(i - 1, 1),arbol), query(1, 1, N, min(i + 1, N), min(i + K + 1, N),arbol));
            r = max(plantas[i] - menor, r);
        }
        cout <<r<<"\n";
    }
    return 0;
}

