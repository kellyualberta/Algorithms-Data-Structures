#include "head.h"

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
  	int m = dungeon.size();
	int n = dungeon[0].size();
	
	vector<vector<int>> dp(m+1, vector<int>(n+1, 0));      
	for(int i=0; i<=m; ++i) dp[i][n] = INT_MAX;
	for(int j=0; j<=n; ++j) dp[m][j] = INT_MAX;
	dp[m][n-1] = 1;
	dp[m-1][n] = 1;

	for(int i=m-1; i>=0; --i){
	    for(int j=n-1; j>=0; --j){
		dp[i][j] = min(dp[i+1][j], dp[i][j+1])-dungeon[i][j];
		dp[i][j] = max(dp[i][j], 1);
	    }
	}
	return dp[0][0];
    }
};

int main(){
    return 0;
}
