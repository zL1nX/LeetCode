/*
给你一个由数字和运算符组成的字符串 expression ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以 按任意顺序 返回答案。

生成的测试用例满足其对应输出值符合 32 位整数范围，不同结果的数量不超过 104 。

 

示例 1：

输入：expression = "2-1-1"
输出：[0,2]
解释：
((2-1)-1) = 0 
(2-(1-1)) = 2
示例 2：

输入：expression = "2*3-4*5"
输出：[-34,-14,-10,-10,10]
解释：
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
 

提示：

1 <= expression.length <= 20
expression 由数字和算符 '+'、'-' 和 '*' 组成。
输入表达式中的所有整数值在范围 [0, 99] 
*/

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, vector<int>> memo; //避免重复计算

vector<int> diffWaysToCompute(string expression) 
{
    if(memo.count(expression)) return memo[expression];
    vector<int> res;
    for(int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];
        if(c == '+' || c == '-' || c == '*')
        {
            vector<int> left = diffWaysToCompute(expression.substr(0, i));// 进行运算符分隔, 分别进行左右的计算
            vector<int> right = diffWaysToCompute(expression.substr(i + 1)); 

            // 单运算符的计算
            for(int x : left)
            {
                for(int y : right)
                {
                    if(c == '+') res.push_back(x + y);
                    else if(c == '-') res.push_back(x - y);
                    else if(c == '*') res.push_back(x * y);
                }
            }
        }
    }
    if(res.empty()) // 说明目前是单一数字, 无分割后计算的结果, 就直接返回
    {
        res.push_back(stoi(expression));
    }
    memo[expression] = res;
    return res;
}

// 这个题对递归与分治的应用非常非常巧妙, 也就是最正确的解这个题的本质思路