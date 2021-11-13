/*
我们定义，在以下情况时，单词的大写用法是正确的：

全部字母都是大写，比如 "USA" 。
单词中所有字母都不是大写，比如 "leetcode" 。
如果单词不只含有一个字母，只有首字母大写， 比如 "Google" 。
给你一个字符串 word 。如果大写用法正确，返回 true ；否则，返回 false 。

 

示例 1：

输入：word = "USA"
输出：true
示例 2：

输入：word = "FlaG"
输出：false
 

提示：

1 <= word.length <= 100
word 由小写和大写英文字母组成
通过次数45,336提交次数79,686

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/detect-capital
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>

using namespace std;

bool detectCapitalUse(string word) 
{
    bool first = isupper(word[0]);
    for(int i = 1; i < word.length(); i++)
    {
        if(i > 1 && isupper(word[i]) != isupper(word[i - 1]))
        {
            return false;
        }
        if(first == false && isupper(word[i]) != false)
        {
            return false;
        }
    }
    return true;
}

// 直接写就行，要意识到如果第一个字符是大写的，那么需要保证后面的其他字符要么都是大写，要么都是小写

// 第一个字符是小写的话，后面的需要都是小写

// 因此归纳一下就是，除第一个字符外的所有字符，大小写形式要一致；只要第一个字符是小写，后面所有的都得是小写

// 按照这个去写两个if判断即可