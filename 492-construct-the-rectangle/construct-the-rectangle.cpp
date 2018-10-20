//
// For a web developer, it is very important to know how to design a web page's size. So, given a specific rectangular web page’s area, your job by now is to design a rectangular web page, whose length L and width W satisfy the following requirements:
// 1. The area of the rectangular web page you designed must equal to the given target area.
// 2. The width W should not be larger than the length L, which means L >= W.
// 3. The difference between length L and width W should be as small as possible.
//
// You need to output the length L and the width W of the web page you designed in sequence.
//
//
//
// Example:
//
// Input: 4
// Output: [2, 2]
// Explanation: The target area is 4, and all the possible ways to construct it are [1,4], [2,2], [4,1]. 
// But according to requirement 2, [1,4] is illegal; according to requirement 3,  [4,1] is not optimal compared to [2,2]. So the length L is 2, and the width W is 2.
//
//
//
// Note:
//
// The given area won't exceed 10,000,000 and is a positive integer
// The web page's width and length you designed must be positive integers.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    vector<int> constructRectangle(int area)
    {
        int min=INT32_MAX;
        int re=0;
        for(long long i=area;i*i>=area;--i)//i:L
        {
            if(area%i==0&&(i-area/i)<min)
            {
                re=i;
                min=i-area/i;
            }
            
        }
        return{re,area/re};
        
    }
};