#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases = 0, n = 0;
    bool r = false;
    string p, a;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        cin >> p >> n >> a;
        deque<int> arr;
        string num = "";
        string opc = p;

        opc.erase(remove(opc.begin(), opc.end(), 'R'), opc.end());

        if (opc.length() > n) {
            cout << "error\n";
            continue;
        }
        else if (opc.length() == n) {
            cout << "[]\n";
            continue;
        }

        for (int j = 1; j < a.length(); j++) {
            if (a[j] == ',' || a[j] == ']') {
                arr.push_back(stoi(num));
                num = "";
            }
            else {
                num += a[j];
            }
        }

        r = false;
        for (int k = 0; k < p.length(); k++) {
            if (p[k] == 'D') {
                if (r == true) {
                    arr.pop_back();
                }
                else {
                    arr.pop_front();
                }
            }
            else if (p[k] == 'R') {
                if (r == false) {
                    r = true;
                }
                else r = false;
            }
            else { a = "error"; break; }
        }
        cout << "[";
        if (r == false) {
            cout << arr.front();
            arr.pop_front();
            while (!arr.empty()) {
                cout << "," << arr.front();
                arr.pop_front();
            }
        }
        else {
            cout << arr.back();
            arr.pop_back();
            while (!arr.empty()) {
                cout << "," << arr.back();
                arr.pop_back();
            }
        }
        cout << "]\n";
    }
    return 0;
}