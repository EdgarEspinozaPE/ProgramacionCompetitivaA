#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverse(vector<int>& nums, int a, int b) {
    int p2=0;
    int mid = (a + ((b - a) / 2));
    for (int i = a; i <= mid; i++) {
        swap(nums[i], nums[b - p2]);
        p2++;
    }
}

int sum(vector<int> nums, int a, int b) {
    int sum = 0;
    for (int i = a; i <= b; i++) {
        sum += nums[i];
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    int t = 0;
    cin >> n >> m;
    vector<int> nums(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> t>>a>>b;
        if (t == 1) {
            reverse(nums, a, b);
        }
        if (t == 2) {
            cout << sum(nums, a, b) << "\n";

        }
    }
}

