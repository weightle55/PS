#include <cstdio>

using namespace std;

int main(){
  int N;
  int sum=0;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int in;
    scanf("%1d",&in);
    sum+=in;
  }
  printf("%d\n",sum);
  return 0;
}
