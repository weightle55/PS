#include <iostream>
#include <string>
#include <vector>
using namespace std;

int arr[3];
vector<char> chvec;

int btking(int depth,int ret_size,char pre,char ppre,int numA,int numB,int numC){
  if(depth==ret_size){
    return 1;
  }

  int ret=-1;

  for(int i=0;i<3;i++){
    if(i==0){
      if(numA<arr[0]){
        chvec.push_back('A');
        ret=btking(depth+1, ret_size, 'A',pre,numA+1,numB,numC);
        if(ret==1) return 1;
        chvec.pop_back();
      }
    }
    else if(i==1){
      if(numB<arr[1] && pre!='B'){
        chvec.push_back('B');
        ret=btking(depth+1,ret_size,'B',pre,numA,numB+1,numC);
        if(ret==1) return 1;
        chvec.pop_back();
      }
    }
    else if(i==2){
      if(numC<arr[2] && pre!='C' && ppre!='C'){
        chvec.push_back('C');
        ret=btking(depth+1,ret_size,'C',pre,numA,numB,numC+1);
        if(ret==1) return 1;
        chvec.pop_back();
      }
    }
  }

  return -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string input;
  cin >> input;

  for(int i=0;i<input.size();i++){
    arr[(int)(input[i]-'A')]++;
  }

  

  int res=btking(0,input.size(),'D','D',0,0,0);

  if(res==-1){
    cout << "-1\n";
  }
  else{
    for(int i=0;i<chvec.size();i++){
      cout << chvec[i];
    }
    cout <<"\n";
  }

  return 0;
}
