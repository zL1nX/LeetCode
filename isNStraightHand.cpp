/*
Alice 手中有一把牌，她想要重新排列这些牌，分成若干组，使每一组的牌数都是 groupSize ，并且由 groupSize 张连续的牌组成。

给你一个整数数组 hand 其中 hand[i] 是写在第 i 张牌，和一个整数 groupSize 。如果她可能重新排列这些牌，返回 true ；否则，返回 false 。

 

示例 1：

输入：hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
输出：true
解释：Alice 手中的牌可以被重新排列为 [1,2,3]，[2,3,4]，[6,7,8]。
示例 2：

输入：hand = [1,2,3,4,5], groupSize = 4
输出：false
解释：Alice 手中的牌无法被重新排列成几个大小为 4 的组。
 

提示：

1 <= hand.length <= 104
0 <= hand[i] <= 109
1 <= groupSize <= hand.length


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/hand-of-straights
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>

using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize) 
{
    int n = hand.size();
    if(n % groupSize != 0)
    {
        return false;
    }
    unordered_map<int, int> rec;
    sort(hand.begin(), hand.end());
    for(int& card : hand)
    {
        rec[card]++;
    }
    // 根据题目要求，这所有的hand必须每张牌都得能用上，否则这就不是一份顺子牌了
    for(int i = 0; i < n; i++)
    {
        int start = hand[i];
        if(rec[start] == 0) // 直到找到一张可以用于开头的牌
        {
            continue;
        }
        for(int k = 0; k < groupSize; k++)
        {
            int next = start + k;
            if(rec[next] == 0) // 第一张牌已经确定好了，后面的牌必须都有，否则不可能让形成一个连续且大小为groupSize的顺子组
            {
                return false;
            }
            rec[next]--;
        }
    }
    return true;
}

// 仔细想想，应该能知道这道题要用 排序 + 哈希 的方法去做，而迭代的方法则是贪心

// 总之，把原数组排序后，如果真的是顺子，那么一定可以按照贪心的方法，在前面的先尽量成一组，最后全部分完

// 因此，排序用来提供贪心的基础，哈希表用来记录某张牌有没有用完

// 对每张牌进行遍历，当出现了一个不为0的值，说明可以已这张牌为头，那么从这张牌开始遍历，下一张必须有牌，否则就不是顺子了，直接return false

// 最后遍历完成即可return true
