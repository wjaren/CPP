#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

/**
 * 贪心算法（英语：greedy algorithm），是用计算机来模拟一个「贪心」的人做出决策的过程．这个人十分贪婪，每一步行动总是按某种指标选取最优的操作．
 * 而且他目光短浅，总是只看眼前，并不考虑以后可能造成的影响．
 * 可想而知，并不是所有的时候贪心法都能获得最优解，所以一般使用贪心法的时候，都要确保自己能证明其正确性．
 *
 * 排序解法
 * 用排序法常见的情况是输入一个包含几个（一般一到两个）权值的数组，通过排序然后遍历模拟计算的方法求出最优值．
 * 后悔解法
 * 思路是无论当前的选项是否最优都接受，然后进行比较，如果选择之后不是最优了，则反悔，舍弃掉这个选项；否则，正式接受．如此往复．
 * 与动态规划的区别
 * 贪心算法与动态规划的不同在于它对每个子问题的解决方案都做出选择，不能回退．动态规划则会保存以前的运算结果，并根据以前的结果对当前进行选择，有回退功能．
 */

/**
 * 排序解法
 * 恰逢 H 国国庆，国王邀请 n 位大臣来玩一个有奖游戏．
 * 首先，他让每个大臣在左、右手上面分别写下一个整数，国王自己也在左、右手上各写一个整数．
 * 然后，让这 n 位大臣排成一排，国王站在队伍的最前面．
 * 排好队后，所有的大臣都会获得国王奖赏的若干金币，每位大臣获得的金币数分别是：排在该大臣前面的所有人的左手上的数的乘积除以他自己右手上的数，然后向下取整得到的结果．
 * 国王不希望某一个大臣获得特别多的奖赏，所以他想请你帮他重新安排一下队伍的顺序，使得获得奖赏最多的大臣，所获奖赏尽可能的少．
 * 注意，国王的位置始终在队伍的最前面．
 */
void solve_eg1() {
    std::vector<std::pair<int, int>> v;
    for (int i = 0; i < 5; ++i) {
        v.emplace_back(rand() % 9 + 1, rand() % 9 + 1);
    }
    std::cout << "before sort:\n|\t";
    for (const auto &[a, b] : v) {
        std::cout << a << " " << b << "\t|\t";
    }

    // 设第 i 位大臣左手上的数为 a_i，右手上的数为 b_i，s 是排在第 i 位大臣前面所有人的左手上的数的乘积
    // 那么第 i 位大臣获得的金币数为 s / b_i, 第 i + 1 位大臣获得的金币数为 s * a_i / b_{i + 1}
    // 交换后 第 i 位大臣获得的金币数为 s / b_{i + 1}, 第 i + 1 位大臣获得的金币数为 s * a_{i + 1} / b_i
    // 要保证 max(s / b_i, s * a_i / b_{i + 1}) < max(s / b_{i + 1}, s * a_{i + 1} / b_i)
    // 即有 max(b_{i + 1}, a_i * b_i) < max(b_i, a_{i + 1} * b_{i + 1})
    std::ranges::sort(v, [](const auto &first, const auto &second) {
        const auto &[a1, b1] = first;
        const auto &[a2, b2] = second;
        return std::max(b2, a1 * b1) < std::max(b1, a2 * b2);
    });

    std::cout << "\nafter sort:\n|\t";
    for (const auto &[a, b] : v) {
        std::cout << a << " " << b << "\t|\t";
    }
}

/**
 * 后悔解法
 * 约翰的工作日从 0 时刻开始，有 10^9 个单位时间．
 * 在任一单位时间，他都可以选择编号 1 到 𝑁 的 N(1 <= N <= 10^5) 项工作中的任意一项工作来完成．
 * 工作 𝑖 的截止时间是 D_i(1 <= D_i <= 10^9)，完成后获利是P_i( 1<= P_i<= 10^9 )．
 * 在给定的工作利润和截止时间下，求约翰能够获得的利润最大为多少．
 */
void solve_eg2() {

    const int MAX = 20;
    const int N = 10;

    struct Job {
        int deadline;
        int profit;

        bool operator<(const Job &other) const {
            return profit < other.profit;
        }
    };

    std::vector<Job> jobs;
    for (int i = 0; i < N; ++i) {
        jobs.emplace_back(rand() % MAX + 1, rand() % MAX + 1);
    }

    // 按照截止时间排序
    std::ranges::sort(jobs, [](const auto &first, const auto &second) {
        return first.deadline < second.deadline;
    });

    // 维护一个优先队列，存储当前选择的工作利润
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
    long long total_profit = 0;
    for (auto &[deadline, profit] : jobs) {
        if (deadline <= pq.size()) {
            if (pq.top() < profit) {
                total_profit += profit - pq.top();
                pq.pop();
                pq.push(profit);
            }
        } else {
            pq.push(profit);
            total_profit += profit;
        }
    }
    std::cout << "total profit: " << total_profit << "\n";
}

int main() {
    // solve_eg1();
    solve_eg2();
    return 0;
}
