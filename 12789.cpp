#include <iostream>
using namespace std;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fast();
    int n,m;
    int doky[10001];
    int top = 1;
    int bot = 1;
    cin >> n;
    while(n--){
        cin >> m;
        if(bot == m){
            bot++;
        }
        else{
            while(top > 0 && doky[top-1] == bot){
                top--;
                bot++;
            }
            doky[top++] = m;
        }
    }
    while(top >= 1){
        if(bot == doky[top-1]){
            bot++;
            top++;
        }
        else{
            cout << "Sad";
            return 0;
        }
    }
    cout << "Nice";
    return 0;
}
