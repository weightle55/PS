#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int max=0;

int find_value(int y,int x){
  bool x_max=true;
  int dist=0, pre=0, dist_even,result=0;

  if(x==0 && y==0) return 1;

  if(abs(x)>abs(y)) x_max=true;
  else x_max=false;

  if(x_max){
    dist=abs(x);
    pre = (2*(dist-1)+1) * (2*(dist-1)+1);
    dist_even = 2 * dist;
    if(x>0){
      result = pre + dist - y;
    }else{
      result = pre + dist_even*2 + dist+y;
    }
  }
  else{
    dist=abs(y);
    pre = (2*(dist-1)+1) * (2*(dist-1)+1);
    dist_even = 2 * dist;
    if(y>0){
      result = pre + dist_even*3 + dist + x;
    }else{
      result = pre + dist_even + dist - x;
    }
  }

  max = result > max ? result : max;

  return result;
}

int blanknum(int a){
  int temp = 1;
  while(a>=10){
    a /= 10 ;
    temp++;
  }

  return temp;
}

int main(){
  int r1,c1,r2,c2;
  int row,col,temp;
  scanf("%d%d%d%d",&r1,&c1,&r2,&c2);

  row = r2-r1+1;
  col = c2-c1+1;

  int arr[row][col];
  memset(arr,0,sizeof(arr));

  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      temp = find_value(r1+i,c1+j);
      arr[i][j] = temp;
      //printf("%2d ",temp);
    }
    //printf("\n");
  }

  int maxblank = blanknum(max);

  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      int tb = blanknum(arr[i][j]);
      for(int k=0;k<maxblank-tb;k++) printf(" ");
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
