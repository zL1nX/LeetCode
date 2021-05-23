/*
给你一个由非负整数组成的数组 nums 。另有一个查询数组 queries ，其中 queries[i] = [xi, mi] 。

第 i 个查询的答案是 xi 和任何 nums 数组中不超过 mi 的元素按位异或（XOR）得到的最大值。换句话说，答案是 max(nums[j] XOR xi) ，其中所有 j 均满足 nums[j] <= mi 。如果 nums 中的所有元素都大于 mi，最终答案就是 -1 。

返回一个整数数组 answer 作为查询的答案，其中 answer.length == queries.length 且 answer[i] 是第 i 个查询的答案。

 

示例 1：

输入：nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
输出：[3,3,7]
解释：
1) 0 和 1 是仅有的两个不超过 1 的整数。0 XOR 3 = 3 而 1 XOR 3 = 2 。二者中的更大值是 3 。
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.
示例 2：

输入：nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
输出：[15,-1,5]
 

提示：

1 <= nums.length, queries.length <= 105
queries[i].length == 2
0 <= nums[j], xi, mi <= 109


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-xor-with-an-element-from-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;
class Trie
{

public:
    Trie* children[2] = {};
    const int L = 30;
    void insert(int val) 
    {
        Trie* node = this;
        for (int i = L - 1; i >= 0; --i) {
            int bit = (val >> i) & 1;
            if (node->children[bit] == nullptr) {
                node->children[bit] = new Trie();
            }
            node = node->children[bit];
        }
    }

    int max_xor(int val)
    {
        Trie* t = this;
        int xor_max = 0;
        for(int i = L - 1; i >= 0; i--)
        {
            int bit = ( val >> i ) & 1;
            if(t->children[bit ^ 1] != nullptr) // 这种写法相较于之前的定义左右子树为01的写法更优
            {
                xor_max |= (1 << i); // 可以做个简单推演，即当bit为0时，希望去1的那边；1时希望去0的那边
                bit ^= 1; // 这一操作实际上和bit 异或 1是一样的
            }
            t = t->children[bit];
        }
        return xor_max;
    }
};


vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) 
{
    int n = nums.size(), q = queries.size();
    //sort 先对nums进行排序，以方便后面的不超过mi
    sort(nums.begin(), nums.end());

    for(int i = 0; i < q; i++)
    {
        queries[i].push_back(i); // 由于后面要对query根据mi排序，因此插入一个qid来保证返回结果的顺序不变
    }
    sort(queries.begin(), queries.end(), [](auto &a, auto &b){
        return a[1] < b[1];
    });
    // sort query
    vector<int> res(q);
    Trie* trie = new Trie();
    int idx = 0;

    for(const auto &query : queries)
    {
        int qid = query[2], mi = query[1], xi = query[0];
        while(idx < n && nums[idx] <= mi)
        {
            trie->insert(nums[idx]);
            idx++;
        }
        if(idx == 0)
        {
            res[qid] = -1;
            // 由于是排好序的，因此可以使用一个唯一的idx来标识此时nums进行到了哪里了
        }
        else
        {
            res[qid] = trie->max_xor(xi);
        }
    }
    return res;
}

// 本题与之前的findMaximumXOR.cpp非常像，一个主要目的都是寻找某个元素在数组中的最大异或值

// 本题中有了个不超过mi的限制，这一限制通过预排序可实现

// 此外，字典树的写法以及使用（this取当前节点，children或左右子树的区别，结果相加（使用异或）等）

/**class Trie {
public:
    const int L = 30;

    Trie* children[2] = {};

    void insert(int val) {
        Trie* node = this;
        for (int i = L - 1; i >= 0; --i) {
            int bit = (val >> i) & 1;
            if (node->children[bit] == nullptr) {
                node->children[bit] = new Trie();
            }
            node = node->children[bit];
        }
    }

    int getMaxXor(int val) {
        int ans = 0;
        Trie* node = this;
        for (int i = L - 1; i >= 0; --i) {
            int bit = (val >> i) & 1;
            if (node->children[bit ^ 1] != nullptr) {
                ans |= 1 << i;
                bit ^= 1;
            }
            node = node->children[bit];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
        sort(nums.begin(), nums.end());
        int numQ = queries.size();
        for (int i = 0; i < numQ; ++i) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [](auto &x, auto &y) { return x[1] < y[1]; });

        vector<int> ans(numQ);
        Trie* t = new Trie();
        int idx = 0, n = nums.size();
        for (auto &q : queries) {
            int x = q[0], m = q[1], qid = q[2];
            while (idx < n && nums[idx] <= m) {
                t->insert(nums[idx]);
                ++idx;
            }
            if (idx == 0) { // 字典树为空
                ans[qid] = -1;
            } else {
                ans[qid] = t->getMaxXor(x);
            }
        }
        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/maximum-xor-with-an-element-from-array/solution/yu-shu-zu-zhong-yuan-su-de-zui-da-yi-huo-7erc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/