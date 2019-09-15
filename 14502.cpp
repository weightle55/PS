#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int cmap[9][9];
int tmap[9][9];
bool visited[9][9];
int permap[65];

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

int twocnt;

void dfs(int x,int y,int N,int M){
    if(visited[y][x]) return;

    visited[y][x]=true;
    twocnt++;

    for(int i=0;i<4;i++){
        int ddx=x+dx[i];
        int ddy=y+dy[i];
        if(ddx>0 && ddx<=M && ddy>0 && ddy<=N && !visited[ddy][ddx] && tmap[ddy][ddx]!=1){
            dfs(ddx,ddy,N,M);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,M;

    cin >> N >> M;

    vector<pair<int,int> > pollute;
    int onecnt=0;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> cmap[i][j];
            tmap[i][j]=cmap[i][j];
            if(tmap[i][j]==2){
                pollute.push_back(make_pair(i,j));
            }
            else if(tmap[i][j]==1) onecnt++;
        }
    }

    permap[N*M]=1;
    permap[N*M-1]=1;
    permap[N*M-2]=1;

    int safe = 0;
    do{
        twocnt=0;
        bool isSkip=false;
        int ttx[3];
        int tty[3];

        int numt=0;
        for(int i=1;i<=N*M;i++){
            if(permap[i]==1){
                int tx=i%M;
                int ty=i/M+1;
                if(tx==0) {
                    ty=i/M;
                    tx=M;
                }
                if(cmap[ty][tx]!=0){
                    isSkip=true;
                }                 
                else{
                    ttx[numt]=tx;
                    tty[numt]=ty;
                    numt++;
                } 
            }
        }
        if(isSkip) continue;

        for(int i=0;i<3;i++){
            tmap[tty[i]][ttx[i]]=1;
        }

        memset(visited,false,sizeof(visited));

        for(int i=0;i<pollute.size();i++){
            int gy=pollute[i].first;
            int gx=pollute[i].second;

            dfs(gx,gy,N,M);
        }

        for(int i=0;i<3;i++){
            tmap[tty[i]][ttx[i]]=0;
        }

        int max = N*M -onecnt-3-twocnt;
        safe = max > safe ? max : safe;

    }while(next_permutation(permap+1,permap+N*M+1));

    cout <<  safe << "\n";

    return 0;
}