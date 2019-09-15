#include <cstdio>
#include <vector>
#include <cstring>
#include <deque>

using namespace std;

vector<int> vec[20001];
int color[20001];

bool bfs(int start){
    if(color[start]>0) return true;
    color[start]=1;
    deque<int> dq;
    dq.push_back(start);

    while(!dq.empty()){
        int temp=dq.front();
        dq.pop_front();
        int curcolor=color[temp];

        for(int i=0;i<vec[temp].size();i++){
            int ti=vec[temp][i];
            if(color[ti]==0){
                color[ti]= (curcolor == 1) ? 2 : 1;
                dq.push_back(ti);
            }else{
                if(color[ti]==curcolor) return false;
            }
        }
    }

    return true;
}

int main(){
    int T;
    scanf("%d",&T);
    for(;T>0;T--){
        memset(color,0,sizeof(color));        
        
        int V,E;
        scanf("%d%d",&V,&E);

        for(int i=0;i<E;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        bool res=true;

        for(int i=1;i<=V;i++){
            res = res && bfs(i) ? true : false;
        }

        if(res) printf("YES\n");
        else printf("NO\n");

        for(int i=1;i<=V;i++){
            vec[i].clear();
        }
    }
    return 0;
}