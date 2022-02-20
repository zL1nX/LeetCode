/*
有两种特殊字符：

第一种字符可以用一个比特 0 来表示
第二种字符可以用两个比特(10 或 11)来表示、
给定一个以 0 结尾的二进制数组 bits ，如果最后一个字符必须是一位字符，则返回 true 。

 

示例 1:

输入: bits = [1, 0, 0]
输出: true
解释: 唯一的编码方式是一个两比特字符和一个一比特字符。
所以最后一个字符是一比特字符。
示例 2:

输入: bits = [1, 1, 1, 0]
输出: false
解释: 唯一的编码方式是两比特字符和两比特字符。
所以最后一个字符不是一比特字符。
 

提示:

1 <= bits.length <= 1000
bits[i] == 0 or 1
通过次数37,974提交次数72,465

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/1-bit-and-2-bit-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

bool isOneBitCharacter(vector<int>& bits) 
{
    int p = 0, n = bits.size();
    while(p < n - 1)
    {
        if(bits[p] == 0)
            p++;
        else
            p += 2;
    }
    return p == n - 1;
}


// 凡是碰到1就跳过下一个，因为两个位的字符都是以1开头的，所以碰到1，必然不可能是一个字符

// 掌握了这个规律，也就意味着其他情况都正常往后遍历，如果能恰好走到最后一个字符，就说明前面的这些字符都是满足条件的

// 有点脑筋急转弯的一道题