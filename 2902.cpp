#include <iostream>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string input;

  cin >> input;

  for(int i=0;i<input.size();i++){
    if(input[i]>='A' && input[i] <='Z') cout << input[i];
  }
  cout <<"\n";

  return 0;
}
