// There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. The bricks have the same height but different width. You want to draw a vertical line from the top to the bottom and cross the least bricks. 
//
//
// The brick wall is represented by a list of rows. Each row is a list of integers representing the width of each brick in this row from left to right. 
//
//
// If your line go through the edge of a brick, then the brick is not considered as crossed. You need to find out how to draw the line to cross the least bricks and return the number of crossed bricks. 
//
// You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks. 
//
// Example:
//
// Input: 
// [[1,2,2,1],
//  [3,1,2],
//  [1,3,2],
//  [2,4],
//  [3,1,2],
//  [1,3,1,1]]
// Output: 2
// Explanation: 
//
//
//
//
// Note:
//
// The width sum of bricks in different rows are the same and won't exceed INT_MAX.
// The number of bricks in each row is in range [1,10,000]. The height of wall is in range [1,10,000]. Total number of bricks of the wall won't exceed 20,000. 
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //遍历所有元素，给出所有该元素的划分线，裂缝
    //我们使用一个哈希表来建立每一个断点的长度和其出现频率之间的映射，这样只要我们从断点频率出现最多的地方劈墙，损坏的板砖一定最少，
    int leastBricks(vector<vector<int>>& wall) {
        int mx = 0;
        unordered_map<int, int> m;
        for (auto a : wall) 
        {
            int sum = 0;
            for (int i = 0; i < a.size() - 1; ++i) 
            {
                sum += a[i];
                ++m[sum];
                mx = max(mx, m[sum]);
            }
        }
        return wall.size() - mx; 
    }
};