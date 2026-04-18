#include <iostream>
#include <unordered_map>
#include <vector>

/**
 * 模拟题的核心不是“数学推导”，而是“按题目说的过程一步步做”。
 * 做这类题时最重要的是：
 * 1. 搞清楚状态有哪些
 * 2. 搞清楚事件发生顺序
 * 3. 小心边界和细节
 */

/**
 * 例子：蜗牛爬井
 * 白天往上爬 u，晚上往下滑 d，问最少几天爬出井口。
 */
void solve_eg() {
    int n = 10;
    int u = 3;
    int d = 2;

    int height = 0;
    int days = 0;

    while (height < n) {
        height += u;
        days++;
        if (height >= n) {
            break;
        }
        height -= d;
    }

    std::cout << "蜗牛至少需要 " << days << " 天才能爬出井口。" << std::endl;
}

/**
 * NOIP2014 生活大爆炸版石头剪刀布
 *
 * 这种题没有复杂公式，
 * 关键是先把“胜负关系”编码出来，再按周期模拟每一轮。
 */
void solve1() {
    std::vector<std::vector<int>> win = {
        {0, 0, 1, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 0, 1},
        {1, 1, 0, 0, 0}};

    int n = 10;
    int na = 5;
    int nb = 6;
    std::vector<int> a = {0, 1, 2, 3, 4};
    std::vector<int> b = {0, 3, 4, 2, 1, 0};

    int score_a = 0;
    int score_b = 0;

    for (int i = 0; i < n; ++i) {
        int move_a = a[i % na];
        int move_b = b[i % nb];

        if (win[move_a][move_b] == 1) {
            ++score_a;
        } else if (win[move_b][move_a] == 1) {
            ++score_b;
        }
    }

    std::cout << score_a << " " << score_b << std::endl;
}

/**
 * OpenJudge 3750 魔兽世界
 *
 * 这道题很长，也很典型。
 * 真正难点不是算法本身，而是：
 * 1. 事件非常多
 * 2. 规则很多
 * 3. 输出顺序要求很严格
 *
 * 下面保留的是一个“建模草稿”，方便理解如何拆状态。
 * 还没有完整实现，所以把它当作思路笔记更合适。
 */
void solve2() {
    // struct Warrior {
    //     std::string type; // 武士种类
    //     int id;           // 编号
    //     int hp;           // 生命值
    //     int attack;       // 攻击力
    //     int cur_location; // 当前所在位置
    // };

    // struct Headquarter {
    //     std::string color;                 // 总部颜色
    //     int elements;                      // 生命元数量
    //     std::vector<std::string> warriors; // 生产顺序
    // };

    // struct City {
    //     int id;                             // 城市编号
    //     int elements;                       // 城市里的生命元
    //     std::vector<Warrior> red_warriors;  // 红方武士
    //     std::vector<Warrior> blue_warriors; // 蓝方武士
    //     std::string flag;                   // 当前旗帜
    //     std::string last_winner;            // 上次战斗的胜者
    // };

    // 这类大模拟题通常建议先写：
    // 1. 数据结构
    // 2. 每个时间点发生的事件
    // 3. 输出函数
    // 4. 主循环
}

int main() {
    // solve_eg();
    // solve1();
    solve2();
    return 0;
}
