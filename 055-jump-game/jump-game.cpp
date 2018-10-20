// Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
// Each element in the array represents your maximum jump length at that position.
//
// Determine if you are able to reach the last index.
//
// Example 1:
//
//
// Input: [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
//
//
// Example 2:
//
//
// Input: [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum
//              jump length is 0, which makes it impossible to reach the last index.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //注意是最大跳跃度
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; ++i) 
        {
            dp[i] = max(dp[i - 1]-1, nums[i - 1]);//dp[i]表示走到i-1位置时 剩余的最大步数(还可以走的)，
            //比如对，于示例1，遍历到3时，还能走2步
            if (dp[i] <= 0) return false;
        }
        return dp[n - 1] >= 0;
    }
};
