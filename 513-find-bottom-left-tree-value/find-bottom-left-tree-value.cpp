//
// Given a binary tree, find the leftmost value in the last row of the tree. 
//
//
// Example 1:
//
// Input:
//
//     2
//    / \
//   1   3
//
// Output:
// 1
//
//
//
//   Example 2: 
//
// Input:
//
//         1
//        / \
//       2   3
//      /   / \
//     4   5   6
//        /
//       7
//
// Output:
// 7
//
//
//
// Note:
// You may assume the tree (i.e., the given root node) is not NULL.
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
    int findBottomLeftValue(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) 
        {
            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                TreeNode *t = q.front(); q.pop();
                if (i == 0) res = t->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return res;
    }
};
