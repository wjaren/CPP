#include <iostream>

/**
 * 递归是一种分治的思想
 * 递归的思想是将一个复杂的问题分解成一个或多个相似的子问题，直到子问题足够简单，可以直接解决．
 * 递归通常需要一个基准情况来终止递归调用，以避免无限循环．
 */

/**
 * 分治
 * 分治是一种算法设计范式，它将一个问题分解成多个子问题，分别解决这些子问题，然后将它们的结果合并起来得到原问题的解．
 * 分治算法通常包含三个步骤：分解、解决和合并．
 * 分解：将原问题分解成若干个规模较小的子问题，这些子问题通常是原问题的子集，或者是原问题的某个部分．
 * 解决：递归地解决这些子问题，直到子问题足够简单，能够直接解决．
 * 合并：将子问题的解合并起来，得到原问题的解．
 * 分治算法的效率通常较高，因为它利用了问题的结构和递归的性质，能够在较短的时间内解决复杂的问题．
 * 分治算法的经典例子包括归并排序、快速排序、二分搜索等．
 */

/**
 * 给定一个二叉树，它的每个结点都存放着一个整数值．
 * 找出路径和等于给定数值的路径总数．
 * 路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）．
 *
 * 二叉树不超过 1000 个节点，且节点数值范围是 [-1000000,1000000] 的整数．
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

    // 路径和等于给定数值的路径总数
    auto count = [&](this auto &&count, TreeNode *node, int target) -> int {
        if (!node) {
            return 0;
        }
        int res = node->val == target ? 1 : 0;
        res += count(node->left, target - node->val);
        res += count(node->right, target - node->val);
        return res;
    };

    // 遍历每个节点，计算以该节点为起点的路径和等于给定数值的路径总数
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