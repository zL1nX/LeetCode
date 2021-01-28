/*
请你设计一个可以解释字符串 command 的 Goal 解析器 。command 由 "G"、"()" 和/或 "(al)" 按某种顺序组成。Goal 解析器会将 "G" 解释为字符串 "G"、"()" 解释为字符串 "o" ，"(al)" 解释为字符串 "al" 。然后，按原顺序将经解释得到的字符串连接成一个字符串。

给你字符串 command ，返回 Goal 解析器 对 command 的解释结果。

 

示例 1：

输入：command = "G()(al)"
输出："Goal"
解释：Goal 解析器解释命令的步骤如下所示：
G -> G
() -> o
(al) -> al
最后连接得到的结果是 "Goal"
示例 2：

输入：command = "G()()()()(al)"
输出："Gooooal"
示例 3：

输入：command = "(al)G(al)()()G"
输出："alGalooG"
 

提示：

1 <= command.length <= 100
command 由 "G"、"()" 和/或 "(al)" 按某种顺序组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/goal-parser-interpretation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
using namespace std;

string interpret(string command) 
{
    int idx = 0;
    string res = "";
    while(idx <= command.length() - 1)
    {
        // if(command[idx] == 'G')
        // {
        //     res += 'G';
        //     idx ++;
        // }
        // if(command[idx] == '(')
        // {
        //     if(command[idx + 1] == ')')
        //     {
        //         res += 'o';
        //         idx += 2;
        //     }
        //     if(command[idx + 2] == 'a')
        //     {
        //         res += "al";
        //         idx += 4;
        //     }
        // } // 这里有点奇怪
        if(command[idx] == 'G')
        {
            res += 'G';
            idx ++;
        }
        else if(command[idx] == '(' && command[idx + 1] == ')')
        {
            res += 'o';
            idx += 2;
        }
        else if(command[idx] == '(' && command[idx + 1] == 'a')
        {
            res += "al";
            idx += 4; 
        }
    }
    return res;
}