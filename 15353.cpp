#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> ac,vector<int> bc){
    vector<int> cc;

    char carry=0;

    while(ac.size()!=0 || bc.size()!=0){
        int ret=0;
        if(ac.size()==0){
            ret=bc.back()+carry;
            if(ret<10){
                carry=0;
            }
            else{
                carry=1;
                ret %=10;
            }
            bc.pop_back();
        }
        else if(bc.size()==0){
            ret=ac.back()+carry;
            if(ret<10){
                carry=0;
            }
            else{
                carry=1;
                ret %=10;
            }
            ac.pop_back();
        }
        else{
            ret = ac.back()+bc.back()+carry;
            if(ret<10){
                carry=0;
            }
            else{
                carry=1;
                ret %=10;
            }
            ac.pop_back();
            bc.pop_back();
        }
    
        cc.push_back(ret);
    }

    if(carry==1){
        cc.push_back(carry);
    }

    return cc;
}

vector<int> substract(vector<int> ac,vector<int> bc){
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a,b;

    vector<int> ac,bc,ret;

    for(int i=0;i<a.size();i++){
        ac.push_back(a[i]-'0');
    }

    for(int i=0;i<b.size();i++){
        bc.push_back(b[i]-'0');
    }
  
    cin >> a >> b;

    for(int i=ret.size()-1;i>=0;i--){
        cout << ret[i];
    }
    cout << "\n";

    return 0;
}