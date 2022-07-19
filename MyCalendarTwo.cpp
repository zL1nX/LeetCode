/*
实现一个 MyCalendar 类来存放你的日程安排。如果要添加的时间内不会导致三重预订时，则可以存储这个新的日程安排。

MyCalendar 有一个 book(int start, int end)方法。它意味着在 start 到 end 时间内增加一个日程安排，注意，这里的时间是半开区间，即 [start, end), 实数 x 的范围为，  start <= x < end。

当三个日程安排有一些时间上的交叉时（例如三个日程安排都在同一时间内），就会产生三重预订。

每次调用 MyCalendar.book方法时，如果可以将日程安排成功添加到日历中而不会导致三重预订，返回 true。否则，返回 false 并且不要将该日程安排添加到日历中。

请按照以下步骤调用MyCalendar 类: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)

 

示例：

MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(50, 60); // returns true
MyCalendar.book(10, 40); // returns true
MyCalendar.book(5, 15); // returns false
MyCalendar.book(5, 10); // returns true
MyCalendar.book(25, 55); // returns true
解释： 
前两个日程安排可以添加至日历中。 第三个日程安排会导致双重预订，但可以添加至日历中。
第四个日程安排活动（5,15）不能添加至日历中，因为它会导致三重预订。
第五个日程安排（5,10）可以添加至日历中，因为它未使用已经双重预订的时间10。
第六个日程安排（25,55）可以添加至日历中，因为时间 [25,40] 将和第三个日程安排双重预订；
时间 [40,50] 将单独预订，时间 [50,55）将和第二个日程安排双重预订。
 

提示：

每个测试用例，调用 MyCalendar.book 函数最多不超过 1000次。
调用函数 MyCalendar.book(start, end)时， start 和 end 的取值范围为 [0, 10^9]。
通过次数10,148提交次数17,660

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/my-calendar-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

class MyCalendarTwo {
private:
    vector<pair<int, int>> books;
    vector<pair<int, int>> overlaps;

public:
    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
        for(auto& [l, r] : overlaps) {
            if(l < end && r > start) {
                return false; // 新区间和已经重叠的两次区间重叠, 直接返回false
            }
        }
        for(auto& [l, r] : books) { // books里是那些顶多有两个重叠的区间
            if(l < end && r > start) { // 如果出现了一次重叠的
                overlaps.emplace_back(max(l, start), min(r, end)); // max和min就是两个区间的重叠部分
            }
        }
        books.emplace_back(start, end); // 只要没重叠三次就可以加到books里, 同时返回true
        return true;
    }
};

// 注意, 题目允许重叠两次, 但不允许重叠三次. 即已经重叠的部分里, 不允许再有新的区间重叠

// overlap表示已经相交的区间里的重叠部分

// 判断两区间是否重叠的方法: l < end && r > start, 非常简洁而且也很robust

// 两区间的重叠部分: max(l, start), min(r, end), 也是非常简洁, 非常好

// 这个题还是能学到不少区间判断上的写法