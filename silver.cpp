#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string input;
    cin >> input;

    vector<char> stk;
    int pipes=0;
    char last='0';

    for(int i=0;i<input.size();i++){
        if(last=='('){
            if(input.[i]=='('){

            }
            else{

            }
        }else if(last==')'){

        }else{
            last=input[i];
        }
    }

    return 0;
}