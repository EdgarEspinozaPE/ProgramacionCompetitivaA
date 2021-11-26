#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0, x = 0, k = 0, lenleft = 0, lenright = 0;
    string S;
    deque<int> left;
    deque<int> right;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> S >> x;
        lenleft = left.size();
        lenright = right.size();

        if (S == "push_back") {
            if (left.empty()) {
                left.push_back(x);
            }
            else if (lenleft - lenright == 1) {
                right.push_back(x);
                left.push_back(right.front());
                right.pop_front();
            }
            else if (lenleft - lenright > 1) {
                right.push_back(x);
            }
        }
        else if (S == "push_front") {
            if (left.empty()) {
                left.push_front(x);
            }
            else if (lenleft - lenright == 1) {
                left.push_front(x);
            }
            else if (lenleft - lenright > 1) {
                left.push_front(x);
                right.push_front(left.back());
                left.pop_back();
            }
        }
        else if (S == "push_middle") {
            if (left.empty()) {
                left.push_back(x);
            }
            else if (lenleft - lenright == 1) {
                left.push_back(x);
            }
            else if (lenleft - lenright > 1) {
                right.push_front(left.back());
                left.pop_back();
                left.push_back(x);
            }
        }
        else if (S == "get") {
            if (x < lenleft) {
                cout << left[x] << "\n";
            }
            else {
                cout << right[x - lenleft] << "\n";
            }
        }
    }

    return 0;
}