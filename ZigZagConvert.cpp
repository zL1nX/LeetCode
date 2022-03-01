/*
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
 

示例 1：

输入：s = "PAYPALISHIRING", numRows = 3
输出："PAHNAPLSIIGYIR"
示例 2：
输入：s = "PAYPALISHIRING", numRows = 4
输出："PINALSIGYAHRPI"
解释：
P     I    N
A   L S  I G
Y A   H R
P     I
示例 3：

输入：s = "A", numRows = 1
输出："A"
 

提示：

1 <= s.length <= 1000
s 由英文字母（小写和大写）、',' 和 '.' 组成
1 <= numRows <= 1000
通过次数365,483提交次数713,134

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zigzag-conversion
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <string>
#include <vector>
using namespace std;

string ZigZagConvert(string s, int numRows) 
{
    int n = s.length();
    if(numRows == 1 || numRows >= n)
    {
        return s;
    }
    int one = 2 * numRows - 2, column = (n + one - 1) / one * (numRows - 1);
    // 这里要补充one - 1 是因为这样可以明确的求出一共有多少个完整的周期，也就是向上取整
    vector<string> zig(numRows, string(column, 0));
    for(int cur = 0, r = 0, c = 0; cur < n; cur++)
    {
        zig[r][c] = s[cur];
        if(cur % one < numRows - 1) // 如果当前cur还在往下的一列中（因为这样的字符是从0到r-1开始的）
        {
            r++;
        } // 这个写法也不错，很简洁
        else // 否则就往右上走
        {
            r--;c++;
        }
    }
    string res;
    for(int i = 0; i < numRows; i++)
    {
        for(int c = 0; c < column; c++)
        {
            if(zig[i][c] != 0)
            {
                res += zig[i][c];
            }
        }
    }
    return res;
}

// 其实本质还是挺简单的，就是单纯的字符串模拟，但关键在于求出一个周期多少个字符，并且了解一共有多少个周期

// 了解这个之后就是直接用两个坐标模拟即可。