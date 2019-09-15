#include <cstdio>

using namespace std;

int mat[1001][1001];
int res[1001];

int main(){
    int N;
    scanf("%d",&N);

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            scanf("%d",&mat[i][j]);
        }
    }

    for(int i=1;i<=N;i++){
        res[i]=0;
        for(int j=1;j<=N;j++){
            if(i==j) continue;
            res[i] |= mat[i][j];
        }
    }

    for(int i=1;i<=N;i++){
        printf("%d ",res[i]);
    }
    printf("\n");
    return 0;
}