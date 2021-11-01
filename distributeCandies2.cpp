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
通过次数48,802提交次数70,081

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distribute-candies
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
using namespace std;

int distributeCandies(vector<int>& candyType) 
{
    unordered_map<int, int> candies;
    for(int candy : candyType)
    {
        candies[candy]++;
    }
    vector<pair<int, int>> candyList(candies.begin(), candies.end());
    sort(candyList.begin(), candyList.end(), [](pair<int, int>&a, pair<int, int>&b){
        return a.second < b.second;
    });
    int sisCnt = 0, idx = 0, upper = candyType.size() / 2;
    while(sisCnt < upper && sisCnt < candyList.size())
    {
        if(candyList[idx].second)
        {
            sisCnt++;
            candyList[idx].second --;
        }
        idx = (idx + 1) % candyList.size();
    }
    return sisCnt;
}

// return min(len(set(candies)),len(candies)//2)

// 再做一遍居然没有想起来，其实set的方法可以直接解决