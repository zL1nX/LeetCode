/*
给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。

 

示例 1:

输入: ["abcw","baz","foo","bar","xtfn","abcdef"]
输出: 16 
解释: 这两个单词为 "abcw", "xtfn"。
示例 2:

输入: ["a","ab","abc","d","cd","bcd","abcd"]
输出: 4 
解释: 这两个单词为 "ab", "cd"。
示例 3:

输入: ["a","aa","aaa","aaaa"]
输出: 0 
解释: 不存在这样的两个单词。
 

提示：

2 <= words.length <= 1000
1 <= words[i].length <= 1000
words[i] 仅包含小写字母
通过次数25,451提交次数35,977

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-of-word-lengths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <string>

using namespace std;

int maxProduct(vector<string>& words) 
{
    int n = words.size();
    vector<int> masks;
    for(int i = 0; i < n; i ++)
    {
        int mask = 0;
        for(char& c : words[i])
        {
            mask |= 1 << (c - 'a'); // 位运算，每一位取1都代表一个字母
        }
        masks.push_back(mask);
    }
    int maxn = 0;
    for(int i = 0; i < n; i ++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if((masks[i] & masks[j]) == 0) // 记得这里要加括号，因为优先级低
            {
                maxn = max(maxn, int(words[j].length() * words[i].length()));
            }
        }
    }
    return maxn;
}

// 对于任意两个word之间的比较，没啥好方法，只有n2级别的直接遍历

// 但真正能优化的地方在于如何判断两个词之间没有相同的字母

// 这一点可以用哈希表去做，但是这里更精妙的就是位运算，因为总共就那么26个字母，因此可以一位代表一个字母

// 如果两个数之间 & 与运算的结果不为0，就说明有相同字母（彳亍）

// 其余的步骤和直接模拟就没啥区别了，这道题可以多做做