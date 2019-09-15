#include <iostream>
#include <string>
#include <vector>
using namespace std;

int arr[3];
char res[51];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string input;
  cin >> input;

  for(int i=0;i<input.size();i++){
    arr[(int)(input[i]-'A')]++;
  }

  char pre='D';
  char ppre='D';

  int num[3]={0,};

  for(int i=0;i<input.size();i++){

      if(arr[2]>num[2] && ppre!='C' && pre!='C'){
          res[i]='C';
          ppre=pre;
          pre='C';
          num[2]++;
      }
      else if(arr[1]>num[1] && pre!='B'){
          res[i]='B';
          ppre=pre;
          pre='B';
          num[1]++;
      }
      else if(arr[0]>num[0]){
          res[i]='A';
          ppre=pre;
          pre='A';
          num[0]++;
      }
      else{
          cout << "-1\n";
          return 0;
      }
  }

  for(int i=0;i<input.size();i++){
      cout<< res[i];
  }
  cout << "\n";


  return 0;

}