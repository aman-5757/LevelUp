// Based on DFS


#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>> dirA {{0,1},{-1,0},{0,-1},{1,0}};
vector<string> dirS {"R","U","L","D"};

int floodFillAlgo(int sr, int sc, int er, int ec,vector<vector<int>>& board, string ans){
    if(sr == er && sc == ec){
        cout<<ans<<endl;
        return 1;
    }


    int count = 0;
    board[sr][sc] = 1;  //mark visited
    for(int d = 0; d<dirA.size(); d++){         //number of calls required
        int r = sr + dirA[d][0];
        int c = sc + dirA[d][1];

        if(r >= 0 && c >= 0 && r <= er && c <= ec && board[r][c] == 0){
            count += floodFillAlgo(r,c,er,ec,board,ans+dirS[d]);
        } 

    }  



    board[sr][sc] = 0;      //mark unvisited
    return count;
}


int main(){
    int n = 3, m = 3;
    vector<vector<int>> board(n,vector<int>(m,0));
    cout<<floodFillAlgo(0,0,n-1, m-1,board,"")<<endl;
    return 0;
}