#include <iostream>
#include <vector>
#include <algorithm> /* for_each */

using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        std::vector<int> result = {-1, -1};
        int left = 0;
        int right = nums.size() - 1;
        int mid  = (left + right) / 2;
        while(left <= right)
        {
            if(nums[mid] == target)
            {
                result[0] = mid;
                result[1] = mid;
                break;
            }
            if(nums[mid] < target)
                left = mid+1;
            if(nums[mid] > target)
                right = mid-1;
            mid  = (left + right) / 2;
        }

        if (result[0] != -1)
        {
            for(int i = result[0]; i >=0; i--)
            {
                if(nums[i] == target) result[0] = i;
                else break;
            }

            for(int i = result[1]; i < nums.size(); i++)
            {
                if(nums[i] == target) result[1] = i;
                else break;
            }
        }

        return result;
        
    }
};


int main()
{
    vector<int> nums = {1};
    int target = 1;
    Solution s;
    vector<int> result = s.searchRange(nums, target);
    std::for_each(result.begin(), result.end(), [](const int& n){std::cout << n << " ";});
    return 0;
}
