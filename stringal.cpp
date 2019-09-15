#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string A,B;
    cin >> A >> B;

    string minA,minB,maxA,maxB;
    int mA,mB,maA,maB;

    minA=A, minB=B, maxA=A, maxB=B;

    for(int i=0;i<minA.size();i++){
        if(minA[i]=='6') minA[i]='5';
    }
    for(int i=0;i<minB.size();i++){
        if(minB[i]=='6') minB[i]='5';
    }

    for(int i=0;i<maxA.size();i++){
        if(maxA[i]=='5') maxA[i]='6';
    }
    
    for(int i=0;i<maxB.size();i++){
        if(maxB[i]=='5') maxB[i]='6';
    }

    mA=atoi(minA.c_str());
    mB=atoi(minB.c_str());

    maA=atoi(maxA.c_str());
    maB=atoi(maxB.c_str());

    int min=mA+mB;
    int max=maA+maB;

    cout << min << " " << max << "\n";
    
    return 0;
}