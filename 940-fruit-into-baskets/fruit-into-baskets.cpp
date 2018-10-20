// In a row of trees, the i-th tree produces fruit with type tree[i].
//
// You start at any tree of your choice, then repeatedly perform the following steps:
//
//
// 	Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
// 	Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.
//
//
// Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.
//
// You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.
//
// What is the total amount of fruit you can collect with this procedure?
//
//  
//
// Example 1:
//
//
// Input: [1,2,1]
// Output: 3
// Explanation: We can collect [1,2,1].
//
//
//
// Example 2:
//
//
// Input: [0,1,2,2]
// Output: 3
// Explanation: We can collect [1,2,2].
// If we started at the first tree, we would only collect [0, 1].
//
//
//
// Example 3:
//
//
// Input: [1,2,3,2,2]
// Output: 4
// Explanation: We can collect [2,3,2,2].
// If we started at the first tree, we would only collect [1, 2].
//
//
//
// Example 4:
//
//
// Input: [3,3,3,1,2,1,1,2,3,3,4]
// Output: 5
// Explanation: We can collect [1,2,1,1,2].
// If we started at the first tree or the eighth tree, we would only collect 4 fruits.
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
// 	1 <= tree.length <= 40000
// 	0 <= tree[i] < tree.length
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int totalFruit(vector<int>& tree) 
    {
        if(tree.size()==0) return 0;
        if(tree.size()==1) return 1;
        int type1=tree[0];
        int count=1;
        int type2=-1;
        int result=0;
        for(int i=1;i!=tree.size();++i)
        {            
            if(tree[i]==type1||tree[i]==type2) ++count;
            else
            {
                type1=tree[i-1];
                type2=tree[i];   
                {
                    count=1;
                    int j=i-1;
                    while(j>=0)
                        if(tree[j--]==type1) ++count;
                        else break;
                }                          
            }
            result=max(result,count);
        }
        return result;
    }
};