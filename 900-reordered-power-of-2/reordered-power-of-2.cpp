// Starting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not zero.
//
// Return true if and only if we can do this in a way such that the resulting number is a power of 2.
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
// Input: 1
// Output: true
//
//
//
// Example 2:
//
//
// Input: 10
// Output: false
//
//
//
// Example 3:
//
//
// Input: 16
// Output: true
//
//
//
// Example 4:
//
//
// Input: 24
// Output: false
//
//
//
// Example 5:
//
//
// Input: 46
// Output: true
//
//
//  
//
// Note:
//
//
// 	1 <= N <= 10^9
//
//
//
//
//
//
//


class Solution {
public:
    //第一感觉都是用排列来做，直到我发现有这种神奇的算法。。。。
    //甚至不明白为什么。但是可以猜测
    bool reorderedPowerOf2(int N) {
        if (N == 1) return true;
    	set<string> two;
    	for (int i=0; i<33; i++) 
        {
    		string s = to_string(1LL << i);
    		sort(s.begin(), s.end());
    		two.insert(s);
    	}
    	string s = to_string(N);
    	sort(s.begin(), s.end());
    	return two.find(s) != two.end(); 
    }
};
