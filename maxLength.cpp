/*
给定一个字符串数组 arr，字符串 s 是将 arr 某一子序列字符串连接所得的字符串，如果 s 中的每一个字符都只出现过一次，那么它就是一个可行解。

请返回所有可行解 s 中最长长度。

 

示例 1：

输入：arr = ["un","iq","ue"]
输出：4
解释：所有可能的串联组合是 "","un","iq","ue","uniq" 和 "ique"，最大长度为 4。
示例 2：

输入：arr = ["cha","r","act","ers"]
输出：6
解释：可能的解答有 "chaers" 和 "acters"。
示例 3：

输入：arr = ["abcdefghijklmnopqrstuvwxyz"]
输出：26
 

提示：

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] 中只含有小写英文字母


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <string>
using namespace std;


// void backtrack(int pos, int &all_count, int& res, vector<int>& one_counts)
// {
//     if(pos == one_counts.size()) //
//     {
//         res = max(res, __builtin_popcount(all_count)); //
//         return;
//     }
//     int new_count = all_count;
//     if((one_counts[pos] & all_count) == 0)//
//     {
//         new_count |= one_counts[pos];
//     }
//     backtrack(pos + 1, new_count, res, one_counts);
// }

void backtrack(int pos, int all_count, int& res, vector<int>& one_counts)
{
    if(pos == one_counts.size()) //到了最后的位置
    {
        res = max(res, __builtin_popcount(all_count)); // 看下allcount里有多少个1，就是我们最终的结果
        return;
    }
    if((one_counts[pos] & all_count) == 0)// 如果当前数 和 已有数的与为0（即没有重合的位，没有一样的字符）（这写法真的屌）
    {
        backtrack(pos + 1, all_count | one_counts[pos], res, one_counts); // 就可以用|来加上去
    }
    backtrack(pos + 1, all_count, res, one_counts); // 注意这里并不是else，因为我上面代表选了pos，这个代表我也可以不选pos啊，所以这句是必然执行的
}

int maxLength(vector<string>& arr) 
{
    vector<int> one_counts;
    for(string& s: arr)
    {
        int one_count = 0;
        for(char& ch : s)
        {
            int c = ch - 'a'; // 代表这个字符，如果已经出现了这个字符了，那么下面的判断必然会触发（这位被置了1）
            if((one_count >> c) & 1)
            {
                one_count = 0;
                break;
            }
            one_count |= (1 << c); // 用或来实现加（哎，我怎么写不出这种代码呢）
        }
        if(one_count > 0) // 当大于0时，和上面等于0呼应了，再加进去
        {
            one_counts.push_back(one_count);
        }
    }// 用多少个1来表示多少个不同的字符（牛蛙），然后用位运算来高效实现（更牛蛙）
    int res = 0;
    backtrack(0, 0, res, one_counts);
    return res;
}

// 回溯啥回溯，明明就是DFS