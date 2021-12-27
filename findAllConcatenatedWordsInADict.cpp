/*
给你一个 不含重复 单词的字符串数组 words ，请你找出并返回 words 中的所有 连接词 。

连接词 定义为：一个完全由给定数组中的至少两个较短单词组成的字符串。

 

示例 1：

输入：words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
输出：["catsdogcats","dogcatsdog","ratcatdogcat"]
解释："catsdogcats" 由 "cats", "dog" 和 "cats" 组成; 
     "dogcatsdog" 由 "dog", "cats" 和 "dog" 组成; 
     "ratcatdogcat" 由 "rat", "cat", "dog" 和 "cat" 组成。
示例 2：

输入：words = ["cat","dog","catdog"]
输出：["catdog"]
 

提示：

1 <= words.length <= 104
0 <= words[i].length <= 1000
words[i] 仅由小写字母组成
0 <= sum(words[i].length) <= 105
通过次数8,638提交次数20,713

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/concatenated-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <string>

using namespace std;

struct Trie 
{
    vector<Trie*> children;
    bool isEnd;
    Trie() {
        this->children = vector<Trie*>(26, nullptr);
        this->isEnd = false;
    }
};

Trie* trie = new Trie();

bool dfs(string word, int start)
{
    if(start == word.size())
    {
        return true;
    }
    Trie* cur = trie;
    for(int i = start; i < word.size(); i++)
    {
        int off = word[i] - 'a';
        cur = cur->children[off];
        if(cur == nullptr) // 字典树中还没出现过这个路径
        {
            return false;
        }
        if(cur->isEnd) // 当前词结束了
        {
            if(dfs(word, i + 1)) // 开始下一轮的搜索
            {
                return true;
            }
        }   
    }
    return false;
}

void insert(string& word)
{
    Trie* cur = trie;
    for(int i = 0; i < word.size(); i++)
    {
        int off = word[i] - 'a';
        if(cur->children[off] == nullptr)
        {
            cur->children[off] = new Trie();
        }
        cur = cur->children[off];
    }
    cur->isEnd = true;
}



vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
{
    sort(words.begin(), words.end(), [&](string a, string b){
        return a.size() < b.size();
    });
    vector<string> res;
    for(string& word : words)
    {
        if(word.size() == 0)
        {
            continue;
        }
        if(dfs(word, 0))
        {
            res.push_back(word);
        }
        else
        {
            insert(word);
        }
        
    }
    return res;
}

// 第一眼就知道是要用字典树（逃，但不知道该怎么实现对连接词的判断

// 字典树的结构与插入操作已经写过很多次了，这里就不再赘述了

// 实现连接词的判断，其实使用dfs来的，一个单词会对应着一条完整的dfs路径，如果碰到了一个完全没加到字典树中的结点，那么这个词肯定不是连接词（因为列表先排序了，比当前词短的词都已经加到字典树里了）

// 之后，要在字典树中就一直遍历下去，直到当前结点是一个词的最后一个结点，即isEnd出现了。这标志着当前词的确可以由一个更短的词表示，但这还没完

// 从下一个位置开始，继续dfs，如果后续的dfs结果还是正确的，说明当前词的确能分解成若干个不同的词

// 这个dfs虽然用在这里了，但这里更类似的是一种递归，或者是一种相同函数范式的思路，即借用字典树这种结构，判断当前单词的组成路径

// 刚开始的排序也很重要，因为这是保证了路径上判定条件的正确性