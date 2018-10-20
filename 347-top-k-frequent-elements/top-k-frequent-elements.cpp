//
// Given a non-empty array of integers, return the k most frequent elements.
//
// For example,
// Given [1,1,1,2,2,3] and k = 2, return [1,2].
//
//
// Note: 
//
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //O(n log n)是一个比较宽松的要求，因为我们可以排序了，排序之后只要遍历一次就行了。
    //但是，我们知道使用堆，可以让复杂度达到nlogk
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>> q;
        vector<int> res;
        for (auto a : nums) 
            ++m[a];
        for (auto it : m) 
            q.push({it.second, it.first});//7654321，4 
        //这里有个优化，就是我们可以检查最小堆的大小，如果超过k，我们就把堆顶pop出来，那么剩下的k个，就是要求的。然后我们不断pop到一个栈输出就行
        for (int i = 0; i < k; ++i)
        {
            res.push_back(q.top().second); 
            q.pop();
        }
        return res; 
    }
};
