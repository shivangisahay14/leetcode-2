// Given the radius and x-y positions of the center of a circle, write a function randPoint which generates a uniform random point in the circle.
//
// Note:
//
//
// 	input and output values are in floating-point.
// 	radius and x-y position of the center of the circle is passed into the class constructor.
// 	a point on the circumference of the circle is considered to be in the circle.
// 	randPoint returns a size 2 array containing x-position and y-position of the random point, in that order.
//
//
//
// Example 1:
//
//
// Input: 
// ["Solution","randPoint","randPoint","randPoint"]
// [[1,0,0],[],[],[]]
// Output: [null,[-0.72939,-0.65505],[-0.78502,-0.28626],[-0.83119,-0.19803]]
//
//
//
// Example 2:
//
//
// Input: 
// ["Solution","randPoint","randPoint","randPoint"]
// [[10,5,-7.5],[],[],[]]
// Output: [null,[11.52438,-8.33273],[2.46992,-16.21705],[11.13430,-12.42337]]
//
//
// Explanation of Input Syntax:
//
// The input is two lists: the subroutines called and their arguments. Solution's constructor has three arguments, the radius, x-position of the center, and y-position of the center of the circle. randPoint has no arguments. Arguments are always wrapped with a list, even if there aren't any.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    /*
    我试了20多次，这道题是完完全全的数学题！！！
    */
    Solution(double radius, double x_center, double y_center): distribution(0, 1), R(radius), X(x_center), Y(y_center) {}
    
    vector<double> randPoint() {
        double theta = distribution(generator) * 2 * PI;
        double r = sqrt(distribution(generator)) * R;
        return {X + r * cos(theta), Y + r * sin(theta)};
    }
private:
    const double PI = 3.1415926535897932384626;
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution;
    const double R;
    const double X;
    const double Y;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */
