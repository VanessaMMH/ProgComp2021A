#include <bits/stdc++.h>
using namespace std;

/*
link: https://leetcode.com/problems/number-of-enclaves/
*/


void path(vector<vector<int>>& grid, int i, int j){
    if( 0>i || i>=grid.size() || 0>j || j>=grid[0].size())
        return;
    if(grid[i][j]==0)
         return;
    grid[i][j]=0;
    path(grid,i+1,j);
    path(grid,i-1,j);
    path(grid,i,j+1);
    path(grid,i,j-1);
}
    
int NumberOfEnclaves(vector<vector<int>>& grid){
   
    for(int i=0;i<grid.size();i++){
        path(grid,i,0);
        path(grid,i,grid[0].size()-1);
    }
    
    for(int i=0;i<grid[0].size();i++){
        path(grid,0,i);
        path(grid,grid.size()-1,i);
    }
                
    int cont=0;
    for(int i=1;i<grid.size();i++){
        for(int j=1;j<grid[0].size();j++)
            if(grid[i][j]==1)
                cont++;
    }
    return cont;
}


int main(){
   
    vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    cout << NumberOfEnclaves(grid) << endl;

    return 0;
}