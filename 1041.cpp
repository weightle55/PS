#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int dice[6];
    int tarr[6];
    int ttarr[6];
    cin >> N;

    int twomin=0x3f3f3f3f,threemin=0x3f3f3f3f,onemin=0x3f3f3f3f;
    int onemax=0;
    int sum=0;

    for(int i=0;i<6;i++){
        cin >> dice[i];
        onemin = onemin > dice[i] ? dice[i]: onemin;
        onemax = onemax < dice[i] ? dice[i]: onemax;
        sum+=dice[i];
    }

    if(N==1){
        cout << sum-onemax<<"\n";
        return 0;
    }

    tarr[4]=1;
    tarr[5]=1;

    ttarr[3]=1;
    ttarr[4]=1;
    ttarr[5]=1;

    do{
        int fir=-1,sec=-1;
        
        for(int i=0;i<6;i++){
            if(tarr[i]==1 && fir==-1){
                fir=i;
            }
            else if(tarr[i]==1){
                sec=i;
            }
        }

        if(fir+sec==5) continue;

        int tmp = dice[fir]+dice[sec];

        twomin = tmp < twomin ? tmp : twomin;

    }while(next_permutation(tarr,tarr+6));

    do{
        int fir=-1,sec=-1,third=-1;
        for(int i=0;i<6;i++){
            if(tarr[i]==1 && fir==-1){
                fir = i;
            }
            else if(tarr[i]==1 && fir!=-1 && sec==-1){
                sec = i;
            }
            else if(tarr[i]==1 && sec!=-1){
                third = i;
            }
        }

    }while(next_permutation(ttarr,ttarr+6));

    return 0;
}