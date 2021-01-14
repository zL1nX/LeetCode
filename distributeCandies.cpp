/*
给定一个偶数长度的数组，其中不同的数字代表着不同种类的糖果，每一个数字代表一个糖果。你需要把这些糖果平均分给一个弟弟和一个妹妹。返回妹妹可以获得的最大糖果的种类数。

示例 1:

输入: candies = [1,1,2,2,3,3]
输出: 3
解析: 一共有三种种类的糖果，每一种都有两个。
     最优分配方案：妹妹获得[1,2,3],弟弟也获得[1,2,3]。这样使妹妹获得糖果的种类数最多。
示例 2 :

输入: candies = [1,1,2,3]
输出: 2
解析: 妹妹获得糖果[2,3],弟弟获得糖果[1,1]，妹妹有两种不同的糖果，弟弟只有一种。这样使得妹妹可以获得的糖果种类数最多。
注意:

数组的长度为[2, 10,000]，并且确定为偶数。
数组中数字的大小在范围[-100,000, 100,000]内。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distribute-candies
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

int distributeCandies(vector<int>& candyType) 
{
     unordered_map<int, int> candy; 
    int cnt = 0;
    for(int i = 0; i < candyType.size(); i++)
    {
        candy[candyType[i]]++;
    }
    vector<pair<int, int>> sorted_candy(candy.begin(), candy.end());
    sort(sorted_candy.begin(), sorted_candy.end(), [](pair<int, int>& a, pair<int, int>& b){
        return a.second < b.second;
    });
    int len = candyType.size() / 2, idx = 0;
    while(cnt < len && cnt < sorted_candy.size())
    {
        if(sorted_candy[idx].second)
        {
            cnt++;
            sorted_candy[idx].second --;
        }
        idx = (idx + 1) % (sorted_candy.size());
    }
    return cnt;
}

/*
解题思路
其实集合不难，主要是返回值难。既然平均分，那么就是分总数的一半，那么如果我的种类数多于一半了，肯定就要返回总数的一半，如果不多余，则返回种类数给妹妹。

代码

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> Set;
        for (auto i:candies)
            Set.insert(i);
        return min(Set.size(), candies.size() / 2);
    }
};

作者：wsy-is-god
链接：https://leetcode-cn.com/problems/distribute-candies/solution/c-unordered_set-202062-by-yu-yang-xian-yi/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/