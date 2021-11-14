/*
实现一个 MapSum 类，支持两个方法，insert 和 sum：

MapSum() 初始化 MapSum 对象
void insert(String key, int val) 插入 key-val 键值对，字符串表示键 key ，整数表示值 val 。如果键 key 已经存在，那么原来的键值对将被替代成新的键值对。
int sum(string prefix) 返回所有以该前缀 prefix 开头的键 key 的值的总和。
 

示例：

输入：
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
输出：
[null, null, 3, null, 5]

解释：
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);  
mapSum.sum("ap");           // return 3 (apple = 3)
mapSum.insert("app", 2);    
mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
 

提示：

1 <= key.length, prefix.length <= 50
key 和 prefix 仅由小写英文字母组成
1 <= val <= 1000
最多调用 50 次 insert 和 sum
通过次数23,511提交次数36,480

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/map-sum-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <unordered_map>
using namespace std;

struct Trie {
    int val;
    Trie* next[26];
    Trie()
    {
        this->val = 0;
        for(int i = 0; i < 26; i++)
        {
            this->next[i] = nullptr;
        }
    }
};

class MapSum {
public:
    MapSum() 
    {
        this->root = new Trie();
    }
    
    void insert(string key, int val) 
    {
        int delta = val;
        if(rec.count(key))
        {
            delta -= rec[key]; // 路径上要变化的值
        }
        rec[key] = val;
        Trie* node = root;
        for(char& c : key)
        {
            if(node->next[c- 'a'] == nullptr)
            {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
            node->val += delta; // 整个路径上都要变化，注意每次插入新的key，都会形成若干个完全不同的路径的树
            // 不会存在相同字母的node被多次累加的情况
            // 只有相同前缀的才会出现node复用的情况（这也是字典树的本意）
        }
    }
    
    int sum(string prefix) 
    {
        Trie* node = root;
        for(char& c : prefix)
        {
            if(node->next[c - 'a'] == nullptr) // 如果路径上出现了没见过的点，直接退出
            {
                return 0;
            }
            else
            {
                node = node->next[c - 'a']; // 因为本题的字典树本质上就是前缀和，因此每个结点的值就是前缀和
            }   
        }
        return node->val;
    }

private:
    Trie* root;
    unordered_map<string, int> rec;
};

// 可以先从哈希表的方法开始想起，即接近于暴力前缀和的方法，搞一张很大的哈希表 以及 遍历每个前缀 立项