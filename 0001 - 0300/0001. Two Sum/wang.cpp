class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> u_map;
        for(int i = 0; i < nums.size(); i++)
        {
            if(u_map.find(nums[i]) == u_map.end())
            {
                u_map[target - nums[i]] = i;
            }
            else
            {
                return std::vector<int>{i, u_map[nums[i]]};
            }
        }
        return std::vector<int>{-1, -1};
    }
};
