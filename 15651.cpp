#include <cstdio>

using namespace std;

int set[9];

void RPerm(int set_size,int m,int n){
    if(set_size==n){
        for(int i=0;i<n;i++){
            printf("%d ",set[i]);
        }
        printf("\n");
        return;
    }

    for(int i=1;i<=m;i++){
        set[set_size]=i;
        RPerm(set_size+1,m,n);
    }
}

int main(){
    int N,M;
    scanf("%d%d",&N,&M);

    for(int i=1;i<=N;i++){
        set[i]=i;
    }
    
    RPerm(0,N,M);
    

    return 0;
}