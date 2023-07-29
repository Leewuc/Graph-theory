#include <bits/stdc++.h>
using namespace std;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fast();
    string s;
    set<string> ss;
    getline(cin,s);
    cin >> s;
    for(int i=0;i<s.size();i++){
        for(int j=1;j+i<=s.size();j++){
            ss.insert(s.substr(i,j));
        }
    }
    cout << ss.size() << '\n';
    return 0;
}
