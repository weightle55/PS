#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define INF 0x3f3f3f3f
using namespace std;

int dt[101][101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;

    memset(dt,0x3f,sizeof(dt));

    cin >> N >> M;
    for(int i=0;i<M;i++){
        int s,t,w;
        cin >> s >> t >> w;
        dt[s][t]=min(w,dt[s][t]);
    }

    for(int i=1;i<=N;i++) dt[i][i]=0;

    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                //if(i==j || i==k || k==j) continue;
                dt[i][j]=min(dt[i][j],dt[i][k]+dt[k][j]);
            }
        }
    }

    for(int i=1; i<=N ;i++ ){
        for(int j=1;j<=N;j++){
            if(dt[i][j]==INF) cout << "0 ";
            else cout << dt[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}