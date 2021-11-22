/*
给你一个字符串 s ，其中包含字母顺序打乱的用英文单词表示的若干数字（0-9）。按 升序 返回原始的数字。

 

示例 1：

输入：s = "owoztneoer"
输出："012"
示例 2：

输入：s = "fviefuro"
输出："45"
 

提示：

1 <= s.length <= 105
s[i] 为 ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"] 这些字符之一
s 保证是一个符合题目要求的字符串
通过次数12,300提交次数20,773

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reconstruct-original-digits-from-english
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string originalDigits(string s) 
{
    unordered_map<char, int> rec;
    vector<int> cnt(10);
    for(auto& c : s)
    {
        rec[c]++;
    }
    cnt[0] = rec['z'];
    cnt[2] = rec['w'];
    cnt[4] = rec['u'];
    cnt[6] = rec['x'];
    cnt[8] = rec['g'];
    // 这些字母和数字都是一一对应的
    cnt[3] = rec['h'] - cnt[8];
    cnt[5] = rec['f'] - cnt[4];
    cnt[7] = rec['s'] - cnt[6];
    // 比如：3和8这两个数字都会出现h这个字母
    cnt[9] = rec['i'] - cnt[5] - cnt[6] - cnt[8]; // 9的话用i来做，因为其他字母中有的会出现两次
    cnt[1] = rec['o'] - cnt[0] - cnt[2] - cnt[4];
    string res;
    for(int i = 0; i < 10; i++)
    {
        for(int _ = 0; _ < cnt[i]; _++)
        {
            res += i + '0';
        }
    }
    return res;
}

// 虽然题目很无聊，但是这个解法还是很有意思的。

// 因为从算法的角度，似乎不存在一个神奇的、普适的算法，能直接将0-9进行识别，因此这题一定是一种比较取巧，而且只适用于特定情况的解法

// 具体而言，就是去统计0-9英文单词对应的字母出现情况，即搞一张 字母-在什么数字中出现的 词频表

// 根据这张表，首先看哪些字母只会在这些数字出现时出现，然后再看有两个数字的，最后通过相差关系，得到每个数字对应的字母出现次数

// 注意，有的单词里字母可能出现两遍，所以要尽可能找那些只有一次的对应关系