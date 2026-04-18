#include <iostream>

/**
 * 递归可以先理解成：
 * “函数在解决问题时，去调用更小规模的自己。”
 *
 * 写递归时一定要想清楚两件事：
 * 1. 什么时候停下来，也就是递归边界
 * 2. 当前问题和子问题之间是什么关系
 *
 * 分治则更强调：
 * 1. 先把问题拆小
 * 2. 分别解决
 * 3. 再把结果合并
 */

/**
 * 例子：路径总和 III
 * 给一棵二叉树，统计向下路径中，和等于目标值的路径条数。
 */
void solve_eg() {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x, TreeNode *left = nullptr, TreeNode *right = nullptr)
            : val(x), left(left), right(right) {}
    };

    TreeNode *root =
        new TreeNode(10,
                     new TreeNode(5,
                                  new TreeNode(3, new TreeNode(3), new TreeNode(-2)),
                                  new TreeNode(2, nullptr, new TreeNode(1))),
                     new TreeNode(-3, nullptr, new TreeNode(11)));
    int sum = 8;

    // count(node, target) 表示：以 node 为起点，路径和等于 target 的条数。
    auto count = [&](this auto &&count, TreeNode *node, int target) -> int {
        if (!node) {
            return 0;
        }
        int res = node->val == target ? 1 : 0;
        res += count(node->left, target - node->val);
        res += count(node->right, target - node->val);
        return res;
    };

    // dfs(node, sum) 表示：整棵以 node 为根的子树里，满足条件的总条数。
    auto dfs = [&](this auto &&dfs, TreeNode *node, int sum) -> int {
        if (!node) {
            return 0;
        }
        int res = count(node, sum);
        res += dfs(node->left, sum);
        res += dfs(node->right, sum);
        return res;
    };

    std::cout << dfs(root, sum) << std::endl;
}

int main() {
    solve_eg();

    return 0;
}
