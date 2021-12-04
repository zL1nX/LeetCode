/*
为了不在赎金信中暴露字迹，从杂志上搜索各个需要的字母，组成单词来表达意思。

给你一个赎金信 (ransomNote) 字符串和一个杂志(magazine)字符串，判断 ransomNote 能不能由 magazines 里面的字符构成。

如果可以构成，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。

 

示例 1：

输入：ransomNote = "a", magazine = "b"
输出：false
示例 2：

输入：ransomNote = "aa", magazine = "ab"
输出：false
示例 3：

输入：ransomNote = "aa", magazine = "aab"
输出：true
 

提示：

1 <= ransomNote.length, magazine.length <= 105
ransomNote 和 magazine 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ransom-note
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>

using namespace std;

bool canConstruct(string ransomNote, string magazine) 
{
    vector<int> rec(26, 0);
    for(char& c : magazine)
    {
        rec[c - 'a']++;
    }
    for(char& c : ransomNote)
    {
        rec[c - 'a']--;
    }
    for(int i = 0; i < 26; i++)
    {
        if(rec[i] < 0)
        {
            return false;
        }
    }
    return true;
}

// 因为都是小写字母，所以可以直接做，即用哈希表记录然后判断即可