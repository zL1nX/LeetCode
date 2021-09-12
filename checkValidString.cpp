/*
给定一个只包含三种字符的字符串：（ ，） 和 *，写一个函数来检验这个字符串是否为有效字符串。有效字符串具有如下规则：

任何左括号 ( 必须有相应的右括号 )。
任何右括号 ) 必须有相应的左括号 ( 。
左括号 ( 必须在对应的右括号之前 )。
* 可以被视为单个右括号 ) ，或单个左括号 ( ，或一个空字符串。
一个空字符串也被视为有效字符串。
示例 1:

输入: "()"
输出: True
示例 2:

输入: "(*)"
输出: True
示例 3:

输入: "(*))"
输出: True
注意:

字符串大小将在 [1，100] 范围内。
通过次数21,297提交次数59,798

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parenthesis-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <stack>
using namespace std;

bool checkValidString(string s) 
{
    stack<int> left, star;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '('){
            left.push(i);
        }else if(s[i] == '*'){
            star.push(i);
        }else{
            if(!left.empty()){
                left.pop();
            }else if(!star.empty()){ // 优先左括号，要左括号没了，星号就顶上
                star.pop();
            }else{
                return false;
            }
        }
    }
    while(!left.empty() && !star.empty()) {
        if(left.top() > star.top()) { // 如果左括号的序号比星号还靠后，说明这个左括号肯定没法配对了
            return false;
        }
        left.pop();
        star.pop();
    }
    return left.empty(); // 星号可以看做是空字符
}

// 使用两个栈分别记录括号和*，遇到右括号即出栈，反正星号和其他字符是等价的

// 最后看星号与左括号是否能配对上