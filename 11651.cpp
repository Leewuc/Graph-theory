#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
bool ab(pair<int,int> xi,pair<int,int> yi){
    if(xi.second == yi.second){
        return xi.first < yi.first;
    }
    return xi.second < yi.second;
}
int main(){
    fast();
    int n;
    cin >> n;
    vector <pair<int,int>> v;
    int xi,yi;
    for(int i=0;i<n;i++){
        cin >> xi >> yi;
        v.push_back(make_pair(xi,yi));
    }
    sort(v.begin(),v.end(),ab);
    for(int i=0;i<n;i++){
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    return 0;
}
