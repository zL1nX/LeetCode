/*
编写一个函数，不用临时变量，直接交换numbers = [a, b]中a与b的值。

示例：

输入: numbers = [1,2]
输出: [2,1]
提示：

numbers.length == 2

*/
#include <vector>
using namespace std;

vector<int> swapNumbers(vector<int>& numbers) 
{
    numbers[0] = numbers[0] ^ numbers[1];
    numbers[1] = numbers[0] ^ numbers[1];
    numbers[0] = numbers[1] ^ numbers[0];
    return numbers;
    
    //其他方法
    // return {numbers[1], numbers[0]};

    // numbers[1] = numbers[0] - numbers[1] + (numbers[0] = numbers[1]);
    // return numbers;

    // numbers[1] = numbers[1] - numbers[0];
    // numbers[0] = numbers[0] + numbers[1];
    // numbers[1] = numbers[0] - numbers[1];
    // return numbers;


}