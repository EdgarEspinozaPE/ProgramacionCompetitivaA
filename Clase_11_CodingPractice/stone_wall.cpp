#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int>& H) {
    stack<int> wall;
    int n = H.size(), sum = 0;
    for (int i = 0; i < n; i++) {
        while (wall.size() > 0) {
            int b = wall.top();
            if (b == H[i]) {
                sum++;
                wall.pop();
                break;
            }
            else {
                if (b > H[i]) {
                    wall.pop();
                }
                else break;
            }
        }
        wall.push(H[i]);
    }
    int a = n - sum;
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> H = { 8,8,5,7,9,8,7,4,8 };

    cout << solution(H);

    return 0;
}