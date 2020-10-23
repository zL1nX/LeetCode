/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."

*/
#include <string>
using namespace std;

string replaceSpace(string s) 
{
    string res = "";
    for(int i = 0;i < s.length();i++)
    {
        if (s[i] == ' ')
        {
            res += "%20";
        }
        else
        {
            res += s[i];
        }
        
    }
    return res;
}