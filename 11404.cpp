#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fast();
    int n,m;
    int a,b,c;
    int flo[101][101];
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            flo[i][j] = i = j ? 0 : INF;
        }
    }
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        flo[a][b] = min(flo[a][b],c);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                flo[j][k] = min(flo[j][k],flo[j][i]+flo[i][k]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << (flo[i][j] == INF ? 0 : flo[i][j]) << ' ';
        }
        cout << '\n';
    }
    return 0;
}
