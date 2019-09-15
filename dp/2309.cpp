#include <cstdio>
#include <algorithm>
using namespace std;

int main(){

  int arr[9];
  int one,two;
  int answer[7];
  int sum=0;

  for(int i=0;i<9;i++){
    scanf("%d",arr+i);
    sum+=arr[i];
  }

  int twosum=0;
  for(int i=0;i<8;i++){
    for(int j=i+1;j<9;j++){
      twosum=arr[i]+arr[j];
      if(sum-twosum==100){
        one=i;two=j;
      }
    }
  }

  int j=0;
  for(int i=0;i<9;i++){
    if(i != one && i != two){
      answer[j]=arr[i];
      j++;
    }
  }

  sort(answer,answer+7);

  for(int i=0;i<7;i++) printf("%d\n",answer[i]);
  return 0;
}
