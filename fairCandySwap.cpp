/*
爱丽丝和鲍勃有不同大小的糖果棒：A[i] 是爱丽丝拥有的第 i 根糖果棒的大小，B[j] 是鲍勃拥有的第 j 根糖果棒的大小。

因为他们是朋友，所以他们想交换一根糖果棒，这样交换后，他们都有相同的糖果总量。（一个人拥有的糖果总量是他们拥有的糖果棒大小的总和。）

返回一个整数数组 ans，其中 ans[0] 是爱丽丝必须交换的糖果棒的大小，ans[1] 是 Bob 必须交换的糖果棒的大小。

如果有多个答案，你可以返回其中任何一个。保证答案存在。

 

示例 1：

输入：A = [1,1], B = [2,2]
输出：[1,2]
示例 2：

输入：A = [1,2], B = [2,3]
输出：[1,2]
示例 3：

输入：A = [2], B = [1,3]
输出：[2,3]
示例 4：

输入：A = [1,2,5], B = [2,4]
输出：[5,4]
 

提示：

1 <= A.length <= 10000
1 <= B.length <= 10000
1 <= A[i] <= 100000
1 <= B[i] <= 100000
保证爱丽丝与鲍勃的糖果总量不同。
答案肯定存在。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fair-candy-swap
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;

vector<int> fairCandySwap(vector<int>& A, vector<int>& B) 
{
    int suma = 0, sumb = 0;
    for(int i = 0; i < A.size(); i++)
    {
        suma += A[i];
    }
    for(int i = 0; i < B.size(); i++)
    {
        sumb += B[i];
    }
    int target = (suma + sumb) / 2, needa = target - suma, needb = -needa;
    unordered_map<int, int> matched;
    vector<int> res(2,0);
    for(int i = 0; i < A.size(); i++)
    {   
        matched[A[i] + needa]++;
    }
    for(int i = 0; i < B.size(); i++)
    {
        matched[B[i] + needb] ++;
        if(matched[B[i] + needb] > 1)
        {
            res[0] = B[i] + needb - needa;
            res[1] = B[i];
            break;
        }
    }
    return res;
}