// 递归法
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root)
    {
        if (root) {
            swap(root->left, root->right);
            mirrorTree(root->left);
            mirrorTree(root->right);
        }
        return root;
    }
};

// 双队列法
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root)
    {
        deque<TreeNode*> q1;
        deque<TreeNode*> q2;

        q1.push_back(root);
        while (!q1.empty()) {
            deque<TreeNode*> q2(move(q1));
            while (!q2.empty()) {
                if (q2.front()) {
                    swap(q2.front()->left, q2.front()->right);
                    q1.push_back(q2.front()->left);
                    q1.push_back(q2.front()->right);
                }
                q2.pop_front();
            }
        }

        return root;
    }
};

// 单队列
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root)
    {
        deque<TreeNode*> q;

        q.push_back(root);
        while (!q.empty()) {
            if (q.front()) {
                swap(q.front()->left, q.front()->right);
                q.push_back(q.front()->left);
                q.push_back(q.front()->right);
            }
            q.pop_front();
        }

        return root;
    }
};