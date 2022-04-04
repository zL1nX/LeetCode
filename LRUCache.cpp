/*
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

 

示例：

输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4
 

提示：

1 <= capacity <= 3000
0 <= key <= 10000
0 <= value <= 105
最多调用 2 * 105 次 get 和 put
通过次数321,431提交次数610,763

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lru-cache
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <unordered_map>
#include <iostream>

using namespace std;

struct Node
{
    int key;
    int val;
    Node *next, *prev;
    Node(int k, int v)
    {
        key = k;
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};

class DoubleList
{
private:
    int size;
    Node *head, *tail;
public:
    DoubleList()
    {
        head = new Node(0, 0); // dummy head
        tail = new Node(0, 0); // dummy tail
        size = 0;
        head->next = tail;
        tail->prev = head;
    }

    int getSize()
    {
        return this->size;
    }

    void addLast(Node *x)
    {
        // 先把新的节点x接上去
        x->prev = tail->prev;
        x->next = tail;

        // 再把原来的链接给更新下
        tail->prev->next = x;
        tail->prev = x; // 注意这句需要在后面, 否则上面那句就相当于next指到了自己

        size += 1;
    }

    void remove(Node *x)
    {
        // 删除比较好理解
        x->prev->next = x->next;
        x->next->prev = x->prev;
        size -= 1;
    }

    void output(Node *x)
    {
        cout << "cache " << x->prev->key << " " << x->key << " " << x->next->key << endl;
    }

    Node* removeFirst()
    {
        if(head->next == tail)
        {
            return nullptr;
        }
        Node *first = head->next;
        cout << "removeFirst " << first->key << endl;
        remove(first);
        return first;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> rec;
    DoubleList* cache;
    int capacity;
    
    void makeRecent(int key)
    {
        Node *node = rec[key];
        cache->remove(node);
        cache->addLast(node);
        //cout << "recent " << key << endl;
    }

    void addRecent(int key, int val)
    {
        Node *x = new Node(key, val);
        cache->addLast(x);
        rec[key] = x;
    }

    void deleteKey(int key)
    {
        Node *x = rec[key];
        cache->remove(x);
        rec.erase(key);
    }

    void removeLastRecent()
    {
        Node *deleteNode = cache->removeFirst();
        int deletedKey = deleteNode->key;
        cout << "deletedKey " << deletedKey << endl;
        rec.erase(deletedKey);
    }

public:
    LRUCache(int capacity) 
    {
        this->capacity = capacity;
        this->rec.clear();
        cache = new DoubleList();
    }
    
    int get(int key) 
    {
        if(!rec.count(key))
        {
            return -1;
        }
        makeRecent(key);
        return rec[key]->val;
    }
    
    void put(int key, int val) 
    {
        cout << "before" << cache->getSize() << endl;
        if(rec.count(key))
        {
            deleteKey(key);
            addRecent(key, val);
            return;
        }

        if(capacity == cache->getSize())
        {
            cout << "remove " << key << endl;
            removeLastRecent();
        }
        addRecent(key, val);
        cout << "after " << cache->getSize() << endl;

    }
};


int main()
{
    LRUCache *o = new LRUCache(2);
    o->put(1, 1);
    o->put(2, 2); // 缓存是 {1=1, 2=2}
    cout << "out get " << o->get(1) << endl;    // 返回 1
    o->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << "out get " << o->get(2) << endl;    // 返回 -1 (未找到)
    return 0;
}