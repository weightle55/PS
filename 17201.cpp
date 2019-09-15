#include <iostream>
#include <cstdio>

using namespace std;

pair<int,int> arr[6];

int main(){
    
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int t1,t2;
        scanf("%1d%1d",&t1,&t2);
        arr[i]=make_pair(t1,t2);
    }

    for(int i=1;i<N;i++){
        if(arr[i-1].second==arr[i].first){
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");
    return 0;
}