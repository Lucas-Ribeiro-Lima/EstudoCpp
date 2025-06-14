#include "Solution.h"
#include <array>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

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

int Solution::closestMeetingNode(std::vector<int>& edges, int node1, int node2) {
	auto bfs = [](std::vector<int>& edges, int node) {
		std::queue<int> q;
		std::vector<int> distances(edges.size(), INT_MAX);
		int i = 1;

		distances[node] = 0;

		q.push(node);

		while (!q.empty()) {
			int val = q.front();
			q.pop();

			int prox = edges[val];

			if (prox == -1) continue;
			if (distances[prox] == INT_MAX) {
				distances[prox] = i++;
				q.push(prox);
			}
		}

		return distances;
	};

	
	std::vector<int> distancesA = bfs(edges, node1);
	std::vector<int> distancesB = bfs(edges, node2);


	int idx = -1;
	int minMaxDistance = INT_MAX;

	for (int i = 0; i < distancesA.size(); i++) {
		if (distancesA[i] == INT_MAX || distancesB[i] == INT_MAX) continue;
		
		int maxDistance = std::max(distancesA[i], distancesB[i]);
		if (maxDistance < minMaxDistance) {
			idx = i;
			minMaxDistance = maxDistance;
		}
		
	}

	return idx;
}

long long Solution::maximumTripletValue(std::vector<int>& nums) {

	auto expression = [](int i, int j, int k) {
		return (long long) (i - j) * k;
	};
	
	long long maxValue = 0;
	int8_t len = nums.size();

	for (int i = 0; i < len - 2; i++) {
		for (int j = i + 1; j < len - 1; j++) {
			for (int k = j + 1; k < len; k++) {
				maxValue = std::max(maxValue, expression(nums[i], nums[j], nums[k]));
			}
		}
	}

	return maxValue;
}

int Solution::snakesAndLadders(vector<vector<int>>& board) {
	int n = board.size();
	int boardSize = n * n;
	vector<int> dist(boardSize + 1, -1);
	queue<int> q;

	auto getCoordinates = [&](int square) {
		int row = (square - 1) / n;
		int col = (square - 1) % n;
		if (row % 2 == 1) col = n - 1 - col;
		row = n - 1 - row;
		return make_pair(row, col);
	};

	q.push(1);
	dist[1] = 0;

	while (!q.empty()) {
		int curr = q.front(); q.pop();

		for (int i = 1; i <= 6 && curr + i <= boardSize; ++i) {
			int next = curr + i;

			int row, col;
			tie(row, col) = getCoordinates(next);

			if (board[row][col] != -1) {
				next = board[row][col];
			}

			if (dist[next] == -1) {
				dist[next] = dist[curr] + 1;
				q.push(next);
			}
		}
	}

	return dist[boardSize];
}

int Solution::countPairs(vector<int>& nums, int k) {
	int pairs = 0;

	for (int i = 0; i < nums.size() - 1; i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[i] != nums[j]) continue;
			if (i * j % k != 0) continue;
			pairs++;
		}
	}

	return pairs;
}

int Solution::countLargestGroup(int n) {
	int largestSize = 0;
	int groups[37] = {};
	int res = 0;

	for (int i = 1; i <= n; i++) {
		int sum = 0;

		for (int x = i; x > 0; x /= 10) {
			sum += x % 10;
		}

		int val = ++groups[sum];

		if (val > largestSize) {
			largestSize = val;
			res = 0;
		}

		if (val == largestSize) {
			res++;
		}

	}

	return res;
}

vector<int> Solution::applyOperations(vector<int>& nums) {
	int len = nums.size();
	
	int insertPosition = 0;

	for (int i = 0; i < len; i++) {
		if(nums[i] == nums[i + 1]) {
			nums[i] *= 2;
			nums[i + 1] = 0;
		}

		if (nums[i] != 0) {
			int tmp = nums[i];
			nums[i] = 0;
			nums[insertPosition++] = tmp;
		}
	}

	if (nums[len - 1] != 0) {
		int tmp = nums[len - 1];
		nums[len - 1] = 0;
		nums[insertPosition++] = tmp;
	}

	return nums;
} 

long long distributeCandies(int n, int limit) {
	long long cnt = 0;

	for (int x = 0; x <= min(n, limit); ++x) {
		for (int y = 0; y <= min(n - x, limit); ++y) {
			int z = n - x - y;
			if (z >= 0 && z <= limit) {
				cnt++;
			}
		}
	}

	return cnt;
}

int Solution::minMaxDifference(int num) {
	std::string s{ std::to_string(num) };
	std::string maxStr{ s };
	std::string minStr{ s };

	char replaceForMax = '\0', replaceForMin = '\0';

	for (char c : s) {
		if (c != '9' && replaceForMax == '\0') replaceForMax = c;
		if (c != '0' && replaceForMin == '\0') replaceForMin = c;
		if (replaceForMax && replaceForMin) break;
	}

	for (int i = 0; i < s.size(); i++) {
		if (maxStr[i] == replaceForMax) maxStr[i] = '9';
		if (minStr[i] == replaceForMin) minStr[i] = '0';
	}

	return std::stoi(maxStr) - std::stoi(minStr);
};
