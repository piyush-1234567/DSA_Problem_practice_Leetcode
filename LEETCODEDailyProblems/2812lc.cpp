#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void PrintIng(vector<vector<int>>& arr){
    int m = arr.size();
    int n = arr[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";

        }
        cout << endl;
    }
}
int main(){
    int m, n;
    cin >> m;
    cin >> n;
    // create a distance vector 
    vector<vector<int>> dist;
    dist.assign(n,vector<int>(n,-1));
    vector<vector<int>> grid(m,vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    // 1st task put everything in the queue
    queue<pair<int,int>> q; 
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                dist[i][j] = 0;
                q.push({i,j});
            }
        }
    }
    // second task finding the distance 
    PrintIng(grid);
    PrintIng(dist);
}