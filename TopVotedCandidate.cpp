/*
给你两个整数数组 persons 和 times 。在选举中，第 i 张票是在时刻为 times[i] 时投给候选人 persons[i] 的。

对于发生在时刻 t 的每个查询，需要找出在 t 时刻在选举中领先的候选人的编号。

在 t 时刻投出的选票也将被计入我们的查询之中。在平局的情况下，最近获得投票的候选人将会获胜。

实现 TopVotedCandidate 类：

TopVotedCandidate(int[] persons, int[] times) 使用 persons 和 times 数组初始化对象。
int q(int t) 根据前面描述的规则，返回在时刻 t 在选举中领先的候选人的编号。
 
示例：

输入：
["TopVotedCandidate", "q", "q", "q", "q", "q", "q"]
[[[0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]], [3], [12], [25], [15], [24], [8]]
输出：
[null, 0, 1, 1, 0, 0, 1]

解释：
TopVotedCandidate topVotedCandidate = new TopVotedCandidate([0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]);
topVotedCandidate.q(3); // 返回 0 ，在时刻 3 ，票数分布为 [0] ，编号为 0 的候选人领先。
topVotedCandidate.q(12); // 返回 1 ，在时刻 12 ，票数分布为 [0,1,1] ，编号为 1 的候选人领先。
topVotedCandidate.q(25); // 返回 1 ，在时刻 25 ，票数分布为 [0,1,1,0,0,1] ，编号为 1 的候选人领先。（在平局的情况下，1 是最近获得投票的候选人）。
topVotedCandidate.q(15); // 返回 0
topVotedCandidate.q(24); // 返回 0
topVotedCandidate.q(8); // 返回 1
 

提示：

1 <= persons.length <= 5000
times.length == persons.length
0 <= persons[i] < persons.length
0 <= times[i] <= 109
times 是一个严格递增的有序数组
times[0] <= t <= 109
每个测试用例最多调用 104 次 q
通过次数7,140提交次数15,115

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/online-election
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
using namespace std;

class TopVotedCandidate {
public:
    vector<int> tops;
    vector<int> times;

public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> pcnt;
        int top = -1;
        pcnt[top] = -1;
        for(int& p : persons)
        {
            pcnt[p] ++;
            if(pcnt[p] >= pcnt[top]) // 这里取等 是因为可以票数相等的话更新到最新的   
            {
                top = p;
            }
            tops.push_back(top);
            // 每个时刻（persons）都会有一个tops
        }
        // 此时 pcnt里就存储的是 每个时刻下的投票最高人，相当于先预计算了一波
        this->times = times;
    }
    
    int q(int t) {
        // 然后二分查找迅速找到应该对应的时刻，再去查哈希表tops里这个时刻的最高票选
        int loc = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return tops[loc];
    }
};

// 典型的看起来题意理解了，但写出来还差点水平的题，需要多感觉几遍

// 反正所有数据都有，那么可以直接得到每个时刻的最高票选人，那么剩下的问题就是找到合适的时刻了

// 这样一个思维分解感觉是很经典的，而且写起来也不会太难

// 几个点：哈希表得到不同时刻的票选人；比较时取等来保证结果最新；二分查找来获取最近的时刻

// 可以多做几遍