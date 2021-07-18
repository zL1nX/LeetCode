/*
编写一种方法，对字符串数组进行排序，将所有变位词组合在一起。变位词是指字母相同，但排列不同的字符串。

注意：本题相对原题稍作修改

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string, vector<int>> wordHash;
    for(int i = 0; i < strs.size(); i++)
    {
        string word = strs[i];
        sort(word.begin(), word.end());
        wordHash[word].push_back(i);
    }
    vector<vector<string>> result;
    for(auto& it : wordHash)
    {
        vector<string> line;
        for(auto& loc : it.second)
        {
            line.push_back(strs[loc]);
        }
        result.push_back(line);
    }
    return result;
}

// 没啥好说的，都做过两遍了，本质上是要找到每个单词的一种hash

// 可以排序，也可以以每个单词字母频率的数组为键