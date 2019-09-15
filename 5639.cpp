#include <cstdio>

using namespace std;

int arr[10000];

void tree(int start,int end){
    int root=arr[start];

    if(end<=start) return;

    int div=start+1;
    for(int i=start+1;i<end;i++){
        if(arr[i]>root){
            div=i;
            break;
        }    
    }
    tree(start+1,div);
    tree(div,end);
    printf("%d\n",root);
}

int main(){

    int cnt=0;

    while(scanf("%d",&arr[cnt]) !=EOF){
        cnt++;
    }

    tree(0,cnt);

    return 0;
}