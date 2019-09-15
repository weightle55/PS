#include <iostream>
#include <deque>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int sharkw=2;
int cnt=0;
int sx,sy;
int mmap[21][21];
int dmap[21][21];
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

vector<pair<int,pair<int,int> > > eatable;

void dfs(int N){
    memset(dmap,0,sizeof(dmap));

    deque<pair<int,int> > dq;
    dq.push_back(make_pair(sy,sx));
    dmap[sy][sx]=1;
    
    while(!dq.empty()){
        int ty=dq.front().first;
        int tx=dq.front().second;
        dq.pop_front();

        for(int i=0;i<4;i++){
            int tty=ty+dy[i];
            int ttx=tx+dx[i];
            if(tty<=N && tty>0 && ttx<=N && ttx>0 && dmap[tty][ttx]==0 && mmap[tty][ttx]<=sharkw){
                dmap[tty][ttx]=dmap[ty][tx]+1;
                dq.push_back(make_pair(tty,ttx));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int res=0;
    cin >> N;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> mmap[i][j];
            if(mmap[i][j]==9){
                sx=j;
                sy=i;
                mmap[i][j]=0;
            }   
        }
    }
    
    do{
        eatable.clear();
        dfs(N);

        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(dmap[i][j]!=0 && mmap[i][j]!=0 && mmap[i][j]<sharkw){
                    eatable.push_back(make_pair(dmap[i][j]-1,make_pair(i,j)));
                }
                //cout <<dmap[i][j] << " ";
            }
            //cout << endl;
        }

        sort(eatable.begin(),eatable.end());
        
        if(!eatable.empty()){
            int dst=eatable.front().first;
            int fishy=eatable.front().second.first;
            int fishx=eatable.front().second.second;

            res+=dst;
            mmap[fishy][fishx]=0;
            sy=fishy;
            sx=fishx;
            cnt++;
            if(cnt==sharkw){
                sharkw++;
                cnt=0;
            }
        }
        

    }while(!eatable.empty());

    cout << res << "\n";
    return 0;
}