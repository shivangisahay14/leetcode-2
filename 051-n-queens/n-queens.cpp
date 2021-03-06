// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
//
//
//
// Given an integer n, return all distinct solutions to the n-queens puzzle.
//
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
//
// Example:
//
//
// Input: 4
// Output: [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
//
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
//
//


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) 
    {
		vector<vector<int>> one_result(n,vector<int>(n,0));//2维数组
		queen(one_result, 0, 0, 0, 0, n);
		return result;    
    }
        
    void queen(vector<vector<int>>& answer, int deep, int l, int d, int r, int num)
	{
		if (deep == num)
		{
			result.push_back(boardToString(answer));
			return;
		}

		for (int i = 0; i < num; ++i)
		{
			if (((1 << i) & l) || ((1 << i)&d) || ((1 << i)&r)) continue;
			answer[deep][i] = 1;
			queen(answer, deep + 1, (l << 1) | (1 << (i + 1)), d | (1 << i), (r >> 1) | (1 << (i - 1)), num);
			answer[deep][i] = 0;
		}
	}
    
    vector<string> boardToString(const vector<vector<int>>& answer)
    {
        vector<string> temp;
        string s;
        auto num=answer.size();
		for (int m = 0; m<num; ++m)
		{		
			s.clear();
			for (int n = 0; n<num; ++n)
			{					
				if (answer[m][n])  s.push_back('Q');
				else               s.push_back('.');					
			}			
			temp.push_back(s);
		}
        return temp;
    }

private:
	vector<vector<string>> result;
};



