/*
编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

 

示例 1：

输入："hello"
输出："holle"
示例 2：

输入："leetcode"
输出："leotcede"
 

提示：

元音字母不包含字母 "y" 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-vowels-of-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <unordered_map>
using namespace std;

string reverseVowels(string s) 
{
    int left = 0, right = s.length() - 1;
    unordered_map<char, int> rec;
    string vowels = "aeiouAEIOU";
    for(char& v : vowels)
    {
        rec[v] = 1;
    }
    while(left < right)
    {
        if(rec[s[left]] && rec[s[right]])
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
        else if(rec[s[left]] == 0)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return s;
}

// 双指针稍微想一下就能写出来，但也许面试会做？