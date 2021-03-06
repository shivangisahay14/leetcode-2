// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
//
// If the last word does not exist, return 0.
//
// Note: A word is defined as a character sequence consists of non-space characters only.
//
// Example:
//
// Input: "Hello World"
// Output: 5
//
//


class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;
        size_t last=s.find_last_not_of(' ');
        size_t first=s.find_first_not_of(' ');
        if(last==string::npos||first==string::npos) return 0;
        s=s.substr(first,last-first+1);        
        size_t pos=s.find_last_of(' ');        
        if(pos==string::npos) return s.size();
        return s.size()-pos-1;        
    }
};
