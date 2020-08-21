class Solution {
    using iter = vector<int>::iterator;

    vector<int> tmp;
    void inplace_merge(const int& n, iter beg, iter mid, iter end, int& ans)
    {
        tmp.clear();
        int maxi = n / 2, maxj = n - maxi;
        int i = 0, j = 0;

        while (i < maxi || j < maxj) {
            if (i < maxi && j < maxj) {
                if (*(beg + i) > *(mid + j)) {
                    tmp.push_back(*(beg + i));
                    i++;
                    ans += maxj - j;
                    continue;
                }
                tmp.push_back(*(mid + j));
                j++;
                continue;
            }
            if (i < maxi) {
                tmp.push_back(*(beg + i));
                i++;
                continue;
            }
            if (j < maxj) {
                tmp.push_back(*(mid + j));
                j++;
            }
        }
        copy(tmp.begin(), tmp.end(), beg);
    }

    void mergesort(iter beg, iter end, int& ans)
    {
        int n = distance(beg, end);
        if (n == 0 || n == 1)
            return;
        else {
            iter mid = beg + n / 2;
            mergesort(beg, mid, ans);
            mergesort(mid, end, ans);
            inplace_merge(n, beg, mid, end, ans);
        }
    }

public:
    int reversePairs(vector<int>& nums)
    {
        int ans = 0;
        tmp.reserve(nums.size());
        mergesort(nums.begin(), nums.end(), ans);
        return ans;
    }
};