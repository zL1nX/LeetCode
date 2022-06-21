/*
给你一个有效的 IPv4 地址 address，返回这个 IP 地址的无效化版本。

所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."。

 

示例 1：

输入：address = "1.1.1.1"
输出："1[.]1[.]1[.]1"
示例 2：

输入：address = "255.100.50.0"
输出："255[.]100[.]50[.]0"
 

提示：

给出的 address 是一个有效的 IPv4 地址
通过次数77,943提交次数92,594

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/defanging-an-ip-address
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
using namespace std;

string defangIPaddr(string address) 
{
    string res = "";
    for(char& c : address)
    {
        if(c == '.')
        {
            res.append("[.]");
        }
        else
        {
            res.push_back(c);
        }
    }
    return res;
}

//1108-IP 地址无效化

// C++的replace真的好弱, 不如直接写算了