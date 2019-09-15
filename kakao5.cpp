#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int visited[200001];
int conis[200001];

void bfs(int start){
    memset(visited,0,sizeof(visited));
    
    visited[start]=1;
    deque<int> dq;
    dq.push_back(start);

    while(!dq.empty()){
        int node=dq.front();
        dq.pop_front();

        int cost=visited[node];

        if(node>0 && visited[node-1]==0){
            dq.push_back(node-1);
            visited[node-1]=cost+1;
        }

        if(node<200000 && visited[node+1]==0){
            dq.push_back(node+1);
            visited[node+1]=cost+1;
        }

        if(node<100000 && visited[node*2]==0){
            dq.push_back(node*2);
            visited[node*2]=cost+1;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int coni,brown;

    cin >> coni >> brown;

    for(int i=0,temp=coni ; temp<200001; i++ ){
        temp+=i;
        conis[temp]=i+1;
    }

    bfs(brown);

    int res=0x3f3f3f3f;
    for(int i=0;i<200001;i++){
        if(conis[i]==visited[i]) res= res>conis[i] ? conis[i]:res;
    }

    // for(int i=0;i<30;i++) cout << conis[i]<<" ";
    // cout << endl;
    // for(int i=0;i<30;i++) cout << visited[i] << " ";
    // cout << endl;

    cout << res-1 << "\n";

    return 0;
}