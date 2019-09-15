#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int mmap[21][21];
int visited[21][21];

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

bool BFS(int sx,int sy,int sharkw){
    memset(visited,0,sizeof(visited));


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int sharkw=2;

    cin >> N;

    vector<pair<int,int> > dist;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> mmap[i][j];
            if(mmap[i][j]==9){
                sy=i;
                sx=j;
                mmap[i][j]=0;
            }
            else if(mmap[i][j]>0 && sharkw>mmap[i][j]){
                dist.push_back(make_pair(i,j));
            }
        }
    }

    return 0;
}
