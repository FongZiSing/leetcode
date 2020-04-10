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
    int deepestLeavesSum(TreeNode* root) {
        stack<pair<TreeNode*, int>> s;
        TreeNode* p = root;
        int depth = 1;
        int maxDepth = 0;
        int result = 0;
        while (p || !s.empty()) {
            while (p) {
                s.push(make_pair(p, depth));
                p = p->left;
                depth++;
            }
            tie(p, depth) = s.top();
            if (depth > maxDepth) {
                maxDepth = depth;
                result = p->val;
            } else if (depth == maxDepth) {
                result += p->val;
            }
            p = p->right;
            s.pop();
            depth++;
        }
        return result;
    }
};