/*
给你由 n 个小写字母字符串组成的数组 strs，其中每个字符串长度相等。

这些字符串可以每个一行，排成一个网格。例如，strs = ["abc", "bce", "cae"] 可以排列为：

abc
bce
cae
你需要找出并删除 不是按字典序升序排列的 列。在上面的例子（下标从 0 开始）中，列 0（'a', 'b', 'c'）和列 2（'c', 'e', 'e'）都是按升序排列的，而列 1（'b', 'c', 'a'）不是，所以要删除列 1 。

返回你需要删除的列数。

 

示例 1：

输入：strs = ["cba","daf","ghi"]
输出：1
解释：网格示意如下：
  cba
  daf
  ghi
列 0 和列 2 按升序排列，但列 1 不是，所以只需要删除列 1 。
示例 2：

输入：strs = ["a","b"]
输出：0
解释：网格示意如下：
  a
  b
只有列 0 这一列，且已经按升序排列，所以不用删除任何列。
示例 3：

输入：strs = ["zyx","wvu","tsr"]
输出：3
解释：网格示意如下：
  zyx
  wvu
  tsr
所有 3 列都是非升序排列的，所以都要删除。
 

提示：

n == strs.length
1 <= n <= 100
1 <= strs[i].length <= 1000
strs[i] 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/delete-columns-to-make-sorted
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>

using namespace std;

int minDeletionSize(vector<string>& strs) 
{
    int res = 0;
    int m = strs[0].size(), n = strs.size();
    for(int j = 0; j < m; j++)
    {
        for(int i = 1; i < n; i++)
        {
            if(strs[i][j] < strs[i - 1][j])
            {
                res += 1;
                break;
            }
        }
    }
    return res;
}

// 直接写即可, 矩阵的按每一列元素遍历罢了, 好像也没啥要注意的, 无非是要仔细看清题目