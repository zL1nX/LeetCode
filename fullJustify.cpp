/*
给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入额外的空格。

说明:

单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。
示例:

输入:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
输出:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
示例 2:

输入:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
输出:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
     因为最后一行应为左对齐，而不是左右两端对齐。       
     第二行同样为左对齐，这是因为这行只包含一个单词。
示例 3:

输入:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
输出:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
通过次数21,792提交次数44,724

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/text-justification
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <string>
using namespace std;

string join(vector<string>& words, int start, int end, string separator)
{
    string s = words[start];
    for(int i  = start + 1; i < end; i++)
    {
        s += separator + words[i];
    }
    return s;
}



vector<string> fullJustify(vector<string>& words, int maxWidth) 
{
    vector<string> res;
    int wordpos = 0, n = words.size();
    while(true)
    {
        int start = wordpos;
        int linelen = 0;
        // 先不断的累加，直到单词与空格的长度超过了max
        while(wordpos < n && linelen + words[wordpos].length() + wordpos - start <= maxWidth)
        {
            linelen += words[wordpos].length();
            wordpos++;
        }
        // 注意区间是左闭右开
    
        // 下面讨论一个句子的三种情况
        
        // 该句子是最后一行了 
        if(wordpos == n)
        {
            string lastline = join(words, start, wordpos, " ");
            lastline += string(maxWidth - lastline.length(), ' '); // 左对齐，剩下的都是空格
            res.push_back(lastline); 
            return res;
        }
        
        // 该句子是中间的行，其中
        int numwords = wordpos - start, numspaces = maxWidth - linelen;
        if(numwords == 1) // 该句只有一个单词
        {
            string singlewordline = words[start] + string(numspaces, ' ');
            res.push_back(singlewordline);
            continue;
        } 

        // 该句有多个单词
        int avgspaces = numspaces / (numwords - 1), extracspaces = numspaces % (numwords - 1);// numwords -1 是之间的空隙 
        // 先算出每个单词之间的空格分布多少
        string wordsline_extra = join(words, start, start + extracspaces + 1, string(avgspaces + 1, ' '));
        string wordsline_normal = join(words, start + extracspaces + 1, wordpos, string(avgspaces, ' '));
        string wordsline = wordsline_extra + string(avgspaces, ' ') + wordsline_normal; // 别忘了两段之间的空格
        res.push_back(wordsline);

    }
}

// 太长了这代码，还是比较考验码力的，感觉怎么都能写出来，但就是经验和简洁上有差距

// 重点是要能分清句子分布的三种情况