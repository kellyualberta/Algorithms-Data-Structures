#include "head.h"

struct Item{
    int i;
    int j;
    int l;
    Item(int i0, int j0, int l0){
	i = i0;
	j = j0;
	l = l0;
    }
};

vector<pair<int, int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

vector<pair<int, int>> getShortestPaths(vector<vector<int>> matrix){
    vector<pair<int, int>> ret;
    int m = matrix.size();
    int n = matrix[0].size();
    int shortestLen = INT_MAX;
  
    for(int i=0; i<m; ++i){
	for(int j=0; j<n; ++i){
	    if(matrix[i][j]==2){
		queue<pair<int, int>> q;
	        q.push(Item(i, j, 1));
	 	while(q.size()){
		    int ii = q.top.i;		       
		    int jj = q.top.j;		       
		    int ll = q.top.l;		       
		    if(ll>shortestLen) break;
		     
	 	}
	    }
	}
    }
}

int main(){
    return 0;
}
