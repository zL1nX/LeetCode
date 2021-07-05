/*
给定一个化学式formula（作为字符串），返回每种原子的数量。

原子总是以一个大写字母开始，接着跟随0个或任意个小写字母，表示原子的名字。

如果数量大于 1，原子后会跟着数字表示原子的数量。如果数量等于 1 则不会跟数字。例如，H2O 和 H2O2 是可行的，但 H1O2 这个表达是不可行的。

两个化学式连在一起是新的化学式。例如 H2O2He3Mg4 也是化学式。

一个括号中的化学式和数字（可选择性添加）也是化学式。例如 (H2O2) 和 (H2O2)3 是化学式。

给定一个化学式，输出所有原子的数量。格式为：第一个（按字典序）原子的名子，跟着它的数量（如果数量大于 1），然后是第二个原子的名字（按字典序），跟着它的数量（如果数量大于 1），以此类推。

示例 1:

输入: 
formula = "H2O"
输出: "H2O"
解释: 
原子的数量是 {'H': 2, 'O': 1}。
示例 2:

输入: 
formula = "Mg(OH)2"
输出: "H2MgO2"
解释: 
原子的数量是 {'H': 2, 'Mg': 1, 'O': 2}。
示例 3:

输入: 
formula = "K4(ON(SO3)2)2"
输出: "K4N2O14S4"
解释: 
原子的数量是 {'K': 4, 'N': 2, 'O': 14, 'S': 4}。
注意:

所有原子的第一个字母为大写，剩余字母都是小写。
formula的长度在[1, 1000]之间。
formula只包含字母、数字和圆括号，并且题目中给定的是合法的化学式。
通过次数7,650提交次数15,587

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-atoms
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

string countOfAtoms(string formula) 
{
    int n = formula.length(), i = 0; // index of atoms
    auto parseAtom = [&]()->string
    {
        string atom;
        atom += formula[i++];
        while(i < n && islower(formula[i]))
        {
            atom += formula[i++];
        }
        return atom;
    };
    // 获取下一个原子，因为可能是Cn这种，所以需要while穷尽考虑

    auto parseNum = [&]()->int
    {
        if(i == n || !isdigit(formula[i])) // 如果一上来就不是数字，说明前面没数字，说明就是1
        {
            return 1; //
        }
        int num = 0;
        while(i < n && isdigit(formula[i]))
        {
            num = num * 10 + int(formula[i++] - '0'); // 可能是多位数字
        }
        return num;
    };

    stack<unordered_map<string, int>> stk;
    stk.push({}); // 先初始一个空哈希表，这样有的存
    while(i < n)
    {
        char ch = formula[i];
        if(ch == '(')
        {
            stk.push({}); // 新的一部分开始了，所以进入一个空哈希表
            i ++;
        }
        else if(ch == ')')
        {
            i++; // 注意先后移再考虑，即同步好这唯一的一个下标
            int nearestNum = parseNum(); // 整个括号的数字
            unordered_map<string, int> current = stk.top(); // 此时栈顶是这整个括号对应的记录表
            stk.pop();
            for(auto& [atom, num] : current)
            {
                stk.top()[atom] += num * nearestNum; // 把整体数字计算好后，需要加到上一层括号的表里
            }
        }
        else
        {
            string atom = parseAtom(); // 就近的那个原子叫啥，此时下标应恰好为一个字符
            int atom_num = parseNum();
            stk.top()[atom] += atom_num;
        }
    }

    vector<pair<string,int>> rec;
    string res = "";
    for(auto& [atom, v] : stk.top())
    {
        rec.emplace_back(atom, v);
    }

    sort(rec.begin(), rec.end()); // 用vector进行排序方便结果输出
    for(auto& p : rec)
    {
        res += p.first;
        if(p.second > 1) // 要是数量大于1个，才需要显式说明
        {
            res += to_string(p.second);
        }
    }
    return res;

}

// 难顶，感觉这种题真的需要多写，或者说很考验你实际解决问题的能力

// 因为题目把化学式简化了，所以本质上就是对括号的处理；因此这样就需要用栈来搞

// 出栈入栈的是用来记录原子数量的哈希表（没想到吧），一对括号对应着一个哈希表

// 注意两个功能函数的设计 以及  下标的同步