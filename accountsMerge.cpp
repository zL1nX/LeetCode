/*
给定一个列表 accounts，每个元素 accounts[i] 是一个字符串列表，其中第一个元素 accounts[i][0] 是 名称 (name)，其余元素是 emails 表示该账户的邮箱地址。

现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。

合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是按顺序排列的邮箱地址。账户本身可以以任意顺序返回。

 

示例 1：

输入：
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
输出：
[["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
解释：
第一个和第三个 John 是同一个人，因为他们有共同的邮箱地址 "johnsmith@mail.com"。 
第二个 John 和 Mary 是不同的人，因为他们的邮箱地址没有被其他帐户使用。
可以以任何顺序返回这些列表，例如答案 [['Mary'，'mary@mail.com']，['John'，'johnnybravo@mail.com']，
['John'，'john00@mail.com'，'john_newyork@mail.com'，'johnsmith@mail.com']] 也是正确的。
 

提示：

accounts的长度将在[1，1000]的范围内。
accounts[i]的长度将在[1，10]的范围内。
accounts[i][j]的长度将在[1，30]的范围内。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/accounts-merge
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
// 重点在于数据结构的设计，即几个哈希表的选取比较重要
unordered_map<int, int> father;

int Find(int x)
{
    if(x != father[x])
    {
        father[x] = Find(father[x]);
    }
    return father[x];
}

void Union(int x, int y)
{
    int fx = Find(x), fy = Find(y);
    if(fx == fy)
    {
        return;
    }
    father[fx] = fy;
}


vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
{
    // step1 建表
    unordered_map<string, int> emailToIndex;
    unordered_map<string, string> emailToAccount;
    int emailInd = 0;
    for(int i = 0;i < accounts.size(); i++)
    {
        string name = accounts[i][0];
        for(int j = 1; j < accounts[i].size(); j++)
        {
            string email = accounts[i][j];
            if(!emailToIndex.count(email))
            {
                emailToIndex[accounts[i][j]] = emailInd ++;
                emailToAccount[accounts[i][j]] = name;
            }
        }
    }

    // Step2 合并

    // father 初始化
    for(int i = 0; i < emailInd + 1; i++)
    {
        father[i] = i;
    }

    // 将同一个账户的邮箱合并
    for(int i = 0; i < accounts.size(); i++)
    {
        string firstEmail = accounts[i][1];
        int firstInd = emailToIndex[firstEmail];
        for(int j = 2; j < accounts[i].size(); j++)
        {
            string nextEmail = accounts[i][j];
            int nextInd = emailToIndex[nextEmail];
            Union(firstInd, nextInd);
        }
    }

    // 将同一个连通分量内的邮箱进行提取
    unordered_map<int, vector<string>> IndexToEmail;
    for(auto& [email, ind] : emailToIndex)
    {
        int accountId = Find(ind);
        vector<string>& sameAccountEmail = IndexToEmail[accountId];
        sameAccountEmail.emplace_back(email);
        IndexToEmail[accountId] = sameAccountEmail;
    }


    // Step3 将邮箱进行整理和结果向量的构造
    vector<vector<string>> res;
    for(auto& [idx, email] : IndexToEmail)
    {
        vector<string> currentAccount;
        sort(email.begin(), email.end());
        string name = emailToAccount[email[0]];
        currentAccount.push_back(name);
        for(string e : email)
        {
            currentAccount.push_back(e);
        }
        res.push_back(currentAccount);
    }
    return res;
}