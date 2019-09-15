#include <cstdio>

using namespace std;

int dividesum(int n){
  int ret=0;
  int temp=n;
  do{
    ret+= temp%10;
    temp /=10;
  }while(temp>0);
  //printf("%d\n",ret);
  return n+ret;
}

int main(){
  int N;
  scanf("%d",&N);

  for(int i=0;i<=N;i++){
    if(dividesum(i)==N){
      printf("%d\n",i);
      return 0;
    }
    if(i==N){
      printf("0\n");
      return 0;
    }
  }

  return 0;
}
