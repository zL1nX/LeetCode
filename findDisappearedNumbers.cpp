/*
给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

找到所有在 [1, n] 范围之间没有出现在数组中的数字。

您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

示例:

输入:
[4,3,2,7,8,2,3,1]

输出:
[5,6]
通过次数77,399提交次数124,743

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) 
{
    vector<int> leftNumbers;
    int n = nums.size();
    for(int i = 0; i < n; i++)
    {
        nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
    }
    for(int i = 0;i < n;i++)
    {
        if(nums[i] > 0)
        {
            leftNumbers.push_back(i + 1);
        }
    }
    return leftNumbers;
}

vector<int> findDisappearedNumbers2(vector<int>& nums) 
{
    vector<int> appearedNumbers, marked(nums.size(), 0);
    for(int i = 0; i < nums.size(); i++)
    {
        marked[nums[i] - 1] ++;
    }
    for(int i = 0; i < nums.size(); i++)
    {
        if(!marked[i])
        {
            appearedNumbers.push_back(i + 1);
        }
    }
    return appearedNumbers;
}

/*
 //首先，题目就是要对比一个排序号的顺序序列，查看哪些没出现，所以直接将两个数组摆出来：
    //4,3,2,7,8,2,3,1  数组1
    //1,2,3,4,5,6,7,8  数组2
    //上面是原数组，下面是序列数组；
    //遇到上面的数字，就将数组2中同样数字给替换为：替换字符（随便设置，这里可以设为*），意思就是该数字已经出现过了；
    //这样不断对照查找哪些元素出现过；则没被替换的就是没出现过的；
    //这基本是最基本的逻辑；

    //4,3,2,7,8,2,3,1

    //依次类推替换
    //1,2,3,*,5,6,7,8
    //1,2,*,*,5,6,7,8
    //1,*,*,*,5,6,7,8
    //1,*,*,*,5,6,*,8
    //1,*,*,*,5,6,*,*
    //1,*,*,*,5,6,*,*  位置2已经替换过,不用再替换；
    //1,*,*,*,5,6,*,*  位置3已经替换过,不用再替换；
    //*,*,*,*,5,6,*,*  此时5，6没被替换，说明5，6在数组1中没出现过；

    //但这样的替换需要额外用一个序列数组（1到n)，
    //所以才有用自身数组元素的负数作为替换字符的方法，这样被替换字符也可以继续作为索引值使用；节省了一个数组空间；
*/