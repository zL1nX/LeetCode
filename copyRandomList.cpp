/*
给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。

构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。

例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random --> y 。

返回复制链表的头节点。

用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：

val：一个表示 Node.val 的整数。
random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
你的代码 只 接受原链表的头节点 head 作为传入参数。

 

示例 1：



输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
示例 2：



输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]
示例 3：



输入：head = [[3,null],[3,0],[3,null]]
输出：[[3,null],[3,0],[3,null]]
示例 4：

输入：head = []
输出：[]
解释：给定的链表为空（空指针），因此返回 null。
 

提示：

0 <= n <= 1000
-10000 <= Node.val <= 10000
Node.random 为空（null）或指向链表中的节点。
通过次数84,997提交次数134,583
请问您在哪类招聘中遇到此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/copy-list-with-random-pointer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <unordered_map>

using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

Node* copyRandomList(Node* head) 
{
    Node *dummy = new Node(-1);
    Node *tail = dummy, *tmp = head;
    unordered_map<Node*, Node*> rec;
    while(tmp != nullptr)
    {
        Node *newNode = new Node(tmp->val); 
        rec[tmp] = newNode;// 新旧节点的映射关系
        tail->next = newNode; // 新链表的增长

        tail = tail->next;
        tmp = tmp->next;
    }
    tail = dummy->next;
    while(head != nullptr)
    {
        if(head->random)
        {
            tail->random = rec[head->random]; // 取random对应的节点
        }
        tail = tail->next;
        head = head->next;
    }
    return dummy->next;
    
}

// 假如没有random，那么直接设个dummy然后顺序复制就完了（第一个循环）

// 但是有个random，而且random中的包含关系，如果在一次遍历时就想复制过来，困难就在于你不能预先声明出某个节点啊

// 因此朴素的方法一定需要遍历两次才可以

// 第一次遍历把新旧节点的映射关系保存下来，这样可以方便的获取一个新节点

// 第二次遍历根据取每个random对应的新节点，然后赋值上去即可