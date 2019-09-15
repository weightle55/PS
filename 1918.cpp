#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

char sik[101];

vector<char> op;

int main(){
    int N;
    scanf("%s",sik);
    N=strlen(sik);

    for(int i=0;i<N;i++){
        if(sik[i]>='A' && sik[i] <='Z'){
            printf("%c",sik[i]);
        }
        else if(sik[i]=='+' || sik[i]=='-'){
            while(!op.empty()&&op.back()!='('){
                printf("%c",op.back());
                op.pop_back();
            }
            op.push_back(sik[i]);
        }
        else if(sik[i]=='*'|| sik[i]=='/'){
            while(!op.empty()&&(op.back()=='*' || op.back()=='/')){
                printf("%c",op.back());
                op.pop_back();
            }
            op.push_back(sik[i]);
        }
        else if(sik[i]=='('){
            op.push_back(sik[i]);
        }
        else if(sik[i]==')'){
           while(op.back()!='('){
               printf("%c",op.back());
               op.pop_back();
           }
           op.pop_back();
        }
    }

    while(!op.empty()){
        printf("%c",op.back());
        op.pop_back();
    }

    printf("\n");

    return 0;
}