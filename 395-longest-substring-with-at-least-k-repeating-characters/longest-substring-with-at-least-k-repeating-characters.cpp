//
// Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.
//
//
// Example 1:
//
// Input:
// s = "aaabb", k = 3
//
// Output:
// 3
//
// The longest substring is "aaa", as 'a' is repeated 3 times.
//
//
//
// Example 2:
//
// Input:
// s = "ababbc", k = 2
//
// Output:
// 5
//
// The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
int longestSubstring(string s, int k) {
    return longestSubstring_recur(s, k, 0, s.size());//注意，这个end不可到达
}

int longestSubstring_recur(const string& s, int k, int first, int last) {
    int count[26] = {0};
    for (int j = first; j < last; ++j) 
        ++count[s[j] - 'a'];//统计每个字符数量
    
    int max_len = 0;
    for (int j = first; j < last;) 
    {
        while (j < last && count[s[j]-'a']<k) 
            ++j;
        if (j == last) 
            break;
        int l = j;//第一个次数大于k的字母作为begin(j)
        while (l < last && count[s[l]-'a']>=k) 
            ++l;//begin之后第一个小于k的字符作为end
        if (j == first && l == last) //最乐观的情况直接返回
            return last-first; 
        max_len = max(max_len, longestSubstring_recur(s, k, j, l));
        j = l;//还要继续循环下去。这么写很不简洁。但似乎没有办法
    }
    return max_len;
}
};
