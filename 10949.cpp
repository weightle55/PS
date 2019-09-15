#include <cstdio>

using namespace std;

int arr[5];

int main(){
    int L,P;
    scanf("%d%d",&L,&P);

    for(int i=0;i<5;i++) scanf("%d",arr+i);

    int temp = L*P;

    for(int i=0;i<5;i++) arr[i]-=temp , printf("%d ",arr[i]);
    printf("\n");
    
    return 0;   
}