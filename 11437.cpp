#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int parent[50001];
int depth[50001];
vector<int> Node[50001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for(int i=1;i<N;i++){
        int u,v;
        cin >> u >> v;
        Node[u].push_back(v);
        Node[v].push_back(u);
    }

     depth[1]=1;
    parent[1]=0;
    deque<int> dq;

    dq.push_back(1);

    while(!dq.empty()){
        int tmp=dq.front();
        dq.pop_front();

       // cout << "bfs\n";

        for(int i=0;i<Node[tmp].size();i++){
            int ttmp=Node[tmp][i];
            if(depth[ttmp]==0){
                parent[ttmp]=tmp;
                depth[ttmp]=depth[tmp]+1;
                dq.push_back(ttmp);
            }
        }
    }

    int M;
    cin >> M;

    for(int i=0;i<M;i++){
        int u,v;
        cin >> u >> v;

        int cmnans;

        if(depth[u]<depth[v]){
            int tmp=u;
            u=v;
            v=tmp;
        }

        while(depth[u] !=depth[v]) u=parent[u];

        while(u!=v){
            u=parent[u];
            v=parent[v];
        }
        cmnans=u;
        cout << cmnans << "\n";
    }



    return 0;
}