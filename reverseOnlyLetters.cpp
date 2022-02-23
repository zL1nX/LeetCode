/*
给你一个字符串 s ，根据下述规则反转字符串：

所有非英文字母保留在原有位置。
所有英文字母（小写或大写）位置反转。
返回反转后的 s 。

 

示例 1：

输入：s = "ab-cd"
输出："dc-ba"
示例 2：

输入：s = "a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"
示例 3：

输入：s = "Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"
 

提示

1 <= s.length <= 100
s 仅由 ASCII 值在范围 [33, 122] 的字符组成
s 不含 '\"' 或 '\\'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-only-letters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
using namespace std;

string reverseOnlyLetters(string s) 
{
    int left = 0, right = s.size() - 1;
    while(left < right)
    {
        if(!isalpha(s[left])) left++;
        if(!isalpha(s[right])) right--;
        if(isalpha(s[left]) && isalpha(s[right]))
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    return s;
}

// 反转字符串的方法中，双指针是最常见的一种

// 这题不过是多了一个只反转字母的条件，因此碰到不是字母的就直接跳过就好了

// 如果是字母的话，就是正常的反转字符串 直接swap就好

// 感觉可以面试用来做一做