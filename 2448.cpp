#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

char paper[3072][6144];

void smallstar(int x,int y){
  for(int i=0;i<5;i++){
    paper[y][x+i]='*';
  }
  paper[y+1][x+1]='*';
  paper[y+1][x+3]='*';
  paper[y+2][x+2]='*';
}

void drawstar(int k,int x,int y){
  int temp=3*pow(2,k);
  if(k==1){
    smallstar(x,y);
    smallstar(x+6,y);
    smallstar(x+3,y+3);
  }
  else{
    drawstar(k-1,x,y);
    drawstar(k-1,temp+x,y);
    drawstar(k-1,temp/2+x,temp/2+y);
  }
}

int main(){
  int N,K,cnt=0;
  cin >> N;
  K=N;
  K /= 3;
  while(K!=1){
    K/=2;
    cnt++;
  }

  memset(paper,' ',sizeof(paper));
  if(cnt==0){
      smallstar(0,0);
  }
  else{
    drawstar(cnt,0,0);
  }
  for(int i=N-1;i>=0;i--){
    for(int j=0;j<2*N-1;j++) cout << paper[i][j];
    cout << "\n";
  }
  return 0;
}
