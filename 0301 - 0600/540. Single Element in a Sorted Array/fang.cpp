/**
 * You are given a sorted array consisting of only integers where every element appears exactly twice,
 * except for one element which appears exactly once. Find this single element that appears only once.
 */
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int temp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            temp ^= nums[i];
            if (i % 2 != 0 && temp != 0) {
                temp = nums[i - 1];
                break;
            }
        }
        return temp;
    }
};