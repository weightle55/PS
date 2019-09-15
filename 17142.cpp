#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;

int mmap[51][51];
int visited[51][51];
vector<pair<int,int> > virus_pos;
int numwall=0;
int mini=0x3f3f3f3f;
int num_of_virus=0;
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

bool bfs(int N,int M){
    int comb[10]={0,};

    for(int i=0;i<M;i++) comb[i]=1;

    do{
        memset(visited,0,sizeof(visited));
        deque<pair<int,int> > dq;
        num_of_virus=0;
        int local_max=0;

        for(int i=0;i<virus_pos.size();i++){
            if(comb[i]==1){
                dq.push_back(virus_pos[i]);
                visited[virus_pos[i].second][virus_pos[i].first]=1;
            }
        }

        while(!dq.empty()){
            int tx=dq.front().first;
            int ty=dq.front().second;
            if(mmap[ty][tx]!=2){
                local_max = local_max<visited[ty][tx]-1 ? visited[ty][tx]-1 : local_max;
            }
            
            num_of_virus++;
            dq.pop_front();

            for(int i=0;i<4;i++){
                int ttx=tx+dx[i];
                int tty=ty+dy[i];

                if(ttx>0 && ttx<=N && tty>0 && tty<=N && visited[tty][ttx]==0 && mmap[tty][ttx]!=1){
                    visited[tty][ttx]=visited[ty][tx]+1;
                    dq.push_back(make_pair(ttx,tty));
                
                }
            }
        }

        if(num_of_virus+numwall == N*N){
            mini = mini > local_max ? local_max : mini;
            
            // if(mini==3) cout << "this\n";
            // cout << endl;
            // for(int i=1;i<=N;i++){
            //     for(int j=1;j<=N;j++){
            //         cout << visited[i][j] << " ";
            //     }
            //     cout << endl;
            // }
        }

    }while(prev_permutation(comb,comb+virus_pos.size()));

    // for(int i=0;i<virus_pos.size();i++) cout<< comb[i]<< " ";
    // cout << endl;

    if(mini==0x3f3f3f3f) return false;
    
    return true;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N,M;

    cin >> N >> M;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> mmap[i][j];
            if(mmap[i][j]==1) numwall++;
            else if(mmap[i][j]==2){
                virus_pos.push_back(make_pair(j,i));
            }
        }
    }

    

    if(bfs(N,M)){
        cout << mini << "\n";
    }
    else{
        cout << "-1\n";
    }
    return 0;
}