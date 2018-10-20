//
// Given two integers n and k, you need to construct a list which contains n different positive integers ranging from 1 to n and obeys the following requirement: 
//
// Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.
//
//
//
// If there are multiple answers, print any of them.
//
//
// Example 1:
//
// Input: n = 3, k = 1
// Output: [1, 2, 3]
// Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.
//
//
//
// Example 2:
//
// Input: n = 3, k = 2
// Output: [1, 3, 2]
// Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 and 2.
//
//
//
// Note:
//
// The n and k are in the range 1 <= k < n <= 104.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //找出一种排列方式，使得1到n组成的数组中相邻两个数的差的绝对值正好有k种
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        int i = 1, j = n;
        while (i <= j) {
            if (k > 1) res.push_back(k-- % 2 ? i++ : j--);
            else res.push_back(i++);
        }
        return res;
    }
};