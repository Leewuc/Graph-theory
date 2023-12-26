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
    int n,m;
    cin >> n >> m;
    queue<pair<long long int,int>> q;
    int answer = -1;
    q.push(make_pair(n,1));
    while(!q.empty()){
        long long int a = q.front().first;
        long long int b = q.front().second;
        q.pop();
        if(a == m){
            answer = b;
            break;
        }
        if(a*2 <= m){
            q.push(make_pair(a*2,b+1));
        }
        if(a*10+1 <= m){
            q.push(make_pair(a*10+1,b+1));
        }
    }
    cout << answer;
    return 0;
}
