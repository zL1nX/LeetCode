/*
句子 是一串由空格分隔的单词。每个 单词 仅由小写字母组成。

如果某个单词在其中一个句子中恰好出现一次，在另一个句子中却 没有出现 ，那么这个单词就是 不常见的 。

给你两个 句子 s1 和 s2 ，返回所有 不常用单词 的列表。返回列表中单词可以按 任意顺序 组织。

 

示例 1：

输入：s1 = "this apple is sweet", s2 = "this apple is sour"
输出：["sweet","sour"]
示例 2：

输入：s1 = "apple apple", s2 = "banana"
输出：["banana"]
 

提示：

1 <= s1.length, s2.length <= 200
s1 和 s2 由小写英文字母和空格组成
s1 和 s2 都不含前导或尾随空格
s1 和 s2 中的所有单词间均由单个空格分隔
通过次数23,392提交次数34,582

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/uncommon-words-from-two-sentences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> uncommonFromSentences(string s1, string s2) 
{
    unordered_map<string, int> cnt;
    string ss = s1 + " " + s2;
    vector<string> words; string word;
    stringstream str(ss);
    while(str >> word)
    {
        words.push_back(word);
    }
    for(auto w : words)
    {
        cnt[w]++;
    }
    vector<string> res;
    for(auto& it : cnt)
    {
        if(it.second == 1)
        {
            res.push_back(it.first);
        }
    }
    return res;

}