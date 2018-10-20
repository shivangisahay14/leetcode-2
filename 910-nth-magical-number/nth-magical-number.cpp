// A positive integer is magical if it is divisible by either A or B.
//
// Return the N-th magical number.  Since the answer may be very large, return it modulo 10^9 + 7.
//
//  
//
//
//
//
//
// Example 1:
//
//
// Input: N = 1, A = 2, B = 3
// Output: 2
//
//
//
// Example 2:
//
//
// Input: N = 4, A = 2, B = 3
// Output: 6
//
//
//
// Example 3:
//
//
// Input: N = 5, A = 2, B = 4
// Output: 10
//
//
//
// Example 4:
//
//
// Input: N = 3, A = 6, B = 4
// Output: 8
//
//
//  
//
// Note:
//
//
// 	1 <= N <= 10^9
// 	2 <= A <= 40000
// 	2 <= B <= 40000
//
//
//
//
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    const int mod = 1e9+7;
    int nthMagicalNumber(int N, int A, int B) {
        long igcd=A*B/gcd(A,B);
        long step=igcd/A+igcd/B-1;//4，6->12->{4,6,8,12},{16,18,20,24}     
        long  x = ((N-1)/step * igcd) %mod;
        N=(N-1)%step;
        N++;
        int ta=A,tb=B;
        while(N-->0)
        {
            if(N==0)
            {
                if(ta<tb) return (x+ta)%mod;
                return (x+tb)%mod;
            }
            if(ta<tb) ta+=A;
            else tb+=B;
        }
        return x;
    }
    
    int gcd(int a,int b)
    {
        while(b)
        {
            int c=a%b;
            a=b;
            b=c;
        }
        return a;
    }
};
