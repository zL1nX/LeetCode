# 部分题目记录
> 按照知识点归类不同题目，方便后续集中查看回忆

## 链表
- 206反转链表 [reverseList.cpp](./reverseList.cpp)
  - 递归的美妙写法，`reverse(head->next)`, node->next成了最后一个节点, 注意reverse函数的定义
  - **相同题目**: [JZOffer24-反转链表](./reverseList2.cpp), [JZOffer24II-反转链表](./reverseList3.cpp)
  - **相似题目**: [92-反转链表 II](./reverseBetween2.cpp), firstNode节点的定义, 以及先反转前N个节点(比较烧脑的递归)

> 注意: 递归虽然代码非常美妙, 理解也挺烧脑, 但效率是不如迭代的, 要真面试的话, 还是得准备一手迭代的解法


- 876链表的中间结点 [middleNode.cpp](./middleNode.cpp)
  - 每次快指针比慢指针多走一步，慢指针就自然到中间了
- 面试题 02.02. 返回倒数第 k 个节点 [kthToLast](./kthToLast.cpp)
  - 和上面一道题类似,也是快慢指针,让快指针先走k步,慢指针再开始走,经典的思路
- 面试题02.01.移除重复节点 [removeDuplicateNodes](./removeDuplicateNodes.cpp)
  - 删除节点 + 哈希表，这两个东西结合一下，会产生很多容易写错的细节，多注意一些
- JZOffer18. 删除链表的节点 [deleteNode](./deleteNode3.cpp)
  - 单纯的单链表节点删除, 注意dummy节点的设置以及删除完后直接break
- 面试题02.06 回文链表 [isPalindrome](./isPalindromeList.cpp)
  - 链表也能后序遍历？能后序遍历就能实现回文（在递归中left向后走，right每层递归结束都会向前）。非常妙
- 剑指Offer 06. 从尾到头打印链表 [reversePrint](./reversePrint.cpp)
  - 链表的后序遍历（递归法），就是上面那道题的简化版
- 面试题 02.07. 链表相交 [getIntersectionNode](./getIntersectionNode3.cpp)
  - 经典的相交链表问题, 当一个指针走完自己的链表时,让它去遍历另外的链表,这相当于对两条链表的不同部分取并集. 非常经典的思路
  - **相同题目**: [JZOfferII023-两个链表的第一个重合节点](./getIntersectionNode4.cpp) (注意**如果没有相交节点时要返回null时**该怎么办)
- 剑指Offer 25-合并两个排序的链表 [mergeTwoLists](./mergeTwoLists.cpp)
  - 一个while循环 + 两个if判断; 关键在于新链表指针每次都是`cur->next`去操作,cur只用移到`cur->next`即可,省去了空节点的麻烦