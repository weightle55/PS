#include <cstdio>

using namespace std;

int main(){
  int N;
  scanf("%d",&N);

  for(int i=1;i<=2*N-1;i++){
    int t;
    t = i > N ? 2*N-i : i;
    for(int j=0;j<(N-t);j++) printf(" ");
    for(int j=0;j<t;j++) printf("*");

    printf("\n");
  }
  return 0;
}
