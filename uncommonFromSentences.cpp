/*
给定两个句子 A 和 B 。 （句子是一串由空格分隔的单词。每个单词仅由小写字母组成。）

如果一个单词在其中一个句子中只出现一次，在另一个句子中却没有出现，那么这个单词就是不常见的。

返回所有不常用单词的列表。

您可以按任何顺序返回列表。

 

示例 1：

输入：A = "this apple is sweet", B = "this apple is sour"
输出：["sweet","sour"]
示例 2：

输入：A = "apple apple", B = "banana"
输出：["banana"]
 

提示：

0 <= A.length <= 200
0 <= B.length <= 200
A 和 B 都只包含空格和小写字母。
通过次数14,753提交次数22,856

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/uncommon-words-from-two-sentences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> uncommonFromSentences(string A, string B) 
{
    vector<string> words, res;
    unordered_map<string, int> maps;
    istringstream s1(A);
    string word;
    while(s1 >> word)
    {
        words.push_back(word);
    }

    istringstream s2(B);
    word = "";
    while(s2 >> word)
    {
        words.push_back(word);
    }

    for(int i = 0; i < words.size(); i++)
    {
        maps[words[i]]++;
    }
    for(auto it : maps)
    {
        if(it.second == 1)
        {
            res.push_back(it.first);
        }
    }
    return res;
}