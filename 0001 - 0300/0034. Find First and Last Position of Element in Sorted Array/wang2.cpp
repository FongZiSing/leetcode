#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        std::vector<int> result = {-1, -1};

        auto left = std::lower_bound(nums.begin(), nums.end(), target);

        if(left == nums.end() || *left != target) return std::vector<int>{-1, -1};

        result[0] = left - nums.begin();
        
        for(int i = result[0]; i < nums.size(); i++)
        {
            if(nums[i] == target) result[1] = i;
            else break;
        }
        

        return result;
    }
};

int main(int, char**) {
    std::vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    
    Solution s;

    std::vector<int> result = s.searchRange(nums, target);

    std::cout << result[0] << " " << result[1] << std::endl;
    std::cout << "Hello, world!\n";
    return 0;
}
