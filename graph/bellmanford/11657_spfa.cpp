#include <iostream>
#include <deque>
#include <utility>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

vector<pair<int,int> > node[501];
int value[501];
bool inQ[501];
int refresh[501];

bool SPFA(int N){
    fill(value+1,value+N+1,INF);
    value[1]=0;
    deque<int> dq;
    dq.push_back(1);
    refresh[1]++;
    inQ[1]=true;

    while(!dq.empty()){
        int temp = dq.front();
        dq.pop_front();
        inQ[temp]=false;

        if(refresh[temp]>=N){
            return false;
        }
        refresh[temp]++;

        for(int i=0;i<node[temp].size();i++){
            int next = node[temp][i].first;
            int weight = node[temp][i].second;
            if(value[temp]+weight < value[next]){
                value[next] = value[temp]+weight;
                
                if(!inQ[next]){
                    dq.push_back(next);
                    inQ[next]=true;
                }
            }
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    int a,b,c;

    cin >> N >> M;

    for(int i=0;i<M;i++){
        cin >> a >> b >> c;
        node[a].push_back(make_pair(b,c));
    }

    if(SPFA(N)){
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
