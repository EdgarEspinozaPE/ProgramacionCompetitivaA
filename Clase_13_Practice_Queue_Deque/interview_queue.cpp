#include <iostream>
#include <queue>
#include <list>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0, x = 0, m = 0, tp = 0;
    bool cont = false;

    deque<int> still;
    vector<int> out;
    cin >> n;
    vector<int> as(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> x;
        as[i] = x;
        if (i >= 1) {
            if (x > as[i - 1]) {
                if (as[i - 1] == still.back()) still.pop_back();
                still.push_back(x);
                if (out.empty()) { out.push_back(as[i - 1]); tp = i - 1; cont = true; }
                else if ((tp != i - 1) || (out.back() != as[i - 1])) {
                    out.push_back(as[i - 1]);
                    tp = i - 1;
                    cont = true;
                }
            }
            else if (x == as[i - 1]) {
                still.push_back(x);
            }
            else {
                out.push_back(x);
                tp = i;
                cont = true;
            }
        }
        if (i == 0) still.push_back(x);
    }

    if (!out.empty()) out.push_back(-1);
    if (cont == true) {
        while (cont == true) {
            cont = false;
            deque<int> op;
            op.push_back(still.front());
            tp = 0;

            for (int i = 1; i < still.size(); i++) {
                if (still[i] > still[i - 1]) {
                    if (still[i - 1] == op.back()) op.pop_back();
                    op.push_back(still[i]);
                    if ((tp != i - 1) || (out.back() != still[i - 1])) {
                        out.push_back(still[i - 1]);
                        tp = i - 1;
                        cont = true;
                    }
                }
                else if (still[i] == still[i - 1]) {
                    op.push_back(still[i]);
                }
                else {
                    out.push_back(still[i]);
                    tp = i;
                    cont = true;
                }
            }
            still = op;
            m++;
            if (cont == true) out.push_back(-1);
        }
        cout << m << "\n";
        for (auto k : out) {
            if (k == -1) { cout << "\n"; continue; }
            cout << k << " ";
        }
        while (!still.empty()) {
            cout << still.front() << " ";
            still.pop_front();
        }
        cout << "\n";
    }

    else {
        cout << m << "\n";
        while (!still.empty()) {
            cout << still.front() << " ";
            still.pop_front();
        }
        cout << "\n";
    }

    return 0;
}