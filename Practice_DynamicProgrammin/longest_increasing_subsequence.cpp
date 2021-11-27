#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLIS(std::vector<int>& nums) {
	std::vector<int> LIS(nums.size(), 1);

	int global_LIS = 1;
	for (int i = 1; i < nums.size(); ++i) {
		for (int j = 0; j < i; ++j)
			if (nums[j] < nums[i])
				LIS[i] = std::max(LIS[i], 1 + LIS[j]);
		global_LIS = std::max(global_LIS, LIS[i]);
	}

	return global_LIS;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> nums;

	nums = { 10, 9, 2, 5, 3, 7, 101, 18 };
	std::cout << lengthOfLIS(nums) << "\n";

	nums = { 0, 1, 0, 3, 2, 3 };
	std::cout << lengthOfLIS(nums) << "\n";

	nums = { 7, 7, 7, 7, 7, 7, 7 };
	std::cout << lengthOfLIS(nums) << "\n";

	return 0;
}