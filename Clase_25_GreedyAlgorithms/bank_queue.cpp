#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 0, T = 0, sum = 0, c = 0, t = 0;


    vector<pair<int, int>> people;
    cin >> N >> T;
    vector<bool> place(T, false);
    for (int i = 0; i < N; i++) {
        cin >> c >> t;
        people.push_back(make_pair(c, t));
    }

    sort(people.begin(), people.end());

    for (int i = people.size() - 1; i >= 0; i--) {
        for (int j = people[i].second; j >= 0; j--) {
            if (place[j] == false) {
                place[j] = true;
                sum += people[i].first;
                break;
            }
        }
    }
    cout << sum;
    return 0;
}




