// We are to write the letters of a given string S, from left to right into lines. Each line has maximum width 100 units, and if writing a letter would cause the width of the line to exceed 100 units, it is written on the next line. We are given an array widths, an array where widths[0] is the width of 'a', widths[1] is the width of 'b', ..., and widths[25] is the width of 'z'.
//
// Now answer two questions: how many lines have at least one character from S, and what is the width used by the last such line? Return your answer as an integer list of length 2.
//
//  
//
//
// Example :
// Input: 
// widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
// S = "abcdefghijklmnopqrstuvwxyz"
// Output: [3, 60]
// Explanation: 
// All letters have the same length of 10. To write all 26 letters,
// we need two full lines and one line with 60 units.
//
//
//
// Example :
// Input: 
// widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
// S = "bbbcccdddaaa"
// Output: [2, 4]
// Explanation: 
// All letters except 'a' have the same length of 10, and 
// "bbbcccdddaa" will cover 9 * 10 + 2 * 4 = 98 units.
// For the last 'a', it is written on the second line because
// there is only 2 units left in the first line.
// So the answer is 2 lines, plus 4 units in the second line.
//
//
//  
//
// Note:
//
//
// 	The length of S will be in the range [1, 1000].
// 	S will only contain lowercase letters.
// 	widths is an array of length 26.
// 	widths[i] will be in the range of [2, 10].
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int getNum(vector<int>& widths,char ch)
    {
        return widths[ch-'a'];
    }
    vector<int> numberOfLines(vector<int>& widths, string S) 
    {
        if(widths.empty()) return {0,0};
        
        int sumOfLine=0;
        int numOfLines=1;
        for(int i=0;i!=S.size();++i)
        {
            if(sumOfLine+getNum(widths,S[i])<100)
                sumOfLine+=getNum(widths,S[i]);
            else if(sumOfLine+getNum(widths,S[i])==100)
            {
                numOfLines++;
                sumOfLine=0;
            }
            else{
                numOfLines++;
                sumOfLine=getNum(widths,S[i]);
            }            
        }
        return {numOfLines,sumOfLine};
        
    }
};