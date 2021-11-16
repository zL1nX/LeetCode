/*
给你一个数组 rectangles ，其中 rectangles[i] = [xi, yi, ai, bi] 表示一个坐标轴平行的矩形。这个矩形的左下顶点是 (xi, yi) ，右上顶点是 (ai, bi) 。

如果所有矩形一起精确覆盖了某个矩形区域，则返回 true ；否则，返回 false 。

 
示例 1：


输入：rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
输出：true
解释：5 个矩形一起可以精确地覆盖一个矩形区域。 
示例 2：


输入：rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
输出：false
解释：两个矩形之间有间隔，无法覆盖成一个矩形。
示例 3：


输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[3,2,4,4]]
输出：false
解释：图形顶端留有空缺，无法覆盖成一个矩形。
示例 4：


输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
输出：false
解释：因为中间有相交区域，虽然形成了矩形，但不是精确覆盖。
 

提示：

1 <= rectangles.length <= 2 * 104
rectangles[i].length == 4
-105 <= xi, yi, ai, bi <= 105
通过次数6,643提交次数16,488

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/perfect-rectangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

bool isRectangleCover(vector<vector<int>>& rectangles) 
{
    int current[4] = {INT_MAX, INT_MAX, INT_MIN, INT_MIN};
    int currArea = 0;
    unordered_set<string> appeared;
    for(vector<int>& rec : rectangles)
    {
        current[0] = min(current[0], rec[0]);current[1] = min(current[1], rec[1]);
        current[2] = max(current[2], rec[2]);current[3] = max(current[3], rec[3]);
        currArea += (rec[2] - rec[0]) * (rec[3] - rec[1]);

        string coordinates[4] = {to_string(rec[0]) + " " + to_string(rec[1]), to_string(rec[2]) + " " + to_string(rec[1]), 
        to_string(rec[0]) + " " + to_string(rec[3]), to_string(rec[2]) + " " + to_string(rec[3])};
        
        for(string& coor : coordinates)
        {
            if(!appeared.count(coor)) // 出现偶数次的话，就没有了
            {
                appeared.insert(coor);
            }
            else
            {
                appeared.erase(coor);
            }
        }
    }
    string ll = to_string(current[0]) + " " + to_string(current[1]);
    string rl = to_string(current[2]) + " " + to_string(current[1]);
    string lh = to_string(current[0]) + " " + to_string(current[3]);
    string rh = to_string(current[2]) + " " + to_string(current[3]);
    if(appeared.size() == 4 && appeared.count(ll) && appeared.count(rl) && appeared.count(lh) && appeared.count(rh))
    {
        // 最终set里只有最外面的这四个顶点
        return currArea == (current[2] - current[0]) * (current[3] - current[1]);
    }
    return false;
}

// 淦 好奇怪的一题 https://leetcode-cn.com/problems/perfect-rectangle/solution/c-zui-tong-su-yi-dong-si-lu-by-heroding-npgj/

// 关键在于观察到合并之后原来每个顶点的状态，对于新矩形的四点，必然只会出现一次，对于新矩形内部的合并的那些点，必然出现了偶数次（否则不可能合并消掉）

// 因此，就可以依次遍历每个矩形的顶点，同时记录其最大最小值（因为如果能合并，这些值必然是最后的大矩形的顶点）

// 在遍历时，用一个set来去重，即最终除四个最外面的顶点外，不会有其他顶点存在于set了（因为是偶数次，所以可以人为控制消掉）

// 同时，判断下小矩形的面积和大矩形是否相等，这样就可以了

// 这题感觉还挺有意思的，尤其是解这题有好几种思路