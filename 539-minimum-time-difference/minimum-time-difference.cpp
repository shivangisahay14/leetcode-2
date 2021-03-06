// Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list. 
//
// Example 1:
//
// Input: ["23:59","00:00"]
// Output: 1
//
//
//
// Note:
//
// The number of time points in the given list is at least 2 and won't exceed 20000.
// The input time is legal and ranges from 00:00 to 23:59.
//
//


class Solution {
public:
    //相差必定<12，比如00:00,13:00
    //求出它们距离00：00的值，排序，然后求差值即可
    int findMinDifference(vector<string>& timePoints) 
    {
        int res = INT_MAX, n = timePoints.size();
        vector<int> nums;
        for (string str : timePoints) 
        {
            int h = stoi(str.substr(0, 2)), m = stoi(str.substr(3));
            nums.push_back(h * 60 + m);
        }
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; ++i) 
            res = min(res, nums[i] - nums[i - 1]);
        return min(res, 1440 + nums[0] - nums.back());
    }
};
