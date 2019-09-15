#include <iostream>
#include <deque>
using namespace std;

int tomato[100][100][100];

struct triple{
  int z;
  int y;
  int x;
  int day;
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int M,N,H,cnt=0,maxday=0,zcnt=0,micnt=0;

  cin >> M >> N >> H;

  deque<struct triple> dq;

  for(int i=0;i<H;i++){
    for(int j=0;j<N;j++){
      for(int k=0;k<M;k++){
        cin >> tomato[i][j][k];
        if(tomato[i][j][k]==1){
          struct triple input;
          input.z=i;
          input.y=j;
          input.x=k;
          input.day=0;
          dq.push_back(input);
        }
        else if(tomato[i][j][k]==0) zcnt++;
        else micnt++;
      }
    }
  }

  while(!dq.empty()){
    struct triple temp=dq.front();
    dq.pop_front();
    int tz=temp.z;
    int ty=temp.y;
    int tx=temp.x;
    int tday=temp.day;
    cnt++;
    if(tday>maxday) maxday=tday;

    struct triple insert;
    //upZ
    if(tz<H-1 && tomato[tz+1][ty][tx]==0){
      tomato[tz+1][ty][tx]=1;
      insert.z=tz+1;
      insert.y=ty;
      insert.x=tx;
      insert.day = tday+1;
      dq.push_back(insert);
    }

    //downZ
    if(tz>0 && tomato[tz-1][ty][tx]==0){
      tomato[tz-1][ty][tx]=1;
      insert.z=tz-1;
      insert.y=ty;
      insert.x=tx;
      insert.day = tday+1;
      dq.push_back(insert);
    }

    //upY
    if(ty<N-1 && tomato[tz][ty+1][tx]==0){
      tomato[tz][ty+1][tx]=1;
      insert.z=tz;
      insert.y=ty+1;
      insert.x=tx;
      insert.day = tday+1;
      dq.push_back(insert);
    }

    //downY
    if(ty>0 && tomato[tz][ty-1][tx]==0){
      tomato[tz][ty-1][tx]=1;
      insert.z=tz;
      insert.y=ty-1;
      insert.x=tx;
      insert.day = tday+1;
      dq.push_back(insert);
    }

    //upX
    if(tx<M-1 && tomato[tz][ty][tx+1]==0){
      tomato[tz][ty][tx+1]=1;
      insert.z=tz;
      insert.y=ty;
      insert.x=tx+1;
      insert.day = tday+1;
      dq.push_back(insert);
    }

    //downX
    if(tx>0 && tomato[tz][ty][tx-1]==0){
      tomato[tz][ty][tx-1]=1;
      insert.z=tz;
      insert.y=ty;
      insert.x=tx-1;
      insert.day = tday+1;
      dq.push_back(insert);
    }
  }

  if(zcnt == 0){
    cout << "0\n";
  }
  else if(cnt<M*N*H-micnt){
    cout << "-1\n";
  }
  else{
    cout << maxday << "\n";
  }


  return 0;
}
