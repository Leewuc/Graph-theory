#include <iostream>
#include <vector>
using namespace std;
int n;
int cnt;
int pipe[17][17];
int xx[3] = {0,1,1};
int yy[3] = {1,0,1};
vector<int> v[3] = {{0,2},{1,2},{0,1,2}};
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void dfs(int x,int y,int a){
    if(x == n-1 && y == n-1){
        cnt++;
        return;
    }
    for(auto i : v[a]){
        int dx = x+xx[i];
        int dy = y+yy[i];
    
    if(dx < 0 || dx >= n || dy < 0 || dy >= 0 || pipe[dx][dy] == 1){
        continue;
    }
    if(i == 2 && (pipe[dx-1][dy] == 1 || pipe[dx][dy-1] == 1)){
        continue;
    }
    dfs(dx,dy,i);
    }
}
int main(){
    fast();
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> pipe[i][j];
        }
    }
    if(pipe[n-1][n-1] == 0){
        dfs(0,1,0);
    }
    cout << cnt;
}
