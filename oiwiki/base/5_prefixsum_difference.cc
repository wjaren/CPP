#include <iostream>
#include <vector>

/**
 * 前缀和适合解决“很多次区间求和”。
 * 核心思想：
 * 先花一次 O(n) 预处理，
 * 以后每次查询都能 O(1) 得到答案。
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
                prefix_sum_2d[i][j] = prefix_sum_2d[i - 1][j] + prefix_sum_2d[i][j - 1] -
                                      prefix_sum_2d[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sum(int l, int r) const {
        return prefix_sum_1d[r + 1] - prefix_sum_1d[l];
    }

    int sum(int x1, int y1, int x2, int y2) const {
        return prefix_sum_2d[x2 + 1][y2 + 1] - prefix_sum_2d[x1][y2 + 1] -
               prefix_sum_2d[x2 + 1][y1] + prefix_sum_2d[x1][y1];
    }

    static void test() {
        std::vector<int> arr = {1, 2, 3, 4, 5};
        PrefixSum prefix_sum_1d(arr);
        std::cout << prefix_sum_1d.sum(0, 2) << std::endl; // 1 + 2 + 3 = 6
        std::cout << prefix_sum_1d.sum(1, 3) << std::endl; // 2 + 3 + 4 = 9

        std::vector<std::vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};

        PrefixSum prefix_sum_2d(matrix);
        std::cout << prefix_sum_2d.sum(0, 0, 1, 1) << std::endl;
        std::cout << prefix_sum_2d.sum(1, 1, 2, 2) << std::endl;
    }
};

/**
 * 例题：最大正方形
 * 枚举每个正方形，再用二维前缀和 O(1) 判断这块区域是不是全 1。
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

/**
 * 差分和前缀和正好相反：
 * 前缀和擅长“快速查询”；
 * 差分擅长“快速区间修改”。
 */
class Difference {
    std::vector<int> diff_1d;
    std::vector<std::vector<int>> diff_2d;

public:
    Difference(const std::vector<int> &arr) {
        diff_1d.resize(arr.size());
        diff_1d[0] = arr[0];
        for (size_t i = 1; i < arr.size(); ++i) {
            diff_1d[i] = arr[i] - arr[i - 1];
        }
    }

    Difference(const std::vector<std::vector<int>> &matrix) {
        size_t m = matrix.size();
        size_t n = matrix[0].size();
        diff_2d.resize(m, std::vector<int>(n));
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                diff_2d[i][j] = matrix[i][j];
                if (i > 0) {
                    diff_2d[i][j] -= matrix[i - 1][j];
                }
                if (j > 0) {
                    diff_2d[i][j] -= matrix[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    diff_2d[i][j] += matrix[i - 1][j - 1];
                }
            }
        }
    }

    void modify(int l, int r, int val) {
        diff_1d[l] += val;
        if (r + 1 < diff_1d.size()) {
            diff_1d[r + 1] -= val;
        }
    }

    void modify(int x1, int y1, int x2, int y2, int val) {
        diff_2d[x1][y1] += val;
        if (y2 + 1 < diff_2d[0].size()) {
            diff_2d[x1][y2 + 1] -= val;
        }
        if (x2 + 1 < diff_2d.size()) {
            diff_2d[x2 + 1][y1] -= val;
        }
        if (x2 + 1 < diff_2d.size() && y2 + 1 < diff_2d[0].size()) {
            diff_2d[x2 + 1][y2 + 1] += val;
        }

        /**
         * 二维差分记忆方法：
         * 左上角加，右边减，下边减，右下角补回来。
         *
         * 三维、四维其实也是同一个思路，
         * 只是“加减位置”的组合会更多。
         */
    }
};

int main() {
    // PrefixSum::test();
    solve_eg();

    return 0;
}
