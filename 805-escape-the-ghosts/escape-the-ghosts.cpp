// You are playing a simplified Pacman game. You start at the point (0, 0), and your destination is (target[0], target[1]). There are several ghosts on the map, the i-th ghost starts at (ghosts[i][0], ghosts[i][1]).
//
// Each turn, you and all ghosts simultaneously *may* move in one of 4 cardinal directions: north, east, west, or south, going from the previous point to a new point 1 unit of distance away.
//
// You escape if and only if you can reach the target before any ghost reaches you (for any given moves the ghosts may take.)  If you reach any square (including the target) at the same time as a ghost, it doesn't count as an escape.
//
// Return True if and only if it is possible to escape.
//
//
// Example 1:
// Input: 
// ghosts = [[1, 0], [0, 3]]
// target = [0, 1]
// Output: true
// Explanation: 
// You can directly reach the destination (0, 1) at time 1, while the ghosts located at (1, 0) or (0, 3) have no way to catch up with you.
//
//
//
// Example 2:
// Input: 
// ghosts = [[1, 0]]
// target = [2, 0]
// Output: false
// Explanation: 
// You need to reach the destination (2, 0), but the ghost at (1, 0) lies between you and the destination.
//
//
//
// Example 3:
// Input: 
// ghosts = [[2, 0]]
// target = [1, 0]
// Output: false
// Explanation: 
// The ghost can reach the target at the same time as you.
//
//
// Note:
//
//
// 	All points have coordinates with absolute value <= 10000.
// 	The number of ghosts will not exceed 100.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //没看懂，但是ghost真的那么聪明，那么ghost挡住物体就行了
    //怎么弄呢？所有ghost占住目标就行了，所以比的不是能不能抓到物体，而是能不能先占领tartget
    //显然，距离近的先占target
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target)
    {
        int distance=abs(target[0])+abs(target[1]);
        for(auto &elem:ghosts)
        {
            int dis=abs(elem[0]-target[0])+abs(elem[1]-target[1]);
            cout<<dis<<endl;
            if(dis<=distance)
                return false;
        }
        return true;
    }
};
