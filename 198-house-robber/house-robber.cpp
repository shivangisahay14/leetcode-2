// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
// Example 1:
//
//
// Input: [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//              Total amount you can rob = 1 + 3 = 4.
//
// Example 2:
//
//
// Input: [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
//              Total amount you can rob = 2 + 9 + 1 = 12.
//
//


class Solution {
public:
    int last=0;//指定可以抢的开始
    int max=0;
    
    int rob(vector<int>& nums) {
        //每个屋子都有抢不和不抢两个选择，但这样似乎太笨了。我们先这样做，看能不能通过.然后再考虑动态规划。
        /*比如说nums为{3, 2, 1, 5}，那么我们来看我们的dp数组应该是什么样的，首先dp[0]=3没啥疑问，再看dp[1]是多少呢，由于3比2大，所以我们抢第一个房子的3，当前房子的2不抢，所以dp[1]=3，那么再来看dp[2]，由于不能抢相邻的，所以我们可以用再前面的一个的dp值加上当前的房间值，和当前房间的前面一个dp值比较，取较大值当做当前dp值4，所以我们可以得到递推公式dp[i] = max(num[i] + dp[i - 2], dp[i - 1]), 由此看出我们需要初始化dp[0]和dp[1]，其中dp[0]即为num[0]，dp[1]此时应该为max(num[0], num[1])，代码如下：
        */
        
        /////////////
        vector<int>& num=nums;
        if (num.size() <= 1) return num.empty() ? 0 : num[0];
        vector<int> dp = {num[0], std::max(num[0], num[1])};
        int dp_of_before_before=num[0];
        int dp_of_before=std::max(num[0], num[1]);
        for (int i = 2; i < num.size(); ++i) {
            //dp.push_back(std::max(num[i] + dp[i - 2], dp[i - 1]));
            int dp_of_this=std::max(num[i] + dp_of_before_before, dp_of_before);
            dp_of_before_before=dp_of_before;
            dp_of_before=dp_of_this;
        }
        return std::max(dp_of_before_before, dp_of_before);
    }
};
