// 1. Flood Fill Algorithm based on DFS (Separate File)
// 2. LeetCode 980      -> Based on DFS
// 3. LeetCode 1219       -> Based on DFS


#include<iostream>
#include<vector>
using namespace std;

int n,m;
vector<vector<int>> dirA{{0,1},{-1,0},{0,-1},{1,0}};
    
int getMaximumGold(int sr, int sc,vector<vector<int>>& grid ){
    int maxGold = 0;
    grid[sr][sc] = -grid[sr][sc] ;
    for( int d = 0; d<dirA.size(); d++){
        int r = sr + dirA[d][0];
        int c = sc + dirA[d][1];
        if (r >= 0 && c >= 0 && c < m && r < n && grid[r][c]>0){
            maxGold = max(maxGold,getMaximumGold(r,c,grid));
        }
    } 
    grid[sr][sc] = -grid[sr][sc] ;
    return grid[sr][sc] + maxGold;

    }   
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
         int maxGold = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] != 0){
                    maxGold = max(maxGold,getMaximumGold(i, j, grid));
                }
            }
        }
        return maxGold;     
        
    }


vector<string> dirS {"U","D","L","R"};
vector<vector<int>> dirB{{-1,0},{1,0},{0,-1},{0,1}};


void ratMaze(int sr, int sc, int er, int ec, vector<vector<int>> & grid, string ans){
    if(sr == er && sc == ec){
        cout<<ans<<endl;
        return ;
    }

    // int count = 0;
    grid[sr][sc] = 0;
    for(int i = 0; i<dirB.size(); i++){
        int r = sr + dirB[i][0];
        int c = sc + dirB[i][1];
        if(r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c] == 1){
            ratMaze(r,c,er,ec,grid,ans + dirS[i]);
        }
    }
     grid[sr][sc] = 1;
    return;
    
}



int main()
{   vector<vector<int>> arr{{1,0,0,0},{1,1,0,1}, {1,1,0,0}, {0,1,1,1}};
    // int ans = ratMaze(0,0,3,3,arr,"");
    // System.out.print(ans);
    // cout<<ans;
    ratMaze(0,0,3,3,arr,"");
    return 0;
}
