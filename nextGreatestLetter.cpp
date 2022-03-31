/*
给你一个排序后的字符列表 letters ，列表中只包含小写英文字母。另给出一个目标字母 target，请你寻找在这一有序列表里比目标字母大的最小字母。

在比较时，字母是依序循环出现的。举个例子：

如果目标字母 target = 'z' 并且字符列表为 letters = ['a', 'b']，则答案返回 'a'
 

示例 1：

输入: letters = ["c", "f", "j"]，target = "a"
输出: "c"
示例 2:

输入: letters = ["c","f","j"], target = "c"
输出: "f"
示例 3:

输入: letters = ["c","f","j"], target = "d"
输出: "f"
 

提示：

2 <= letters.length <= 104
letters[i] 是一个小写字母
letters 按非递减顺序排序
letters 最少包含两个不同的字母
target 是一个小写字母
通过次数54,874提交次数117,199

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-smallest-letter-greater-than-target
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;


char nextGreatestLetter(vector<char>& letters, char target) 
{
    int left = 0, right = letters.size();
    while(left < right)
    {
        int mid = left + (right - left) / 2;
        char c = letters[mid];
        if(c <= target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return letters[left % letters.size()];
}

// 看完有序肯定知道要用二分了, 不过这一题的二分还有点不一样

// 这里的二分是要找第一个大于的, 传统二分是找相等的. 不过没关系, 二分只是一个查找的思想

// 只要按照模板将二分的查找框架写好, 剩下的任务就是不断逼近, 最后停止状态的地方就是第一个比target大的元素

// 而此时如果整个letters都太小了, 那么left就会不断右移跑到最后一个位置

// 此时返回的结果就需要模一下

// 二分不一定要相等!!! 二分的思想是逼近