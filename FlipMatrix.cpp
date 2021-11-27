/*
给你一个 m x n 的二元矩阵 matrix ，且所有值被初始化为 0 。请你设计一个算法，随机选取一个满足 matrix[i][j] == 0 的下标 (i, j) ，并将它的值变为 1 。所有满足 matrix[i][j] == 0 的下标 (i, j) 被选取的概率应当均等。

尽量最少调用内置的随机函数，并且优化时间和空间复杂度。

实现 Solution 类：

Solution(int m, int n) 使用二元矩阵的大小 m 和 n 初始化该对象
int[] flip() 返回一个满足 matrix[i][j] == 0 的随机下标 [i, j] ，并将其对应格子中的值变为 1
void reset() 将矩阵中所有的值重置为 0
 

示例：

输入
["Solution", "flip", "flip", "flip", "reset", "flip"]
[[3, 1], [], [], [], [], []]
输出
[null, [1, 0], [2, 0], [0, 0], null, [2, 0]]

解释
Solution solution = new Solution(3, 1);
solution.flip();  // 返回 [1, 0]，此时返回 [0,0]、[1,0] 和 [2,0] 的概率应当相同
solution.flip();  // 返回 [2, 0]，因为 [1,0] 已经返回过了，此时返回 [2,0] 和 [0,0] 的概率应当相同
solution.flip();  // 返回 [0, 0]，根据前面已经返回过的下标，此时只能返回 [0,0]
solution.reset(); // 所有值都重置为 0 ，并可以再次选择下标返回
solution.flip();  // 返回 [2, 0]，此时返回 [0,0]、[1,0] 和 [2,0] 的概率应当相同
 

提示：

1 <= m, n <= 104
每次调用flip 时，矩阵中至少存在一个值为 0 的格子。
最多调用 1000 次 flip 和 reset 方法。
通过次数4,486提交次数10,738

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/random-flip-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
using namespace std;

class FlipMatrix {
private:
    unordered_map<int, int> rec;
    int m, n;
    int leftloc;
public:
    FlipMatrix(int m, int n) {
        this->m = m;
        this->n = n;
        this->leftloc = m * n;
        srand(time(NULL));
    }
    
    vector<int> flip() {
        vector<int> res;
        int loc = rand() % leftloc;
        if(rec.count(loc)) // 要是这个位置之前被选过了，但题目需要返回一个0位，而根据对hash表的设置，如果出现过，那么出现过的这个位会被置为一个没被动过的位置
        {
            res = {rec[loc] / n, rec[loc] % n}; // 所以直接返回这个位置的坐标
        }
        else
        {
            res = {loc / n, loc % n}; // 要是这个位置没被动过，那就直接返回就行
        }
        leftloc--;
        
        // 接下来得处理下被选中后该咋办了
        if(rec.count(leftloc)) // 要是leftloc被挑过了，那么就让loc的值为leftloc的（反正这个机制保证了leftloc对应的值也是个空值）
        {
            rec[loc] = rec[leftloc];
        }
        else
        {
            rec[loc] = leftloc; // 否则leftloc没挑过，那就直接让loc换成leftloc本身
        }
        return res;
    }
    
    void reset() {
        this->leftloc = m * n;
        this->rec.clear();
    }
};

// 随机这件事肯定得借助一些系统API完成，比如rand

// 之后，由于测试的矩阵规模都很大，所以直接二维的话内存和时间都可能是不够的，这里就需要转换成一维来作

// 还有一点是，每次翻转后，都用一个hash表存下来哪些地方是翻转过的，并且通过交换的方法来让哈希表中最后的那个元素保持一个没被动过的空位


// 这个题的思路给人一种很不自然的感觉，就是充满了一种为了换而换，为了效率而哈希交换的感觉
// 但它是微软的面试题，可以多作两边