/*
Alice 和 Bob 计划分别去罗马开会。

给你四个字符串 arriveAlice ，leaveAlice ，arriveBob 和 leaveBob 。Alice 会在日期 arriveAlice 到 leaveAlice 之间在城市里（日期为闭区间），而 Bob 在日期 arriveBob 到 leaveBob 之间在城市里（日期为闭区间）。每个字符串都包含 5 个字符，格式为 "MM-DD" ，对应着一个日期的月和日。

请你返回 Alice和 Bob 同时在罗马的天数。

你可以假设所有日期都在 同一个 自然年，而且 不是 闰年。每个月份的天数分别为：[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31] 。

 

示例 1：

输入：arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
输出：3
解释：Alice 从 8 月 15 号到 8 月 18 号在罗马。Bob 从 8 月 16 号到 8 月 19 号在罗马，他们同时在罗马的日期为 8 月 16、17 和 18 号。所以答案为 3 。
示例 2：

输入：arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"
输出：0
解释：Alice 和 Bob 没有同时在罗马的日子，所以我们返回 0 。
 

提示：

所有日期的格式均为 "MM-DD" 。
Alice 和 Bob 的到达日期都 早于或等于 他们的离开日期。
题目测试用例所给出的日期均为 非闰年 的有效日期。
通过次数2,972提交次数6,748

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-days-spent-together
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>

using namespace std;


vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int convertdays(string& date)
{
    int month = stoi(date.substr(0,2)), day = stoi(date.substr(3,2)), monthdays = 0;
    for(int i = 1; i <= month - 1; i++)
    {
        monthdays += days[i]; //累积算下前面有多少天, 同样注意这里的索引
    }
    return monthdays + day;
}

int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) 
{
    int a = convertdays(arriveAlice), b = convertdays(leaveAlice);
    int c = convertdays(arriveBob), d = convertdays(leaveBob);
    return (a <= d && b >= c) ? min(b, d) - max(a, c) + 1 : 0; // 这里要取等, 因为是闭区间
}

// 直接模拟, 但是区间重叠, 以及区间重叠部分大小的写法, 边界考虑, 索引等等细节需要注意

// 而且记得最后结果 + 1