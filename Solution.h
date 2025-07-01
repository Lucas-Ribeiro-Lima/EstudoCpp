#include <array>
#include <vector>
#include <string>
#pragma once

class Solution
{
public:
	static std::array<int, 2> twoSum(std::vector<int>& nums, int target);

	static int closestMeetingNode(std::vector<int>& edges, int node1, int node2);

	static bool isPalindrome(int x);

	static long long maximumTripletValue(std::vector<int>& nums);

	static int snakesAndLadders(std::vector<std::vector<int>>& board);

	static int maxDifference(std::string s);

	static int maximumDifference(std::vector<int>& nums);

	static std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k);

	static int possibleStringCount(std::string word);
};

