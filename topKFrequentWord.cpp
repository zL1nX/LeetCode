/*
给一非空的单词列表，返回前 k 个出现次数最多的单词。

返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。

示例 1：

输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
输出: ["i", "love"]
解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
    注意，按字母顺序 "i" 在 "love" 之前。
 

示例 2：

输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
输出: ["the", "is", "sunny", "day"]
解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
    出现次数依次为 4, 3, 2 和 1 次。
 

注意：

假定 k 总为有效值， 1 ≤ k ≤ 集合元素数。
输入的单词均由小写字母组成。
 

扩展练习：

尝试以 O(n log k) 时间复杂度和 O(n) 空间复杂度解决。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/top-k-frequent-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;
struct cmp{
    bool operator()(pair<string, int> a, pair<string, int> b)
    {
        if(a.second != b.second)
        {
            return a.second > b.second;
        }
        else
        {
            return a.first < b.first;
        }
    }
};
vector<string> topKFrequent(vector<string>& words, int k) 
{
    unordered_map<string, int> word_map;
    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> sort_map; // 注意这里优先队列的初始化方式
    vector<string> res;
    for(string word : words)
    {
        word_map[word]++;
    }
    for(const pair<string, int> it : word_map)
    {
        sort_map.push(it);
        if(sort_map.size() > k)
        {
            sort_map.pop();
        }
    }
    while(k--)
    {
        res.push_back(sort_map.top().first);
        sort_map.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}