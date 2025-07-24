#include <array>
#include <vector>
#include <string>
#pragma once

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {};
	ListNode(int x) : val(x), next(nullptr) {};
	ListNode(int x, ListNode* next) : val(x), next(next) {};
};

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

	static std::vector<int> maxSubsequence(std::vector<int>& nums, int k);

	static long long kthSmallestProduct(std::vector<int>& nums1, std::vector<int>& nums2, long long k);

	static int numSubSeq(std::vector<int>& nums, int target);

	static int maxDifference(std::string s);

	static int maximumDifference(std::vector<int>& nums);

	static std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k);

	static int possibleStringCount(std::string word);

	static char kthCaracter(int k);

	static char kthCharacter(long long k, std::vector<int>& operations);

	static int findLHS(std::vector<int>& nums);

	static int findLucky(std::vector<int>& arr);

	static int maxEvents(std::vector<std::vector<int>>& events);

	static int getDecimalValue(ListNode* head);

	static bool isValid(std::string word);

	static int maximumLength(std::vector<int>& nums);

	static std::vector<std::string> removeSubFolders(std::vector<std::string>& folder);

	static std::vector<std::vector<std::string>> deleteDuplicateFolder(std::vector<std::vector<std::string>>& paths);

	static std::string makeFancyString(std::string s);

	static void transposeMatrix(std::vector<std::vector<int>>& matrix);

	static int maximumGain(std::string s, int x, int y);

	static std::vector<std::pair<int, int>> findSubstrings(std::string s, std::string pattern);
};