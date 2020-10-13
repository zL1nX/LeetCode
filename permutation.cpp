/*
无重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合，字符串每个字符均不相同。

示例1:

 输入：S = "qwe"
 输出：["qwe", "qew", "wqe", "weq", "ewq", "eqw"]
示例2:

 输入：S = "ab"
 输出：["ab", "ba"]
提示:

字符都是英文字母。
字符串长度在[1, 9]之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutation-i-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> permutation(string S) 
{
    vector<string> res;
    string copy = string(S);
    res.push_back(S);
    while(next_permutation(S.begin(), S.end()))
    {
        res.push_back(S);
    }
    while(prev_permutation(copy.begin(), copy.end()))
    {
        res.push_back(copy);
    }
    return res;
}
// 还可用dfs回溯的方法生成