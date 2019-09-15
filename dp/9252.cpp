#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[1001][1001];
int pre[1001][1001];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string a,b;

  cin >> a >>b;

  for(int i=0;i<=b.size();i++){
    for(int j=0;j<=a.size();j++){
      if(i==0 || j==0){
        dp[i][j]=0;
      } 
      else if(a[j-1]==b[i-1]){
        dp[i][j]=dp[i-1][j-1]+1;
        pre[i][j]=1;
      } 
      else{
        if(dp[i][j-1]>dp[i-1][j]){
          dp[i][j]=dp[i][j-1];
          pre[i][j]=2;
        }else{
          dp[i][j]=dp[i-1][j];
          pre[i][j]=3;
        }
      } 
    }
  }

  // for(int i=0;i<=b.size();i++){
  //   for(int j=0;j<=a.size();j++) cout << dp[i][j]<<" ";
  //   cout << endl;
  // }
  // for(int i=0;i<=b.size();i++){
  //   for(int j=0;j<=a.size();j++) cout << pre[i][j]<<" ";
  //   cout << endl;
  // }

  vector<char> stk;

  int ta=a.size();
  int tb=b.size();

  bool br=true;

  while(ta>=0 && tb>=0 && br){
    switch(pre[tb][ta]){
      case 1: stk.push_back(a[ta-1]); ta--; tb--;break;
      case 2: ta--; break;
      case 3: tb--; break;
      default : br=false; break;
    }
  }

  cout << dp[b.size()][a.size()] << "\n";
  while(!stk.empty()){
    cout << stk.back();
    stk.pop_back();
  }
  cout << "\n";

  return 0;
}
