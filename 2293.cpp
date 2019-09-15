#include <cstdio>
#include <algorithm>
using namespace std;

int coin[10000];

int main(){
  int n,k;
  int result=0;
  scanf("%d%d",&n,&k);

  for(int i=0;i<n;i++){
    scanf("%d",coin+i);
  }
  sort(coin,coin+n);

  return 0;
}
