#include <iostream>
#include <queue>
using namespace std;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fast();
    int n;
    int day;
    int score;
    priority_queue<pair<int,int>> pq;
    int cnt = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> day >> score;
        pq.push({score,day});
    }
    bool visited[1001] = {};
    while(!pq.empty()){
        pq.pop();
        for(int i=pq.top().second;i>=1;i--){
            if(!visited[i]){
                visited[i] = true;
                cnt += pq.top().first;
                break;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
