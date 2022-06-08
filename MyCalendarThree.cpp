#include <map>
using namespace std;


class MyCalendarThree {
private:
    map<int, int> cnt;

public:
    MyCalendarThree() {

    }
    
    int book(int start, int end) {
        cnt[start]++;
        cnt[end]--;
        int res = 0, bookTimes = 0;
        for(auto& [_, times] : cnt)
        {
            bookTimes += times;
            res = max(res, bookTimes);
        }
        return res;
    }
};

// 732-我的日程安排表 III


// 首先注意题目中的描述是：在加入第k次之后， 返回总共重叠的最大值，即题目不要求返回某个日程「所对应的」重叠最大值

// 那么这样一来就只需要一种方法，找到重叠次数的最大值即可。 这里是差分数组，即首部加，尾部减

// 那么每次更新完这个map之后，遍历一遍这个map时，同时记录最大值，当前面那的所有首部都加完之后，此时其实就是最大值了

// 之后的尾部加进来只会减少这个最大值，那么最大值一定代表的是尾部出现之前所有首部加起来的结果，即重叠的区间个数

// 只要保证用map实现是有序加的即可，很妙


/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */