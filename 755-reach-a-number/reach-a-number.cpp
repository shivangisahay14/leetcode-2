//
// You are standing at position 0 on an infinite number line.  There is a goal at position target.
//
// On each move, you can either go left or right.  During the n-th move (starting from 1), you take n steps.
//
// Return the minimum number of steps required to reach the destination.
//
//
// Example 1:
//
// Input: target = 3
// Output: 2
// Explanation:
// On the first move we step from 0 to 1.
// On the second step we step from 1 to 3.
//
//
//
// Example 2:
//
// Input: target = 2
// Output: 3
// Explanation:
// On the first move we step from 0 to 1.
// On the second move we step  from 1 to -1.
// On the third move we step from -1 to 2.
//
//
//
// Note:
// target will be a non-zero integer in the range [-10^9, 10^9].
//


class Solution {
public:
    //第一感觉是动态规划，因为如果我知道怎么走到1，2就是1多向右走一步
    //似乎找不到规律
    //那就用广度遍历，第一次可以走到1，-1，第二次可以走到3,-1,1,-3,第三次...直到target的最小值出现
    //那么最小值时候出现呢？显然，每次遍历后出现的时候就是最小值
    int reachNumber(int target) {
        target = abs(target);
        int res = 0, sum = 0;
        while (sum < target || (sum - target) % 2 == 1) {
            ++res;
            sum += res;
        }
        return res;
    }
};
