#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int arr[501];

int merging(int start,int end,int pre){
  if(start==end) return arr[start];

  int mini=INT_MAX;
  if(end-start==2){
    return min(2*(arr[start]+arr[start+1])+arr[end], arr[start]+2*(arr[start+1]+arr[end]) );
  }
  
  
  for(int i=start;i<end;i++){
    int tmp = merging(start,i,pre)+merging(i+1,end,pre);
    mini = mini > tmp ? tmp : mini;
  }

  return mini;
}

int main(){
  int T;
  scanf("%d",&T);

  for(;T>0;T--){
    memset(arr,0,sizeof(arr));
   
    int K;
    scanf("%d",&K);

    for(int i=1;i<=K;i++) scanf("%d",&arr[i]);

    printf("%d\n",merging(1,K));
  }

  return 0;
}
