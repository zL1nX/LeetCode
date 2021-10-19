/*
请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。

实现词典类 WordDictionary ：

WordDictionary() 初始化词典对象
void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。word 中可能包含一些 '.' ，每个 . 都可以表示任何一个字母。
 

示例：

输入：
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
输出：
[null,null,null,null,false,true,true,true]

解释：
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

提示：

1 <= word.length <= 500
addWord 中的 word 由小写英文字母组成
search 中的 word 由 '.' 或小写英文字母组成
最多调用 50000 次 addWord 和 search

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-add-and-search-words-data-structure
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>

using namespace std;

class Trie 
{   
public:
    vector<Trie*> children;
    bool isEnd;
    Trie()
    {
        this->children = vector<Trie*>(26, nullptr);
        this->isEnd = false;
    }

    void insert(string word)
    {
        Trie* node = this;
        for(int i = 0; i < word.size();i++)
        {
            int index = word[i] - 'a';
            if(node->children[index] == nullptr)
            {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEnd = true; // 只有最后的子节点的这个成员才会是true
    }
};

class WordDictionary {
private:
    Trie* root;
public:
    WordDictionary() 
    {
        root = new Trie();
    }
    
    void addWord(string word) {
        root->insert(word);
    }

    bool dfs(string word, int loc, Trie* node)
    {
        if(loc == word.size())
        {
            return node->isEnd; // 只有最深层的子节点的isEnd才是true，上层的都是false
        }
        char ch = word[loc];
        if(ch >= 'a' && ch <= 'z')
        {
            Trie* child = node->children[ch - 'a'];
            if(child != nullptr && dfs(word, loc + 1, child))
            {
                return true;
            }
        }
        else
        {
            for(int i = 0; i < 26; i++) 
            {
                Trie* child = node->children[i];
                if(child != nullptr && dfs(word, loc + 1, child))
                {
                    return true; // 只要有一个符号条件的就true
                }
                // 就算不符合，这里也就先不管
            }
        }
        return false; // 只有两种情况都跑完之后，才能确认真的是false了
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};

// 看完题就知道应该是字典树了，这里再回顾一下字典树的写法，其实并不难，但要考虑好该怎么遍历

// 字典树的添加操作时比较容易的，就直接按照顺序新建即可，只不过这里多了个最后的isEnd flag来标识是否到了最后

// 而搜索虽然说是dfs，但就是普通的递归；按照子节点去不断地递归，如果不是字母而是点的话，就把所有子节点都递归一遍


