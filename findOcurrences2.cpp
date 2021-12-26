/*
给出第一个词 first 和第二个词 second，考虑在某些文本 text 中可能以 "first second third" 形式出现的情况，其中 second 紧随 first 出现，third 紧随 second 出现。

对于每种这样的情况，将第三个词 "third" 添加到答案中，并返回答案。

 

示例 1：

输入：text = "alice is a good girl she is a good student", first = "a", second = "good"
输出：["girl","student"]
示例 2：

输入：text = "we will we will rock you", first = "we", second = "will"
输出：["we","rock"]
 

提示：

1 <= text.length <= 1000
text 由小写英文字母和空格组成
text 中的所有单词之间都由 单个空格字符 分隔
1 <= first.length, second.length <= 10
first 和 second 由小写英文字母组成
通过次数15,599提交次数24,429

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/occurrences-after-bigram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> findOcurrences(string text, string first, string second) 
{
    string word;
    vector<string> words, results;
    stringstream ss(text);
    while(ss >> word)
    {
        words.push_back(word);
    }
    for(int i = 0; i < words.size() - 2; i ++)
    {
        if(words[i] == first && words[i + 1] == second)
        {
            results.push_back(words[i + 2]);
        }
    }
    return results;
}

//  这道题就是直接模拟就好，没有太多别的思路，而且写起来也很简单