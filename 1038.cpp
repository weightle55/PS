#include <cstdio>
#include <cstring>
#include <algorithm>

#define ll long long

using namespace std;

ll arr[2000];
ll num[10];
int flag[10];

int main(){
  int N;

  scanf("%d",&N);



  for(int i=0;i<10;i++){
    num[i]=i;
  }

  int index=0;
  for(int i=1;i<=10;i++){
    memset(flag,0,sizeof(flag));
    for(int j=9;j>=10-i;j--) flag[j]=1;

    // for(int j=0;j<10;j++) printf("%d ",flag[j]);
    // printf("\n");

    do{
      ll temp=0;
      int mult=1;
      for(int k=0;k<10;k++){
        if(flag[k]==1){
          temp += num[k]*mult;
          mult*=10;
        }       
      }
      arr[index]=temp;
      index++;    
    }while(next_permutation(flag,flag+10));
  }

  sort(arr,arr+index);

  if(N>=index) printf("-1\n");
  else printf("%lld\n",arr[N]);

  return 0;
}