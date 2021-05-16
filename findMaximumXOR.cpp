/*
给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0 ≤ i ≤ j < n 。

进阶：你可以在 O(n) 的时间解决这个问题吗？

 

示例 1：

输入：nums = [3,10,5,25,2,8]
输出：28
解释：最大运算结果是 5 XOR 25 = 28.
示例 2：

输入：nums = [0]
输出：0
示例 3：

输入：nums = [2,4]
输出：6
示例 4：

输入：nums = [8,10,2]
输出：10
示例 5：

输入：nums = [14,70,53,83,49,91,36,80,92,51,66,70]
输出：127
 

提示：

1 <= nums.length <= 2 * 104
0 <= nums[i] <= 231 - 1
通过次数12,622提交次数20,862

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>

using namespace std;
class Trie
{
public:
    Trie* left = nullptr;
    Trie* right = nullptr;
    Trie();
};

Trie* root = new Trie();
int bits_num = 30;

void add(int num)
{
    Trie* cur = root;
    for(int b = bits_num; b >= 0; b--)
    {
        int bit = (num >> b) & 1;
        if(bit == 0)
        {
            if(!cur->left) //指定left表示0，right表示1
            {
                cur->left = new Trie();
            }
            cur = cur->left; //迭代继续
        }
        else
        {
            if(!cur->right)
            {
                cur->right = new Trie(); //
            }
            cur = cur->right; 
        }  
    }
}

int check(int num)
{
    Trie *cur = root;
    int current = 0;
    for(int b = bits_num; b >= 0; b--)
    {
        int bit = (num >> b) & 1;
        if(bit == 0)
        {
            if(cur->right)
            {
                current = current * 2 + 1; // 当前位为0的话，找有1的那位即right
                cur = cur->right;
            }
            else
            {
                current = current * 2; // 要是目前right没有定义，那只能将就下去left
                cur = cur->left;
            }
        }
        else
        {
            if(cur->left)//当前位为1的话，找有0的那位
            {
                current = current * 2 + 1; //
                cur = cur->left;
            }
            else
            {
                current = current * 2; //同理
                cur = cur->right;
            }
        }
    }
    return current;
}

int findMaximumXOR(vector<int>& nums) 
{
    int res = 0;
    for(int i = 1; i < nums.size(); i++)
    {
        add(nums[i - 1]); // 将前面的数加进来（所有前面的数都已加进去了）
        res = max(res, check(nums[i])); // 得到最大值
    }
    return res;
}

// 字典树来构造一个通向最大的异或值路径，这思路真是妙啊

// 将每个数的每一位展开作为字典树的结构，因为字典树里的元素都是存进去的数组值，因此每加进去一个数，从根开始就能找到和这个数异或最大的一个元素

// 依次遍历并加入每个元素，就能得到整个数组中最大的异或结果

// 而这个「找」的方法也比较精妙且直观了；就是如果当前位是0的话，那就去找有1的那位；位是1的话，就去找0的那位；即尽可能时异或的结果保持1