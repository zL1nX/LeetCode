/*
在考场里，一排有 N 个座位，分别编号为 0, 1, 2, ..., N-1 。

当学生进入考场后，他必须坐在能够使他与离他最近的人之间的距离达到最大化的座位上。如果有多个这样的座位，他会坐在编号最小的座位上。(另外，如果考场里没有人，那么学生就坐在 0 号座位上。)

返回 ExamRoom(int N) 类，它有两个公开的函数：其中，函数 ExamRoom.seat() 会返回一个 int （整型数据），代表学生坐的位置；函数 ExamRoom.leave(int p) 代表坐在座位 p 上的学生现在离开了考场。每次调用 ExamRoom.leave(p) 时都保证有学生坐在座位 p 上。

 

示例：

输入：["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
输出：[null,0,9,4,2,null,5]
解释：
ExamRoom(10) -> null
seat() -> 0，没有人在考场里，那么学生坐在 0 号座位上。
seat() -> 9，学生最后坐在 9 号座位上。
seat() -> 4，学生最后坐在 4 号座位上。
seat() -> 2，学生最后坐在 2 号座位上。
leave(4) -> null
seat() -> 5，学生最后坐在 5 号座位上。
 

提示：

1 <= N <= 10^9
在所有的测试样例中 ExamRoom.seat() 和 ExamRoom.leave() 最多被调用 10^4 次。
保证在调用 ExamRoom.leave(p) 时有学生正坐在座位 p 上。
*/

#include <vector>
#include <set>
#include <unordered_map>

using namespace std;


class ExamRoom {

public:
    unordered_map<int, int> start_map; // p
    unordered_map<int, int> end_map; // q


public:
    struct Comp
    {
        int cap;
        Comp(int Cap) : cap(Cap) {};
        int distance(const pair<int, int>& v) const
        {
            int x = v.first, y = v.second;
            if(x == -1) return y;
            if(y == cap) return cap - 1- x;
            return (y - x) / 2; // 中点到端点的距离
        }

        bool operator()(const pair<int, int>& l, const pair<int, int>& r) const 
        {
            if(distance(l) == distance(r))
            {
                return l.first < r.first; // 线段长度相等时, 返回索引小的
            }
            return distance(l) > distance(r); // 按降序排列 , 返回最长的线段
        }
    };
    
    set<pair<int, int>, Comp> *pq = nullptr; // pq, 所有线段
    int N;

public:
    void addInterval(const int l, const int r)
    {
        pq->insert({l, r});
        start_map[l] = r;
        end_map[r] = l;
    }

    void removeInterval(const int l, const int r)
    {
        pq->erase({l, r});
        start_map.erase(l);
        end_map.erase(r);
    }

public:
    ExamRoom(int n) 
    {
        this->N = n;
        start_map.clear();
        end_map.clear();
        pq = new set<pair<int, int>, Comp>(Comp(n));
        pq->insert({-1, N}); // dummy head;
    }


    int seat() 
    {
        auto p = pq->begin();
        int l = p->first, r = p->second;
        int seat;

        if(l == -1) seat = 0;
        else if(r == this->N) seat = N - 1;
        else
        {
            seat = (l + r) / 2;
        }

        // 这下形成了新的区间
        removeInterval(l, r);
        addInterval(l, seat);
        addInterval(seat, r);

        return seat;
    }
    
    void leave(int p) 
    {
        int l = end_map[p], r = start_map[p];
        removeInterval(l, p);
        removeInterval(p, r);
        addInterval(l, r);
    }


};

// 855-考场就座