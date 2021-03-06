// Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
//
//
// Example 1:
//
//
// Input: nums = [1,2,3,1], k = 3, t = 0
// Output: true
//
//
//
// Example 2:
//
//
// Input: nums = [1,0,1,1], k = 1, t = 2
// Output: true
//
//
//
// Example 3:
//
//
// Input: nums = [1,5,9,1,5,9], k = 2, t = 3
// Output: false
//
//
//
//
//


class Solution {
public:
    //100,80,70,60,50,40,30,20,11，5，9，14，25，54，3,99,87,30 k=6 t=2
    //我们以一个虚拟窗口移动前向，窗口长度为k+1，
    //我们先排序，
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> m;//为了排序
        int j = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i - j > k) 
                m.erase(nums[j++]);
            auto a = m.lower_bound((long long)nums[i] - t);
            if (a != m.end() && abs(a->first - nums[i]) <= t) 
                return true;
            m[nums[i]] = i;
        }
        return false;
    }
};
