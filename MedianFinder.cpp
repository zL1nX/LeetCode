/*
中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例：

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
进阶:

如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？
通过次数46,784提交次数89,503

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-median-from-data-stream
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <queue>
using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> queMin; // 此处less表示堆顶最大，下面greater表示堆顶最小
    priority_queue<int, vector<int>, greater<int>> queMax;

public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(queMin.empty() || num <= queMin.top()) // num比小堆的堆顶还要小
        {
            queMin.push(num);
            if(queMax.size() + 1 < queMin.size()) // 保证二者的数量平衡
            {
                queMax.push(queMin.top());
                queMin.pop();
            }
        }
        else
        {
            queMax.push(num);
            if(queMax.size() > queMin.size())
            {
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }
    
    double findMedian() {
        if (queMin.size() <= queMax.size())
        {
            return (queMin.top() + queMax.top()) / 2.0;
        }
        else
        {
            return (double)queMin.top();
        }
    }
};

// 用两个堆分别维护，一个存比中位数小的，一个存比中位数大的，那么二者的top或者小的top就是中位数

// 要注意，最终数据添加完后，小堆要么比大堆多一个，要么两个相等。因此在添加时，每次push完都要比较下两个堆的数量，然后互相push调整二者的数量关系保持平衡

// 而push时要注意，对于要添加的num以及堆的top，比较后进行push

// 可以算是面试中会考一些这种发散型的题