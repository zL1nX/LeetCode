/*
给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。

字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。

 

示例 1：



输入：text = "nlaebolko"
输出：1
示例 2：



输入：text = "loonbalxballpoon"
输出：2
示例 3：

输入：text = "leetcode"
输出：0
 

提示：

1 <= text.length <= 10^4
text 全部由小写英文字母组成
通过次数26,429提交次数39,974

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-balloons
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <unordered_map>

using namespace std;

int maxNumberOfBalloons(string text) 
{
    unordered_map<char, int> rec;
    for(char& c : text)
    {
        rec[c]++;
    }
    int mint = text.length();
    string target = "balloon";
    for(char& c : target)
    {
        int times = rec[c];
        if(c == 'o' || c == 'l')
        {
            times /= 2;
        }
        mint = min(mint, times);
    }
    return mint;
}

// 先哈希表统计频率，再遍历balloon依次看每个频率值是啥

// 注意其中 o与 l因为出现了两次所以要除以2

// 取出现的所有次数的最小值（木桶原理）