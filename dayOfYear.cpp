/*
给你一个字符串 date ，按 YYYY-MM-DD 格式表示一个 现行公元纪年法 日期。请你计算并返回该日期是当年的第几天。

通常情况下，我们认为 1 月 1 日是每年的第 1 天，1 月 2 日是每年的第 2 天，依此类推。每个月的天数与现行公元纪年法（格里高利历）一致。

 

示例 1：

输入：date = "2019-01-09"
输出：9
示例 2：

输入：date = "2019-02-10"
输出：41
示例 3：

输入：date = "2003-03-01"
输出：60
示例 4：

输入：date = "2004-03-01"
输出：61
 

提示：

date.length == 10
date[4] == date[7] == '-'，其他的 date[i] 都是数字
date 表示的范围从 1900 年 1 月 1 日至 2019 年 12 月 31 日
通过次数21,058提交次数34,674

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/day-of-the-year
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
using namespace std;

int dayOfYear(string date) 
{
    int year = stoi(date.substr(0, 4)), month = stoi(date.substr(5, 2)), day = stoi(date.substr(8, 2));
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int result = day;
    for(int i = 1; i < month; i++)
    {
        result += days[i];
    }
    if(((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) && month > 2)
    {
        result += 1;
    }
    return result;
}

// 冬至日给了个还挺应景的题

// 直接对每个月的天数进行累加，然后看是否为闰年且月数比2大，如果大的加1

// 至于每个月的天数，直接用数组完事，千万不要想着判断一下这个月是否在xxx数组里啥的，这种直接用天数这种类似于「哈希表」的方法去做就行