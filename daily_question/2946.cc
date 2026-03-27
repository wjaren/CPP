/**
 * 2946. 循环移位后的矩阵相似检查
 *
 * 给你一个下标从 0 开始且大小为 m x n 的整数矩阵 mat 和一个整数 k 。矩阵行的下标是从 0 开始的。
 * 进行下面操作 k 次：
 * 偶数行（0, 2, 4, ...）循环向左移动。
 * 奇数行（1, 3, 5, ...）循环向右移动。
 * 如果经过 k 步后的最终修改矩阵与原始矩阵相同，则返回 true，否则返回 false。
 *
 */
#include <algorithm>
#include <vector>

using namespace std;

/**
 *
 * 循环移位，反转原理（左移）
 * 1. 将数组分成两部分：前 k 个元素和剩余的元素。
 * 2. 反转前 k 个元素。
 * 3. 反转剩余的元素。
 * 4. 反转整个数组。
 *
 */

class Solution {
public:
    bool areSimilar(vector<vector<int>> &mat, int k) {
        // auto re_row = [&](vector<int> v, int k) -> vector<int> {
        //     int n = v.size();
        //     k = (k % n + n) % n;
        //     reverse(v.begin(), v.begin() + k);
        //     reverse(v.begin() + k, v.end());
        //     reverse(v.begin(), v.end());
        //     return v;
        // };
        // for (auto& row : mat) {
        //     if (row != re_row(row, k)) {
        //         return false;
        //     }
        //     k = -k;
        // }
        // return true;
        int n = mat[0].size();
        for (auto &row : mat) {
            for (int j = 0; j < n; ++j) {
                if (row[j] != row[(j + k) % n]) {
                    return false;
                }
            }
        }
        return true;
    }
};