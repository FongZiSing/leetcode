// 双指针 方法一
class Solution {
public:
    bool isLongPressedName(string name, string typed)
    {
        int p = 0, q = 0;
        int n = name.size(), m = typed.size();
        while (p != n || q != m) {
            if (name[p] == typed[q])
                q++, p++;
            else if (p > 0 && name[p - 1] == typed[q])
                q++;
            else
                return false;
        }
        return p == n && q == m;
    }
};

// 双指针 方法二
class Solution {
public:
    bool isLongPressedName(string name, string typed)
    {
        int p1 = 0, p2 = 0, q1 = 0, q2 = 0;
        int n = name.size(), m = typed.size();
        while (p1 < n && q1 < m) {
            while (p2 < n && name[p1] == name[p2])
                p2++;
            while (q2 < m && typed[q1] == typed[q2])
                q2++;
            if (name[p1] != typed[q1] || p2 - p1 > q2 - q1) {
                return false;
            }
            p1 = p2;
            q1 = q2;
        }
        return p1 == n && q1 == m;
    }
};