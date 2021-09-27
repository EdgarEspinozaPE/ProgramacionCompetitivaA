#include <iostream>
#include <vector>
using namespace std;

void sumtarget(vector<int> nums, int target) {
	int punt1 = 0;
	int punt2 = nums.size()-1;
	while (nums[punt1] + nums[punt2] != target) {
		if (punt1 == punt2) {
			cout << "No hay solucion";
			return;
		}

		if (nums[punt1] + nums[punt2] > target) {
			punt2--;
		}
		else if (nums[punt1] + nums[punt2] < target) {
			punt1++;
		}
	}
	std::cout << punt1 <<" "<< punt2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums;
	int n, end = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> end;
		nums.push_back(end);
	}
	int target;
	cin >> target;
	sumtarget(nums, target);
}

