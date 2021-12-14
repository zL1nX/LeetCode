/*
这里有 n 门不同的在线课程，按从 1 到 n 编号。给你一个数组 courses ，其中 courses[i] = [durationi, lastDayi] 表示第 i 门课将会 持续 上 durationi 天课，并且必须在不晚于 lastDayi 的时候完成。

你的学期从第 1 天开始。且不能同时修读两门及两门以上的课程。

返回你最多可以修读的课程数目。

 

示例 1：

输入：courses = [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
输出：3
解释：
这里一共有 4 门课程，但是你最多可以修 3 门：
首先，修第 1 门课，耗费 100 天，在第 100 天完成，在第 101 天开始下门课。
第二，修第 3 门课，耗费 1000 天，在第 1100 天完成，在第 1101 天开始下门课程。
第三，修第 2 门课，耗时 200 天，在第 1300 天完成。
第 4 门课现在不能修，因为将会在第 3300 天完成它，这已经超出了关闭日期。
示例 2：

输入：courses = [[1,2]]
输出：1
示例 3：

输入：courses = [[3,2],[4,3]]
输出：0
 

提示:

1 <= courses.length <= 104
1 <= durationi, lastDayi <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/course-schedule-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <queue>
using namespace std;

int scheduleCourse(vector<vector<int>>& courses) 
{
    sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    });
    priority_queue<int> pq;
    int sum = 0;
    for(auto& course : courses) 
    {
        int ti = course[0], di = course[1];
        if(sum + ti <= di)
        {
            sum += ti;
            pq.push(ti);
        }
        else if(!pq.empty() && pq.top() > ti)
        {
            sum -= pq.top() - ti;
            pq.pop();
            pq.push(ti);
        }
    }
    return pq.size();
}


// 用优先队列来存储排课方案

// 能知道要按照结束时间升序排序，但是之后的思路应该是判断当前这第i个课程能否加入最优方案

// 如果加上第i门课的持续时间ti后，还在di范围内，就说明可以加入

// 如果超了的话，优先队列中最大的元素的持续时间要是比ti多，那么就把这个最大元素踢出去，并加入ti，这样会让总持续更小一些，从而能加入更多的课程

// 这个课程排序的贪心思想其实是比较常见的，即按照结束时间升序排序，一定能尽可能多的排出课程

// 但是这个用优先队列来动态维护排课方案的实现没怎么见过，这个优先队列的优势就在于能随时拿出最大的元素来踢掉

// 同时，前面的元素保证了每个课程之间是互斥的，没有交集的，这样也有一些dp的思想在里面