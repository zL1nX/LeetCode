/*

给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。
通过次数128,038提交次数198,969

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    unordered_map<string, vector<int>> words;
    vector<vector<string>> res;
    for(int i = 0; i < strs.size(); i ++)
    {
        string word = strs[i];
        sort(word.begin(), word.end());
        words[word].push_back(i);
    }
    for(auto it : words)
    {
        vector<string> line;
        for(int i = 0; i < it.second.size();i++)
        {
            line.push_back(strs[it.second[i]]);
        }
        res.push_back(line);
    }
    return res;
}