#include "head.h"

vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
class Solution{
public:
    pair<int, int> getMergePoint(vector<vector<char>> matrix, vector<pair<int, int>> robots){
	int m = matrix.size();
	int n = matrix.size();
	int K = robots.size();
	vector<vector<int>> distance_total(m, vector<int>(n, 0));

	for(int i=0; i<K; ++i){
	    vector<vector<bool>> visited(m, vector<bool>(n, false));
	    vector<vector<int>> distance(m, vector<int>(n, 0));
	    queue<pair<int, int>> q;
	    q.push(pair<int, int>(robots[i].first, robots[i].second));
	    visited[robots[i].first][robots[i].second] = true;
	    while(!q.empty()){
		pair<int, int> t = q.front();
		q.pop();
		int x = t.first;
		int y = t.second;
//		cout<<x<<" "<<y<<endl; 
		for(int d=0; d<4; ++d){
		    int x1 = x + dir[d][0];	
		    int y1 = y + dir[d][1];
		    if(x1>=0 && x1<m && y1>=0 && y1<n && matrix[x1][y1]!='X' && !visited[x1][y1]){
			q.push(pair<int, int>(x1, y1));
			visited[x1][y1] = true;
			distance[x1][y1] = distance[x][y]+1;
		    }
		}
//		PrintVV(distance, "distance");
//		PrintVV(visited, "visited");
	    }

	    PrintVV(distance, "distance");
	    for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
		    distance_total[i][j] += distance[i][j];
		}
	    }
	}

	PrintVV(distance_total, "distance_total");	
	pair<int, int> mp;
	return mp;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> matrix = {{'0','0','0','0','0'},
				   {'0','0','X','0','0'},
				   {'0','X','0','0','0'},
				   {'0','0','0','0','0'},
				   {'0','0','0','0','0'}};
    vector<pair<int, int>> robots;
    robots.push_back(pair<int, int>(0,4));
    robots.push_back(pair<int, int>(1,1));
    robots.push_back(pair<int, int>(3,3));
    sol.getMergePoint(matrix, robots);
    return 0;
}
