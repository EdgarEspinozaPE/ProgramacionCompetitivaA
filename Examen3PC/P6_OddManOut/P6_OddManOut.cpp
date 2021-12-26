#include<iostream>
#include<vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int Nonrepeated(vector<int> arr, int n)
{
    unordered_map<int, int> aux;
    for (int i = 0; i < n; i++)
        aux[arr[i]]++;

    for (int i = 0; i < n; i++)
        if (aux[arr[i]] == 1)
            return arr[i];
    return -1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int G;
        cin >> G;
        int aux=0;
        vector<int> guests;
        int flag = 0;

        for(int j=0;j<G;j++) {
            int aux;
            cin >> aux;
            guests.push_back(aux);
        }
        cout << "Case #" << i + 1 << ": " << Nonrepeated(guests,G)<<"\n";
    }

    return 0;
}

