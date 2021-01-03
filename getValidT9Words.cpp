/*
在老式手机上，用户通过数字键盘输入，手机将提供与这些数字相匹配的单词列表。每个数字映射到0至4个字母。给定一个数字序列，实现一个算法来返回匹配单词的列表。你会得到一张含有有效单词的列表。映射如下图所示：



示例 1:

输入: num = "8733", words = ["tree", "used"]
输出: ["tree", "used"]
示例 2:

输入: num = "2", words = ["a", "b", "c", "d"]
输出: ["a", "b", "c"]
提示：

num.length <= 1000
words.length <= 500
words[i].length == num.length
num中不会出现 0, 1 这两个数字

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/t9-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <string>
using namespace std;

vector<string> getValidT9Words(string num, vector<string>& words) 
{
    vector<int> boards = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
    vector<string> matched;
    for(string word : words)
    {
        string number = "";
        for(char c : word)
        {
            number += boards[c - 'a'];
        }
        if(number == num)
        {
            matched.push_back(word);
        }
    }
    return matched;
}