#include<iostream>
#include<vector>
using namespace std;


//LeetCode 200

vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

void numIslands_(int sr, int sc, vector<vector<char>>& grid) {
    
    grid[sr][sc] = '0';
    for(int d = 0; d<4; d++){
        int r = sr + dir[d][0];
        int c = sc + dir[d][1];
        if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c] == '1'){
            numIslands_(r,c,grid);
        }
    }
    
}

int numIslands(vector<vector<char>>& grid) {
    if(grid.size() == 0 || grid[0].size() == 0)     return 0;
    int count = 0;
    for(int  i = 0; i<grid.size(); i++){
        for(int j = 0; j<grid[0].size(); j++){
            if(grid[i][j] == '1'){
                count++;
                numIslands_(i,j,grid);
            }
        }
    }
    return count;

}


// LeetCode 695 ================================

 vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    
    int maxAreaOfIsland_(int sr, int sc,vector<vector<int>>& grid ){
        int co = 0;
        grid[sr][sc] = 0;
    for(int d = 0; d<4; d++){
        int r = sr + dir[d][0];
        int c = sc + dir[d][1];
        if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c] == 1){
            co += maxAreaOfIsland_(r,c,grid);
        }
    }
        return co+1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)     return 0;
    int maxArea = 0;
    for(int  i = 0; i<grid.size(); i++){
        for(int j = 0; j<grid[0].size(); j++){
            if(grid[i][j] == 1){
                maxArea = max(maxArea,maxAreaOfIsland_(i,j,grid));
            }
        }
    }
    return maxArea;
    }



// LeetCode 463 === PERIMETER==============================================================

    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0;
        int nbrs = 0;
        for(int  i = 0; i<grid.size(); i++){
             for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                  count++;
                  for(int d = 0; d<4; d++){
                        int r = sr + dir[d][0];
                        int c = sc + dir[d][1];
                        if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c] == 1){
                            nbrs++;
        }

            }
        }
    }
    return 4*count-nbrs;
    }

//LeetCode 130 ===== or say COLORING OF GRAPH=========================================


// This is also known as coloring of Graph
vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    
    void solve_(vector<vector<char>>& grid,int i, int j ){
        
        grid[i][j] = '#';
    for(int d = 0; d<4; d++){
        int r = i + dir[d][0];
        int c = j + dir[d][1];
        if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c] == 'O'){
            solve_(grid,r,c);
        }
    }
        
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0)  return;
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < board.size(); i++ ){
            if(board[i][0] == 'O'){
                solve_(board,i,0);
            }
            if(board[i][m-1] == 'O')
                solve_(board,i,m-1);
        }
        for(int i = 0; i < board[0].size(); i++ ){
            if(board[0][i] == 'O'){
                solve_(board,0,i);
            }
            if(board[n-1][i] == 'O')
                solve_(board,n-1,i);
        }
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(board[i][j] == 'O')  board[i][j] = 'X';
                else if(board[i][j] == '#')  board[i][j] = 'O';
            }
        }
    }


    //Graph Continue == 10/July/20
    //=======================================================================================

    //LeetCode 994 --> Rotten Oranges

    int orangesRotting(vector<vector<int>> & grid){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> qu;
        int freshOrganes = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    qu.push({i,j});
                }
                else if(grid[i][j] == 1){
                    freshOrganes++;
                }
            }
        }
        if(freshOrganes == 0)   return 0;
        vector<vector<int >> dir{{0,1},{0,-1},{1,0},{-1,0}};
        int time = 0;
        while(qu.size!=0){
            int size = qu.size();
            while(size-->0){
                pair<int, int> rv = qu.front(); qu.pop();
                for(int d = 0; d<4; d++){
                    int r = rv.first + dir[d][0];
                    int c = rv.second + dir[d][1];
                    if(r>=0 && c>=0 && r<n && c<m && grid[r][c] ==1){
                        grid[r][c] =2 ;
                        qu.push({r,c});
                        freshOrganes--;
                    }
                }
            }
            time++;
        }
        return freshOrganes != 0 ? -1: time-1;
    }


    //Graph Continue == 12/July/20
    //=======================================================================================

    //LeetCode 207 --> Course Schedule
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        vector<vector<int>> graph(N, vector<int>());
        vector<int> indegree(N,0);
        for(vector<int> & ar : prerequisites){
            graph[ar[0]].push_back(ar[1]);
            indegree[ar[1]]++;

        }
        queue<int> qu;
        int count = 0;
        for(int i = 0 ; i<N; i++){
            if(indegree[i] == 0){
                qu.push(i);
            }
        }
        while(qu.size() != 0){
            int rvtx = qu.front(); qu.pop();
            count++;
            for(int e : graph[rvtx]){
                if(--indegree[e] == 0){
                    qu.push(e);
                }
            }
        }
        return count == N;
}

//LeetCode 210 --> Course Schedule ||
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        vector<vector<int>> graph(N, vector<int>());
        vector<int> indegree(N,0);
        for(vector<int> & ar : prerequisites){
            graph[ar[0]].push_back(ar[1]);
            indegree[ar[1]]++;

        }
        queue<int> qu;
        vector<int> ans;
        for(int i = 0 ; i<N; i++){
            if(indegree[i] == 0){
                qu.push(i);
            }
        }
        while(qu.size() != 0){
            int rvtx = qu.front(); qu.pop();
            // count++;
            ans.push_back(rvtx);
            for(int e : graph[rvtx]){
                if(--indegree[e] == 0){
                    qu.push(e);
                }
            }
        }
        if(ans.size() != N){
            ans.clear();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }


//========UNION FIND 13 JULY 2020=====================================================================
//LeetCode 684==================
vector<int > par;
int findPar(int u){
    if(par[u] == u){
        return u;
    }
    return par[u] = findPar(par[u]);
}
    
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    if (edges.size() == 0 || edges[0].size() == 0)
    return {};
   for(int i = 0; i<edges.size()+1; i++){
        par.push_back(i);
    }
    for(vector<int> e : edges){
        int p1 = findPar(e[0]);
        int p2 = findPar(e[1]);
        if(p1 != p2){
            par[p1] = p2;
        }
        else{
            return e;
        }
    }
    return {};
}

//LeetCode 547==========FRIEND CIRCLE===============================
vector<int > par;
int findPar(int u){
    if(par[u] == u){
        return u;
    }
    return par[u] = findPar(par[u]);
}
int findCircleNum(vector<vector<int>>& M) {
    for(int i = 0; i<M.size(); i++){
        par.push_back(i);
    }
    for(int i = 0; i<M.size(); i++){
        for(int j = 0; j<M[0].size; j++){
            if(M[i][j] == 1 && i!=j){
                int p1 = findPar(i);
                int p2 = findPar(j);
                if(p1!=p2){
                    par[p1] = p2;
                }
            }
        }
    }
    int count = 0;
    for(int i = 0; i<par.size(); i++){
        if(i == par[i])     count++;
    }
    return count;
}


//LeetCOde 200 num
vector<int> par;
int findPar(int u){
    if (par[u] == u)    return u;
    return par[u] = findPar(par[u]);
}


int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == '1')   count++;
            par.push_back(i*m+j);
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){

            if(grid[i][j] == '1'){
                    int p1 = findPar(i*m+j);
            if(j+1<m && grid[i][j+1] == '1'){
                int p2 = findPar(i*m+j+1);
                if(p1 != p2){
                    par[p1] = p2;
                    count--;
                }
            }
            if(i+1<n && grid[i+1][j] == '1'){
                int p2 = findPar((i+1)*m+j);
                if(p1 != p2){
                    par[p1] = p2;
                    count--;
                }
            }
            }


            
        }
    }
    return count;
} 


//LeetCode 1061 --> LOCKED

string smallestEquivalentString(string A, string B, string S){
    vector<int > par;
    for(int i = 0; i<26; i++)   par.push_back(i);
    for(int i = 0; i<A.size(); i++){
        int ch1 = A[i];
        int ch2 = B[i];
        
        int p1 = findPar(ch1-'a');
        int p2 = findPar(ch2-'a');

        par[p1] = min(p1,p2);
        par[p2] = min(p1,p2);
    }
    string ans = "";
    for(int i = 0; i<S.size(); i++){
        ans += (char)(findPar(S[i]-'a')+'a');
    }
    return ans;
}

//LeetCode 839  ===========================================

vector<int > par;

bool isSimilar(string & a, string & b){
    int count = 0;
    for(int i = 0; i<a.size(); i++){
        if(a[i] != b[i]){
            count++;   
           }
        if(count > 2) return false;
        }
        return true;
}

int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        for(int i = 0; i<n; i++)    par.push_back(i);
        int count = n;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(isSimilar(A[i],A[j])){
                    int p1 = findPar(i);
                    int p2 = findPar(j);
                    if(p1!=p2){
                        par[p1] = p2;
                        count--;
                    }
                }
            }
        }
        return count;
}


//


//LeetCode 1168== == == Min Cost Well (Take 0(well virtual) node and connect all nodes to it and the find MST)

int minCostToSupplyWater(int n, vector<int> & wells, vector<vector<int>> & pipes){
    for(int i = 0; i<wells.size(); i++){
        pipes.push_back(0,i+1,wells[i]);
    }
    sort(pipes.begin(), pipes.end(), []vector<int> &a, vector<int> &b){
        return a[2]<b[2];
    }
    int cost = 0;
    for(vector<int > & e : pipes){
        int p1 = findPar(e[0]);
        int p2 = findPar(e[1]);
        if(p1!=p2){
            par[p1] = p2;
            cost += e[2];
        }
    }
    return cost;
}

//LeetCode 787
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    typedef pair<int, int>  pii; //{v,w}
    vector<vector<pii>> graph(n,vector<pii>());
    for(vector<int> & flight : flights) {
        graph[flight[0]].push_back({flight[1],flight[2]});
    }   
    typedef vector<int > pqPair ; // {wsf,src,stops}
    priority_queue<pqPair,vector<pqPair> , greater<pqPair>> pq;
    pq.push({0,src,K+1});
    while(pq.size()!= 0){
        pqPair rvtx = pq.top();
        pq.pop();
        int u = rvtx[1];
        int wsf = rvtx[0];
        int stop = rvtx[2];

        if(u == dst)    return wsf;
        if(stop == 0)   continue;
        for(pii e : graph[u]){
            int v = e.first;
            int weightOfEdge = e.second;
            pq.push({wsf+weightOfEdge,v,stop-1});
        }

    }
    return -1;
}