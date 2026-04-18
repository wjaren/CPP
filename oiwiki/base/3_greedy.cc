#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

/**
 * 贪心的思路是：
 * 每一步都做“当前看起来最优”的选择。
 *
 * 但它不是万能的。
 * 真正使用贪心时，必须能说明：
 * “局部最优能推出全局最优”。
 */

/**
 * 例 1：排序型贪心
 * 有些题先排序，再按顺序处理，就能得到最优答案。
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

    // 这个比较规则来自交换相邻两个人后的收益比较。
    // 能推出更优顺序时，就按那个顺序排。
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
 * 例 2：反悔贪心
 * 先尽量选，发现选错了再撤销之前“最不划算”的那个。
 *
 * 任务调度、课程安排、利润最大化等题里很常见。
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

    std::ranges::sort(jobs, [](const auto &first, const auto &second) {
        return first.deadline < second.deadline;
    });

    // 小根堆里维护“当前已经选择的工作利润”。
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
    long long total_profit = 0;

    for (auto &[deadline, profit] : jobs) {
        if (deadline <= pq.size()) {
            // 时间不够了，只在“新工作更值钱”时替换掉堆顶。
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
