#include <bits/stdc++.h>
using namespace std;


/*
link: https://open.kattis.com/problems/countingstars
*/

void path(vector<vector<int>> &grid, int i, int j, int m, int n){
    if(i < 0 || i > (m-1) || j < 0 || j > (n-1) || grid[i][j] != 1) return;


    if(grid[i][j] == 1){

        grid[i][j] = 0;
        int rowNbr[] = {-1, 0, 0, 1};
        int colNbr[] = {0, -1, 1, 0};
        for(int k = 0; k < 4; k++){
            int row = i + rowNbr[k];
            int col = j + colNbr[k];
            path(grid, row, col, m, n);
        }      
    }
    
}


int countingStars(vector<vector<int>> &grid, int m, int n){
    int res = 0;
    int rowNbr[] = {-1, 0, 0, 1};
    int colNbr[] = {0, -1, 1, 0};

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            if(grid[i][j] == 1){
                grid[i][j] = 0;
                res++;
                for(int k=0; k<4; k++){
                    int row = i + rowNbr[k];
                    int col = j + colNbr[k];
                    path(grid, row, col, m, n);
                }
            }

    return res;
}

int main(int argc, char const *argv[]){
    int m,n,cont = 1;
    while(cin >> m && cin >> n){

        vector<vector<int>> grid(m, vector<int>(n));
        string s;
        for(int i=0; i<m; i++){
            cin >> s;
            int j=0;
            for(auto car : s){
                grid[i][j++] = (car == '#') ? 0 : 1;
            }
        }
        cout << "Case " << cont << ": " << countingStars(grid, m, n) << endl;
        cont++;
    } 


    return 0;
}