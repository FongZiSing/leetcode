#include <iostream>
#include <vector>
#include <algorithm> /*std::min*/
using namespace std;

// naive method two-layer loop
class Solution1 {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for(int i = 0; i < height.size(); i++)
        {
            for(int j = i; j < height.size(); j++)
            {
                int min = std::min(height[j], height[i]);
                max = max > min * (j - i)?max:min * (j - i);
            }
        }
        return max;
    }
};

// two pointers
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;

        int max = 0;
        while(left < right)
        {
            int min = std::min(height[left], height[right]);
            max = max > min*(right - left) ? max : min*(right - left);

            if(height[left] < height[right])
                left++;
            else right--;
        }
        return max;
    }
};

int main()
{
    std::vector<int> height{1,8,6,2,5,4,8,3,7};
    Solution s;
    cout << s.maxArea(height) << endl;
    return 0;
}
