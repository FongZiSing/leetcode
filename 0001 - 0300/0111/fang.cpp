// 先序遍历
class Solution {
public:
    int minDepth(TreeNode* root)
    {
        stack<pair<TreeNode*, int>> s;
        int min = root ? INT_MAX : 0;
        int depth = 0;
        TreeNode *q, *p = root;

        while (!s.empty() || p) {
            while (p) {
                s.push(make_pair(p, depth));
                p = p->left;
                depth++;
            }

            tie(p, depth) = s.top();
            s.pop();
            depth++;
            q = p;
            p = p->right;
            if (!p && !q->left && min > depth) {
                min = depth;
            }
        }

        return min;
    }
};

// 广度遍历
class Solution {
public:
    int minDepth(TreeNode* root)
    {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;
        TreeNode* p = root;
        int depth = 1;

        q.push(make_pair(p, depth));
        while (!q.empty()) {
            tie(p, depth) = q.front();
            q.pop();
            if (!p->left && !p->right) {
                return depth;
            }

            if (p->left) {
                q.push(make_pair(p->left, depth + 1));
            }
            if (p->right) {
                q.push(make_pair(p->right, depth + 1));
            }
        }

        return 0;
    }
};