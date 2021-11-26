#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int CN, N, n, x;
    priority_queue<int, vector<int>, greater<int>> p;

    scanf("%d", &CN);
    while (CN--) {

        scanf("%d", &N);
        n = 0;
        while (n++ < N) {
            scanf("%d", &x);
            p.push(x);
        }

        while (!p.empty()) {
            if (p.size() == 1) {
                printf("%d\n", p.top());
            }
            else {
                printf("%d ", p.top());
            }
            p.pop();
        }
    }

    return 0;
}