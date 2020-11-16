/*
假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

注意：
总人数少于1100人。

示例

输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/queue-reconstruction-by-height
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include <vector>
using namespace std;

bool heightCmp(vector<int> a, vector<int> b)
{
    return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
    // 身高降序，个数升序
}
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
{
    if(people.size() <= 1)
    {
        return people;
    }
    sort(people.begin(), people.end(), heightCmp);
    vector<vector<int>> res;
    for(int i = 0; i < people.size(); i ++)
    {
        res.insert(res.begin() + people[i][1], people[i]);
        // 第k个位置就直接插入，此时前面必然有K个高个子，即使有矮个子插到前面了也无所谓
    }
    return res;
}
// 因为是恢复合法队列，因此目标队列必然蕴含着排列的某种合法性，这种合法性就是以前面高个子的数量作为排序的依据。
// 所以在排序时就应该以这种身高和数量之间的联系去排列