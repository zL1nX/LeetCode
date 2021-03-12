/*
序列化二叉树的一种方法是使用前序遍历。当我们遇到一个非空节点时，我们可以记录下这个节点的值。如果它是一个空节点，我们可以使用一个标记值记录，例如 #。

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
例如，上面的二叉树可以被序列化为字符串 "9,3,4,#,#,1,#,#,2,#,6,#,#"，其中 # 代表一个空节点。

给定一串以逗号分隔的序列，验证它是否是正确的二叉树的前序序列化。编写一个在不重构树的条件下的可行算法。

每个以逗号分隔的字符或为一个整数或为一个表示 null 指针的 '#' 。

你可以认为输入格式总是有效的，例如它永远不会包含两个连续的逗号，比如 "1,,3" 。

示例 1:

输入: "9,3,4,#,#,1,#,#,2,#,6,#,#"
输出: true
示例 2:

输入: "1,#"
输出: false
示例 3:

输入: "9,#,#,1"
输出: false
通过次数13,861提交次数29,425

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <sstream>
#include <vector>

using namespace std;


// bool traverse(vector<string>& nodes, int left, int right)
// {
//     if(left >= right)
//     {
//         return true;
//     }
//     int mid_pos = (left + right) / 2;
//     string mid_node = nodes[mid_pos];
//     if(mid_node == "#")
//     {
//         return false;
//     }
//     return traverse(nodes, left, mid_pos - 1) && traverse(nodes, mid_pos + 1, right);

// }


// bool isValidSerialization(string preorder) 
// {
//     vector<string> nodes;
//     stringstream ss;
//     for(string node ; ss >> node; )
//     {
//         nodes.push_back(node);
//         if(ss.peek() == ',')
//         {
//             ss.ignore();
//         }
//     }
//     if(nodes.size() == 0)
//     {
//         return false;
//     }
//     bool isvalid = traverse(nodes, 0, nodes.size() - 1);
//     return isvalid;
// }

bool isValidSerialization(string preorder) 
{
    vector<string> nodes;
    stringstream ss(preorder);
    while(ss.good())
    {
        string node;
        getline(ss, node, ',');
        nodes.push_back(node);
    }
    if(nodes.size() == 0)
    {
        return false;
    }
    int slot = 1;
    for(int i = 0; i < nodes.size(); i++)
    {
        if(slot == 0)
        {
            return false;
        }
        if(nodes[i] == "#")
        {
            slot -= 1;
        }
        else
        {
            slot -= 1;
            slot += 2;
        }
    }
    return slot == 0;
}
// 淦 这道题刚开始就判断错思路了，而且当成了是验证是否满足中序

// 其实判断是否满足前序的关键在于「节点数量及其之间是否满足一定的关系」

// 具体而言，就是一个非空节点必然对应着俩子节点，因此如果整个string中节点的数量不能满足这种依赖关系

// 就说明这个树是不正确的，此外我们不用关心非空节点的值具体是多少

// 因此可以用一个槽位的概念来动态维护这样的一个依赖关系

// 妙啊