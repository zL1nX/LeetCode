/*

给定一个整数数组 A，如果它是有效的山脉数组就返回 true，否则返回 false。

让我们回顾一下，如果 A 满足下述条件，那么它是一个山脉数组：

A.length >= 3
在 0 < i < A.length - 1 条件下，存在 i 使得：
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]

*/
#include <vector>
using namespace std;

bool validMountainArray(vector<int>& A) 
{
    if(!A.size())
    {
        return false;
    }
    int p = A[0], i = 1;
    for(; i < A.size() && A[i] > A[i - 1]; i++) {}
    if(i == 1 || i == A.size())
    {
        return false;
    }
    for(;i < A.size() && A[i] < A[i - 1]; i++){}
    if(i != A.size())
    {
        return false;
    }
    return true;
}