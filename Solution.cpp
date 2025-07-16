#include "Solution.h"
#include <array>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <tuple>
#include <algorithm>
#include <charconv>
#include <ranges>
#include <bitset>

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

int Solution::maxDiff(int num) {
	std::string s{ std::to_string(num) };
	std::string max_string{ s };
	std::string min_string{ s };

	char replaceForMax = '\0', replaceForMin = '\0';

	for (char c : s) {
		if (c != '9' && !replaceForMax) replaceForMax = c;
		if (c != '0' && c != '1' && !replaceForMin) replaceForMin = c;
		if (replaceForMax && replaceForMin) break;
	}

	char min_sub = '0';

	for (int i = 0; i < s.size(); i++) {
		if (max_string[i] == replaceForMax) max_string[i] = '9';
		if (min_string[i] == replaceForMin) {
			if (i == 0) min_sub = '1';
			min_string[i] = min_sub;
		}
	}


	return stoi(max_string) - stoi(min_string);
}


std::vector<int> Solution::maxSubsequence(std::vector<int>& nums, int k) {
	std::vector<int> slice;
	slice.reserve(k);

	for (int i = 0; i < k; i++) {
		slice.push_back(nums[i]);
	}

	for (int i = k; i < nums.size(); i++) {
		int min_n = INT_MAX;
		int min_idx = -1;
		for (int j = 0; j < slice.size(); j++) {
			if (slice[j] < min_n) {
				min_n = slice[j];
				min_idx = j;
			}
		}

		if (nums[i] > min_n) {
			slice.erase(slice.begin() + min_idx);
			slice.push_back(nums[i]);
		}
	}
		

	return slice;
}

int Solution::numSubSeq(vector<int>& nums, int target) {
	int res = 0;
	
	sort(nums.begin(), nums.end());

	int i = 0;
	int j = nums.size() - 1;

	while (i < nums.size()) {
		if (nums[i] + nums[j] <= target) {
			if (j == i) res++;
			else res += j - i;
		}

		if (i == j) {
			i++;
			j = nums.size() - 1;
		}
		else {
			j--;
		}
	}


	return res % 1000000007;
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

char Solution::kthCaracter(int k) {
	string word = "a";

	while (word.size() < k) {
		string tmp = "";

		for (char c : word) {
			c++;
			tmp += c;
		}

		word += tmp;
	}

	return word[k - 1];
};


char Solution::kthCharacter(long long k, vector<int>& operations) {
	string word{ "a" };

	for(int operation : operations) {
		if (!operation) word += word;
		else {
			string tmp{ "" };
			for (char c : word) {
				int code = ++c % 97;
				tmp += 'a' + ((char)code % 26);
			}
			word += tmp;
		}
	}

	return word[k - 1];
}


int Solution::findLHS(std::vector<int>& nums) {
	int min = nums[0];

	return 0;
}


int Solution::findLucky(vector<int>& arr) {
	int lucky = -1;

	unordered_map<int, int> frequency;

	for (int n : arr) {
		frequency[n]++;
	}

	int largest = INT_MIN;
	for (auto [ k, v ] : frequency) {
		if (k != v) continue;
		if (v > largest) 
		{
			largest = v;
			lucky = k;
		}
	}
	

	return lucky;
}

bool cmp(const vector<int>& a, const vector<int>& b) {
	if (a[0] < b[0]) return true;
	if (a[0] == b[0] && a[1] < b[1]) return true;
	
	return false;
}

int Solution::maxEvents(vector<vector<int>>& events) {
	sort(events.begin(), events.end(), cmp);
	int attended = 0;
	int day = 1;

	for (vector<int> event : events) {
		if (event[0] <= day && day <= event[1]) {
			attended++;
		}
		day++;
	}

	return attended;
};

int Solution::getDecimalValue(ListNode* head) {
	int val = 0;

	while (head) {
		val <<= 1;
		val += head->val;
		head = head->next;
	};

	return val;
};

#define hasVowel 0x01
#define hasConsonant 0x10

static inline bool isVowel(char& _c) {
	if(_c < 91) {
		_c += 'a' - 'A';
	}
	return _c == 'a' || _c == 'e' || _c == 'i' || _c == 'o' || _c == 'u';
}

bool Solution::isValid(string word) {
	uint8_t mask =  0x00;
	for ( char c : word ) {
		if(isdigit(c)) continue;

		if (!isalnum(c)) {
			return false;
		}

		if (isVowel(c)) {
			mask |= hasVowel;
		}
		else {
			mask |= hasConsonant;
		}
	}

	return mask & hasVowel && mask & hasConsonant && word.size() >= 3;
}

int Solution::maximumLength(vector<int>& nums) {
	int oddOdd = 0;
	int evenEven = 0;
	int alternate = 0;

	//Invert the parity of first element to count as dummy of the earliest alternate sequence
	int lastOdd = (nums[0] % 2) ^ 0b1; 

	for (int n : nums) {
		if (n % 2 == 0)
		{
			evenEven++;
			if (lastOdd)
			{
				alternate++;
				lastOdd = false;
			}
		}
		else 
		{
			oddOdd++;
			if (!lastOdd)
			{
				alternate++;
				lastOdd = true;
			}
		}
	}

	return max({ evenEven, oddOdd, alternate });
}