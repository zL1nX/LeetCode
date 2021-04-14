/*
Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。

请你实现 Trie 类：

Trie() 初始化前缀树对象。
void insert(String word) 向前缀树中插入字符串 word 。
boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。
 

示例：

输入
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
输出
[null, null, true, false, true, null, true]

解释
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 True
trie.search("app");     // 返回 False
trie.startsWith("app"); // 返回 True
trie.insert("app");
trie.search("app");     // 返回 True
 

提示：

1 <= word.length, prefix.length <= 2000
word 和 prefix 仅由小写英文字母组成
insert、search 和 startsWith 调用次数 总计 不超过 3 * 104 次
通过次数86,126提交次数122,285


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-trie-prefix-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <stdlib.h>

using namespace std;

class Trie {
private:
    bool isEnd;
    Trie* next[26];

public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this; // 这种方法可以取到当前对象
        for(char c : word)
        {
            int loc = c - 'a';
            if(node->next[loc] == nullptr)
            {
                node->next[loc] = new Trie();
            }
            node = node->next[loc];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) { // word应完整的存在并覆盖于树中
        Trie* node = this;
        for(char c : word)
        {
            int loc = c - 'a';
            node = node->next[loc];
            if(node == nullptr)
            {
                return false;
            }
        }
        return node->isEnd; // 因此当word遍历完后，应该也到了树的一个分支的最后
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) { // 前缀的话，只用让前缀在树中即可，树不一定到最后
        Trie* node = this;
        for(char c : prefix)
        {
            int loc = c - 'a';
            node = node->next[loc];
            if(node == nullptr)
            {
                return false;
            }
        }
        return true;
    }
};