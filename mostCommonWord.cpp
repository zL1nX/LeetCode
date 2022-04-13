/*
给定一个段落 (paragraph) 和一个禁用单词列表 (banned)。返回出现次数最多，同时不在禁用列表中的单词。

题目保证至少有一个词不在禁用列表中，而且答案唯一。

禁用列表中的单词用小写字母表示，不含标点符号。段落中的单词不区分大小写。答案都是小写字母。

 

示例：

输入: 
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
输出: "ball"
解释: 
"hit" 出现了3次，但它是一个禁用的单词。
"ball" 出现了2次 (同时没有其他单词出现2次)，所以它是段落里出现次数最多的，且不在禁用列表中的单词。 
注意，所有这些单词在段落里不区分大小写，标点符号需要忽略（即使是紧挨着单词也忽略， 比如 "ball,"）， 
"hit"不是最终的答案，虽然它出现次数更多，但它在禁用单词列表中。
 

提示：

1 <= 段落长度 <= 1000
0 <= 禁用单词个数 <= 100
1 <= 禁用单词长度 <= 10
答案是唯一的, 且都是小写字母 (即使在 paragraph 里是大写的，即使是一些特定的名词，答案都是小写的。)
paragraph 只包含字母、空格和下列标点符号!?',;.
不存在没有连字符或者带有连字符的单词。
单词里只包含字母，不会出现省略号或者其他标点符号。
通过次数30,784提交次数70,396

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/most-common-word
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
#include <unordered_set>
#include <sstream>
#include <unordered_map>
#include <iostream>

using namespace std;

string mostCommonWord(string paragraph, vector<string>& banned) 
{
    unordered_set<string> banset;
    unordered_map<string, int> rec;
    for(string& banw : banned)
    {
        banset.insert(banw);
    }
    string word = "", res;
    vector<string> words;
    int cnt = 0;
    for(int i = 0; i < paragraph.length(); i++)
    {
        char c = tolower(paragraph[i]);
        if(isalpha(c))
        {
            word +=c;
        }
        else if(word.length() > 0 && banset.find(word) == banset.end())
        {
            rec[word] += 1;
            word = "";
        }
    }
    if(word.length() > 0)
    {
        rec[word] += 1;
    }
    for(auto& it : rec)
    {
        if(it.second > cnt)
        {
            cnt = it.second;
            res = it.first;
        }
    }
    return res;
}

int main()
{
    string para = "Bob. hIt, baLl";
    vector<string> banned = {"bob", "hit"};
    string res = mostCommonWord(para, banned);
    cout << "res " << res << endl;
}


//写起来又臭又长, 真的佛这种题
/*
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet;
        for (auto & word : banned) {
            bannedSet.emplace(word);
        }
        int maxFrequency = 0;
        unordered_map<string, int> frequencies;
        string word;
        int length = paragraph.size();
        for (int i = 0; i <= length; i++) {
            if (i < length && isalpha(paragraph[i])) {
                word.push_back(tolower(paragraph[i]));
            } else if (word.size() > 0) {
                if (!bannedSet.count(word)) {
                    frequencies[word]++;
                    maxFrequency = max(maxFrequency, frequencies[word]);
                }
                word = "";
            }
        }
        string mostCommon = "";
        for (auto &[word , frequency] : frequencies) {
            if (frequency == maxFrequency) {
                mostCommon = word;
                break;
            }
        }
        return mostCommon;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/most-common-word/solution/zui-chang-jian-de-dan-ci-by-leetcode-sol-mzjb/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/