#include <iostream>
#include <vector>
#include <cstring>

#define INF 0x3f3f3f3f

using namespace std;

vector<pair<int,int> > node[501];
int value[501];

bool bellmanford(int N){
    memset(value,INF,sizeof(value));

    value[1] = 0;
    for(int i=0;i<N;i++){
        for(int j=1; j<=N; j++){
            for(int k=0;k<node[j].size();k++){
                int next=node[j][k].first;
                int dist=node[j][k].second;
                if(value[j] != INF && value[next] > value[j]+dist){
                    value[next]= value[j]+dist;
                    if(i == N-1) return false;
                }
            }
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    int a,b,c;

    cin >> N >> M;

    for(int i=0;i<M;i++){
        cin >> a >> b >> c;
        node[a].push_back(make_pair(b,c));
    }

    if(bellmanford(N)){
        for(int i=2;i<=N;i++) {
            if(value[i] == INF) cout << "-1\n";
            else cout << value[i] << "\n";
        }
    }
    else{
        cout << "-1\n";
    }
    return 0;
}