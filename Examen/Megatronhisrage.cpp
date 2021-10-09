#include <iostream>
#include <vector>
#include <set>
using namespace std;

void megatron(vector<int>planets, int P, int M) {
    vector<long long int> acumuladasuma;
    long long int suma = 0, planetasdestruidos = -1, autobotsdestruidos = 99999999;
    acumuladasuma.push_back(0);
    for (int i = 1; i <= P; i++) {
        suma += planets[i - 1];
        acumuladasuma.push_back(suma);
    }
    int p1 = 0, p2 = 0,flag = 0;
    suma = 0;
    for (int i = 1; i <= P; i++) {
        if (flag == 1) i--;
        suma = acumuladasuma[i] - acumuladasuma[p1];
        flag = 0;
        if (suma > M) {
            flag = 1;
            p1++;
        }
        if (planetasdestruidos < (i - p1)) {
            planetasdestruidos = i - p1;
            autobotsdestruidos = suma;
        }
        else if (planetasdestruidos == (i - p1)) {
            if (autobotsdestruidos > suma) autobotsdestruidos = suma;
        }
    }
    if (planetasdestruidos == 0) {
        autobotsdestruidos = 0;
    }
    if (autobotsdestruidos == 99999999)
        cout << 0 << " " << 0;
    else
        cout << autobotsdestruidos <<" "<<planetasdestruidos;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int P, M, aux;
        vector<int>planets;
        cin >> P >> M;
        for (int i = 0; i < P; i++) {
            cin >> aux;
            planets.push_back(aux);
        }
        megatron(planets, P, M);
        cout << "\n";
    }
}

