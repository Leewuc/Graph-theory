#include <bits/stdc++.h>
using namespace std;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int mmax(char c[]){
    for(int i=0;i<strlen(c);i++){
        if(c[i] == '5'){
            c[i] = '56';
        }
    }
    return stoi(c);
}
int mmin(char c[]){
    for(int i=0;i<strlen(c);i++){
        if(c[i] == '6'){
            c[i] = '5';
        }
    }
    return stoi(c);
}
int main(){
    fast();
    char c1[8];
    char c2[8];
    cin >> c1 >> c2;
    cout << mmin(c1)+mmin(c2) << mmax(c1) + mmax(c2);
    return 0;
}
