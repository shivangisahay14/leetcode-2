// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
//
// Example 1:
//
// Input:s1 = "ab" s2 = "eidbaooo"
// Output:True
// Explanation: s2 contains one permutation of s1 ("ba").
//
//
//
// Example 2:
//
// Input:s1= "ab" s2 = "eidboaoo"
// Output: False
//
//
//
// Note:
//
// The input strings only contain lower case letters.
// The length of both given strings is in range [1, 10,000].
//
//


class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        //构建s2的子串显然不合适
        //那么，构造s1的排列似乎是一个方法
        //但是s1长度太大就麻烦了，因为组合数太多。
        //我们遍历s1和s2.我们应该对s2使用滑动窗口
        if(s2.size()<s1.size()) return false;
        unordered_map<char, int> col;
	    for (auto elem : s1)
		    col[elem] += 1;
        unordered_map<char, int> col2;
	    for (int i=0;i!=s2.size();++i)
        {
            if(i<s1.size())
                col2[s2[i]]+=1;           
            else
            {
                col2[s2[i]]+=1;
                col2[s2[i-s1.size()]]--;
                if(col2[s2[i-s1.size()]]<=0)
                    col2.erase(s2[i-s1.size()]);
            }
            if(col==col2) return true;
        }
        return false;
    }
};
