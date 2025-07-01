#include "Solution.h"
#include <array>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

array<int, 2> Solution::twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> map;

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
	string s = to_string(x);
	int m = s.length() / 2;

	for(int i = 0, j = s.length() - 1; i < j; i++, j--) if (s[i] != s[j]) return false;
	
	return true;
}

int Solution::closestMeetingNode(vector<int>& edges, int node1, int node2) {
	auto bfs = [](vector<int>& edges, int node) {
		queue<int> q;
		vector<int> distances(edges.size(), INT_MAX);
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

long long Solution::maximumTripletValue(vector<int>& nums) {

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
	std::vector<int> dist(boardSize + 1, -1);
	std::queue<int> q;

	auto getCoordinates = [&](int square) {
		int row = (square - 1) / n;
		int col = (square - 1) % n;
		if (row % 2 == 1) col = n - 1 - col;
		row = n - 1 - row;
		return std::make_pair(row, col);
	};

	q.push(1);
	dist[1] = 0;

	while (!q.empty()) {
		int curr = q.front(); q.pop();

		for (int i = 1; i <= 6 && curr + i <= boardSize; ++i) {
			int next = curr + i;

			int row, col;
			std::tie(row, col) = getCoordinates(next);

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

int Solution::maxDifference(string s) {
	int map[26]{0};
	int oddMax = 0;
	int evenMin = INT_MAX;

	for (int i = 0; i < s.size(); i++) {
		int charCode = s[i] - 'a';
		map[charCode]++;
	};

	for (int i = 0; i < 26; i++) {
		if (map[i] % 2 == 0 && map[i] != 0) {
			evenMin = min(map[i], evenMin);
		}
		else {
			oddMax = max(map[i], oddMax);
		}
	}

	return oddMax - evenMin;
}

int Solution::maximumDifference(std::vector<int>& nums) {
	int length = nums.size(), res = -1;
	std::vector<int> pre(length), suff(length);

	pre[0] = nums[0];
	suff[length - 1] = nums[length - 1];

	for (int i = 1; i < length; i++) {
		pre[i] = min(pre[i - 1], nums[i]);
	}

	for (int i = length - 2; i >= 0; i--) {
		suff[i] = max(suff[i - 1], nums[i]);
	}

	for (int i = 0; i < length; i++) {
		res = max(res, suff[i] - pre[i]);
	}

	return res;
}

vector<vector<int>> Solution::divideArray(vector<int>& nums, int k) {
	vector<vector<int>> res;
	int lenRes= nums.size() / 3;
	
	std::sort(nums.begin(), nums.end());

	std::vector<int> slide;
	slide.reserve(3);

	auto isValid = [k, &nums, &slide]() {
		int a = abs(slide[0] - slide[1]);
		int b = abs(slide[0] - slide[2]);
		int c = abs(slide[1] - slide[2]);

		return a <= k && b <= k && c <= k;
	};

	for (int i = 0; i < nums.size(); i++) {
		if (slide.size() < 3) {
			slide.push_back(nums[i]);
		}
		else {
			slide.erase(slide.begin());
			slide.push_back(nums[i]);
		}

		if (slide.size() == 3 && isValid())
		{
			res.push_back(slide);
			slide.erase(slide.begin(), slide.end());
		}
	}

	if (res.size() != lenRes) return vector<vector<int>>{};
	return res;
}


int Solution::possibleStringCount(string word) {
	char last = word[0];
	int charCnt = 1;
	int res = 0;

	for (int i = 1; i < word.size(); i++) {
		if (word[i] == last) charCnt++;
		else
		{
			last = word[i];
			res += charCnt - 1;
			charCnt = 1;
		}
	}

	return res + charCnt;
}