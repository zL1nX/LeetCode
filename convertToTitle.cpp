/*
给定一个正整数，返回它在 Excel 表中相对应的列名称。

例如，

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
示例 1:

输入: 1
输出: "A"
示例 2:

输入: 28
输出: "AB"
示例 3:

输入: 701
输出: "ZY"
通过次数56,363提交次数140,131

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/excel-sheet-column-title
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
using namespace std;

string convertToTitle(int columnNumber) 
{
    string res = "";
    while(columnNumber)
    {
        int bit = columnNumber % 26;
        columnNumber = (columnNumber - 1) / 26;
        res += 'A' + (26 + bit - 1) % 26;
    }
    return string(res.rbegin(), res.rend());
}

/*
while (columnNumber) {
			--columnNumber;
			res += 'A' + columnNumber % 26;
			columnNumber /= 26;
		}

这样写就不别扭了，核心是一定要减1，否则位数可能不对
本质就是一个进制转化问题，但因为没有0的参与，所以就很难受
*/