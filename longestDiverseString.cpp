/*
如果字符串中不含有任何 'aaa'，'bbb' 或 'ccc' 这样的字符串作为子串，那么该字符串就是一个「快乐字符串」。

给你三个整数 a，b ，c，请你返回 任意一个 满足下列全部条件的字符串 s：

s 是一个尽可能长的快乐字符串。
s 中 最多 有a 个字母 'a'、b 个字母 'b'、c 个字母 'c' 。
s 中只含有 'a'、'b' 、'c' 三种字母。
如果不存在这样的字符串 s ，请返回一个空字符串 ""。

 

示例 1：

输入：a = 1, b = 1, c = 7
输出："ccaccbcc"
解释："ccbccacc" 也是一种正确答案。
示例 2：

输入：a = 2, b = 2, c = 1
输出："aabbc"
示例 3：

输入：a = 7, b = 1, c = 0
输出："aabaa"
解释：这是该测试用例的唯一正确答案。
 

提示：

0 <= a, b, c <= 100
a + b + c > 0
通过次数7,697提交次数14,265

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-happy-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
using namespace std;


string longestDiverseString(int a, int b, int c) 
{
    vector<pair<int, char>> p = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
    string res = "";
    while(true)
    {
        sort(p.begin(), p.end(), [&](const pair<int, int>&a, const pair<int, int>& b){
            return a.first > b.first;
        });
        bool goOn = false; // 这个标识变量是每次循环都重新生成一个来表示这轮还能不能继续
        for(auto& [num, ch] : p)
        {
            if(num <= 0)
            {
                break; // we need all three kinds of chars
            }
            int curr = res.size();
            if(curr >= 2 && res[curr - 2] == ch && res[curr - 1] == ch)
            {
                continue; // next char, please
            }
            // everything is ok, add this char
            res.push_back(ch);
            goOn = true;
            num --;
            break; // as long as we find the suitable char, we go into the next round;
        }
        if(!goOn)
        {
            break;
        }
    }
    return res;
}
// 题目的这种不断增加新的字符进去的情景，感觉就像是不断排序然后放进去，但写起来还不好写

// 本来想着用类似于set的方式始终维护一个有序的pair这样就不用每次sort了

// 题解的做法其实就是，每次循环，循环内部开始将pair从大到小排序，之后遍历这些pair（自然就是贪心的顺序）

// 如果当前pair的字符还有值，并且前两个字符不是当前字符，那么就放进去。否则的话直接退出（或者继续）循环

// 然而，只要找到一个符合条件的pair，在处理完相关的变量后其实也是直接退出循环，只不过退出之后还能继续。其他情况退出了那就真退出了
