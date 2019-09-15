#include <iostream>

using namespace std;

char bulpan[12][12];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int T,H,W;
  cin >> T;
  for(;T>0;T--){
    cin >> H >> W;
    for(int i=1;i<=H;i++){
      for(int j=1;j<=W;j++) cin >> bulpan[i][j];
    }

    for(int i=1;i<=H;i++){
      for(int j=W;j>0;j--) cout << bulpan[i][j];
      cout << "\n";
    }
  }

  return 0;
}
