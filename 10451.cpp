#include <bits/stdc++.h>
using namespace std;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int n,m,k;
vector<int> v[1001];
bool vis[1001];
void dfs(int a){
    int nt;
    if(vis[a]){
        return;
    }
    vis[a] = 1;
    for(int i=0;i<v[a].size();i++){
        nt = v[a][i];
        dfs(nt);
    }
}
int main(){
    fast();
    int cnt = 0;
    cin >> m;
    while(m--){
        cin >> n;
        memset(v,0,sizeof(v));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            cin >> k;
            v[i+1].push_back(k);
        }
        for(int i = 1;i<=n;i++){
            if(!vis[i]){
                dfs(i);
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
