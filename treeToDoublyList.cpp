/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

 

为了让您更好地理解问题，以下面的二叉搜索树为例：

 



 

我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。

下图展示了上面的二叉搜索树转化成的链表。“head” 表示指向链表中有最小元素的节点。

 



 

特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。

 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};


Node *dummy = new Node(-1), *cur = dummy;

Node* treeToDoublyList(Node* root) 
{
    if(root == nullptr)
    {
        return nullptr; //佛了这测试样例
    }
    construct(root);
    cur->right = dummy->right;
    dummy->right->left = cur;
    return dummy->right;
}

void construct(Node* node)
{
    if(node == nullptr)
    {
        return;
    }
    construct(node->left); // 中序遍历 直接写
    cur->right = node; //这里就是正常的接到下一个节点
    node->left = cur; // 这里也是正常的接到上一个节点
    // 注意, 这里是否需要考虑cur==dummy的情况呢, 其实不用
    // 因为这里即使node->left指到了dummy上, 最后递归结束的时候
    // 还是会让dummy->right->left手动改到最后一个节点上面, 所以其实不用判断
    cur = cur->right;
    construct(node->right);
}