/*
字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。

 

示例 1:

输入: 
first = "pale"
second = "ple"
输出: True
 

示例 2:

输入: 
first = "pales"
second = "pal"
输出: False

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/one-away-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>

using namespace std;

bool oneEditAway(string first, string second) 
{
    string a = first, b = second;
    if(a.length() > b.length())
    {
        a = second;
        b = first;
    }
    int n = a.length(), m = b.length(), i = 0, j = 0;
    if(abs(m - n) > 1)
    {
        return false;
    }
    int cnt = 0;
    while(i < n && j < m)
    {
        if(a[i] == b[j])
        {
            i++;j++;
            continue;
        }
        if(m == n)
        {
            i++;j++;cnt++; // 长度相等, 但是元素内容不等, 只能通过替换实现
        }
        else
        {
            j++; cnt++; // 长度更长, 只能通过添加元素来实现, 那么就相当于把长的指针多走一步, 相当于在短的指针上多增加一个长的那个位置的字符 (妙)
        }
    }
    return cnt <= 1;
}

// 简化版的编辑距离, 因为只需要判定bool即可, 最少编辑次数的话可以用dp来解

// 当两个元素一样就直接跳过, 如果元素不一样, 那么要是长度一样的话, 只能通过修改来实现, 因此用cnt来计数

// 要是一方的长度更长的话,  那么后移长的那个的指针, 这就相当于把短的多扩充了一个字母, 这个字母就是长的那个位置上的字母, 这下再去看后面一不一样

// 因为只能通过一次操作看是否能转换的话, 就可以直接判定了

