/*
给定一个Excel表格中的列名称，返回其相应的列序号。

例如，

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
示例 1:

输入: "A"
输出: 1
示例 2:

输入: "AB"
输出: 28
示例 3:

输入: "ZY"
输出: 701
致谢：
特别感谢 @ts 添加此问题并创建所有测试用例。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/excel-sheet-column-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <math.h>
using namespace std;

int titleToNumber(string columnTitle) 
{
    int sum = 0, e = 0;
    for(int i = columnTitle.length() - 1; i >= 0; i--)
    {
        sum += (columnTitle[i] - 'A') * pow(26, i);
    }
    return sum;
}

// 就是一个26进制的转换