/*
某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。

给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回 false。

 

示例 1：

输入：words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
输出：true
解释：在该语言的字母表中，'h' 位于 'l' 之前，所以单词序列是按字典序排列的。
示例 2：

输入：words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
输出：false
解释：在该语言的字母表中，'d' 位于 'l' 之后，那么 words[0] > words[1]，因此单词序列不是按字典序排列的。
示例 3：

输入：words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
输出：false
解释：当前三个字符 "app" 匹配时，第二个字符串相对短一些，然后根据词典编纂规则 "apple" > "app"，因为 'l' > '∅'，其中 '∅' 是空白字符，定义为比任何其他字符都小（更多信息）。
 

提示：

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
在 words[i] 和 order 中的所有字符都是英文小写字母。
通过次数23,916提交次数42,268

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/verifying-an-alien-dictionary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool isAlienSorted(vector<string>& words, string order) 
{
    unordered_map<char, int> rec;
    for(int i = 0; i < order.size();i++)
    {
        rec[order[i]] = i;
    }
    for(int i = 1; i < words.size(); i++)
    {
        bool flag = true;
        for(int j = 0; j < min(words[i - 1].size(), words[i].size()); j++)
        {
            if(rec[words[i][j]] < rec[words[i - 1][j]])
            {
                return false;
            }
            else
            {   
                flag = false;
                break;
            }
        }
        if(flag && words[i].size() < words[i - 1].size())
        {
            return false;
        }
    }
    return true;
}


/*
class Solution {
public:
    void doTranslate(std::string &word,std::unordered_map<char,int>& dict) {
        for (auto &ch : word) {
            ch = dict[ch] + 'a';
        }
    }
    bool isAlienSorted(vector<string>& words, string order) {
        std::unordered_map<char,int> index;
        for (int i=0;i<order.size();i++) {
            index[order[i]] = i;
        }
        for (auto &word : words) {
            doTranslate(word, index);
        }
        for (int i=1;i<words.size();i++) {
            if (words[i] < words[i-1]) {
                return false;
            }
        }
        return true;
    }
};
*/


// 真是个NT题, 字典序这种最好还是直接用内置的字符串比较 