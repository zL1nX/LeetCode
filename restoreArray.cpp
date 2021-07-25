/*
存在一个由 n 个不同元素组成的整数数组 nums ，但你已经记不清具体内容。好在你还记得 nums 中的每一对相邻元素。

给你一个二维整数数组 adjacentPairs ，大小为 n - 1 ，其中每个 adjacentPairs[i] = [ui, vi] 表示元素 ui 和 vi 在 nums 中相邻。

题目数据保证所有由元素 nums[i] 和 nums[i+1] 组成的相邻元素对都存在于 adjacentPairs 中，存在形式可能是 [nums[i], nums[i+1]] ，也可能是 [nums[i+1], nums[i]] 。这些相邻元素对可以 按任意顺序 出现。

返回 原始数组 nums 。如果存在多种解答，返回 其中任意一个 即可。

 

示例 1：

输入：adjacentPairs = [[2,1],[3,4],[3,2]]
输出：[1,2,3,4]
解释：数组的所有相邻元素对都在 adjacentPairs 中。
特别要注意的是，adjacentPairs[i] 只表示两个元素相邻，并不保证其 左-右 顺序。
示例 2：

输入：adjacentPairs = [[4,-2],[1,4],[-3,1]]
输出：[-2,4,1,-3]
解释：数组中可能存在负数。
另一种解答是 [-3,1,4,-2] ，也会被视作正确答案。
示例 3：

输入：adjacentPairs = [[100000,-100000]]
输出：[100000,-100000]
 

提示：

nums.length == n
adjacentPairs.length == n - 1
adjacentPairs[i].length == 2
2 <= n <= 105
-105 <= nums[i], ui, vi <= 105
题目数据保证存在一些以 adjacentPairs 作为元素对的数组 nums

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/restore-the-array-from-adjacent-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
using namespace std;

vector<int> restoreArray(vector<vector<int>>& adjacentPairs) 
{
    unordered_map<int, vector<int>> neighbour;
    for(auto& pair : adjacentPairs)
    {
        neighbour[pair[0]].push_back(pair[1]);
        neighbour[pair[1]].push_back(pair[0]);
    }
    vector<int> result(neighbour.size());

    for(auto& it : neighbour)
    {
        if(it.second.size() == 1)
        {
            result[0] = it.first; // 找到端点的位置
            result[1] = it.second[0]; // 端点的邻居
            break;
        }
    }
    
    // 重点是这部分代码怎么写
    for(int i = 2; i < result.size(); i++)
    {
        vector<int>& nextNeighbour = neighbour[result[i - 1]];
        if(result[i - 2] == nextNeighbour[0]) // 只要目前这个点的邻居出现过
        {
            result[i] = nextNeighbour[1]; // 那就选另外一个邻居
        }
        else
        {
            result[i] = nextNeighbour[0]; // 要没出现过就直接选上
        }
    }
    return result;
}

// 基本思路其实就是用哈希表记录邻居的是谁

// 然后在循环内不断判断形成结果数组

// 为什么不用考虑最后一个端点，因为最后端点的邻居，一定是由一个有两邻居的点过渡而来的，因此最后端点的邻居的一个邻居已经被占掉了

// 因此这个邻居只有最后端点这邻居可以用了

// 也就是说，最后端点的哈希表项实际上并没有被访问到