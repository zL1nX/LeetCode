/*
给你一个嵌套的整型列表。请你设计一个迭代器，使其能够遍历这个整型列表中的所有整数。

列表中的每一项或者为一个整数，或者是另一个列表。其中列表的元素也可能是整数或是其他列表。

 

示例 1:

输入: [[1,1],2,[1,1]]
输出: [1,1,2,1,1]
解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
示例 2:

输入: [1,[4,[6]]]
输出: [1,4,6]
解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,4,6]。
通过次数19,657提交次数28,882


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-nested-list-iterator
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


class NestedIterator {
private:
    vector<int> nlist;
    int pos;
    void assignList(const vector<NestedInteger>& nested)
    {
        for(int i = 0; i < nested.size(); i++)
        {
            if(nested[i].isInteger())
            {
                nlist.push_back(nested[i].getInteger());
            }
            else
            {
                auto list = nested[i].getList();
                assignList(list);
            }
        }
    }


public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        pos = 0;
        assignList(nestedList);
    }
    
    int next() {
        return nlist[pos++];
    }
    
    bool hasNext() {
        return pos < nlist.size();
    }
};

// 重要的是理解题意，以及会用迭代的方式先把嵌套列表展开，之后的工作就很容易了；组织以及展开是关键