/*
你正在参与祖玛游戏的一个变种。

在这个祖玛游戏变体中，桌面上有 一排 彩球，每个球的颜色可能是：红色 'R'、黄色 'Y'、蓝色 'B'、绿色 'G' 或白色 'W' 。你的手中也有一些彩球。

你的目标是 清空 桌面上所有的球。每一回合：

从你手上的彩球中选出 任意一颗 ，然后将其插入桌面上那一排球中：两球之间或这一排球的任一端。
接着，如果有出现 三个或者三个以上 且 颜色相同 的球相连的话，就把它们移除掉。
如果这种移除操作同样导致出现三个或者三个以上且颜色相同的球相连，则可以继续移除这些球，直到不再满足移除条件。
如果桌面上所有球都被移除，则认为你赢得本场游戏。
重复这个过程，直到你赢了游戏或者手中没有更多的球。
给你一个字符串 board ，表示桌面上最开始的那排球。另给你一个字符串 hand ，表示手里的彩球。请你按上述操作步骤移除掉桌上所有球，计算并返回所需的 最少 球数。如果不能移除桌上所有的球，返回 -1 。

 

示例 1：

输入：board = "WRRBBW", hand = "RB"
输出：-1
解释：无法移除桌面上的所有球。可以得到的最好局面是：
- 插入一个 'R' ，使桌面变为 WRRRBBW 。WRRRBBW -> WBBW
- 插入一个 'B' ，使桌面变为 WBBBW 。WBBBW -> WW
桌面上还剩着球，没有其他球可以插入。
示例 2：

输入：board = "WWRRBBWW", hand = "WRBRW"
输出：2
解释：要想清空桌面上的球，可以按下述步骤：
- 插入一个 'R' ，使桌面变为 WWRRRBBWW 。WWRRRBBWW -> WWBBWW
- 插入一个 'B' ，使桌面变为 WWBBBWW 。WWBBBWW -> WWWW -> empty
只需从手中出 2 个球就可以清空桌面。
示例 3：

输入：board = "G", hand = "GGGGG"
输出：2
解释：要想清空桌面上的球，可以按下述步骤：
- 插入一个 'G' ，使桌面变为 GG 。
- 插入一个 'G' ，使桌面变为 GGG 。GGG -> empty
只需从手中出 2 个球就可以清空桌面。
示例 4：

输入：board = "RBYYBBRRB", hand = "YRBGB"
输出：3
解释：要想清空桌面上的球，可以按下述步骤：
- 插入一个 'Y' ，使桌面变为 RBYYYBBRRB 。RBYYYBBRRB -> RBBBRRB -> RRRB -> B
- 插入一个 'B' ，使桌面变为 BB 。
- 插入一个 'B' ，使桌面变为 BBB 。BBB -> empty
只需从手中出 3 个球就可以清空桌面。
 

提示：

1 <= board.length <= 16
1 <= hand.length <= 5
board 和 hand 由字符 'R'、'Y'、'B'、'G' 和 'W' 组成
桌面上一开始的球中，不会有三个及三个以上颜色相同且连着的球
通过次数4,885提交次数11,423

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zuma-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <unordered_map>
using namespace std;

string cancelBoard(string board)
{
    for(int i = 0, j = 0; i <= board.length(); ++i)
    {
        if(i < board.length() && board[i] == board[j])
        {
            continue;
        }

        if(i - j >= 3)
        {
            return cancelBoard(board.substr(0, j) + board.substr(i));
        }
        else
        {
            j = i;
        }
    }
}

int backtrack(string board, unordered_map<char, int> rec)
{
    board = cancelBoard(board);
    if(board.empty())
    {
        return 0; //
    }
    int cnt = INT_MAX, j = 0;
    for(int i = 0; i <= board.size(); i++)
    {
        if(i < board.size() && board[j] == board[i])
        {
            continue;
        }
        int need = 3 - (i - j);
        if(rec[board[j]] >= need)
        {
            rec[board[j]] -= need; //
            int current = backtrack(board.substr(0, j) + board.substr(i), rec); //
            if(current != INT_MAX)
            {
                cnt = min(cnt, current + need); // 
            }
            rec[board[j]] += need;
        }
        j = i;
    }
    return cnt;
}

int findMinStep(string board, string hand) 
{
    unordered_map<char, int> rec;
    for(char c : hand)
    {
        ++rec[c];
    }
    int res = INT_MAX;
    res = backtrack(board, rec);
    return res == INT_MAX ? -1 : res;
}

/*
class Solution {
public:
    int ans=INT_MAX;
    int findMinStep(string board, string hand) {
        unordered_map<char,int>hand2cnt;
        for(char c:hand)hand2cnt[c]++;
        dfs(0,board,hand2cnt);
        return ans==INT_MAX?-1:ans;
    }
    void dfs(int usedCnt,string&board,unordered_map<char,int>&hand2cnt){
        if(usedCnt>=ans)return ;
        if(board.empty()){
            ans=min(ans,usedCnt);
            return;
        }
        for(int slow=0,fast=0;fast<=board.size();fast++){
            if(fast<board.size()&&board[slow]==board[fast])continue;
            //2个连续则需要1个，1个连续则需要两个
            int alreadyHad=fast-slow;
            int need=3-alreadyHad;
            if(hand2cnt.count(board[slow])&&hand2cnt[board[slow]]>=need){
                string newBoard=board.substr(0,slow)+board.substr(fast);
                update(newBoard);
                hand2cnt[board[slow]]-=need;
                dfs(usedCnt+need,newBoard,hand2cnt);
                hand2cnt[board[slow]]+=need;
            }
            //RRWWRRBBRR  WB,先R[B]RWWRRBBRR再R[B]RWW[W]RRBBRR
            // 这里这种处理方法感觉好牵强，这直接强行让自己先走一手，以实现连续的相消，好奇怪的写法
            if(need==1){
                //5种颜色，如果和[slow]不同色且hand有
                for(char color:{'R','Y','B','G','W'}){
                    if(color==board[slow]||hand2cnt.count(color)==0||hand2cnt[color]==0)continue;
                    string newBoard=board;
                    newBoard.insert(newBoard.begin()+slow+1,color);
                    hand2cnt[color]--;
                    dfs(usedCnt+1,newBoard,hand2cnt);
                    hand2cnt[color]++;
                }
            }
            slow=fast;
        }
    }
    void update(string &board){
       for(int slow=0,fast=0;fast<=board.size();fast++){
           if(fast<board.size()&&board[slow]==board[fast])continue;
           if(fast-slow>=3){
               board.erase(slow,fast-slow);
               fast=0;
           }
           slow=fast;
       } 
    }
};
*/

// 流汗黄豆

// 最开始的解法就是，暴搜然后回溯，但这种解法有个问题是，他机械地找到自己能消去的第一种元素，这样一来，本来能攒着消掉其他元素，但由于它这么一搞

// 有些元素就落单了，结果就消不了了。这种问题的解决方法就是，暴力地去遍历每种消去策略，然后取一个最小值

// 这个题属实有点强人所难