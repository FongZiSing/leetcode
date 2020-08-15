/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 动态规划思想
    pair<int, int> dp(TreeNode* p)
    {
        if (p == nullptr) return move(make_pair(0, 0));
        int l1, l2, r1, r2, select, unselect;
        tie(l1, l2) = dp(p->left);
        tie(r1, r2) = dp(p->right);

        select = p->val + l2 + r2;
        unselect = max(l1, l2) + max(r1, r2);
        return move(make_pair(select, unselect));
    }

    int rob(TreeNode* root)
    {
        int select, unselect;
        tie(select, unselect) = dp(root);
        return max(select, unselect);
    }
};