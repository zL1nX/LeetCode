/*
给定一个字符串 s 表示一个整数嵌套列表，实现一个解析它的语法分析器并返回解析的结果 NestedInteger 。

列表中的每个元素只可能是整数或整数嵌套列表

 

示例 1：

输入：s = "324",
输出：324
解释：你应该返回一个 NestedInteger 对象，其中只包含整数值 324。
示例 2：

输入：s = "[123,[456,[789]]]",
输出：[123,[456,[789]]]
解释：返回一个 NestedInteger 对象包含一个有两个元素的嵌套列表：
1. 一个 integer 包含值 123
2. 一个包含两个元素的嵌套列表：
    i.  一个 integer 包含值 456
    ii. 一个包含一个元素的嵌套列表
         a. 一个 integer 包含值 789
 

提示：

1 <= s.length <= 5 * 104
s 由数字、方括号 "[]"、负号 '-' 、逗号 ','组成
用例保证 s 是可解析的 NestedInteger
输入中的所有值的范围是 [-106, 106]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/mini-parser
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <stack>

using namespace std;


class NestedInteger {
   public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


NestedInteger deserialize(string s) 
{
    if(s[0] != '[')
    {
        return NestedInteger(stoi(s));
    }
    int num = 0;
    bool negative = false;
    stack<NestedInteger> sk;
    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if(c == '-')
        {
            negative = true;
        }
        else if(isdigit(c))
        {
            num = num * 10 + c - '0';
        }
        else if(c == '[')
        {
            sk.emplace(NestedInteger());
        }
        else if(c == ',' || c == ']')
        {
            if(isdigit(s[i - 1]))
            {
                if(negative)
                {
                    num *= -1;
                }
                sk.top().add(NestedInteger(num));
            }
            num = 0;
            negative = false;
            if(c == ']' && sk.size() > 1)
            {
                NestedInteger n = sk.top();
                sk.pop();
                sk.top().add(n);
            }
        }
    }
    return sk.top();
}

// 标准的恶心人的栈模拟字符串类型的题

// 先考虑清楚各种情况, 即负号 左括号 逗号 右括号

// 左括号说明有一个新的nest要出现, 逗号说明要考虑下一波数字, 右括号除了说明当前数字结束外

// 还要将目前的这个nest加到上一个nest里面

// 这种感觉就是面试时会非常讨厌的字符串与栈模拟题