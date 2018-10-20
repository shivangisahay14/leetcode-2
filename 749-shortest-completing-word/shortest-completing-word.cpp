//
// Find the minimum length word from a given dictionary words, which has all the letters from the string licensePlate.  Such a word is said to complete the given string licensePlate
//
// Here, for letters we ignore case.  For example, "P" on the licensePlate still matches "p" on the word.
//
// It is guaranteed an answer exists.  If there are multiple answers, return the one that occurs first in the array.
//
// The license plate might have the same letter occurring multiple times.  For example, given a licensePlate of "PP", the word "pair" does not complete the licensePlate, but the word "supper" does.
//
//
// Example 1:
//
// Input: licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
// Output: "steps"
// Explanation: The smallest length word that contains the letters "S", "P", "S", and "T".
// Note that the answer is not "step", because the letter "s" must occur in the word twice.
// Also note that we ignored case for the purposes of comparing whether a letter exists in the word.
//
//
//
// Example 2:
//
// Input: licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
// Output: "pest"
// Explanation: There are 3 smallest length words that contains the letters "s".
// We return the one that occurred first.
//
//
//
// Note:
//
// licensePlate will be a string with length in range [1, 7].
// licensePlate will contain digits, spaces, or letters (uppercase or lowercase).
// words will have a length in the range [10, 1000].
// Every words[i] will consist of lowercase letters, and have length in range [1, 15].
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        map<int, vector<string>> m;
        vector<char> chars;
        for (string word : words) {
            m[word.size()].push_back(word);
        }
        for (char c : licensePlate) {//写法很烂，可以用transform,再删除空格。而不必建立新对象
            if (c >= 'a' && c <= 'z') chars.push_back(c);
        else if (c >= 'A' && c <= 'Z') chars.push_back(c + 32);
        }
        for(int i=0;i!=chars.size();++i)
            cout<<chars[i];
        for (auto a : m) {
            if (a.first < chars.size()) continue;
            for (string word : a.second) {
                bool succ = true;
                unordered_map<char, int> freq;
                for (char c : word) ++freq[c];
                for (char c : chars) {
                    if (--freq[c] < 0) {succ = false; break;}
                }
                if (succ) return word;
            }
        }
        return ""; 
    }
};
