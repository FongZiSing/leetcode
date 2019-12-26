// 暴力法的进一步优化
// 在一次测试中，原先要2s，现在需20ms
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        if(size == 0) return 0;
        vector<int> remnent(size);
        int min, sum, p, q;
        remnent[0] = heights[0];
        heights.push_back(0);
        for(int i = 1; i < size; ++i) {
            sum = min = heights[i];
            if(heights[i+1] < heights[i]) {
                for(int j = i-1; j>=0; --j) {
                    if(heights[j] < min) min = heights[j];
                    if(sum < min*(i-j+1)) sum = min*(i-j+1);
                }
            }
            remnent[i] = max(remnent[i-1], sum);
        }
        return remnent.back();
    }
};