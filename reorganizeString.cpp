/*
给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。

若可行，输出任意可行的结果。若不可行，返回空字符串。

示例 1:

输入: S = "aab"
输出: "aba"
示例 2:

输入: S = "aaab"
输出: ""
注意:

S 只包含小写字母并且长度在[1, 500]区间内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reorganize-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string reorganizeString(string S) 
{
    //unordered_map<char, int> frequency;
    vector<pair<char, int>> frequency(26, make_pair('a', 0));
    string res = "";
    for(int i = 0; i < 26; i ++)
    {
        frequency[i].first += i;
    }
    for(char c : S)
    {
        frequency[c - 'a'].second ++;
    }
    sort(frequency.begin(), frequency.end(), [](pair<char, int> a, pair<char, int> b){
        return a.second > b.second;
    });
    int seg_size = frequency[0].second;

    if(seg_size > (S.length() + 1) / 2)
    {
        return "";
    }
    vector<string> segment(seg_size);
    int l = 0;
    for(int i = 0; i < 26; i ++)
    {
        int n = frequency[i].second;
        for(int j = 0; j < n; j++)
        {
            segment[l++ % seg_size].push_back(frequency[i].first);
        }
    }
    // 轮询排入是精髓，可以作为模板学习
    for(string s : segment)
    {
        res += s;
    }
    return res;

}