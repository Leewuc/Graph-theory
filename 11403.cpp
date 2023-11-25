#include <iostream>
#include <string.h>
using namespace std;
int n;
int arr[101][101];
bool visited[101];
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void dfs(int m){
    for(int i=0;i<n;i++){
        if(!visited[i] && arr[m][i]){
            visited[i] = true;
            dfs(i);
        }
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        memset(visited,false,101);
        dfs(i);
        for(int j=0;j<n;j++){
            if(visited[j]){
                arr[i][j] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
