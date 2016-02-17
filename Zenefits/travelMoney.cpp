#include "head.h"

class Solution{
public:
    bool travel(vector<vector<int>> & matrix, int k){
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
	for(int i=0; i<m-1; ++i) dp[i][n] = INT_MAX;
	for(int j=0; j<n-1; ++j) dp[m][j] = INT_MAX;
	
	for(int i=m-1; i>=0; --i){
	    for(int j=n-1; j>=0; --j){
		dp[i][j] = matrix[i][j] + min(dp[i+1][j], dp[i][j+1]);
	    }
	}
	PrintVV(matrix, "matrix");
	PrintVV(dp, "dp");
	return k>=dp[0][0];
    }
};

int main(){
    vector<vector<int>> matrix = {{0, 5, 10},{2, 9, 7},{4, 13, 6}};
    Solution sol;
    sol.travel(matrix, 10);
    return 0;
}
