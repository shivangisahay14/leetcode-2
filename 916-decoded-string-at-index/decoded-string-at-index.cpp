// An encoded string S is given.  To find and write the decoded string to a tape, the encoded string is read one character at a time and the following steps are taken:
//
//
// 	If the character read is a letter, that letter is written onto the tape.
// 	If the character read is a digit (say d), the entire current tape is repeatedly written d-1 more times in total.
//
//
// Now for some encoded string S, and an index K, find and return the K-th letter (1 indexed) in the decoded string.
//
//  
//
//
// Example 1:
//
//
// Input: S = "leet2code3", K = 10
// Output: "o"
// Explanation: 
// The decoded string is "leetleetcodeleetleetcodeleetleetcode".
// The 10th letter in the string is "o".
//
//
//
// Example 2:
//
//
// Input: S = "ha22", K = 5
// Output: "h"
// Explanation: 
// The decoded string is "hahahaha".  The 5th letter is "h".
//
//
//
// Example 3:
//
//
// Input: S = "a2345678999999999999999", K = 1
// Output: "a"
// Explanation: 
// The decoded string is "a" repeated 8301530446056247680 times.  The 1st letter is "a".
//
//
//  
//
// Note:
//
//
// 	2 <= S.length <= 100
// 	S will only contain lowercase letters and digits 2 through 9.
// 	S starts with a letter.
// 	1 <= K <= 10^9
// 	The decoded string is guaranteed to have less than 2^63 letters.
//
//
//
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:

	string decodeAtIndex(string S, int K) {
		long long len = 0;
		int i = 0;
		string s;
		for (; i != S.size(); ++i)
		{
			if (isdigit(S[i]))
			{
				len = len * (S[i]-'0');
				if (len >= K)
					break;
			}
			else//这一步返回了特殊情况
			{
				++len;
				if (len == K)
				{
					s.push_back(S[i]);
					return s;
				}					
			}
		}
		char c;
		//cout << K - 1 << "    " << ((K - 1) % (len / (S[i] - '0'))) <<"   "<< (len / (S[i] - '0') )<< endl;
		helper(S.substr(0, i), (K-1) % (len / (S[i]-'0')), c, len / (S[i] - '0'));		
		s.push_back(c);
		return s;
	}

	//从S里找到索引为K的元素，S的长度为len
	void helper(string S, int K, char& c,long long len)
	{
		for (int i = S.size()-1; i >= 0; --i)
		{
			if (isdigit(S[i]))
			{
				helper(S.substr(0, i), K % (len / (S[i] - '0')), c, len / (S[i] - '0'));
				return;
			}
			else
			{
				if (len-1 == K)
				{
					c = S[i];
					return;
				}		
				len--;
			}
		}
	}
};