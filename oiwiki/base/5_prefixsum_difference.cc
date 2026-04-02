#include <iostream>
#include <vector>

/**
 * 前缀和
 * 前缀和是一个数组，其中每个元素是原数组中从第一个元素到当前元素的累积和。前缀和可以用来快速计算任意区间的和。
 * 给定一个数组 arr，前缀和数组 prefix_sum 定义如下：prefix_sum[i] = arr[0] + arr[1] + ... + arr[i]
 * 这样，任意区间 [l, r] 的和可以通过以下公式计算：sum(l, r) = prefix_sum[r] - prefix_sum[l - 1]
 */

class PrefixSum {
    std::vector<int> prefix_sum_1d;
    std::vector<std::vector<int>> prefix_sum_2d;

public:
    PrefixSum(const std::vector<int> &arr) {
        prefix_sum_1d.resize(arr.size() + 1);
        for (size_t i = 1; i <= arr.size(); ++i) {
            prefix_sum_1d[i] = prefix_sum_1d[i - 1] + arr[i - 1];
        }
    }

    PrefixSum(const std::vector<std::vector<int>> &matrix) {
        size_t m = matrix.size();
        size_t n = matrix[0].size();
        prefix_sum_2d.resize(m + 1, std::vector<int>(n + 1));
        for (size_t i = 1; i <= m; ++i) {
            for (size_t j = 1; j <= n; ++j) {
                prefix_sum_2d[i][j] = prefix_sum_2d[i - 1][j] + prefix_sum_2d[i][j - 1] - prefix_sum_2d[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sum(int l, int r) const {
        return prefix_sum_1d[r + 1] - prefix_sum_1d[l];
    }

    int sum(int x1, int y1, int x2, int y2) const {
        return prefix_sum_2d[x2 + 1][y2 + 1] - prefix_sum_2d[x1][y2 + 1] - prefix_sum_2d[x2 + 1][y1] + prefix_sum_2d[x1][y1];
    }

    static void test() {
        std::vector<int> arr = {1, 2, 3, 4, 5};
        PrefixSum prefix_sum_1d(arr);
        std::cout << prefix_sum_1d.sum(0, 2) << std::endl; // 输出 6 (1 + 2 + 3)
        std::cout << prefix_sum_1d.sum(1, 3) << std::endl; // 输出 9 (2 + 3 + 4)

        std::vector<std::vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};

        PrefixSum prefix_sum_2d(matrix);
        std::cout << prefix_sum_2d.sum(0, 0, 1, 1) << std::endl; // 输出 12 (1 + 2 + 4 + 5)
        std::cout << prefix_sum_2d.sum(1, 1, 2, 2) << std::endl; // 输出 28 (5 + 6 + 8 + 9)
    }
};

/**
 * 洛谷 P1387 最大正方形
 * 在一个 n×m 的只包含 0 和 1 的矩阵里找出一个不包含 0 的最大正方形，输出边长。
 * 保证矩阵里有至少一个 1。
 *
 * 输入格式
 * 输入文件第一行为两个整数 n,m(1≤n,m≤100)，接下来 n 行，每行 m 个数字，用空格隔开，0 或 1。
 * 输出格式
 * 一个整数，最大正方形的边长。
 */
void solve_eg() {
    int n = 4, m = 4;
    std::vector<std::vector<int>> matrix = {
        {0, 1, 1, 1},
        {1, 1, 1, 0},
        {0, 1, 1, 0},
        {1, 1, 0, 1}};

    PrefixSum prefix_sum(matrix);
    int max_side = 0;
    for (int l = 0; l < std::min(n, m); ++l) {
        for (int i = 0; i + l < n; ++i) {
            for (int j = 0; j + l < m; ++j) {
                if (prefix_sum.sum(i, j, i + l, j + l) == (l + 1) * (l + 1)) {
                    max_side = std::max(max_side, l + 1);
                }
            }
        }
    }
    std::cout << max_side << std::endl;
}

int main() {
    // PrefixSum::test();
    solve_eg();

    return 0;
}