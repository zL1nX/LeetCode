/*
你有一个单词列表 words 和一个模式  pattern，你想知道 words 中的哪些单词与模式匹配。

如果存在字母的排列 p ，使得将模式中的每个字母 x 替换为 p(x) 之后，我们就得到了所需的单词，那么单词与模式是匹配的。

（回想一下，字母的排列是从字母到字母的双射：每个字母映射到另一个字母，没有两个字母映射到同一个字母。）

返回 words 中与给定模式匹配的单词列表。

你可以按任何顺序返回答案。

 

示例：

输入：words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
输出：["mee","aqq"]
解释：
"mee" 与模式匹配，因为存在排列 {a -> m, b -> e, ...}。
"ccc" 与模式不匹配，因为 {a -> c, b -> c, ...} 不是排列。
因为 a 和 b 映射到同一个字母。
 

提示：

1 <= words.length <= 50
1 <= pattern.length = words[i].length <= 20
通过次数13,017提交次数17,262

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-and-replace-pattern
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
{
    vector<string> res;
    for(string& word : words)
    {
        bool flag = true;
        vector<int> rec(26, -1), visited(26, 0); // 每次都有一个新表
        for(int i = 0; i < word.size(); i++)
        {
            int c1 = word[i] - 'a', c2 = pattern[i] - 'a';
            if(rec[c1] == -1 && visited[c2] == 0)
            {
                rec[c1] = c2;
                visited[c2] = 1;
            }
            else if(rec[c1] != c2)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            res.push_back(word);
        }
    }
    return res;
}

// 双哈希表的模拟, visitied这个表的存在是因为, pattern中会有重复字母

// 如果不用visited来对重复字母进行限制的话, 只要word中没有重复字母, 就都可以匹配上

// 此外, 就是每次用一个map来映射当前word的字母应该对应pattern的那个字母, 如果遇到map entry不为空的情况

// 就要检查是不是之前pattern对应上的那个, 否则就错误了