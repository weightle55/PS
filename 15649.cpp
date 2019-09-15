#include <cstdio>
#include <algorithm>
using namespace std;

int arr[9];

int factorial(int a){
  if(a==1) return a;
  else if(a==0) return 0;
  return a*factorial(a-1);
}

int main(){
  int N,M;
  scanf("%d%d",&N,&M);

  for(int i=0;i<=N;i++) arr[i]=i;

  do{
    for(int i=1;i<=M;i++){
      printf("%d ",arr[i]);
    }
    printf("\n");

    for(int i=1;i<factorial(N-M);i++) next_permutation(arr+1,arr+1+N);

  }while(next_permutation(arr+1,arr+1+N));

  return 0;
}
