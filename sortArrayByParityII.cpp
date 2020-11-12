/*
给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。

对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。

你可以返回任何满足上述条件的数组作为答案。

 

示例：

输入：[4,2,5,7]
输出：[4,5,2,7]
解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
 

提示：

2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000

*/
#include <vector>
using namespace std;
bool cmp(int a, int b)
{
    return a % 2 < b % 2;
}
vector<int> sortArrayByParityII(vector<int>& A) 
{
    sort(A.begin(), A.end(), cmp);
    int half = A.size() / 2;
    int off = half % 2 ? A.size() / 2 : A.size() / 2 - 1;
    for(int i = 1; i < A.size() / 2; i += 2)
    {
        swap(A[i], A[i + off]);
    }
    return A;
}

/*

vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        vector<int> ans(n);

        int i = 0;
        for (int x: A) {
            if (x % 2 == 0) {
                ans[i] = x;
                i += 2;
            }
        }
        i = 1;
        for (int x: A) {
            if (x % 2 == 1) {
                ans[i] = x;
                i += 2;
            }
        }
        return ans;
    }
*/