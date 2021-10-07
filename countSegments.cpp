/*
统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。

请注意，你可以假定字符串里不包括任何不可打印的字符。

示例:

输入: "Hello, my name is John"
输出: 5
解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。
通过次数43,159提交次数112,770


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-segments-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
using namespace std;

int countSegments(string s) 
{
    int n = s.length(), cnt = 0;
    for(int i = 0; i < n;)
    {
        if(s[i] == ' ')
        {
            i++;
            continue;
        } 
        while(i < n && s[i] != ' ')
        {
            i++;
        }
        cnt++;
    }
    return cnt;
}

// 直接做即可，遇到空格跳过，然后用一个while循环移到下一个为空格的地方，同时累加cnt

// 但是感觉真实写起来还是要多注意下，很多用例可能并不简单，只关心空格以及空格之后是否为非空字符即可