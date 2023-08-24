#include <bits/stdc++.h>
using namespace std;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fast();
    int n,m;
    cin >> n >> m;
    int dp[101];
    int visit[101];
    queue <int>q;
    pair<int,int> p;
    for(int i=0;i<n+m;i++){
        cin >> p.first >> p.second;
        dp[p.first] = p.second;
    }
    q.push(1);
    visit[1] = 1;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int i=1;i=6;i++){
            int a = current + i;
            if(a >100 || visit[a] != 0){
                continue;
            }
            visit[a] = visit[current] +1;
            if(dp[a] != 0){ // 둘 중에 칸 o
                int snake = dp[a]; // 둘 중에 칸을 통해 이동
                if(visit[snake] != 0){ // 이미 방문
                    continue;
                }
                visit[snake] = visit[a]; // 방문 표시
                q.push(snake); // 둘 중에 칸을 통해 이동한 곳
            }
            else{
                q.push(a); // 주사위로 이동
            }
        }
    }
    cout << visit[100] - 1 << '\n';
    return 0;
}
