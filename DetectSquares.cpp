/*
给你一个在 X-Y 平面上的点构成的数据流。设计一个满足下述要求的算法：

添加 一个在数据流中的新点到某个数据结构中。可以添加 重复 的点，并会视作不同的点进行处理。
给你一个查询点，请你从数据结构中选出三个点，使这三个点和查询点一同构成一个 面积为正 的 轴对齐正方形 ，统计 满足该要求的方案数目。
轴对齐正方形 是一个正方形，除四条边长度相同外，还满足每条边都与 x-轴 或 y-轴 平行或垂直。

实现 DetectSquares 类：

DetectSquares() 使用空数据结构初始化对象
void add(int[] point) 向数据结构添加一个新的点 point = [x, y]
int count(int[] point) 统计按上述方式与点 point = [x, y] 共同构造 轴对齐正方形 的方案数。
 

示例：


输入：
["DetectSquares", "add", "add", "add", "count", "count", "add", "count"]
[[], [[3, 10]], [[11, 2]], [[3, 2]], [[11, 10]], [[14, 8]], [[11, 2]], [[11, 10]]]
输出：
[null, null, null, null, 1, 0, null, 2]

解释：
DetectSquares detectSquares = new DetectSquares();
detectSquares.add([3, 10]);
detectSquares.add([11, 2]);
detectSquares.add([3, 2]);
detectSquares.count([11, 10]); // 返回 1 。你可以选择：
                               //   - 第一个，第二个，和第三个点
detectSquares.count([14, 8]);  // 返回 0 。查询点无法与数据结构中的这些点构成正方形。
detectSquares.add([11, 2]);    // 允许添加重复的点。
detectSquares.count([11, 10]); // 返回 2 。你可以选择：
                               //   - 第一个，第二个，和第三个点
                               //   - 第一个，第三个，和第四个点
 

提示：

point.length == 2
0 <= x, y <= 1000
调用 add 和 count 的 总次数 最多为 5000
通过次数4,833提交次数11,494
请问您在哪类招聘中遇到此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/detect-squares
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
using namespace std;

class DetectSquares {
private:
    unordered_map<int, unordered_map<int, int>> cnt;
    
public:
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        cnt[y][x] ++;
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int res = 0;
        if(!cnt.count(y))
        {
            return 0;
        }
        unordered_map<int, int> & same = cnt[y]; // 和查询点在同一行的所有点
        for(auto & [yloc, ycnt] : cnt)
        {
            int d = y - yloc;
            if(yloc != y)
            {
                // 下面的两个式子其实是对称的
                // 就是 先看同一条纵边的端点（x, yloc）存不存在，再看同一横边的(x +- d, y) 与另一条横边的 (x +- d, yloc)存不存在
                res += (ycnt.count(x) ? ycnt[x] : 0) * (same.count(x + d) ? same[x + d] : 0) * (ycnt.count(x + d) ? ycnt[x + d] : 0);
                res += (ycnt.count(x) ? ycnt[x] : 0) * (same.count(x - d) ? same[x - d] : 0) * (ycnt.count(x - d) ? ycnt[x - d] : 0); 
            }
        }
        return res;
    }
};

// 本质依然是一道枚举题，我本来想类似于用一种压缩方法，把二维化为一维，然后再去判断和还原，但后面卡在了枚举的地方

// 结果发现题解的枚举也是又臭又长（逃

// 整体过程就是，先枚举一条纵边，然后找看有没有符合正方形长度的点

// 注意把正方形边的这个条件用起来，不是矩形不是矩形不是矩形