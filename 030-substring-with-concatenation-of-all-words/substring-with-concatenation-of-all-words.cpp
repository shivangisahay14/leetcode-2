// You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
//
// Example 1:
//
//
// Input:
//   s = "barfoothefoobarman",
//   words = ["foo","bar"]
// Output: [0,9]
// Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
// The output order does not matter, returning [9,0] is fine too.
//
//
// Example 2:
//
//
// Input:
//   s = "wordgoodstudentgoodword",
//   words = ["word","student"]
// Output: []
//
//


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s==""||words.size()==0) return {};
        int n = s.size(), len = words[0].size(), total = words.size(), cnt = total;
        vector<int> res;
        unordered_map<string, int> counts;
        for (string s : words) counts[s]++;
        for (int i = 0; i < len; i++) {//比如"oooooooooooo" "ooo" "ooo",需要每个字符串都从内部走len
            unordered_map<string, int> wordcnt = counts;
            cnt = total;
            for (int j = i; j + len <= n; j += len) {
                string cur = s.substr(j, len);
                if (wordcnt[cur]-- > 0) cnt--;
                if (j - total*len >= 0) {                  
                    string out = s.substr(j - total*len, len); // the word out side of current sliding window
                    if (++wordcnt[out] > 0) cnt++;
                }
                if (cnt == 0) res.push_back(j - (total-1)*len);                
            }
        }
        return res;
    }
};
