/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
var preOrderTraverse = function (root) {
    let order = '';
    const s = [];
    let p = root;
    while (p || s.length) {
        if (p) {
            order += p.val;
            s.push(p);
            p = p.left;
        } else {
            order += '*';
            p = s.pop();
            p = p.right;
        }
    }

    return order;
}

var isSameTree = function (p, q) {
    return preOrderTraverse(p) == preOrderTraverse(q);
};