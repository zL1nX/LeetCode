/*
给你一个数组 orders，表示客户在餐厅中完成的订单，确切地说， orders[i]=[customerNamei,tableNumberi,foodItemi] ，其中 customerNamei 是客户的姓名，tableNumberi 是客户所在餐桌的桌号，而 foodItemi 是客户点的餐品名称。

请你返回该餐厅的 点菜展示表 。在这张表中，表中第一行为标题，其第一列为餐桌桌号 “Table” ，后面每一列都是按字母顺序排列的餐品名称。接下来每一行中的项则表示每张餐桌订购的相应餐品数量，第一列应当填对应的桌号，后面依次填写下单的餐品数量。

注意：客户姓名不是点菜展示表的一部分。此外，表中的数据行应该按餐桌桌号升序排列。

 

示例 1：

输入：orders = [["David","3","Ceviche"],["Corina","10","Beef Burrito"],["David","3","Fried Chicken"],["Carla","5","Water"],["Carla","5","Ceviche"],["Rous","3","Ceviche"]]
输出：[["Table","Beef Burrito","Ceviche","Fried Chicken","Water"],["3","0","2","1","0"],["5","0","1","0","1"],["10","1","0","0","0"]] 
解释：
点菜展示表如下所示：
Table,Beef Burrito,Ceviche,Fried Chicken,Water
3    ,0           ,2      ,1            ,0
5    ,0           ,1      ,0            ,1
10   ,1           ,0      ,0            ,0
对于餐桌 3：David 点了 "Ceviche" 和 "Fried Chicken"，而 Rous 点了 "Ceviche"
而餐桌 5：Carla 点了 "Water" 和 "Ceviche"
餐桌 10：Corina 点了 "Beef Burrito" 
示例 2：

输入：orders = [["James","12","Fried Chicken"],["Ratesh","12","Fried Chicken"],["Amadeus","12","Fried Chicken"],["Adam","1","Canadian Waffles"],["Brianna","1","Canadian Waffles"]]
输出：[["Table","Canadian Waffles","Fried Chicken"],["1","2","0"],["12","0","3"]] 
解释：
对于餐桌 1：Adam 和 Brianna 都点了 "Canadian Waffles"
而餐桌 12：James, Ratesh 和 Amadeus 都点了 "Fried Chicken"
示例 3：

输入：orders = [["Laura","2","Bean Burrito"],["Jhon","2","Beef Burrito"],["Melissa","2","Soda"]]
输出：[["Table","Bean Burrito","Beef Burrito","Soda"],["2","1","1","1"]]
 

提示：

1 <= orders.length <= 5 * 10^4
orders[i].length == 3
1 <= customerNamei.length, foodItemi.length <= 20
customerNamei 和 foodItemi 由大小写英文字母及空格字符 ' ' 组成。
tableNumberi 是 1 到 500 范围内的整数。
通过次数7,450提交次数11,540

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/display-table-of-food-orders-in-a-restaurant
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

vector<vector<string>> displayTable(vector<vector<string>>& orders)
{
    unordered_map<string, vector<string>> table_to_dish;
    set<string> dishes;
    vector<vector<string>> res;
    for(int i = 0; i < orders.size(); i++)
    {
        table_to_dish[orders[i][1]].push_back(orders[i][2]); // table : dish1, dish2
        dishes.insert(orders[i][2]);
    }

    vector<string> first_line(dishes.size() + 1);
    first_line[0] = "Table";
    copy(dishes.begin(), dishes.end(), first_line.begin() + 1);
    res.push_back(first_line);

    for(auto it : table_to_dish)
    {
        vector<string> table_order;
        table_order.push_back(it.first);
        for(int i = 1; i < first_line.size(); i++)
        {
            int num = count(it.second.begin(), it.second.end(), first_line[i]);
            table_order.push_back(to_string(num));
        }
        res.push_back(table_order);
    }

    sort(res.begin() + 1, res.end(), [](const vector<string>&a, const vector<string>& b){
        return stoi(a[0]) < stoi(b[0]);
    });
    return res;
}

/**vector<vector<string>> displayTable(vector<vector<string>>& orders){
        vector<vector<string>>res;
        set<string>food;       
        map<int,unordered_map<string,int>>m;
        for(auto order:orders){
            m[stoi(order[1])][order[2]]++;  
            food.insert(order[2]);            
        }
        vector<string>head(food.begin(),food.end());
        head.insert(head.begin(),"Table");
        res.push_back(head);
        for(auto p=m.begin();p!=m.end();p++){
            vector<string>t;
            t.push_back(to_string(p->first));
            for(auto q=food.begin();q!=food.end();q++){
                t.push_back(to_string(p->second[*q]));
            }
            res.push_back(t);
        }
        return res;
    }*/

// 这道题就是直接模拟就好，但选取合适的数据结构可以省很多事

// 可以直接用二维map记录数量，然后同时map本身自带排序功能

// 然后就是枯燥无味的插入即可