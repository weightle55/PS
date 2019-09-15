#include <iostream>
#include <cmath>
using namespace std;

bool numcheck[10];

bool checking(int num,int &sq10){
  int tmp=num;
  int mod=tmp%10;
  sq10=0;

  do{
    if(!numcheck[mod]) return false;
    tmp/=10;
    mod=tmp%10;
    sq10++;
  }while(tmp>0);
  //if(!numcheck[mod]) return false;

  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int input,M;

  cin >> input >> M;

  for(int i=0;i<10;i++)  numcheck[i]=true;
 
  for(int i=0;i<M;i++){
    int num;
    cin >> num;
    numcheck[num]=false;
  }
  
  int minhigh=1000001,maxlow=-200;
  int highcnt,lowcnt;
  int highdiff=10000001,lowdiff=10000001,hundiff;

  if(M<10){
    for(int i=input;i<1000001;i++){
      if(checking(i,highcnt)){
        minhigh=i;
        highdiff=minhigh-input+highcnt;
        break;
      }
    }

    for(int i=input;i>=0;i--){
      if(checking(i,lowcnt)){
        maxlow=i;
        lowdiff=input-maxlow+lowcnt;
        break;
      }
   }

  }
  
  hundiff=abs(input-100);

  int res=hundiff;

  res = res > highdiff ? highdiff:res;
  res = res > lowdiff ? lowdiff:res;

  //cout << hundiff<<" " <<minhigh<<" " << maxlow<<endl;
  cout << res<< "\n";
  
  return 0;
}