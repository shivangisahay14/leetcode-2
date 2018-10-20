// You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.
//
// Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 
//
// Please note that both secret number and friend's guess may contain duplicate digits.
//
// Example 1:
//
//
// Input: secret = "1807", guess = "7810"
//
// Output: "1A3B"
//
// Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
//
// Example 2:
//
//
// Input: secret = "1123", guess = "0111"
//
// Output: "1A1B"
//
// Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.
//
// Note: You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal." />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //突然出现一个简单题，都不太相信了
    string getHint(string secret, string guess)
    {
        int m[10] = {0}, bulls = 0, cows = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) ++bulls;
            else {
                /*
                secret当前位置数字的映射值小于0，则表示其在guess中出现过，cows自增1，然后映射值加1，如果guess当前位置的数字的映射值大于0，则表示其在secret中出现过，cows自增1，然后映射值减1
                */
                if (m[secret[i]-'0']++ < 0) ++cows;//m[t]表示该位数字猜对的个数。
                if (m[guess[i]-'0']-- > 0) ++cows;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
