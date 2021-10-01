/*
给你 二维 平面上两个 由直线构成的 矩形，请你计算并返回两个矩形覆盖的总面积。

每个矩形由其 左下 顶点和 右上 顶点坐标表示：

第一个矩形由其左下顶点 (ax1, ay1) 和右上顶点 (ax2, ay2) 定义。
第二个矩形由其左下顶点 (bx1, by1) 和右上顶点 (bx2, by2) 定义。
 

示例 1：


输入：ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
输出：45
示例 2：

输入：ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
输出：16
 

提示：

-104 <= ax1, ay1, ax2, ay2, bx1, by1, bx2, by2 <= 104
通过次数23,526提交次数48,773

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rectangle-area
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <math.h>

using namespace std;

// int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) 
// {
//     int spec1 = (ax2 - ax1) * (ay2 - ay1), spec2 = (bx2 - bx1) * (by2 - by1);
//     if((ax2 <= bx1) || ( ax1 >= bx2) || (ay1 >= by2) || (ay2 <= by1))
//     {
//         return spec1 + spec2;
//     }
//     int topx = min(ax2, bx2), bottomx = max(ax1, bx1);
//     int topy = min(ay2, by2), bottomy = max(ay1, by1); 
//     return spec1 + spec2 - abs(topy - bottomy) * abs(topx - bottomx);
// }

 // 乍一看挺吓人，实际上并不难

// 因为ax1与ax2已经暗含了大小关系，y也是类似

// 因此只需要小心看下边界条件，可以只用两个坐标就能判断是否重叠

// 而交叉的部分只需要看最小的最大，和最大的最小即可（其实最后可以不用abs）

// 个人感觉挺适合面试的，如果心态紧张很可能就崩了写不出来