class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int num = 0, real;
        vector<int> lut(1000, 0);
        std::for_each(answers.begin(), answers.end(), [&lut](int& ans) { lut[ans]++; });
        for (int i = 0; i < lut.size(); ++i) {
            if (lut[i]) {
                real = i + 1;
                num += (lut[i] + i) / real * real;
            }
        }
        return num;
    }
};