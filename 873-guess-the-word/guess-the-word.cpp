// This problem is an interactive problem new to the LeetCode platform.
//
// We are given a word list of unique words, each word is 6 letters long, and one word in this list is chosen as secret.
//
// You may call master.guess(word) to guess a word.  The guessed word should have type string and must be from the original list with 6 lowercase letters.
//
// This function returns an integer type, representing the number of exact matches (value and position) of your guess to the secret word.  Also, if your guess is not in the given wordlist, it will return -1 instead.
//
// For each test case, you have 10 guesses to guess the word. At the end of any number of calls, if you have made 10 or less calls to master.guess and at least one of these guesses was the secret, you pass the testcase.
//
// Besides the example test case below, there will be 5 additional test cases, each with 100 words in the word list.  The letters of each word in those testcases were chosen independently at random from 'a' to 'z', such that every word in the given word lists is unique.
//
//
// Example 1:
// Input: secret = "acckzz", wordlist = ["acckzz","ccbazz","eiowzz","abcczz"]
//
// Explanation:
//
// master.guess("aaaaaa") returns -1, because "aaaaaa" is not in wordlist.
// master.guess("acckzz") returns 6, because "acckzz" is secret and has all 6 matches.
// master.guess("ccbazz") returns 3, because "ccbazz" has 3 matches.
// master.guess("eiowzz") returns 2, because "eiowzz" has 2 matches.
// master.guess("abcczz") returns 4, because "abcczz" has 4 matches.
//
// We made 5 calls to master.guess and one of them was the secret, so we pass the test case.
//
//
// Note:  Any solutions that attempt to circumvent the judge will result in disqualification.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:   
    void shrinkWordList(vector<string>& wordlits, const string& guessWord, const int matches)
    {
        vector<string> tmp;        
        for(string &word : wordlits)
        {
            int ans = 0;        
            for(int i = 0;i<6; i++)
                if(word[i] == guessWord[i])
                    ++ans;        
            if(ans == matches)
                tmp.push_back(word);
        }        
        swap(wordlits,tmp);
    }
    
    void findSecretWord(vector<string>& wordlist, Master& master) {        
        string target = wordlist[random() % wordlist.size()];
        int Count = 10;
        while(Count--)
        {
            int matches = master.guess(target);          
            shrinkWordList(wordlist, target, matches);         
            target = wordlist[random() % wordlist.size()];
        }      
    }
};