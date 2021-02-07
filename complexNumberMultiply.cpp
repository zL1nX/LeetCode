/*
给定两个表示复数的字符串。

返回表示它们乘积的字符串。注意，根据定义 i2 = -1 。

示例 1:

输入: "1+1i", "1+1i"
输出: "0+2i"
解释: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。
示例 2:

输入: "1+-1i", "1+-1i"
输出: "0+-2i"
解释: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。 
注意:

输入字符串不包含额外的空格。
输入字符串将以 a+bi 的形式给出，其中整数 a 和 b 的范围均在 [-100, 100] 之间。输出也应当符合这种形式。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/complex-number-multiplication
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> process(string i)
{
    int loc = i.find("+"), n = i.length();
    int real = stoi(i.substr(0, loc)), imag = stoi(i.substr(loc + 1, n - loc - 1));
    vector<int> ni(2,0);
    ni[0] = real; ni[1] = imag;
    return ni;
}


string complexNumberMultiply(string a, string b) 
{
    vector<int> ia = process(a), ib = process(b);
    int n1 = ia[0] * ib[0], n2 = ia[1] * ib[0] + ia[0] * ib[1], n3 = ia[1] * ib[1];
    string real = to_string(n1 - n3), imaginary = to_string(n2);
    string res = real + "+" + imaginary;
    return res;

}

/*
 string complexNumberMultiply(string a, string b) {
        
        int a1, b1, a2, b2;
        sscanf(a.c_str(), "%d+%di", &a1, &b1);
        sscanf(b.c_str(), "%d+%di", &a2, &b2);
        
        int aa = a1 * a2 - b1 * b2;
        int bb = a1 * b2 + a2 * b1;
        
        return string(to_string(aa) + "+" + to_string(bb) + "i");
    }
*/
// 用sscanf确实不错