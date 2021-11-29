#include <bits/stdc++.h>
using namespace std;


/*
link: https://leetcode.com/problems/keys-and-rooms/
*/


void path(vector<vector<int>> & rooms, vector<int> &visited, int u){
    visited[u] = 1;
    for(int j = 0; j < (int) rooms[u].size(); j++){
        int vec = rooms[u][j];
        if(visited[vec] == 0){
            path(rooms, visited, vec);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<int> visited(n, 0);
    path(rooms, visited, 0);
    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> rooms = {{1}, {2}, {3}, {}};
    if (!canVisitAllRooms(rooms))
        cout << "false" << endl;
    else
        cout << "true" << endl ;
    
    return 0;
}