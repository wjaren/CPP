#include <algorithm>
#include <iostream>
#include <random>
#include <unordered_set>
#include <vector>

/**
 * 枚举是一种暴力搜索的思想
 * 枚举的思想是不断地猜测，从可能的集合中一一尝试，然后再判断题目的条件是否成立．
 */

/**
 * 给定一个数组，其所有元素互不相同且均不为 0．求该数组中和为 0 的数对个数．
 */

std::vector<int> arr;
int n;

void init() {
    n = rand() % 1000 + 1; // 数组大小
    for (int i = 0; i < n; i++) {
        arr.push_back(rand() % 101 - 50); // 数组元素范围 [-50, 50]
    }
    std::ranges::sort(arr);
    arr.erase(std::unique(arr.begin(), arr.end()), arr.end());
    n = arr.size();
    std::shuffle(arr.begin(), arr.end(), std::mt19937(std::random_device()()));

    // 输出数组
    std::cout << "Array size: " << n << "\nArray is: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// 枚举所有的数对，判断是否满足条件
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

// 优化范围
void solve_eg2() {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] + arr[j] == 0) {
                ans++;
            }
        }
    }
    ans *= 2; // 因为每对数对会被计算两次，所以乘以 2
    std::cout << ans << std::endl;
}

// hash 表优化
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
 * 2811: 熄灯问题 - OpenJudge
 * 有一个由按钮组成的矩阵，其中每行有6个按钮，共5行。每个按钮的位置上有一盏灯。
 * 当按下一个按钮后，该按钮以及周围位置(上边、下边、左边、右边)的灯都会改变一次。
 * 即，如果灯原来是点亮的，就会被熄灭；如果灯原来是熄灭的，则会被点亮。
 * 在矩阵角上的按钮改变3盏灯的状态；在矩阵边上的按钮改变4盏灯的状态；其他的按钮改变5盏灯的状态。
 *
 *
 * 输入:
 * 5行组成，每一行包括6个数字（0或1）。相邻两个数字之间用单个空格隔开。0表示灯的初始状态是熄灭的，1表示灯的初始状态是点亮的。
 * 输出:
 * 5行组成，每一行包括6个数字（0或1）。相邻两个数字之间用单个空格隔开。其中的1表示需要把对应的按钮按下，0则表示不需要按对应的按钮。
 */
void solve() {
    std::vector<std::vector<int>> grid =
        {{0, 1, 1, 0, 1, 0},
         {1, 0, 0, 1, 1, 1},
         {0, 0, 1, 0, 0, 1},
         {1, 0, 0, 1, 0, 1},
         {0, 1, 1, 1, 0, 0}};

    std::vector ans(5, std::vector<int>(6, 0)); // 存储按键组合的结果

    auto down = [&](int x, int y) {
        grid[x][y] ^= 1;            // 按下按钮，改变当前灯的状态
        int d[] = {0, 1, 0, -1, 0}; // 定义方向数组，表示上下左右四个方向
        for (int i = 0; i < 4; ++i) {
            int nx = x + d[i], ny = y + d[i + 1];         // 计算相邻位置的坐标
            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 6) { // 判断相邻位置是否在矩阵范围内
                grid[nx][ny] ^= 1;                        // 改变相邻位置灯的状态
            }
        }
    };

    // 枚举所有可能的按键组合
    for (int mask = 0; mask < (1 << 6); ++mask) {  // 2^6 种组合
        std::vector<std::vector<int>> temp = grid; // 复制初始状态
        for (int i = 0; i < 6; ++i) {
            if (mask & (1 << i)) { // 如果第 i 个按钮被按下
                down(0, i);        // 按下第一行的按钮
                ans[0][i] = 1;     // 记录按下的按钮
            }
        }
        for (int i = 1; i < 5; ++i) { // 从第二行开始，根据上一行的状态决定是否按下按钮
            for (int j = 0; j < 6; ++j) {
                if (grid[i - 1][j] == 1) { // 如果上一行的灯是点亮的
                    down(i, j);            // 按下当前行的按钮
                    ans[i][j] = 1;         // 记录按下的按钮
                }
            }
        }
        bool valid = true;
        for (int j = 0; j < 6; ++j) { // 检查最后一行是否全部熄灭
            if (grid[4][j] == 1) {
                valid = false;
                break;
            }
        }

        if (valid) { // 如果找到一个有效的按键组合
            for (const auto &row : ans) {
                for (int x : row) {
                    std::cout << x << " ";
                }
                std::cout << std::endl;
            }
            return; // 输出结果后退出
        } else {
            grid = temp;                                               // 恢复初始状态，继续枚举下一种组合
            std::fill(ans.begin(), ans.end(), std::vector<int>(6, 0)); // 重置按键组合结果
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