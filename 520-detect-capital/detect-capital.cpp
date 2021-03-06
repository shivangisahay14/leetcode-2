//
// Given a word, you need to judge whether the usage of capitals in it is right or not.
//
//
//
// We define the usage of capitals in a word to be right when one of the following cases holds:
//
// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital if it has more than one letter, like "Google".
//
// Otherwise, we define that this word doesn't use capitals in a right way.
//
//
//
// Example 1:
//
// Input: "USA"
// Output: True
//
//
//
// Example 2:
//
// Input: "FlaG"
// Output: False
//
//
//
// Note:
// The input will be a non-empty word consisting of uppercase and lowercase latin letters.
//


class Solution {
public:
    bool detectCapitalUse(string word) {
        //如果不愿意写太代码，可以直接计算大写字母的个数，0是ok，为size ok 1且word[0] ok
        int cnt = count_if(word.begin(), word.end(), [](char c){return c <= 'Z'&&c>='A';});
        return cnt == 0 || cnt == word.size() || (cnt == 1 && word[0] <= 'Z');
    }
};
