/*
给出一个字符串数组 words 组成的一本英语词典。返回 words 中最长的一个单词，该单词是由 words 词典中其他单词逐步添加一个字母组成。

若其中有多个可行的答案，则返回答案中字典序最小的单词。若无答案，则返回空字符串。

 

示例 1：

输入：words = ["w","wo","wor","worl", "world"]
输出："world"
解释： 单词"world"可由"w", "wo", "wor", 和 "worl"逐步添加一个字母组成。
示例 2：

输入：words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
输出："apple"
解释："apply" 和 "apple" 都能由词典中的单词组成。但是 "apple" 的字典序小于 "apply" 
 

提示：

1 <= words.length <= 1000
1 <= words[i].length <= 30
所有输入的字符串 words[i] 都只包含小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-word-in-dictionary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

string longestWord(vector<string>& words) 
{
    sort(words.begin(), words.end(), [](const string& a, const string &b)
    {
        if(a.length() != b.length())
        {
            return a.length() < b.length();
        }
        else
        {
            return a > b; // 注意这里是字典序降序排列, 希望把满足条件的 且 字典序小的放到后面
        }
    });
    unordered_set<string> rec;
    rec.emplace(""); // 插入一个空字符串, 用来满足最短的一个字母的情况
    string candidate;
    for(int i = 0;i < words.size(); i++)
    {
        if(rec.count(words[i].substr(0, words[i].size() - 1))) // 只有在自身的前缀的确出现在了set中时
        {
            rec.emplace(words[i]); // 才会把自己这个单词也算到这个set里面
            candidate = words[i];
        }
    }
    return candidate;
}

// 一眼字典树, 但是的确懒得写, 字典树还得专门定义一个class和里面的insert与search方法等等

// 不如直接模拟算了

// 模拟的话, 注意题目中的需求是最后的那个单词必须得是一个个字母添加而来的单词

// 因此, 在使用set前, 需要首先对数组排下序. 而排序时, 一个原则是长度升序排列, 而另一个原则是字典序降序排列

// 字典序降序的目的是, 当有若干个长度相等的单词时, for循环进行迭代, 那必然是靠后的, 满足条件的单词时我们想要的

// 那这样一来, 只要靠后, 我们就希望它的字典序是更小的

// 虽然是模拟题, 但有很多细节都非常精髓而且容易忘记

// 这玩意能算简单题? 