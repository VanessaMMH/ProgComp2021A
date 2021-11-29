#include <bits/stdc++.h>
using namespace std;


/*
link: https://open.kattis.com/problems/amoebas
*/

void path(vector<vector<char>>& grid, int i, int j){
   
    if( 0>i || i>=grid.size() || 0>j || j>=grid[0].size())
        return;
    if(grid[i][j]=='.')
         return;

    grid[i][j]='.';

    path(grid,i,j-1);
    path(grid,i+1,j);
    path(grid,i,j+1);
    path(grid,i-1,j);
    path(grid,i+1,j-1);
    path(grid,i-1,j-1);
    path(grid,i+1,j+1);
    path(grid,i-1,j+1);

}


int shebasAmoebas(vector<vector<char>>& grid){
    int cont=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]!='.') {
                cont++;
                path(grid,i,j);
            }
        }
    }
    return cont;
}

int main(){

    int n,m;
    cin >> n >> m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    cout<<shebasAmoebas(grid);
    return 0;
}
