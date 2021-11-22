/*
给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。

实现 Solution class:

Solution(int[] nums) 使用整数数组 nums 初始化对象
int[] reset() 重设数组到它的初始状态并返回
int[] shuffle() 返回数组随机打乱后的结果
 

示例：

输入
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
输出
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

解释
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。例如，返回 [3, 1, 2]
solution.reset();      // 重设数组到它的初始状态 [1, 2, 3] 。返回 [1, 2, 3]
solution.shuffle();    // 随机返回数组 [1, 2, 3] 打乱后的结果。例如，返回 [1, 3, 2]
 

提示：

1 <= nums.length <= 200
-106 <= nums[i] <= 106
nums 中的所有元素都是 唯一的
最多可以调用 5 * 104 次 reset 和 shuffle

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shuffle-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

class ShuffleArray {
private:
    vector<int> original;
    vector<int> nums;

public:
    ShuffleArray(vector<int>& nums) {
        this->nums = nums;
        this->original.resize(nums.size());
        copy(nums.begin(), nums.end(), this->original.begin());
    }
    
    vector<int> reset() {
        copy(this->original.begin(), this->original.end(), this->nums.begin());
        return this->nums;
    }
    
    vector<int> shuffle() {
        for(int i = 0;i < this->nums.size();i++) {
            int j = i + rand() % (this->nums.size() - i);
            swap(this->nums[i], this->nums[j]);
        }
        return this->nums;
    }
};

// 其实reset应该是个人就知道怎么写

// 主要是shuffle这里，有很多种数组的shuffle方式，这种就是将一个元素随机和后面的元素交换位置，直到没元素了

// 但本质上题目也没有规定要如何实现这个shuffle，感觉只要不原样返回即可

// 另外，需要学习下这里的rand与shuffle的写法