/*
给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

 

示例 1：


输入：board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
输出：["eat","oath"]
示例 2：


输入：board = [["a","b"],["c","d"]], words = ["abcb"]
输出：[]
 

提示：

m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] 是一个小写英文字母
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] 由小写英文字母组成
words 中的所有字符串互不相同
通过次数48,203提交次数105,695


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

struct TrieNode {
    string word;
    unordered_map<char, TrieNode*> children;
    TrieNode() {
        this->word = "";
    }
};

void insertTrie(TrieNode *root, string word)
{
    TrieNode *node = root;
    for(char& c : word)
    {
        if(!node->children.count(c))
        {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->word = word;
}

int moves[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(TrieNode* node, vector<vector<char>>& board, int i, int j, set<string>& res)
{
    char currCh = board[i][j];
    if(!node->children.count(currCh))
    {
        return;
    }
    node = node->children[currCh]; // 
    if(node->word.size() > 0)
    {
        res.insert(node->word);
    }
    board[i][j] = '#'; //
    for(int c = 0; c < 4;c ++)
    {
        int ni = i + moves[c][0], nj = j + moves[c][1];
        if(ni >= 0 && nj >= 0 && ni < board.size() && nj < board[0].size())
        {
            if(board[ni][nj] != '#')
            {
                dfs(node, board, ni, nj, res);
            }
        }
    }
    board[i][j] = currCh;
    return;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
{
    TrieNode* root = new TrieNode();
    set<string> res;
    for(auto& word : words)
    {
        insertTrie(root, word);
    }
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            dfs(root, board, i, j, res);
        }
    }
    vector<string> result;
    for(auto& w : res)
    {
        result.push_back(w);
    }
    return result;
}