#include <cstdio>

using namespace std;

int set[10];

void RComb(int set_size,int m,int n, int index){
    if(set_size==n){
        for(int i=0;i<n;i++){
            printf("%d ",set[i]);
        }
        printf("\n");
        return;
    }
    else if(index==m+1) return;

    set[set_size]=index;
    RComb(set_size+1,m,n,index);
    RComb(set_size,m,n,index+1);
}

int main(){
    int N,M;

    scanf("%d%d",&N,&M);

    for(int i=1;i<=N;i++){
        set[i]=i;
    }

    RComb(0,N,M,1);


    return 0;
}