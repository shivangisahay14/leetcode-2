// Given an undirected graph, return true if and only if it is bipartite.
//
// Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.
//
// The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.
//
//
// Example 1:
// Input: [[1,3], [0,2], [1,3], [0,2]]
// Output: true
// Explanation: 
// The graph looks like this:
// 0----1
// |    |
// |    |
// 3----2
// We can divide the vertices into two groups: {0, 2} and {1, 3}.
//
//
//
// Example 2:
// Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
// Output: false
// Explanation: 
// The graph looks like this:
// 0----1
// | \  |
// |  \ |
// 3----2
// We cannot find a way to divide the set of nodes into two independent subsets.
//
//
//  
//
// Note:
//
//
// 	graph will have length in range [1, 100].
// 	graph[i] will contain integers in range [0, graph.length - 1].
// 	graph[i] will not contain i or duplicate values.
// 	The graph is undirected: if any element j is in graph[i], then i will be in graph[j].
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {

public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),0);
        for(int i=0;i<graph.size();++i)
        {
            if(color[i]==0 && !isBipartiteAux(graph,color,i,1))
                return false;
        }
        return true;
    }
    
private:
    bool isBipartiteAux(const vector<vector<int>>& graph,vector<int>& color,int u,int co){
        if(color[u]!=0)
            return color[u]==co;
        color[u]=co;
        for(auto v:graph[u]){
            if(!isBipartiteAux(graph,color,v,-1*co))
                return false;
        }
        return true;
    }
};