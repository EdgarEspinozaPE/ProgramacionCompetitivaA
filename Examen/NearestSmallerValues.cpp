#include <iostream>
#include <vector>
using namespace std;    

vector<int> findnearest(vector<int> nums, int n) {
    vector<int> indexes;
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (nums[i] > nums[j]) {
                indexes.push_back(j+1);
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            indexes.push_back(0);
        }
    }
    return indexes;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, aux;
    cin >> n;
    vector<int>nums(n+1);
    vector<int>rpta(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        rpta[i] = i - 1;
        int aux = ~rpta[i];
        while (~rpta[i] && nums[rpta[i]] >= nums[i]) {
            rpta[i] = rpta[rpta[i]];
        }
        cout << rpta[i] + 1 << " ";
    }

    /*
    vector<int>rpta = findnearest(nums, n);
    for (auto i : rpta) {
        cout << i << " ";
    }
    */
}

