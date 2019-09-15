#include <cstdio>
#include <cmath>
using namespace std;

int arr[10001];

int main(){
  int M,N;
  int start,end;
  long long sum=0;
  scanf("%d%d",&M,&N);

  for(int i=0;i<10001;i++){
    arr[i]=i*i;
  }

  start = ceil(sqrt(M));
  end = floor(sqrt(N));

  for(int i=start; i<=end; i++){
    sum += arr[i];
  }

  if(end<start)  printf("-1\n");
  else  printf("%lld\n%d\n",sum,arr[start]);

  return 0;
}
