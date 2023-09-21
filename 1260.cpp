#include <bits/stdc++.h>
using namespace std;
int n,m,v;
vector<vector<int>> vv(1001);
bool visit_d[1001] = {false,};
bool visit_b[1001] = {false,};
void fast();
void dfs(int a);
void bfs(int a);
int main(){
    fast();
    cin >> n >> m >> v;
    int x,y;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        vv[x].push_back(y);
        vv[y].push_back(x);
    }
    for(int i=0;i<vv.size();i++){
        sort(vv[i].begin(),vv[i].end());
    }
    dfs(v);
    cout << '\n';
    bfs(v);
    return 0;
}
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void dfs(int a){
    stack<int> s;
    s.push(a);
    bool home = true;
    visit_d[a] = true;
    cout << a << " ";
    while(!s.empty()){
        home = true;
        for(int i=0;i<vv[s.top()].size();i++){
            if(visit_d[vv[s.top()][i]]){
                s.push(vv[s.top()][i]);
                visit_d[vv[s.top()][i]] = true;
                cout << vv[s.top()][i] << " ";
                home = false;
                break;
            }
        }
        if(home){
            s.pop();
        }
    }
}
void bfs(int a){
    queue<int> q;
    q.push(a);
    while(!q.empty()){
        q.pop();
        if(visit_b[q.front()]){
            continue;
        }
        visit_b[q.front()] = true;
        cout << q.front() << " ";
        for(int i=0;i<vv[q.front()].size();i++){
            if(!visit_b[vv[q.front()][i]]){
                q.push(vv[q.front()][i]);
            }
        }
    }
}
