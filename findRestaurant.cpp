/*
假设 Andy 和 Doris 想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。

你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设答案总是存在。

 

示例 1:

输入: list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]，list2 = ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
输出: ["Shogun"]
解释: 他们唯一共同喜爱的餐厅是“Shogun”。
示例 2:

输入:list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]，list2 = ["KFC", "Shogun", "Burger King"]
输出: ["Shogun"]
解释: 他们共同喜爱且具有最小索引和的餐厅是“Shogun”，它有最小的索引和1(0+1)。
 

提示:

1 <= list1.length, list2.length <= 1000
1 <= list1[i].length, list2[i].length <= 30 
list1[i] 和 list2[i] 由空格 ' ' 和英文字母组成。
list1 的所有字符串都是 唯一 的。
list2 中的所有字符串都是 唯一 的。
通过次数39,374提交次数73,230

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-index-sum-of-two-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
{
    unordered_map<string, int> rec;
    for(int i = 0; i < list1.size(); i++)
    {
        rec[list1[i]] = i;
    }
    int res = INT_MAX;
    vector<string> candidates;
    for(int j = 0; j < list2.size(); j++)
    {
        if(!rec.count(list2[j]))
        {
            continue;
        }
        int canid = rec[list2[j]] + j;
        if(canid < res)
        {
            res = canid;
            candidates.clear();
            candidates.push_back(list2[j]);
        }
        else if(canid == res)
        {
            candidates.push_back(list2[j]);
        }
    }
    return candidates;
}

// 直接用哈希表模拟即可，好像也没别的更好的方法

// 注意到返回的结果是一个vector,即所有的候选结果,因此如果找到了更小的res,就应该清空原来的candidates

// 此外,还要再加一句和原来res相等的情况,相等时直接相加即可.

// 别的是没有什么了,直接做就好,记得几个if里面要写清楚