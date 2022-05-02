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
  - **相似题目**
    - [JZOfferII021-删除链表的倒数第 n 个结点](./removeNthFromEnd2.cpp), slow指向删的节点, 并保存一个前驱指针, 如果要删除头节点该怎么办
- 面试题02.01.移除重复节点 [removeDuplicateNodes](./removeDuplicateNodes.cpp)
  - 删除节点 + 哈希表，这两个东西结合一下，会产生很多容易写错的细节，多注意一些
- JZOffer18. 删除链表的节点 [deleteNode](./deleteNode3.cpp)
  - 单纯的单链表节点删除, 注意dummy节点的设置以及删除完后直接break
  - **相似题目**: [203-移除链表元素](./removeElements2.cpp), 这一题需要删除多个节点, 注意与上面这个题的不同(cur的移动条件)
- 面试题02.06 回文链表 [isPalindrome](./isPalindromeList.cpp)
  - 链表也能后序遍历？能后序遍历就能实现回文（在递归中left向后走，right每层递归结束都会向前）。非常妙
  - **相同题目**: [JZOfferII027-回文链表](./isPalindromeList2.cpp) (注意递归return的条件)
- 剑指Offer 06. 从尾到头打印链表 [reversePrint](./reversePrint.cpp)
  - 链表的后序遍历（递归法），就是上面那道题的简化版
- 面试题 02.07. 链表相交 [getIntersectionNode](./getIntersectionNode3.cpp)
  - 经典的相交链表问题, 当一个指针走完自己的链表时,让它去遍历另外的链表,这相当于对两条链表的不同部分取并集. 非常经典的思路
  - **相同题目**: [JZOfferII023-两个链表的第一个重合节点](./getIntersectionNode4.cpp) (注意**如果没有相交节点时要返回null时**该怎么办)
- 剑指Offer 25-合并两个排序的链表 [mergeTwoLists](./mergeTwoLists.cpp)
  - 一个while循环 + 两个if判断; 关键在于新链表指针每次都是`cur->next`去操作,cur只用移到`cur->next`即可,省去了空节点的麻烦. 最开始cur就是dummy自己
  - **相同题目**: [21-合并两个有序链表](./mergeTwoLists2.cpp)
  - **相似题目** 
    - [面试题02.05-链表求和](./addTwoNumbers.cpp): 基于链表的按位加模拟过程, 记得设置进位
    - [JZOfferII025-链表中的两数相加](./addTwoNumbers2.cpp): 反向的上一题, 栈的使用 + 反向构建链表(node->next = cur)
    - [23-合并K个升序链表](./mergeKLists.cpp), 优先队列中初始放入所有的头节点, 自己只完成指针的移动即可
    - [61-旋转链表](./rotateRight2.cpp), `p->next=head` 以及移动的是`len-k%len`个节点, 剩余的就是节点next的拆分与更新
- 面试题17.12-BiNode BST展开为链表 [convertBiNode](./convertBiNode.cpp)
  - 本质是BST中序遍历 + 修改指针, 注意left指针修改时要修改当前节点而非上一个节点的.
  - **相似题目**
    - [114-二叉树展开为链表](./flatten2.cpp), 经典的递归定义题目, 核心在于考虑清楚单节点的处理方式, 以及需要在原地空间完成
    - [JZOfferII028-展平多级双向链表](./flattenMultiLevelNode.cpp), 同样从DFS的定义出发, 定义好lastNode后对两端进行操作即可
- 109-有序链表转换二叉搜索树 有序链表构造为BST [sortedListToBST](./sortedListToBST.cpp)
  - 本质是BST中序遍历构造 + 二分, 递归的模板题
  - **相似题目** : [JZOffer36-二叉搜索树与双向链表](./treeToDoublyList.cpp), 直接中序遍历 + 节点的指针修改, 注意递归结束后首尾节点的处理
- 24-两两交换链表中的节点 [swapPairs](./swapPairs2.cpp), 模拟即可, 静下心来想一下就能解决
- 146-LRU 缓存, 经典的面试题, 双向链表 + 哈希表, 需要掌握对功能的分解, LRU的原理, (双向)链表的各种操作.
  - 因为要查找 + 时序 + 删除与插入 , 所以只能双向链表 (删除与插入) + 哈希表 (查找) , 以实现快速的时序
  - 操作过的元素就放在链表最后, 由此头元素就是最久没有被使用的元素
  - 哈希表中存储节点, 负责新元素的get与set, 链表用来维护元素之间的新旧顺序
  - 注意双向链表的插入与删除操作, 语句之间的顺序
- 142-环形链表 II, 经典链表的环相交问题, 快指针比慢指针多走一步, 之后快指针从头开始继续走, 直到相遇 (**画图理解**)
  - 注意: 两指针的相遇点不一定是环的起点!
  - **相同题目**: [JZOfferII022-链表中环的入口节点](./detectCycle3.cpp) (注意可能没有环的返回结构), [面试题02.08-环路检测](./detectCycle4.cpp)
- 面试题04.03-特定深度节点链表: [面试题04.03-特定深度节点链表](./listOfDepth.cpp), BFS层序遍历的模板题目, 兼顾树和链表的结点类型
- JZOffer35-复杂链表的复制 : [copyRandomList](./copyRandomList2.cpp) 两次遍历 + 哈希表方便新建节点 (似乎有更巧妙的方法如dfs, 拆分等)
- 面试题02.04-分割链表[partitionList](./partitionList.cpp), 一个小指针, 一个大指针, 大指针最后别忘了置空
  - **相似题目**: 
    - [JZOfferII026-重排链表](./reorderList2.cpp), 需要用vector来存, 然后跟交换节点很像, 记得最后的节点next置空以及left++


## 树与二叉树

- [104-二叉树的最大深度](./treemaxDepth.cpp): 有多种解法, 考虑分而治之(动规)的思想, 即左子树的最大高度和右子树的最大高度的最大值+1, 就是当前节点的最大深度
  - 后序位置上的遍历, 非常经典的题目, 还可以直接dfs全局变量, bfs遍历等思路去做
  - **相似题目**
    - [543-二叉树的直径](./diameterOfBinaryTree.cpp), 当前节点的最长直径 = 左右子树的最大深度之和, 同样还是后序位置的遍历, 思路与104相同, 只不过单个节点上的操作多了一些.

- [226-翻转二叉树](./invertTree.cpp), 前序和后序位置都可以做, 因为单独到一个节点就是交换左右子树即可, 前序和后序对于这个题而言只是遍历方向不同
- [116-填充每个节点的下一个右侧节点指针](./connectPadNextTree.cpp), 如何访问同辈节点? 递归的时候怎么就抽象成了三叉树?
- [114-二叉树展开为链表](./flatten3.cpp): 典中典之将树展开为链表, 递归求解子问题的经典题目, 即先展开左右子树, 再把左子树接到右子树, 右子树接到新的右子树后面
- [654-最大二叉树](./constructMaximumBinaryTree2.cpp), 分解问题 or 遍历思想? 只取决于怎么理解问题. 对于单个节点而言, 在[left, right] 这个范围里找到最大值后构造节点, 剩下的交给递归.