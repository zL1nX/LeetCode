/*
给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。

注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。

 

示例 1：

输入：nums = [10,2]
输出："210"
示例 2：

输入：nums = [3,30,34,5,9]
输出："9534330"
示例 3：

输入：nums = [1]
输出："1"
示例 4：

输入：nums = [10]
输出："10"
 

提示：

1 <= nums.length <= 100
0 <= nums[i] <= 109
通过次数61,479提交次数159,190

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <vector>
using namespace std;
bool comp(string a, string b)
{
    int n = a.length(), m = b.length();
    int p = 0, q = 0;
    while(p < n && q < m)
    {
        if(a[p] > a[q])
        {
            return true;
        }
        else if(a[p] < a[q])
        {
            return false;
        }
        else
        {
            p++;
            q++;
        }
    }
    if(p < n) return false;
    else if(q < m) return true;
}
// 我一直想着用传统方法能不能搞，但最主要的问题在于长度的判断

bool comp2(string a, string b)
{
    return a + b > b + a ? true : false; // 用加起来的方法巧妙地规避了这种长度的差异
}
// 这个排序方法是真的妙
string largestNumber(vector<int>& nums) 
{
    string res = "";
    vector<string> snum;
    for(int i = 0; i < nums.size(); i++)
    {
        snum.push_back(to_string(nums[i]));
    }
    sort(snum.begin(), snum.end(), comp2);
    for(string s : snum)
    {
        if(!(s == "0" && res[0] == '0')) // 注意这里00要变成0
        {
            res += s;
        }
    }
    return res;
}