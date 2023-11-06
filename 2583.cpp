#include <iostream>
#include <queue>
using namespace std;
int n,m,k;
queue <pair<int,int>> q;
priority_queue <int> pq;
int xx[4] = {0,1,0,-1};
int yy[4] = {1,0,-1,0};
bool visited[101][101];
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int bfs(int x,int y){
    int cnt = 0;
    q.push({x,y});
    visited[x][y] = true;
    while(!q.empty()){
        cnt ++;
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx = x+xx[i];
            int dy = y+yy[i];
            if(dx >= 0 && dx < n && dy >= 0 && dy <m){
                if(!visited[dx][dy]){
                    visited[dx][dy] = true;
                    q.push({dx,dy});
                }
            }
        }
    }
    return cnt;
}
int main(){
    fast();
    cin >> n >> m >> k;
    int x1,x2,y1,y2;
    int cnt = 0;
    while(k--){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i=y1; i<y2;i++){
            for(int j=x1;j<x2;j++){
                visited[i][j] = true;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]){
                cnt ++;
                pq.push(-bfs(i,j));
            }
        }
    }
    cout << cnt << '\n';
    while(!pq.empty()){
        cout << -pq.top() << ' ';
        pq.pop();
    }
    return 0;
}
