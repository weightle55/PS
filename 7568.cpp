#include <cstdio>

using namespace std;

int weight[50];
int height[50];
int ret[50];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d%d",weight+i,height+i);
  }

  for(int i=0;i<N;i++){
    int level=1;
    for(int j=0;j<N;j++){
      if(weight[i]<weight[j] && height[i]<height[j]) level++;
    }
    ret[i]=level;
  }

  for(int i=0;i<N;i++) printf("%d\n",ret[i]);

  return 0;
}
