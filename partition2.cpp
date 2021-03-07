/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]
通过次数67,971提交次数96,034

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include <vector>
#include <string>
#include <deque>

using namespace std;



// 使用索引而非子串for循环，是因为每次截取子串会有额外的性能损耗
bool isPalindrome(string& target, int begin, int end)
{
    while(begin < end)
    {
        if(target[begin] != target[end])
        {
            return false;
        }
        begin++;
        end--;
    }
    return true;
}

void dfs(string& s, int index_begin, int len, deque<string> dfs_path, vector<vector<string>>& result) // 注意这的引用
{
    if(index_begin == len) // 在这种分隔递归树下，最终达到了字符串末尾，说明是一种满足题意的分隔
    {
        result.push_back(vector<string>(dfs_path.begin(), dfs_path.end())); // 转化为vector后存储到结果中
        return;
    }
    for(int i = index_begin; i < len; i++) // 对每一个位置上的分隔进行判断，
    {
        if(!isPalindrome(s, index_begin, i)) // 判断这个分隔得到的前缀是否符合，要不符合直接下一种分隔
        {
            continue;
        }
        dfs_path.push_back(s.substr(index_begin, i + 1 - index_begin)); //当前分隔符合了，然后将这个前缀放入path中
        dfs(s, i + 1, len, dfs_path, result); // 对当前这个分隔后的后缀子串继续递归判断
        dfs_path.pop_back(); // 每次dfs后，都需把刚才添加进去的一种情况给pop出来，即回溯到上一个状态，然后才能进行下一次测试
    }
}

vector<vector<string>> partition(string s) 
{
    vector<vector<string>> result;
    deque<string> dfs_path;
    int len = s.length();
    dfs(s, 0, len, dfs_path, result);
    return result;
}