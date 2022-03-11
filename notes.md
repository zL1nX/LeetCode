# 部分题目记录
> 按照知识点归类不同题目，方便后续集中查看回忆

## 链表
- 206反转链表 [reverseList.cpp](./reverseList.cpp)
  - 递归的美妙写法，`reverse(head->next)`
- 876链表的中间结点 [middleNode.cpp](./middleNode.cpp)
  - 每次快指针比慢指针多走一步，慢指针就自然到中间了
- 面试题02.01.移除重复节点 [removeDuplicateNodes](./removeDuplicateNodes.cpp)
  - 删除节点 + 哈希表，这两个东西结合一下，会产生很多容易写错的细节，多注意一些
