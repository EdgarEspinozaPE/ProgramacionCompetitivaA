#include <iostream>
#include <set>

using namespace std;

int main(int argc, char const* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, n = 0, x;

    multiset<int, less<int>> even;
    multiset<int, greater<int>> odd;

    cin >> N;
    while (n++ < N) {
        cin >> x;
        if (x % 2 == 0)
            even.insert(x);
        else
            odd.insert(x);
    }

    for (auto i = even.begin(); i != even.end(); i++)
        cout << *i << endl;

    for (auto i = odd.begin(); i != odd.end(); i++)
        cout << *i << endl;

    return 0;
}