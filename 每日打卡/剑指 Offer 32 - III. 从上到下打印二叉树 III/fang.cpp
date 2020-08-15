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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> ans;
        TreeNode* p;
        int level;

        q.push(make_pair(root, 0));
        while (!q.empty()) {
            tie(p, level) = q.front();
            q.pop();
            if (!p) {
                continue;
            }

            q.push(make_pair(p->left, level + 1));
            q.push(make_pair(p->right, level + 1));
            if (ans.size() <= level) {
                ans.resize(level + 1);
            }
            if (level % 2) {
                ans[level].insert(ans[level].begin(), p->val);
            }
            else {
                ans[level].push_back(p->val);
            }
        }
        return ans;
    }
};