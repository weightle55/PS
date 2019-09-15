#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int rarr[101][101];
int carr[101][101];
int cntarr[101];

int row_size,col_size;

void RCop(){
    vector<pair<int,int> > opvec;
    //열증가 행연산
    if(row_size>=col_size){
        int new_col_size=0;
        for(int i=1;i<=row_size;i++){
            opvec.clear();
            memset(cntarr,0,sizeof(cntarr));
            for(int j=1;j<=col_size;j++){
                if(rarr[i][j]!=0){
                    cntarr[rarr[i][j]]++;
                }
            }
            for(int j=1;j<=100;j++){
                if(cntarr[j]>0) opvec.push_back(make_pair(cntarr[j],j));
            }
            sort(opvec.begin(),opvec.end());

            int newk=0;
            for(int k=0;k<opvec.size();k++){
                newk++;
                if(newk>100) break;
                rarr[i][newk]=opvec[k].second;
                
                newk++;
                if(newk>100) break;
                rarr[i][newk]=opvec[k].first;          
            }

            for(int k=newk+1;k<101;k++){
                rarr[i][k]=0;
            }
            new_col_size=new_col_size < newk ? newk : new_col_size;
        }

        col_size=new_col_size;

        for(int i=1;i<=row_size;i++){
            for(int j=1;j<=col_size;j++){
                carr[j][i]=rarr[i][j];
            }
        }
    }
    //행증가 열연산
    else{
        int new_row_size=0;
        for(int i=1;i<=col_size;i++){
            opvec.clear();
            memset(cntarr,0,sizeof(cntarr));
            for(int j=1;j<=row_size;j++){
                if(carr[i][j]!=0){
                    cntarr[carr[i][j]]++;
                }
            }
            for(int j=1;j<=100;j++){
                if(cntarr[j]>0) opvec.push_back(make_pair(cntarr[j],j));
            }
            sort(opvec.begin(),opvec.end());

            int newk=0;
            for(int k=0;k<opvec.size();k++){
                newk++;
                if(newk>100) break;
                carr[i][newk]=opvec[k].second;
                
                newk++;
                if(newk>100) break;
                carr[i][newk]=opvec[k].first;          
            }

            for(int k=newk+1;k<101;k++){
                carr[i][k]=0;
            }
            new_row_size=new_row_size < newk ? newk : new_row_size;
        }

        row_size=new_row_size;

        for(int i=1;i<=col_size;i++){
            for(int j=1;j<=row_size;j++){
                rarr[j][i]=carr[i][j];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    row_size=3;
    col_size=3;

    int r,c,k;
    cin >> r >> c >> k;

    for(int i=1;i<4;i++){
        for(int j=1;j<4;j++){
            cin >> rarr[i][j];
            carr[j][i]=rarr[i][j];
        }
    }

    int timer=0;
    while(true){
        if(rarr[r][c]==k){
            cout << timer <<"\n";
            break;
        }

        if(timer>100){
            cout << "-1\n";
            break;
        }
        RCop();
        timer++;
    }

    // cout << endl;
    // for(int i=1;i<=row_size;i++){
    //     for(int j=1;j<=col_size;j++){
    //         cout << rarr[i][j] << " ";
    //     }
    //     cout <<endl;
    // }

    return 0;
}