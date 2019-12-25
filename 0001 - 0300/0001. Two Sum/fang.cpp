class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		unordered_map<int, int>::const_iterator got;
		unordered_map<int, int> mapper;

		for (int i = 0; i < numbers.size(); ++i) {
			got = mapper.find(target - numbers[i]);
			if(got == mapper.end()) {
				mapper.emplace(numbers[i], i);
			} else {
				return vector<int>{got->second, i};
			}
		}

		return vector<int>{-1, -1};
	}
};