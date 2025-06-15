#include <array>
#include <vector>
#pragma once
class Solution
{
	public:
		static std::array<int, 2> twoSum(std::vector<int>& nums, int target);

		static int closestMeetingNode(std::vector<int>& edges, int node1, int node2);

		static bool isPalindrome(int x);

		static long long maximumTripletValue(std::vector<int>& nums);

		static int snakesAndLadders(std::vector<std::vector<int>>& board);

		static int countPairs(std::vector<int>& nums, int k);

		static int countLargestGroup(int n);

		static std::vector<int> applyOperations(std::vector<int>& nums);

		static int minMaxDifference(int num);

		static int maxDiff(int num);
};

