/*
外国友人仿照中国字谜设计了一个英文版猜字谜小游戏，请你来猜猜看吧。

字谜的迷面 puzzle 按字符串形式给出，如果一个单词 word 符合下面两个条件，那么它就可以算作谜底：

单词 word 中包含谜面 puzzle 的第一个字母。
单词 word 中的每一个字母都可以在谜面 puzzle 中找到。
例如，如果字谜的谜面是 "abcdefg"，那么可以作为谜底的单词有 "faced", "cabbage", 和 "baggage"；而 "beefed"（不含字母 "a"）以及 "based"（其中的 "s" 没有出现在谜面中）。
返回一个答案数组 answer，数组中的每个元素 answer[i] 是在给出的单词列表 words 中可以作为字谜迷面 puzzles[i] 所对应的谜底的单词数目。

 

示例：

输入：
words = ["aaaa","asas","able","ability","actt","actor","access"], 
puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
输出：[1,1,3,2,4,0]
解释：
1 个单词可以作为 "aboveyz" 的谜底 : "aaaa" 
1 个单词可以作为 "abrodyz" 的谜底 : "aaaa"
3 个单词可以作为 "abslute" 的谜底 : "aaaa", "asas", "able"
2 个单词可以作为 "absoryz" 的谜底 : "aaaa", "asas"
4 个单词可以作为 "actresz" 的谜底 : "aaaa", "asas", "actt", "access"
没有单词可以作为 "gaswxyz" 的谜底，因为列表中的单词都不含字母 'g'。
 

提示：

1 <= words.length <= 10^5
4 <= words[i].length <= 50
1 <= puzzles.length <= 10^4
puzzles[i].length == 7
words[i][j], puzzles[i][j] 都是小写英文字母。
每个 puzzles[i] 所包含的字符都不重复。
通过次数3,211提交次数8,694

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-valid-words-for-each-puzzle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;
// 考点是状态压缩（素数打表和哈希）与子集枚举（位操作）
vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) 
{
    // 首先注意到每个puzzle的长度都为7
    int k = 7;
    // 定义一个素数映射，作为简短的哈希压缩结果（即唯一分解定理）
    vector<int> primeDict = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
    unordered_map<long, int> hashed; // 用于存储某个哈希值（words谜底）的数量
    // 对每一个word进行排序并去重，即得到唯一的哈希表达
    for(auto word : words)
    {
        sort(word.begin(), word.end());
        //auto it = unique(word.begin(), word.end());
        word.erase(unique(word.begin(), word.end()), word.end());
        if(word.size() <= k)
        {
            long s = 1;
            for(auto& c : word)
            {
                s *= primeDict[c - 'a']; // 映射到一个唯一的哈希值
            }
            hashed[s]++; // 代表这一种哈希值的个数
        }
    }
    vector<int> res;
    for(auto& puzzle : puzzles)
    {
        int cnt = 0;
        for(int i = 0; i < (1 << (k - 1)); i++)
        {
            long s = primeDict[puzzle[0] - 'a'];
            for(int j = 0; j < k - 1; j++) // 枚举子集
            {
                if((i >> j) & 1) // 对选中的子集进行标记
                {
                    s *= primeDict[puzzle[j + 1] - 'a'];
                }
            }
            if(hashed.count(s))
            {
                cnt += hashed[s];
            }
        }
        res.push_back(cnt);
    }
    return res;
}