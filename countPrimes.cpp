/*
统计所有小于非负整数 n 的质数的数量。

 

示例 1：

输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
示例 2：

输入：n = 0
输出：0
示例 3：

输入：n = 1
输出：0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-primes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
int countPrimes(int n) 
{
int a[n+1]; 
    int count = 0;
    for(int i = 2; i < n; i++)
        a[i] = 1;
    
    for(int i = 2; i < n; i++)
        if(a[i])
        {
            count++;
            for(int j = 2 * i; j < n; j += i)
                a[j] = 0;
        }
    
    return count;
}