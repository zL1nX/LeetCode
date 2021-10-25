/*
给你一个字符串数组 words ，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。键盘如下图所示。

美式键盘 中：

第一行由字符 "qwertyuiop" 组成。
第二行由字符 "asdfghjkl" 组成。
第三行由字符 "zxcvbnm" 组成。


 

示例 1：

输入：words = ["Hello","Alaska","Dad","Peace"]
输出：["Alaska","Dad"]
示例 2：

输入：words = ["omk"]
输出：[]
示例 3：

输入：words = ["adsdf","sfd"]
输出：["adsdf","sfd"]
 

提示：

1 <= words.length <= 20
1 <= words[i].length <= 100
words[i] 由英文字母（小写和大写字母）组成
通过次数36,276提交次数50,050

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/keyboard-row
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>

using namespace std;

vector<string> findWords(vector<string>& words) 
{
    vector<int> loc = {2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};
    vector<string> result;
    for(int i = 0; i < words.size(); i++)
    {
        bool flag = true;
        int cloc = loc[tolower(words[i][0]) - 'a'];
        for(int j = 1; j < words[i].size(); j++)
        {
            if(loc[tolower(words[i][j]) - 'a'] != cloc)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            result.push_back(words[i]);
        }
    }
    return result;
}

// 直接哈希表模拟，庵后判断就行

// 我居然原来做过这题但一点印象都没有