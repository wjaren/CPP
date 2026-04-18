#include <algorithm>
#include <iostream>
#include <random>
#include <unordered_set>
#include <vector>

/**
 * 枚举可以理解成：
 * “把所有可能情况一个个试过去，再判断哪一种满足条件。”
 *
 * 它通常不是最优算法，但非常适合作为：
 * 1. 题目的第一版思路
 * 2. 更优算法的对照组
 * 3. 数据范围较小时的直接解法
 */

/**
 * 例子：
 * 给定一个数组，元素互不相同且都不为 0，
 * 统计其中和为 0 的有序数对个数。
 */

std::vector<int> arr;
int n;

void init() {
    n = rand() % 1000 + 1;
    for (int i = 0; i < n; i++) {
        arr.push_back(rand() % 101 - 50);
    }

    std::ranges::sort(arr);
    arr.erase(std::unique(arr.begin(), arr.end()), arr.end());
    n = arr.size();
    std::shuffle(arr.begin(), arr.end(), std::mt19937(std::random_device()()));

    std::cout << "Array size: " << n << "\nArray is: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// 最朴素的双重循环：把所有数对都检查一遍。
void solve_eg1() {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i] + arr[j] == 0) {
                ans++;
            }
        }
    }
    std::cout << ans << std::endl;
}

// 利用对称性少枚举一半，再按需要修正答案。
void solve_eg2() {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] + arr[j] == 0) {
                ans++;
            }
        }
    }
    ans *= 2;
    std::cout << ans << std::endl;
}

// 用哈希表把“找相反数”这件事优化掉。
void solve_eg3() {
    int ans = 0;
    std::unordered_set<int> s(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i) {
        if (s.count(-arr[i])) {
            ans++;
        }
    }
    std::cout << ans << std::endl;
}

/**
 * OpenJudge 2811: 熄灯问题
 *
 * 题意可以抓住一句话：
 * 每次按下一个开关，会翻转自己和上下左右的灯。
 *
 * 这题常见做法是：
 * 1. 枚举第一行怎么按
 * 2. 第一行一旦确定，后面每一行的操作也就被唯一确定
 * 3. 最后检查最后一行能不能全灭
 */
void solve() {
    std::vector<std::vector<int>> grid =
        {{0, 1, 1, 0, 1, 0},
         {1, 0, 0, 1, 1, 1},
         {0, 0, 1, 0, 0, 1},
         {1, 0, 0, 1, 0, 1},
         {0, 1, 1, 1, 0, 0}};

    std::vector ans(5, std::vector<int>(6, 0));

    auto down = [&](int x, int y) {
        grid[x][y] ^= 1;
        int d[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < 4; ++i) {
            int nx = x + d[i], ny = y + d[i + 1];
            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 6) {
                grid[nx][ny] ^= 1;
            }
        }
    };

    for (int mask = 0; mask < (1 << 6); ++mask) {
        std::vector<std::vector<int>> temp = grid;

        for (int i = 0; i < 6; ++i) {
            if (mask & (1 << i)) {
                down(0, i);
                ans[0][i] = 1;
            }
        }

        // 如果上一行某个灯还亮着，就必须按下一行对应位置去消掉它。
        for (int i = 1; i < 5; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (grid[i - 1][j] == 1) {
                    down(i, j);
                    ans[i][j] = 1;
                }
            }
        }

        bool valid = true;
        for (int j = 0; j < 6; ++j) {
            if (grid[4][j] == 1) {
                valid = false;
                break;
            }
        }

        if (valid) {
            for (const auto &row : ans) {
                for (int x : row) {
                    std::cout << x << " ";
                }
                std::cout << std::endl;
            }
            return;
        } else {
            grid = temp;
            std::fill(ans.begin(), ans.end(), std::vector<int>(6, 0));
        }
    }
}

int main() {
    // init();
    // solve_eg1();
    // solve_eg2();
    // solve_eg3();

    solve();

    return 0;
}
