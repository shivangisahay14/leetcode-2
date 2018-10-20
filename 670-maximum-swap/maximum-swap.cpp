//
// Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.
//
//
// Example 1:
//
// Input: 2736
// Output: 7236
// Explanation: Swap the number 2 and the number 7.
//
//
//
// Example 2:
//
// Input: 9973
// Output: 9973
// Explanation: No swap.
//
//
//
//
// Note:
//
// The given number is in the range [0, 108]
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //2395
    //9937 22245 32224 55441 11667 10000 7689 8899
    //12345 4356 3576 9005 5601 175 437 5493 59870345 698594 23574 6540 8977487 5349878 54737 432256 548 958 94895 67854 6874 9067 54680 4809
    int maximumSwap(int nums) 
    {
        string num=to_string(nums);
        //每一位都得确定自己是最大值。否则和最大值交换，最大值是从尾向前最后一个。     
        for(auto iter=num.begin();iter!=num.end();++iter)
        {
            auto s_max=max_element(iter,num.end());
            if(*s_max==*iter)
                  continue;
            else
            {
                auto last=find(num.rbegin(),num.rend(),*s_max);
                swap(*iter,*last);
                return stoi(num);
            }
        }
        return stoi(num);
    }
};
