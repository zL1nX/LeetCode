/*
给定一个仅包含数字 0-9 的字符串 num 和一个目标值整数 target ，在 num 的数字之间添加 二元 运算符（不是一元）+、- 或 * ，返回所有能够得到目标值的表达式。

 

示例 1:

输入: num = "123", target = 6
输出: ["1+2+3", "1*2*3"] 
示例 2:

输入: num = "232", target = 8
输出: ["2*3+2", "2+3*2"]
示例 3:

输入: num = "105", target = 5
输出: ["1*0+5","10-5"]
示例 4:

输入: num = "00", target = 0
输出: ["0+0", "0-0", "0*0"]
示例 5:

输入: num = "3456237490", target = 9191
输出: []
 

提示：

1 <= num.length <= 10
num 仅含数字
-231 <= target <= 231 - 1
通过次数8,664提交次数20,984

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/expression-add-operators
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
using namespace std;

vector<string> addOperators(string num, int target) 
{
    int n = num.length();
    vector<string> ans;

    function<void(string&, int, long, long)> backtrack = [&](string& expr, int i, long res, long mul) 
    {
        if(i == n)
        {
            if(res == target)
            {
                ans.emplace_back(expr);
            }
            return;
        }
        int ind = expr.size();
        if(ind > 0)
        {
            expr.push_back('0');
        }
        long val = 0;
        for(int j = i; j < n && (j == i || num[i] != '0'); ++j) // 每次j累加，就相当于多截取一位的数字
        {
            val = val * 10 + num[j] - '0';
            expr.push_back(num[j]);
            if(i == 0)
            {
                backtrack(expr, j + 1, val, val);
            }
            else
            {
                expr[ind] = '+';backtrack(expr, j + 1, res + val, val);
                expr[ind] = '-';backtrack(expr, j + 1, res - val, -val);
                expr[ind] = '*';backtrack(expr, j + 1, res - mul + mul * val, mul * val); // mul存储了上一轮的值，相当于随时为乘法这个操作作准备
            }
        }
        expr.resize(ind);
    };
    string expr;
    backtrack(expr, 0, 0, 0); // 
    return ans;
}

// 看题解 https://leetcode-cn.com/problems/expression-add-operators/solution/gei-biao-da-shi-tian-jia-yun-suan-fu-by-2o1s7/
// 其他的基本都大概知道要做啥，但最后那个resize这句属实没整明白，难道是回溯一次还要再还原成初始状态

// 但中间那个循环的写法就很强，循环终止的条件从反面考虑，即碰到了第一个0的时候结束（因为下一个数字的前导不能为0）

