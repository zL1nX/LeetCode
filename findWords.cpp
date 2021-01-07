/*

给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。

 



 

示例：

输入: ["Hello", "Alaska", "Dad", "Peace"]
输出: ["Alaska", "Dad"]
 

注意：

你可以重复使用键盘上同一字符。
你可以假设输入的字符串将只包含字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/keyboard-row
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> findWords(vector<string>& words) 
{
    vector<vector<char>> boards = {{'q','w','e','r','t','y','u','i','i','o'}, {'a','s','d','f','g','h','j','k','l'},{'z','x','c','v','b','n','m'}};
    vector<int> loc(26, 0);
    vector<string> res;
    int num = 1;
    for(int i = 0; i < boards.size(); i ++)
    {
        for(char c : boards[i])
        {
            loc[c - 'a'] = num;
        }
        num++;
    }
    for(int i = 0; i < words.size(); i ++)
    {
        string lword = "";
        transform(words[i].begin(), words[i].end(), lword.begin(), ::tolower);
        bool flag = true;
        for(int j = 1; j < lword.length(); j++)
        {
            if(loc[lword[j] - 'a'] != loc[lword[j - 1] - 'a'])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            res.push_back(words[i]);
        }
    }
    return res;
}