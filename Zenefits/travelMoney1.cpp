#include "head.h"

class Solution{
    int m;
    int n;
public:
    int travel(vector<vector<int>> matrix, int k){
	m = matrix.size();
	n = matrix[0].size();
	int ret = INT_MAX;
	bfs(0, 0, k, ret, matrix);
	return ret;
    }

    void bfs(int i, int j, int left, int& ret, vector<vector<int>> &matrix){
	left -= matrix[i][j];
	if(left<0) return;
	if(i==m-1 && j==n-1) ret = min(ret, left);
	if(i+1<m) bfs(i+1, j, left, ret, matrix);		
	if(j+1<n) bfs(i, j+1, left, ret, matrix);		
    }
};

int main(){
    vector<vector<int>> matrix = {{0, 5},{2, 9}};
    Solution sol;
    cout<<sol.travel(matrix, 20)<<endl;
    return 0;
}
