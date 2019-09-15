#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string input;
    cin >> input;
    int cnt=0;

    for(int i=0;i<input.size();i++){
        if(input[i]=='a' || input[i]=='e' || input[i]=='i' || input[i]=='o' || input[i]=='u') cnt++;
    }

    cout << cnt<<"\n";
    return 0;
}