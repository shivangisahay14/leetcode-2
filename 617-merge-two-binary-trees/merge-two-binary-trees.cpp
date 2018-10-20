//
// Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. 
//
//
// You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.
//
//
//
// Example 1:
//
// Input: 
// 	Tree 1                     Tree 2                  
//           1                         2                             
//          / \                       / \                            
//         3   2                     1   3                        
//        /                           \   \                      
//       5                             4   7                  
// Output: 
// Merged tree:
// 	     3
// 	    / \
// 	   4   5
// 	  / \   \ 
// 	 5   4   7
//
//
//
//
// Note:
// The merging process must start from the root nodes of both trees.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //直接在t1上合并
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t2) return t1;
        if(!t1&&t2) return t2;
        
        if(t1&&t2)//否则什么也不做
            t1->val+=t2->val;
        if(!t1->left&&t2->left)//保证下一节点可以操作
        {
            t1->left=new TreeNode(0);
            
        }
        if(!t1->right&&t2->right)
        {
            t1->right=new TreeNode(0);
            
        }
        mergeTrees(t1->left,t2->left);
        mergeTrees(t1->right,t2->right);  
        return t1;                   
    }
};