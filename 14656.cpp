#include <cstdio>

using namespace std;

int arr[20001];

int main(){
    int N;

    scanf("%d",&N);

    for(int i=1;i<=N;i++) scanf("%d",arr+i);
    int cnt=0;
    for(int i=1;i<=N;i++) if(arr[i]!=i) cnt++;

    printf("%d\n",cnt);
    return 0;
}