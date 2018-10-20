// Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.
//
// The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.
//
// For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].
//
//  
//
//
// Example 1:
//
//
// Input: ["StockSpanner","next","next","next","next","next","next","next"], [[],[100],[80],[60],[70],[60],[75],[85]]
// Output: [null,1,1,1,2,1,4,6]
// Explanation: 
// First, S = StockSpanner() is initialized.  Then:
// S.next(100) is called and returns 1,
// S.next(80) is called and returns 1,
// S.next(60) is called and returns 1,
// S.next(70) is called and returns 2,
// S.next(60) is called and returns 1,
// S.next(75) is called and returns 4,
// S.next(85) is called and returns 6.
//
// Note that (for example) S.next(75) returned 4, because the last 4 prices
// (including today's price of 75) were less than or equal to today's price.
//
//
//  
//
// Note:
//
//
// 	Calls to StockSpanner.next(int price) will have 1 <= price <= 10^5.
// 	There will be at most 10000 calls to StockSpanner.next per test case.
// 	There will be at most 150000 calls to StockSpanner.next across all test cases.
// 	The total time limit for this problem has been reduced by 75% for C++, and 50% for all other languages.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class StockSpanner {
public:
    //原理很简单，比如，...100 80，70，对于70，80，100都有用，因为以后还可能用到，100,80,70,80,那么70就必须删除掉
    //因为下一个是70的话，这段信息也没用，因为不连续。
    //现在考虑100，80，70，80.80显然需要直到有多少比<=70，<=80（2）有多少然后加上自己+1.
    StockSpanner() 
    {       
    }   
    
    int next(int price)
    {
        int res = 1;
        while (!s.empty() && s.top().first <= price) 
        {
            res += s.top().second;
            s.pop();
        }
        s.push({price, res});
        return res;
    }
    
    stack<pair<int, int>> s;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
