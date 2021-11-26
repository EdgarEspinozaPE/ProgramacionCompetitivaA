#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> q2;
    for (auto i : nums) {
        q2.push(i);
        if (q2.size() > k) {
            q2.pop();
        }
    }
    return q2.top();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k = 2;
    vector<int> nums{ 3,2,1,5,6,4 };

    cout << findKthLargest(nums, k);
    return 0;
}