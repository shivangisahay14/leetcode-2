// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
//
// Note: The solution set must not contain duplicate subsets.
//
// Example:
//
//
// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res(1);//我们需要一个[],因为这不是算法能制造出来的
       // sort(S.begin(), S.end());
        for(int i=0;i!=nums.size();++i)//依次放1，2，3
        {
            auto len=res.size();//len会改变，因此。。。
            for(int j=0;j!=len;++j)
            {
                res.push_back(res[j]);//先放自己
                res.back().push_back(nums[i]);
            }            
        }
        for(auto &elem:res)
            sort(elem.begin(),elem.end());
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
};//[] [1] [] [1] [2] [12] [12] [22] [122]
