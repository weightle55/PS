#include <cstdio>
using namespace std;

long long arr[101];

long long PN(int n){
  long long ret;
  if(n<6)
    return arr[n];

  for(int i=6;i<=n;i++){
    arr[i]=arr[i-1]+arr[i-5];
  }

  ret = arr[n];

  return ret;
}

int main(){
  int T;
  scanf("%d",&T);

  arr[1]=1;
  arr[2]=1;
  arr[3]=1;
  arr[4]=2;
  arr[5]=2;

  for(;T>0;T--){
    int pn;
    scanf("%d",&pn);
    printf("%lld\n",PN(pn));
  }
  return 0;
}
