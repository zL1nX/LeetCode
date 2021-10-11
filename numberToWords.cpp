/*
将非负整数 num 转换为其对应的英文表示。

 

示例 1：

输入：num = 123
输出："One Hundred Twenty Three"
示例 2：

输入：num = 12345
输出："Twelve Thousand Three Hundred Forty Five"
示例 3：

输入：num = 1234567
输出："One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
示例 4：

输入：num = 1234567891
输出："One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
 

提示：

0 <= num <= 231 - 1
通过次数14,501提交次数43,616

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/integer-to-english-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <vector>

using namespace std;

vector<string> singles = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
vector<string> thousands = {"", "Thousand", "Million", "Billion"};

string numberToWords(int num) 
{
    if(num == 0) return "Zero";
    string res = "";
    for(int group = 3, unit = 1e9; group >= 0; group--, unit /= 1000)
    {
        int currNum = num / unit; // 获取当前这三位数，即多少个thousand、million或billion
        if(currNum != 0)
        {
            num -= currNum * unit; 
            res += groupNumToWords(currNum) + thousands[group] + " "; // 这三位数对应的是啥
        }
    }
    while(res.back() == ' ')
    {
        res.pop_back();
    }
    return res;
}

string groupNumToWords(int num)
{
    string res = "";
    int hundred = num / 100;
    num %= 100;
    if(hundred != 0)
    {
        res += singles[hundred] + " Hundred ";
    }
    int ten = num / 10;
    if(ten >= 2) 
    {
        res += tens[ten] + " ";
        num %= 10;
    }
    if(num > 0 && num < 10)
    {
        res += singles[num] + " ";
    }
    else if(num >= 10) // 说明之前没有进那个判断，即小于20，则可以直接转换
    {
        res += teens[num - 10] + " ";
    }
    return res;
}

// 字符串模拟题，也太鸡儿复杂了

// 不过学习到了两点：英文数字可以三位为一组进行划分
    // 此时就可以用循环+除法来定位是到了哪一组，然后用thousands里面的词对应上即可（其实是三组，因此group=3）

// 第二点，对一个三位数进行到英文的转化：小于20的可以直接转换，这点也额外注意

// 还好题目里没有让加and，否则还要更难写一点