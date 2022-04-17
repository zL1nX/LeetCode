/*
实现RandomizedSet 类：

RandomizedSet() 初始化 RandomizedSet 对象
bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 相同的概率 被返回。
你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 。

 

示例：

输入
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
输出
[null, true, false, true, 2, true, false, 2]

解释
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
randomizedSet.remove(2); // 返回 false ，表示集合中不存在 2 。
randomizedSet.insert(2); // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
randomizedSet.getRandom(); // getRandom 应随机返回 1 或 2 。
randomizedSet.remove(1); // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
randomizedSet.insert(2); // 2 已在集合中，所以返回 false 。
randomizedSet.getRandom(); // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
 

提示：

-231 <= val <= 231 - 1
最多调用 insert、remove 和 getRandom 函数 2 * 105 次
在调用 getRandom 方法时，数据结构中 至少存在一个 元素。
通过次数51,758提交次数101,017

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insert-delete-getrandom-o1
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <random>
#include <time.h>
#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet 
{
private:
    vector<int> nums;
    unordered_map<int, int> rec;
public:
    RandomizedSet() 
    {
        srand((unsigned)time(nullptr));
    }
    
    bool insert(int val)
    {
        if(rec.count(val))
        {
            return false;
        }
        int id = nums.size();
        rec[val] = id;
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) 
    {
        if(!rec.count(val))
        {
            return false;
        }
        int id = rec[val];
        int lastVal = nums.back();
        nums[id] = lastVal;
        rec[lastVal] = id;
        nums.pop_back();
        rec.erase(val);
        return true;
    }

    int getRandom() 
    {
        int rid = rand() % (nums.size());
        return nums[rid]; 
    }
};

// 删除的思路还挺鬼畜, 即将数组最后一个元素和移除的元素交换, 然后删除最后一个元素

// (这样删除后的效果是一样的, 但数组此时的结构和布局变了, 虽然后续的元素坐标可能会不一样, 但元素内容本身是没变的)

// 所以直接getRandom依然是正确的