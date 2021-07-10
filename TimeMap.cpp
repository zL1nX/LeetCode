/*
创建一个基于时间的键值存储类 TimeMap，它支持下面两个操作：

1. set(string key, string value, int timestamp)

存储键 key、值 value，以及给定的时间戳 timestamp。
2. get(string key, int timestamp)

返回先前调用 set(key, value, timestamp_prev) 所存储的值，其中 timestamp_prev <= timestamp。
如果有多个这样的值，则返回对应最大的  timestamp_prev 的那个值。
如果没有值，则返回空字符串（""）。
 

示例 1：

输入：inputs = ["TimeMap","set","get","get","set","get","get"], inputs = [[],["foo","bar",1],["foo",1],["foo",3],["foo","bar2",4],["foo",4],["foo",5]]
输出：[null,null,"bar","bar",null,"bar2","bar2"]
解释：  
TimeMap kv;   
kv.set("foo", "bar", 1); // 存储键 "foo" 和值 "bar" 以及时间戳 timestamp = 1   
kv.get("foo", 1);  // 输出 "bar"   
kv.get("foo", 3); // 输出 "bar" 因为在时间戳 3 和时间戳 2 处没有对应 "foo" 的值，所以唯一的值位于时间戳 1 处（即 "bar"）   
kv.set("foo", "bar2", 4);   
kv.get("foo", 4); // 输出 "bar2"   
kv.get("foo", 5); // 输出 "bar2"   

示例 2：

输入：inputs = ["TimeMap","set","set","get","get","get","get","get"], inputs = [[],["love","high",10],["love","low",20],["love",5],["love",10],["love",15],["love",20],["love",25]]
输出：[null,null,null,"","high","high","low","low"]
 

提示：

所有的键/值字符串都是小写的。
所有的键/值字符串长度都在 [1, 100] 范围内。
所有 TimeMap.set 操作中的时间戳 timestamps 都是严格递增的。
1 <= timestamp <= 10^7
TimeMap.set 和 TimeMap.get 函数在每个测试用例中将（组合）调用总计 120000 次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/time-based-key-value-store
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class TimeMap {
    unordered_map<string, vector<pair<int, string>>> rec; // 
public:
    /** Initialize your data structure here. */
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        rec[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& candidate = rec[key];
        pair<int, string> locator = {timestamp, string({127})};
        // 用127表示最大的字符串，因此即使时间戳相同，upper bound返回结果 - 1那也是最大的元素
        auto it = upper_bound(candidate.begin(), candidate.end(), locator);
        // 找到一个刚大于pair的地方
        if(it != candidate.begin())
        {
            return (it - 1)->second; // 此时i-1就是一个合法的结果
        }
        return "";
    }
};

// 其实仔细想想，这题如果没有时间戳的限制，那不就是直接用哈希表就成？

// 加上这个时间戳的限制之后，本质上就是要多一步查找

// 因为时间戳的添加过程是严格有序的，因此查找就可以用二分来做