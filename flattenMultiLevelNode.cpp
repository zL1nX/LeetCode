/*
多级双向链表中，除了指向下一个节点和前一个节点指针之外，它还有一个子链表指针，可能指向单独的双向链表。这些子列表也可能会有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。

给定位于列表第一级的头节点，请扁平化列表，即将这样的多级双向链表展平成普通的双向链表，使所有结点出现在单级双链表中。

 

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

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/Qv1Da2
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


using namespace std;

class Node 
{
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


Node* flatten(Node* head) 
{
    dfs(head);
    return head;
}

Node* dfs(Node* cur) // dfs的定义是, 将输入节点的整个序列child展平, 然后返回这个序列的最后一个节点 (即最后一个child)
{
    Node* lastNode = nullptr;
    Node* node = cur;
    while(node != nullptr)
    {
        Node* nnext = node->next; // 先提前保存一份指向原有后面节点的指针
        if(node->child != nullptr)
        {
            Node* child = node->child; // child序列的第一个孩子
            Node* childLast = dfs(node->child); // dfs深搜, 类似于前序遍历, 优先处理child序列
            // dfs之后返回的是当前这个child序列的最后一个孩子, 下面的工作就是要将这最后一个孩子链到主链上

            // 原有node的next肯定要接到第一个孩子上
            node->next = child;
            child->prev = node; // 别忘了这还是个双向链表
            
            // 如果原有node还有后继的话, 需要把最后一个孩子连接到主链上
            if(nnext != nullptr)
            {
                nnext->prev = childLast;
                childLast->next = nnext; // 同理, 和上面的操作是类似的
            }
            
            // 最后, 别忘了原有的child指针要置空, 因为我们目前是只有一条路径, 原来的next也改到了child上
            node->child = nullptr;
            // 更新主链的lastnode为目前这个node的最后一个孩子
            lastNode = childLast;
        }
        else // 要是当前节点没孩子的话, 那last就设置为这个节点然后继续
        {
            lastNode = node;
        }
        node = nnext;
    }
    return lastNode;
}


// 看完题目, 那必然是要用DFS的方法去做, DFS的思路就是, 只要当前节点有child, 

// 就先展平child, 然后继续遍历, 只不过记得将child给勾连到当前的主链上面

// 其实这道题也是, 锚定了dfs的定义, 然后处理dfs之后的链即可

// lastNode的定义是核心