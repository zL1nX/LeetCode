# 部分题目记录
> 按照知识点归类不同题目，方便后续集中查看回忆

## 链表
- 206反转链表 [reverseList.cpp](./reverseList.cpp)
  - 递归的美妙写法，`reverse(head->next)`
- 876链表的中间结点 [middleNode.cpp](./middleNode.cpp)
  - 每次快指针比慢指针多走一步，慢指针就自然到中间了
- 面试题02.01.移除重复节点 [removeDuplicateNodes](./removeDuplicateNodes.cpp)
  - 删除节点 + 哈希表，这两个东西结合一下，会产生很多容易写错的细节，多注意一些
- 面试题02.06 回文链表 [isPalindrome](./isPalindromeList.cpp)
  - 链表也能后序遍历？能后序遍历就能实现回文（在递归中left向后走，right每层递归结束都会向前）。非常妙
- 剑指Offer 06. 从尾到头打印链表 [reversePrint](./reversePrint.cpp)
  - 链表的后序遍历（递归法），就是上面那道题的简化版
- 面试题 02.07. 链表相交 [getIntersectionNode](./getIntersectionNode3.cpp)
  - 经典的相交链表问题, 当一个指针走完自己的链表时,让它去遍历另外的链表,这相当于对两条链表的不同部分取并集. 非常经典的思路