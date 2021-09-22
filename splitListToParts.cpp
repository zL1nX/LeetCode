/*
给你一个头结点为 head 的单链表和一个整数 k ，请你设计一个算法将链表分隔为 k 个连续的部分。

每部分的长度应该尽可能的相等：任意两部分的长度差距不能超过 1 。这可能会导致有些部分为 null 。

这 k 个部分应该按照在链表中出现的顺序排列，并且排在前面的部分的长度应该大于或等于排在后面的长度。

返回一个由上述 k 部分组成的数组。

 
示例 1：


输入：head = [1,2,3], k = 5
输出：[[1],[2],[3],[],[]]
解释：
第一个元素 output[0] 为 output[0].val = 1 ，output[0].next = null 。
最后一个元素 output[4] 为 null ，但它作为 ListNode 的字符串表示是 [] 。
示例 2：


输入：head = [1,2,3,4,5,6,7,8,9,10], k = 3
输出：[[1,2,3,4],[5,6,7],[8,9,10]]
解释：
输入被分成了几个连续的部分，并且每部分的长度相差不超过 1 。前面部分的长度大于等于后面部分的长度。
 

提示：

链表中节点的数目在范围 [0, 1000]
0 <= Node.val <= 1000
1 <= k <= 50
通过次数27,149提交次数47,114

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-linked-list-in-parts
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<ListNode*> splitListToParts(ListNode* head, int k) 
{
    ListNode *p = head, *q = head;
    int n = 0;
    vector<ListNode*> parts(k);
    while(p){
        n ++;
        p = p->next;
    }
    p = nullptr;
    int extraNum = n % k;
    for(int i = 0; i < k; i++)
    {
        parts.push_back(q);
        int nodeNum = extraNum > 0 ? n / k + 1 : n / k;
        for(int j = 0; j < nodeNum; j++)
        {
            p = q;
            q = q->next;
        }
        if(p) // 记得加这个判断，否则一个null的pointer是不存在next成员的
        {
            p->next = nullptr; // 将p next置空，表示结束当前这若干个节点
            // 此时q仍指向的是第一个开始的节点
        }
        extraNum--;
    }
    return parts;
}

// p q分别设置为快慢指针，然后用一个双层循环来添加节点

// 内层循环结束后，p此时指向了最后一个节点，因此要将p next设置为null

// 之后q继续遍历。因为默认就是nullptr，所以直接加入即可

// 代码里的nodeNum写法比较精简