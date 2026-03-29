#include <iostream>
#include <unordered_map>
#include <vector>

/**
 * 模拟是一种暴力搜索的思想
 * 模拟的思想是按照题目的描述，逐步模拟题目的过程，直到得到最终的结果．
 */

/**
 * 一只长度不计的蠕虫位于 𝑛 英寸深的井的底部．它每次向上爬 𝑢* 英寸，但是必须休息一次才能再次向上爬．
 * 在休息的时候，它滑落了 𝑑 英寸．之后它将重复向上爬和休息的过程．
 * 蠕虫爬出井口需要至少爬多少次？如果蠕虫爬完后刚好到达井的顶部，我们也设作蠕虫已经爬出井口．
 */
void solve_eg() {
    int n = 10; // 井的深度
    int u = 3;  // 每次向上爬的距离
    int d = 2;  // 每次休息时滑落的距离

    int height = 0; // 当前高度
    int days = 0;   // 爬行的天数

    while (height < n) {
        height += u;       // 向上爬
        days++;            // 增加一天
        if (height >= n) { // 如果已经爬出井口，结束循环
            break;
        }
        height -= d; // 滑落
    }

    std::cout << "蠕虫需要至少 " << days << " 天才能爬出井口。" << std::endl;
}

/**
 * 「NOIP2014」生活大爆炸版石头剪刀布 - Universal Online Judge
 * 石头剪刀布是常见的猜拳游戏:石头胜剪刀,剪刀胜布,布胜石头。如果两个人出拳一 样，则不分胜负。在《生活大爆炸》第二季第 8 集中出现了一种石头剪刀布的升级版游戏。
 *
 * 升级版游戏在传统的石头剪刀布游戏的基础上,增加了两个新手势:
 *
 * 斯波克:《星际迷航》主角之一。
 *
 * 蜥蜴人:《星际迷航》中的反面角色。
 *
 * 这五种手势的胜负关系如表一所示,表中列出的是甲对乙的游戏结果。
 *
 * 甲\乙	剪刀	石头	布	    蜥蜴人	斯波克
 * 剪刀	    平	    输	    赢	    赢	    输
 * 石头	    ×	    平	    输	    赢	    输
 * 布	    ×	    ×	    平	    输	    赢
 * 蜥蜴人	×	    ×	    ×	    平	    赢
 * 斯波克	×	    ×	    ×	    ×	    平
 *
 * 现在,小 A 和小 B 尝试玩这种升级版的猜拳游戏。已知他们的出拳都是有周期性规律的，但周期长度不一定相等。
 * 例如：如果小 A 以“石头-布-石头-剪刀-蜥蜴人-斯波克”长度为 6 的周期出拳,那么他的出拳序列就是“石头-布-石头-剪刀-蜥蜴人-斯波克-石头-布-石头-剪刀-蜥蜴人-斯波克-......”,
 * 而如果小 B 以“剪刀-石头-布-斯波克-蜥蜴人”长度为 5 的周期出拳,那么他出拳的序列就是“剪刀-石头-布-斯波克-蜥蜴人-剪刀-石头-布-斯波克-蜥蜴人-......”
 *
 * 已知小 A 和小 B 一共进行 N 次猜拳。每一次赢的人得 1 分，输的得 0 分；平局两人都得 0 分。现请你统计 N 次猜拳结束之后两人的得分。
 * 输入格式
 * 第一行包含三个整数：$N,N_A,N_B$,分别表示共进行 $N$ 次猜拳、小 A 出拳的周期长度，小 B 出拳的周期长度。数与数之间以一个空格分隔。
 * 第二行包含
 * $N_A$ 个整数,表示小 A 出拳的规律,第三行包含
 * $N_B$ 个整数,表示小 B 出拳的规律。其中，0 表示“剪刀”，1 表示“石头”，2 表示“布”，3 表示“蜥蜴人”，4 表示“斯波克”。数与数之间以一个空格分隔。
 *
 * 输出格式
 * 输出一行，包含两个整数，以一个空格分隔，分别表示小 A、小 B 的得分。
 */
void solve1() {
    std::vector<std::vector<int>> win = {
        {0, 0, 1, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 0, 1},
        {1, 1, 0, 0, 0}};

    int n = 10;                              // 猜拳的次数
    int na = 5;                              // 小 A 出拳的周期长度
    int nb = 6;                              // 小 B 出拳的周期长度
    std::vector<int> a = {0, 1, 2, 3, 4};    // 小 A 出拳的规律
    std::vector<int> b = {0, 3, 4, 2, 1, 0}; // 小 B 出拳的规律

    // n = 9;
    // na = 5;
    // nb = 5;
    // a = {0, 1, 2, 3, 4};
    // b = {1, 0, 3, 2, 4};

    int score_a = 0; // 小 A 的得分
    int score_b = 0; // 小 B 的得分

    for (int i = 0; i < n; ++i) {
        int move_a = a[i % na]; // 小 A 的出拳
        int move_b = b[i % nb]; // 小 B 的出拳

        if (win[move_a][move_b] == 1) {
            ++score_a; // 小 A 赢
        } else if (win[move_b][move_a] == 1) {
            ++score_b; // 小 B 赢
        }
    }

    std::cout << score_a << " " << score_b << std::endl;
}

/**
 * 「OpenJudge 3750」魔兽世界
 * 魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市，城市从西向东依次编号为1,2,3 .... N ( N <= 20)。
 *
 * 红司令部 City1 City2 City3 ... CityN 蓝司令部
 *
 * 两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。
 *
 * 双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是 n。
 *
 * 武士在刚降生的时候有一个初始的生命值，生命值在战斗中会发生变化，如果生命值减少到0或少于0，则武士死亡（消失）。
 *
 * 在每个整点，即每个小时的第0分， 双方的司令部中各有一个武士降生。
 *
 * 红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序制造武士。
 *
 * 蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序制造武士。
 *
 * 制造武士需要生命元。
 *
 * 制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。
 *
 * 如果司令部中的生命元不足以制造某武士，那么司令部就等待，直到获得足够生命元后的第一个整点，才制造该武士。例如，在2:00，红方司令部本该制造一个 wolf ，如果此时生命元不足，那么就会等待，直到生命元足够后的下一个整点，才制造一个 wolf。
 *
 * 在每个小时的第10分：所有的武士朝敌人司令部方向前进一步。即从己方司令部走到相邻城市，或从一个城市走到下一个城市。或从和敌军司令部相邻的城市到达敌军司令部。
 *
 * 在每个小时的第20分：每个城市产出10个生命元。生命元留在城市，直到被武士取走。
 *
 * 在每个小时的第30分：如果某个城市中只有一个武士，那么该武士取走该城市中的所有生命元，并立即将这些生命元传送到其所属的司令部。
 *
 * 在每个小时的第40分：在有两个武士的城市，会发生战斗。
 * 在每个小时的第50分，司令部报告它拥有的生命元数量。
 *
 * 每次战斗有且只有一方武士主动进攻。被攻击者生命值会减去进攻者的攻击力值。如果被攻击者生命值减至小于等于0，则其被杀死。
 *
 * 如果被攻击者没有被杀死，则会发动反击，被反击者的生命值要减去反击者攻击力值的一半(去尾取整)。反击当然可能致敌人于死地。
 *
 * 如果武士在战斗中杀死敌人（不论是主动进攻杀死还是反击杀死），则其司令部会立即向其发送8个生命元作为奖励，使其生命值增加8。当然前提是司令部得有8个生命元。如果司令部的生命元不足以奖励所有的武士，则优先奖励距离敌方司令部近的武士。
 *
 * 如果某武士在某城市的战斗中杀死了敌人，则该武士的司令部立即取得该城市中所有的生命元。注意，司令部总是先奖励武士，然后再收回打了胜仗的城市的生命元。对于因司令部生命元不足而领不到奖励的武士，司令部也不会在取得战利品生命元后为其补发奖励。
 *
 * 每次战斗都只有一方主动进攻一次。战斗并非是你死我活的，可能是双方都幸存。如果双方都幸存，则双方都不能拿走发生战斗的城市的生命元
 *
 *
 * 在插红旗的城市，以及编号为奇数的无旗城市，由红武士主动发起进攻。
 *
 * 在插蓝旗的城市，以及编号为偶数的无旗城市，由蓝武士主动发起进攻。
 *
 * 一开始所有的城市都是无旗的。当某个城市有连续两场战斗都是同一方的武士杀死敌人(两场战斗中间如果有若干个战斗时刻并没有发生战斗，则这两场战斗仍然算是连续的) ，那么该城市就会插上胜方的旗帜
 * 若原来插着败方的旗帜，则败方旗帜落下。旗帜一旦插上，就一直插着，直到被敌人更换。一个城市最多只能插一面旗帜，旗帜没被敌人更换前，也不会再次插同颜色的旗。
 *
 * 不同的武士各有其特点：
 *
 * dragon 在一次在它主动进攻的战斗结束后，如果还没有战死，就会欢呼。
 *
 * ninja 挨打了也从不反击敌人。
 *
 * iceman 每前进两步，在第2步完成的时候，生命值会减少9，攻击力会增加20。但是若生命值减9后会小于等于0，则生命值不减9,而是变为1。即iceman不会因走多了而死。
 *
 * lion 若是战死，则其战斗前的生命值就会转移到对手身上。
 *
 * 在一个 wolf 通过主动攻击杀死敌人的次数达到偶数的时刻（次数从1开始算），在战斗完成后，该 wolf 生命值和攻击力都增加1倍。如果其杀死的敌人是lion,则攻击力和生命值先加倍，然后才吸取lion的生命值。
 * 获取总部的生命元奖励，发生在加倍之后。只有在主动攻击杀死敌人时才能有加倍的事情，反击杀死敌人则不不会发生加倍。
 *
 * 武士到达对方司令部后就算完成任务了，从此就呆在那里无所事事。
 *
 * 任何一方的司令部里若是出现了2个敌人，则认为该司令部已被敌人占领。
 * 任何一方的司令部被敌人占领，则战争结束。战争结束之后就不会发生任何事情了。
 *
 *
 * 给定一个时间，要求你将从0点0分开始到此时间为止的所有事件按顺序输出。事件及其对应的输出样例如下：
 *
 *
 * 1) 武士降生
 *
 * 输出样例： 000:00 blue lion 1 born
 * 表示在 0点0分，编号为1的蓝魔lion武士降生
 *
 * 2) 武士前进到某一城市
 *
 * 输出样例： 000:10 red iceman 1 marched to city 1 with 20 elements and force 30
 * 表示在 0点10分，红魔1号武士iceman前进到1号城市，此时他生命值为20,攻击力为30
 * 对于iceman,输出的生命值和攻击力应该是变化后的数值
 *
 * 3) 武士主动进攻
 * 输出样例：000:40 red iceman 1 attacked blue lion 1 in city 1 with 20 elements and force 30
 * 表示在0点40分，1号城市中，红魔1号武士iceman 进攻蓝魔1号武士lion,在发起进攻前，红魔1号武士iceman生命值为20，攻击力为 30
 *
 *
 * 4) 武士反击
 * 输出样例：001:40 blue dragon 2 fought back against red lion 2 in city 1
 * 表示在1点40分，1号城市中，蓝魔2号武士dragon反击红魔2号武士lion
 *
 * 5) 武士战死
 * 输出样例：001:40 red lion 2 was killed in city 1
 *
 * 6) 武士欢呼
 * 输出样例：003:40 blue dragon 2 yelled in city 4
 *
 * 7) 武士获取生命元( elements )
 * 输出样例：001:40 blue dragon 2 earned 10 elements for his headquarter
 *
 * 8) 旗帜升起
 * 输出样例：004:40 blue flag raised in city 4
 *
 * 9) 武士抵达敌军司令部
 * 输出样例：001:10 red iceman 1 reached blue headquarter with 20 elements and force 30
 * （此时他生命值为20,攻击力为30）对于iceman,输出的生命值和攻击力应该是变化后的数值
 *
 *
 * 10) 司令部被占领
 * 输出样例：003:10 blue headquarter was taken
 *
 * 11)司令部报告生命元数量
 * 000:50 100 elements in red headquarter
 * 000:50 120 elements in blue headquarter
 * 表示在0点50分，红方司令部有100个生命元，蓝方有120个
 *
 *
 * 输出事件时：
 *
 * 首先按时间顺序输出；
 *
 * 同一时间发生的事件，按发生地点从西向东依次输出. 武士前进的事件, 算是发生在目的地。
 *
 *
 * 在一次战斗中有可能发生上面的 3 至 8 号事件。这些事件都算同时发生，其时间就是战斗开始时间。一次战斗中的这些事件，序号小的应该先输出。
 *
 * 两个武士同时抵达同一城市，则先输出红武士的前进事件，后输出蓝武士的。
 *
 * 显然，10号事件发生之前的一瞬间一定发生了9号事件。输出时，这两件事算同一时间发生，但是应先输出9号事件
 * 虽然任何一方的司令部被占领之后，就不会有任何事情发生了。但和司令部被占领同时发生的事件，全都要输出。
 *
 * 输入
 * 第一行是一个整数,代表测试数据组数
 * 每组测试数据共三行。
 *
 * 第一行，三个整数 M,N,T。其含义为：
 *
 * 每个司令部一开始都有M个生命元( 1 <= M <= 1000)
 * 两个司令部之间一共有N个城市( 1 <= N <= 20 )
 * 要求输出从0时0分开始，到时间T为止(包括T) 的所有事件。T以分钟为单位，0 <= T <= 1000
 *
 * 第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于100
 *
 * 第三行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的攻击力。它们都大于0小于等于100
 *
 * 输出
 * 对每组测试数据，首先输出“Case:n" n是测试数据的编号，从1开始
 * 接下来按恰当的顺序和格式输出到时间T为止发生的所有事件。每个事件都以事件发生的时间开头，时间格式是“时: 分”，“时”有三位，“分”有两位。
 *
 */
void solve2() {
    // struct Warrior {
    //     std::string type; // 武士类型
    //     int id;           // 武士编号
    //     int hp;           // 生命值
    //     int attack;       // 攻击力
    //     int cur_location; // 当前所在城市编号
    // };

    // struct Headquarter {
    //     std::string color;                 // 司令部颜色
    //     int elements;                      // 生命元数量
    //     std::vector<std::string> warriors; // 武士列表
    // };

    // struct City {
    //     int id;                             // 城市编号
    //     int elements;                       // 生命元数量
    //     std::vector<Warrior> red_warriors;  // 红方武士列表
    //     std::vector<Warrior> blue_warriors; // 蓝方武士列表
    //     std::string flag;                   // 旗帜颜色，"red"、"blue"或"none"
    //     std::string last_winner;            // 上一次战斗的胜方，"red"、"blue"或"none"
    // };

    // struct Game {
    //     int time;                                                         // 当前时间
    //     Headquarter *red;                                                 // 红方司令部
    //     Headquarter *blue;                                                // 蓝方司令部
    //     std::vector<City> cities;                                         // 城市列表
    //     std::unordered_map<Headquarter *, std::vector<Warrior>> warriors; // 司令部与武士的映射
    //     int make_warrior_idx;                                             // 记录下一个要制造的武士类型索引
    //     int red_warrior_id;                                               // 红方武士编号
    //     int blue_warrior_id;                                              // 蓝方武士编号

    //     int M; // 初始生命元
    //     int N; // 城市数量
    //     int T; // 模拟时间

    //     std::unordered_map<std::string, int> hp;
    //     std::unordered_map<std::string, int> attack;

    //     Game() {
    //         M = 99;   // 初始生命元
    //         N = 2;    // 城市数量
    //         T = 1000; // 模拟时间

    //         time = 0;
    //         make_warrior_idx = 0; // 从第一个武士类型开始制造
    //         red_warrior_id = 1;   // 红方武士编号从1开始
    //         blue_warrior_id = 1;  // 蓝方武士编号从1开始

    //         hp = {{"dragon", 10}, {"ninja", 20}, {"iceman", 50}, {"lion", 50}, {"wolf", 30}};     // dragon、ninja、iceman、lion、wolf 的初始生命值
    //         attack = {{"dragon", 20}, {"ninja", 50}, {"iceman", 50}, {"lion", 50}, {"wolf", 50}}; // dragon、ninja、iceman、lion、wolf 的攻击力

    //         // 初始化司令部和城市
    //         red = new Headquarter{"red", M, {"iceman", "lion", "wolf", "ninja", "dragon"}};
    //         blue = new Headquarter{"blue", M, {"lion", "dragon", "ninja", "iceman", "wolf"}};

    //         cities.resize(N + 1); // 城市编号从1到N
    //         for (int i = 1; i <= N; ++i) {
    //             cities[i] = {i, 0, {}, {}, "none", "none"};
    //         }
    //     }

    //     void update() {
    //         // 更新游戏状态，包括武士的移动、战斗、生命元的变化等
    //         if (time % 60 == 0) {
    //             // 每小时的第0分，制造武士
    //             if (red->elements >= hp[red->warriors[make_warrior_idx % 5]]) {
    //                 red->elements -= hp[red->warriors[make_warrior_idx % 5]];
    //                 warriors[red].push_back({red->warriors[make_warrior_idx % 5], red_warrior_id, hp[red->warriors[make_warrior_idx % 5]], attack[red->warriors[make_warrior_idx % 5]], 0});
    //                 printf("%03d:%02d red %s %d born\n", time / 60, time % 60, red->warriors[make_warrior_idx % 5].c_str(), red_warrior_id);
    //                 red_warrior_id++;
    //             }

    //             if (blue->elements >= hp[blue->warriors[make_warrior_idx % 5]]) {
    //                 blue->elements -= hp[blue->warriors[make_warrior_idx % 5]];
    //                 warriors[blue].push_back({blue->warriors[make_warrior_idx % 5], blue_warrior_id, hp[blue->warriors[make_warrior_idx % 5]], attack[blue->warriors[make_warrior_idx % 5]], N + 1});
    //                 printf("%03d:%02d blue %s %d born\n", time / 60, time % 60, blue->warriors[make_warrior_idx % 5].c_str(), blue_warrior_id);
    //                 blue_warrior_id++;
    //             }

    //         } else if (time % 60 == 10) {
    //             // 每小时的第10分，武士前进
    //             for (auto &w : warriors[red]) {
    //                 if (w.cur_location < N + 1) {
    //                     w.cur_location++;
    //                     printf("%03d:%02d red %s %d marched to city %d with %d elements and force %d\n", time / 60, time % 60, w.type.c_str(), w.id, w.cur_location, w.hp, w.attack);
    //                     cities[w.cur_location].red_warriors.push_back(w);
    //                 }
    //             }
    //             for (auto &w : warriors[blue]) {
    //                 if (w.cur_location > 0) {
    //                     w.cur_location--;
    //                     printf("%03d:%02d blue %s %d marched to city %d with %d elements and force %d\n", time / 60, time % 60, w.type.c_str(), w.id, w.cur_location, w.hp, w.attack);
    //                     cities[w.cur_location].blue_warriors.push_back(w);
    //                 }
    //             }

    //         } else if (time % 60 == 20) {
    //             // 每小时的第20分，城市产出生命元
    //             for (int i = 1; i <= N; ++i) {
    //                 cities[i].elements += 10;
    //             }
    //         } else if (time % 60 == 30) {
    //             // 每小时的第30分，武士取走生命元
    //             for (int i = 1; i <= N; ++i) {
    //                 if (cities[i].red_warriors.size() == 1 && cities[i].blue_warriors.empty()) {
    //                     printf("%03d:%02d red %s %d earned %d elements for his headquarter\n", time / 60, time % 60, cities[i].red_warriors[0].type.c_str(), cities[i].red_warriors[0].id, cities[i].elements);
    //                     red->elements += cities[i].elements;
    //                     cities[i].elements = 0;
    //                 } else if (cities[i].blue_warriors.size() == 1 && cities[i].red_warriors.empty()) {
    //                     printf("%03d:%02d blue %s %d earned %d elements for his headquarter\n", time / 60, time % 60, cities[i].blue_warriors[0].type.c_str(), cities[i].blue_warriors[0].id, cities[i].elements);
    //                     blue->elements += cities[i].elements;
    //                     cities[i].elements = 0;
    //                 }
    //             }
    //         } else if (time % 60 == 40) { ------------------------------------------------------------------------------------------------
    //             // 每小时的第40分，发生战斗
    //             for (int i = 1; i <= N; ++i) {
    //                 if (cities[i].red_warriors.size() > 0 && cities[i].blue_warriors.size() > 0) {
    //                     if (cities[i].flag == "red" || (cities[i].flag == "none" && i % 2 == 1)) {
    //                         // 红方主动进攻
    //                         printf("%03d:%02d red %s %d attacked blue %s %d in city %d with %d elements and force %d\n",
    //                             time / 60, time % 60, cities[i].red_warriors[0].type.c_str(), cities[i].red_warriors[0].id,
    //                             cities[i].blue_warriors[0].type.c_str(), cities[i].blue_warriors[0].id, i, cities[i].red_warriors[0].hp, cities[i].red_warriors[0].attack);
    //                     }
    //                 }
    //             }
    //         } else if (time % 60 == 50) {----------------------------------------------------------------------------------------------------
    //             // 每小时的第50分，司令部报告生命元数量
    //             printf("%03d:%02d %d elements in red headquarter\n", time / 60, time % 60, red->elements);
    //             printf("%03d:%02d %d elements in blue headquarter\n", time / 60, time % 60, blue->elements);
    //         }

    //         time += 10; // 每次更新增加10分钟
    //     }

    //     void run() {------------------------------------------------------------------------------------------------------------------------
    //         while (time <= T) {
    //             update();
    //         }
    //     }
    // };

    // Game game;
    // game.run();
}

int main() {
    // solve_eg();
    // solve1();
    solve2();
    return 0;
}