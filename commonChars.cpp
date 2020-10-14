/*
给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。

你可以按任意顺序返回答案。

 

示例 1：

输入：["bella","label","roller"]
输出：["e","l","l"]
示例 2：

输入：["cool","lock","cook"]
输出：["c","o"]

*/
// 题目表达有很大问题，究竟要打印几次？
#include <vector>
#include <string>
#include <map>
using namespace std;

// vector<string> commonChars(vector<string>& A) 
// {
//     map<char, int> times;
//     vector<string> res;
//     for(string s : A)
//     {
//         for(int i = 0; i < s.size(); i ++)
//         {
//             if(times.count(s[i]))
//             {
//                 times[s[i]]++;
//             }
//             else
//             {
//                 times.insert(pair<char, int>(s[i], 0));
//             }   
//         }
//     }
//     for(auto it : times)
//     {
//         for(int i = 0; i < it.second;i++)
//         {
//             string r(1, it.first);
//             res.push_back(r);
//         }
            
//     }
//     return res;
// }

vector<string> commonChars(vector<string>& A) 
{
    int res[26] = { 0 };
    vector<string> result;
    for(char c : A[0])
    {
        res[c - 'a']++;
    }
    for(int i = 1; i < A.size(); i ++)
    {
        int chs[26] = { 0 };
        for(char c : A[i])
        {
            chs[c - 'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            res[i] = min(res[i], chs[i]);
        }
    }
    for(int i = 0; i < 26; i ++)
    {
        for(int k = 0; k < res[i];k++)
        {
            result.push_back(string(1, i + 'a'));
        }
    }
    return result;
}