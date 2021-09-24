/*
多级双向链表中，除了指向下一个节点和前一个节点指针之外，它还有一个子链表指针，可能指向单独的双向链表。这些子列表也可能会有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。

给你位于列表第一级的头节点，请你扁平化列表，使所有结点出现在单级双链表中。

 

示例 1：

输入：head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
输出：[1,2,3,7,8,11,12,9,10,4,5,6]
解释：

输入的多级列表如下图所示：



扁平化后的链表如下图：


示例 2：

输入：head = [1,2,null,3]
输出：[1,3,2]
解释：

输入的多级列表如下图所示：

  1---2---NULL
  |
  3---NULL
示例 3：

输入：head = []
输出：[]
 

如何表示测试用例中的多级链表？

以 示例 1 为例：

 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
序列化其中的每一级之后：

[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
为了将每一级都序列化到一起，我们需要每一级中添加值为 null 的元素，以表示没有节点连接到上一级的上级节点。

[1,2,3,4,5,6,null]
[null,null,7,8,9,10,null]
[null,11,12,null]
合并所有序列化结果，并去除末尾的 null 。

[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
 

提示：

节点数目不超过 1000
1 <= Node.val <= 10^5
通过次数24,654提交次数44,463


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

void dfs(Node* curr, vector<Node*>& nodes)
{
    if(curr == nullptr) return;
    nodes.push_back(curr);
    dfs(curr->child, nodes); // 先child，即先深层再dfs
    dfs(curr->next, nodes);
}

Node* flatten(Node* head) 
{
    vector<Node*> nodes;
    dfs(head, nodes);
    for(int i = 0; i < nodes.size(); i++)
    {
        // 对节点进行连接
        if(i < nodes.size() - 1)
        {
            nodes[i]->next = nodes[i + 1];
        }
        if(i > 0)
        {
            nodes[i]->prev = nodes[i - 1];
        }
        nodes[i]->child = nullptr;
    }
    return head; // 因为head就存在vector的第一个，所以可以直接返回；但是不能返回nodes[0]，因为可能是空链表
}

// 其实本质上就是dfs，无非是dfs的对象结构看起来有点复杂

// 而且一旦涉及到重构链表，比较好的方法就是用一个vector来存, 然后对这个vector里的节点进行

// 因此本题就是，先用dfs得到节点，然后用一个循环来重构链表

// 感觉这题的情景挺实际，而且代码也不多，适合面试出