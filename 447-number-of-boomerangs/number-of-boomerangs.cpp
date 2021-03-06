// Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
//
// Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).
//
// Example:
//
// Input:
// [[0,0],[1,0],[2,0]]
//
// Output:
// 2
//
// Explanation:
// The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
//
//


class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        //要求求出tuple的个数，其中，第一个点和第二个点之间的距离跟第一个点和第三个点之间的距离相等
        //我们依次让每个数充当第一个点
        int res = 0;
        for (int i = 0; i < points.size(); ++i)//遍历所有点
        {
            unordered_map<int, int> m;//{距离，数量}
            for (int j = 0; j < points.size(); ++j)//求出每个点到这个点的距离
            {
                int a = points[i].first - points[j].first;
                int b = points[i].second - points[j].second;
                ++m[a * a + b * b];
            }
            for (auto it = m.begin(); it != m.end(); ++it)
            {
                res += it->second * (it->second - 1);//求出数量
            }
        }
        return res;
    }
};
