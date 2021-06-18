/*
对于给定的整数 n, 如果n的k（k>=2）进制数的所有数位全为1，则称 k（k>=2）是 n 的一个好进制。

以字符串的形式给出 n, 以字符串的形式返回 n 的最小好进制。

 

示例 1：

输入："13"
输出："3"
解释：13 的 3 进制是 111。
示例 2：

输入："4681"
输出："8"
解释：4681 的 8 进制是 11111。
示例 3：

输入："1000000000000000000"
输出："999999999999999999"
解释：1000000000000000000 的 999999999999999999 进制是 11。
 

提示：

n的取值范围是 [3, 10^18]。
输入总是有效且没有前导 0。
 

通过次数3,697提交次数7,201

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-good-base
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <math.h>
typedef long long int ll;
using namespace std;

ll bitToNum(int bit_num, ll flag)
{
    ll res = 0;
    for(int i = 0; i < bit_num; i++)
    {
        res += pow(flag, i); 
    }
    return res;
}


string smallestGoodBase(string n) 
{
    ll upper_bound = 1e18;
    ll num = atoll(n.c_str());
    int max_bit = 64;
    ll res = num;
    for(int bit = 1; bit <= max_bit; bit++)
    {
        // 对有多少个bit为1进行遍历
        ll l = 2, r = num, mid = 0; // 每个bit的情况都会考察下在这个bit数量的条件下，是否有进制满足题意
        while(l < r)
        {
            mid = l + (r - l) / 2;
            ll tmp = bitToNum(bit, mid); //
            if(tmp == num)
            {
                res = min(res, mid); // 返回一个最小进制
                break;
            }
            else if(tmp < num)
            {
                if(tmp == 0)
                {
                    r = mid;
                }
                else
                {
                   l = mid + 1;
                }
            }
            else
            {
                r = mid;
            }
        }
    }
    return to_string(res);
}
// 按理说朴素二分应该没错啊，但就是搜不到值，佛了
string smallestGoodBase(string n) 
{
        long nVal = stol(n);
        int mMax = floor(log(nVal) / log(2));
        for (int m = mMax; m > 1; m--) {
            int k = pow(nVal, 1.0 / m);
            long mul = 1, sum = 1;
            for (int i = 0; i < m; i++) {
                mul *= k;
                sum += mul;
            }
            if (sum == nVal) {
                return to_string(k);
            }
        }
        return to_string(nVal - 1);
}