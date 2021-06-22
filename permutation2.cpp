/*
输入一个字符串，打印出该字符串中字符的所有排列。

 

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

 

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
 

限制：

1 <= s 的长度 <= 8

通过次数107,946提交次数190,291

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string> 
#include <set>
using namespace std;

void dfs(vector<string>& res, string s, int pos) // 无需string&，因为在递归内就保存了变量
{
    if(pos == s.length() - 1) // 递归结束，一种排列已经形成
    {
        res.push_back(s);
        return;
    }
    set<int> unique_chars;
    for(int i = pos; i < s.length();i ++)
    {
        if(unique_chars.find(s[i]) != unique_chars.end()) // 若有某个字符已经出现过（在set中），说明那个字符对应的排列已经考虑到了
        {
            continue; // 所以就剪枝，不考虑这个相同字符的了
        }
        unique_chars.insert(s[i]); // 记录所有考虑到的字符
        swap(s[i], s[pos]); // 交换，i=pos时，相当于固定当前第一个位置的字符
        dfs(res, s, pos + 1); // 开启新的递归
        swap(s[i], s[pos]); // 交换回来，恢复现场，从而使循环继续往后
    }
}

vector<string> permutation(string s) 
{
    vector<string> res;
    dfs(res, s, 0);
    return res;
}

// 一道经典题，但网上所谓的好题解写的怎么都和xx一样

// 要解这道题，需要思考一个字符串全排列究竟是怎么产生的；

// 一种方法就是，将第一个位置的字符与后面所有字符逐个交换，这样就能产生关于第一个位置的n种排列（连上自己）；以此类推，将第二个位置的字符与后面所有字符排列，在第一个位置字符固定的条件下

// 就有n-1种排列（同样算上自己），然后固定第二个位置字符，对第三个位置的字符作同样操作；此时应该能意识到一个递归的雏形了

// dfs(res, s, pos), 其中s即为要操作的字符串，pos为要固定第几个位置；那么要推进递归的进程，就是要把pos及其后面每个字符分别交换，即pos+1， pos+2等

// 每交换一个，就有一个新的递归起点，即再次调用dfs(res, s, pos + 1)，此时的s是有两字符交换过的s

// 那么当pos == length - 1时，就形成了一个全排列