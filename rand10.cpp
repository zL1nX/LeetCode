/*
已有方法 rand7 可生成 1 到 7 范围内的均匀随机整数，试写一个方法 rand10 生成 1 到 10 范围内的均匀随机整数。

不要使用系统的 Math.random() 方法。

 

示例 1:

输入: 1
输出: [7]
示例 2:

输入: 2
输出: [8,4]
示例 3:

输入: 3
输出: [8,1,10]
 

提示:

rand7 已定义。
传入参数: n 表示 rand10 的调用次数。
 

进阶:

rand7()调用次数的 期望值 是多少 ?
你能否尽量少调用 rand7() ?
通过次数37,779提交次数68,363

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-rand10-using-rand7
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;

int rand7()
{
    return 0;
}

int rand10() 
{
    int temp;
    while(true)
    {
        temp = (rand7() - 1) * 7 + rand7(); // 1 - 49
        // rand7() - 1 => 0-6
        // *7 = 0 - 42
        // + rand7() = 1 - 49
        if(temp <= 40) 
        {
            break; // 1 - 40
        }
    }
    return temp % 10 + 1; // %10 => 0 - 9 ; +1 => 1 - 10
}

// (rand(X)-1)*Y + randY() -----生成 [1,X*Y]区间，并且等概。 

// 注意这个公式里 *Y就是相当于分成了Y份，这样在+rangY时才依然能保持等概

// rand8 rand9原理也类似

// 面试可能会问类似的。总之就是先套公式，然后截断到整10的倍数，最后取模即可