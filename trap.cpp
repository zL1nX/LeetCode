/*
给定一个直方图(也称柱状图)，假设有人从上面源源不断地倒水，最后直方图能存多少水量?直方图的宽度为 1。



上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的直方图，在这种情况下，可以接 6 个单位的水（蓝色部分表示水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
通过次数12,045提交次数19,103


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/volume-of-histogram-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int trap(vector<int>& height) 
{
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0, volume = 0 ;
    while(left < right)
    {
        leftMax = max(leftMax, height[left]);
        rightMax = max(rightMax, height[right]);
        if(height[left] < height[right])
        {
            volume += leftMax - height[left];
            left++;
        }
        else
        {
            volume += rightMax - height[right];
            right--;
        }   
    }
    return volume;
}
//https://leetcode-cn.com/problems/volume-of-histogram-lcci/solution/zhi-fang-tu-de-shui-liang-by-leetcode-so-7rla/

// 精髓就是一句话，left与right谁小谁动，因为如果大的话往前移是没法计算当前积雨量的

// 同时，注意这个left与right 和 leftMax与rightMax之间的大小对应关系，因为是小的一直动，所以谁小说明自己那方的Max一定小于等于对方的Max（因为祖上没阔过）

// 移动对象发生变化的时候是对方有一个值成为了Max且大于本方此时的大值

// 需要多想想