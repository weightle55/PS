#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int group[1001];
int sfx[1001];
int tmpg[1001];

int sfxt;

bool sfxcmp(int a,int b){
    if(group[a]==group[b]) return group[a+sfxt]<group[b+sfxt];
    return group[a]<group[b];
}

void sfxarr(int n,string str){
    sfxt=1;
    for(int i=0;i<n;i++){
        sfx[i]=i;
        group[i]=str[i]-'a';
    }

    while(sfxt<n){
        group[n]=-1;

        sort(sfx,sfx+n,sfxcmp);

        tmpg[sfx[0]]=0;

        for(int i=0;i<n-1;i++){
            if(sfxcmp(sfx[i],sfx[i+1])) tmpg[sfx[i+1]]=tmpg[sfx[i]]+1;
            else tmpg[sfx[i+1]]=tmpg[sfx[i]];
        }

        for(int i=0;i<n;i++) group[i]=tmpg[i];
        sfxt *=2;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string input;
    cin >> input;

    sfxarr(input.size(),input);

    for(int i=0;i<input.size();i++){
        int start=sfx[i];
        for(int j=start;j<input.size();j++){
            cout << input[j];
        }
        cout << "\n";
    }

    return 0;
}