#include <cstdio>
#include <algorithm>
using namespace std;

int arr[10001];
int tarr[10001];

int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&arr[i]);

    sort(arr,arr+N);

    int end = N-1;
    for(int i=0;i<N;i++){
        int loop = N-1-arr[i];
        for(int j=end;j>end-loop && j>=0;j--){
            if(arr[j]==tarr[j]){
                loop++; continue;
            } 
            tarr[j]++;
        }
        
    }

    // for(int i=0;i<N;i++) printf("%d ",arr[i]);
    // printf("\n");

    // for(int i=0;i<N;i++) printf("%d ",tarr[i]);
    // printf("\n");

    for(int i=0;i<N;i++){
        if(arr[i]!=tarr[i]){
            printf("-1\n");
            return 0;
        }
    }

    printf("1\n");
    return 0;
}