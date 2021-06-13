/*
你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。

假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。

你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。

示例:

给定 n = 5，并且 version = 4 是第一个错误的版本。

调用 isBadVersion(3) -> false
调用 isBadVersion(5) -> true
调用 isBadVersion(4) -> true

所以，4 是第一个错误的版本。 


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-bad-version
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;

// for own purpose, not the real function
bool isBadVersion(int n)
{
    return n > 10;
}

int firstBadVersion(int n) 
{
    int right = n, left = 1, mid = n / 2;
    while(left < right) // 最后结束的条件是left==right，所以返回哪个都行
    {
        mid = left + (right - left) / 2;
        if(isBadVersion(mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }    
    return left;    
}

// 有序 + 查找，那么这道题显然是要用二分

// 因此，写一个标准的左闭右开的二分代码即可

// 要记得左闭右开的代码里，right每次是mid而不是mid - 1；