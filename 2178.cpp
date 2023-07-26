#include <bits/stdc++.h>
using namespace std;
int n,m;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fast();
    int dx,dy;
    string maze[101];
    int arr[101][101];
    bool check[101][101];
    cin >> n >> m;
    int x[4] = {1,0,-1,0};
    int y[4] = {0,1,0,-1};
    queue<pair<int,int>> q;
    pair<int,int> p;
    for(int i=0;i<n;i++){
        cin >> maze[i];
    }
    arr[0][0] = 1;
    check[0][0] = 1;
    q.push({0,0});
    while(!q.empty()){
        p = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            dx = p.first + x[i];
            dy = p.second + y[i];
            if(dx < 0 || dx >= n || dy < 0 || dy >= m){
                continue;
            }
            if(maze[dx][dy] == '0' || check[dx][dy]){
                continue;
            }
            arr[dx][dy] = arr[p.first][p.second]+1;
            q.push({dx,dy});
            check[dx][dy] = 1;
        }
    }
    cout << arr[n-1][m-1];
    return 0;
}
