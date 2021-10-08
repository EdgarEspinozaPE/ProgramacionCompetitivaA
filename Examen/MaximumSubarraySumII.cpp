#include <iostream>
#include <vector>
#include <set>
using namespace std;

long long int Maxsubarray(vector<long long int> nums, int n, int a, int b) {
    for (int i = 1; i <= n; i++) {
        nums[i] += nums[i - 1];   
    }
    set<pair<long long int, int>> subder;
    for (int i = a; i <= b; i++) {
        subder.insert({ nums[i],i });
    }
    long long int maxglobal=-1e18;
    for (int i = 1; i <= n - a + 1; i++) {
        maxglobal = max(maxglobal, subder.rbegin()->first - nums[i - 1]);
        subder.erase({ nums[i + a - 1],i + a - 1 });
        if (i + b <= n) {
            subder.insert({ nums[i + b],i + b });
        }
    }
    return maxglobal;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int a, b;
    cin >> n >> a >> b;
    vector<long long int> nums(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    cout << Maxsubarray(nums, n, a, b);
    return 0;
}

