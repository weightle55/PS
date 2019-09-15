#include <iostream>

using namespace std;

int game[100001];
int buyer[100001];
int root[100001];
int joincnt[100001];

int find(int x){
    if(x==root[x]) return x;

    return root[x]=find(root[x]);
}

void _union(int x,int y){
    x=find(x);
    y=find(y);
    root[y]=x;
    joincnt[x]+=joincnt[y];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N,M,Q;
    cin >> N >> M >> Q;
    for(int i=1;i<=N;i++){
        cin >> buyer[i];
        game[buyer[i]]++;
        root[i]=i;
    }

    for(int i=1;i<=M;i++){
        if(game[i]==1){
            cout << "0\n";
        }
    }

    for(int i=1;i<=Q;i++){
        int a,b;
        cin >> a >> b;

        _union(a,b);

        for(int j=1;j<=M;j++){
            if(game)
        }
    }

    return 0;
}