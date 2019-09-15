#include <cstdio>

using namespace std;

int arr[1000000];

int main(){
  int N;

  int max=-0x3f3f3f3f;
  int min=0x3f3f3f3f;

  scanf("%d",&N);

  for(int i=0;i<N;i++) {
    scanf("%d",arr+i);
    max = arr[i]>max ? arr[i] :max;
    min = arr[i]<min ? arr[i] :min;
  }

  printf("%d %d\n",min,max);

  return 0;
}
