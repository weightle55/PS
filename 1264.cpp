#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    while(true){
        string input;
        getline(cin,input);
        if(!input.compare("#")) break;
        int cnt=0;
        for(int i=0;i<input.size();i++){
            if(input[i]=='a'||input[i]=='e'||input[i]=='i'||input[i]=='o'||input[i]=='u'){
                cnt++;
            }
            else if(input[i]=='A'||input[i]=='E'||input[i]=='I'||input[i]=='O'||input[i]=='U')
            cnt++;
        }

        cout << cnt << "\n";
    }
    
    return 0;
}