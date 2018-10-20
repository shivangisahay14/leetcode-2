// On a 2 dimensional grid with R rows and C columns, we start at (r0, c0) facing east.
//
// Here, the north-west corner of the grid is at the first row and column, and the south-east corner of the grid is at the last row and column.
//
// Now, we walk in a clockwise spiral shape to visit every position in this grid. 
//
// Whenever we would move outside the boundary of the grid, we continue our walk outside the grid (but may return to the grid boundary later.) 
//
// Eventually, we reach all R * C spaces of the grid.
//
// Return a list of coordinates representing the positions of the grid in the order they were visited.
//
//  
//
// Example 1:
//
//
// Input: R = 1, C = 4, r0 = 0, c0 = 0
// Output: [[0,0],[0,1],[0,2],[0,3]]
//
//
//
//
//  
//
// Example 2:
//
//
// Input: R = 5, C = 6, r0 = 1, c0 = 4
// Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
//
//
//
//
//
//
//
// Note:
//
//
// 	1 <= R <= 100
// 	1 <= C <= 100
// 	0 <= r0 < R
// 	0 <= c0 < C
//
//
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int X, int Y) {
        vector<vector<int>> key{{X,Y}};
        int count=1,num=1;
        //the integer "count" was used for count how many step needed to move each round 
		//右1下1，左2上2，右3下3		
        while(key.size()!=R*C)
         {    
            for(int i=0;i<count;i++) 
            {             
                Y+=num;  
                if(X<R&&Y<C&&X>=0&&Y>=0) key.push_back({X,Y}); 
            }

            for(int i=0;i<count;i++)
            {                    
                 X+=num;
                 if(X<R&&Y<C&&X>=0&&Y>=0)  key.push_back({X,Y}); 
            }
            count++;
            num=-num;//方向 
         }           
            return key;
    } 
};
