/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。

 

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
 

提示：

1 <= num1.length, num2.length <= 200
num1 和 num2 只能由数字组成。
num1 和 num2 都不包含任何前导零，除了数字0本身。
*/

#include <string>
#include <vector>
using namespace std;

string multiply(string num1, string num2) 
{
    if(num1 == "0" || num2 == "0") return "0";

    int m = num1.size(), n = num2.size();
    vector<int> res(m + n, 0);
    for(int i = m - 1; i >= 0; i--)
    {
        for(int j = n - 1; j >= 0; j--)
        {
            int single = (num1[i] - '0') * (num2[j] - '0');            
            int p1 = i + j, p2 = i + j + 1; // 这一点观察非常重要
            int sum = single + res[p2];

            res[p1] += sum / 10;
            res[p2] = sum % 10;
        }
    }
    string str;
    int i = 0;
    while(i < res.size() && res[i] == 0) i++; // 可能有前导0的存在
    for(; i < res.size(); i++)
    {
        str.push_back('0' + res[i]);
    }
    return str;
}

//43-字符串相乘