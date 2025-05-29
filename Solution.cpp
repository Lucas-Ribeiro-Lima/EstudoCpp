#include "Solution.h"
#include <array>
#include <vector>
#include <unordered_map>
#include <string>

std::array<int, 2> Solution::twoSum(std::vector<int>& nums, int target) {
	std::unordered_map<int, int> map;

	for (int i = 0; i < nums.size(); i++) {
		int c = target - nums[i];
		if (map.find(c) != map.end()) {
			return { i, map[c] };
		}
		map[nums[i]] = i;
	}

	return { -1, -1 };
}

bool Solution::isPalindrome(int x) {
	std::string s = std::to_string(x);
	int m = s.length() / 2;

	for(int i = 0, j = s.length() - 1; i < j; i++, j--) if (s[i] != s[j]) return false;
	
	return true;
}