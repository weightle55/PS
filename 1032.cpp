#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string str[50];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N;

    for(int i=0;i<N;i++){
        cin >> str[i];
    }

    //cout << "input\n";
    string result=str[0];
    for(int i=0;i<N-1;i++){
        stringstream sts;

        for(int j=0;j<result.size();j++){
            if(result[j]=='?'){
                sts << '?';
            }
            else if(result[j]==str[i+1][j]){
                sts << result[j];
            }
            else{
                sts << '?';
            }
        }

        result = sts.str();
    }

    cout << result << "\n";

    return 0;
}