// Given an integer array with even length, where different numbers in this array represent different kinds of candies. Each number means one candy of the corresponding kind. You need to distribute these candies equally in number to brother and sister. Return the maximum number of kinds of candies the sister could gain. 
//
// Example 1:
//
// Input: candies = [1,1,2,2,3,3]
// Output: 3
// Explanation:
// There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
// Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too. 
// The sister has three different kinds of candies. 
//
//
//
// Example 2:
//
// Input: candies = [1,1,2,3]
// Output: 2
// Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1]. 
// The sister has two different kinds of candies, the brother has only one kind of candies. 
//
//
//
// Note:
//
// The length of the given array is in range [2, 10,000], and will be even.
// The number in given array is in range [-100,000, 100,000].
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        //题目：必定是偶数
        //放到set里面，最多种类就处来了
        unordered_set<int> s;
        for (int candy : candies) 
            s.insert(candy);
        return min(s.size(), candies.size() / 2);//可能种类超过一半
    }
};