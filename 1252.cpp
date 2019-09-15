#include <cstdio>
#include <cstring>

using namespace std;

char bi1[82];
char bi2[82];
char res[82];

void swap(char &bit1,char &bit2){
    char temp;
    temp = bit1;
    bit1= bit2;
    bit2=temp;
}

void reverse(char* bi,int size){
    for(int i=0;i<size/2;i++){
        swap(bi[i],bi[size-1-i]);
    }
}

bool isbothzero(char* a,int asize,char* b,int bsize){
    bool isazero=true;
    bool isbzero=true;

    for(int i=0;i<asize;i++){
        if(a[i]!='0'){
            isazero=false;
            break;
        }
    }

    for(int j=0;j<bsize;j++){
        if(b[j]!='0'){
            isbzero=false;
            break;
        }
    }

    return isazero && isbzero;
}

int main(){
    scanf("%s",bi1);
    scanf("%s",bi2);

    int bi1size=strlen(bi1);
    int bi2size=strlen(bi2);

    if(isbothzero(bi1,bi1size,bi2,bi2size)){
        printf("0\n");
        return 0;
    } 

    reverse(bi1,bi1size);
    reverse(bi2,bi2size);

    //for(int i=0;i<bi1size;i++) printf("%c",bi1[i]);

    int i=0;
    bool iscarry=false;
    bool big1=false;
    int addsize=bi1size > bi2size ? bi2size:bi1size;
    int bigsize=0;

    if(bi1size>bi2size){
        bigsize=bi1size;
        big1=true;
    }
    else{
        bigsize=bi2size;
    }

    for(;i<addsize;i++){
        if(bi1[i]=='1' && bi2[i]=='1'){
            if(iscarry){
                res[i]='1';
                iscarry=true;
            }
            else{
                res[i]='0';
                iscarry=true;
            }
        }
        else if((bi1[i]=='0' && bi2[i]=='1') || (bi1[i]=='1' && bi2[i]=='0') ){
            if(iscarry){
                res[i]='0';
                iscarry=true;
            }
            else{
                res[i]='1';
                iscarry=false;
            }
        }
        else if(bi1[i]=='0' && bi2[i]=='0'){
            if(iscarry){
                res[i]='1';
                iscarry=false;
            }
            else{
                res[i]='0';
                iscarry=false;
            }
        }
    }

    for(;i<bigsize;i++){
        if(big1){
            if(iscarry){
                if(bi1[i]=='1'){
                    res[i]='0';
                    iscarry=true;
                }
                else{
                    res[i]='1';
                    iscarry=false;
                }
            }
            else{
                res[i]=bi1[i];
            }
        }
        else{
            if(iscarry){
                if(bi2[i]=='1'){
                    res[i]='0';
                    iscarry=true;
                }
                else{
                    res[i]='1';
                    iscarry=false;
                }
            }
            else{
                res[i]=bi2[i];
            }
        }
    }

    if(iscarry){
        res[i]='1';
        i++;
    }

    reverse(res,i);

    bool isstartzero=true;
    for(int j=0;j<i;j++){
        if(res[j]=='1') isstartzero=false;

        if(isstartzero) continue;
        printf("%c",res[j]);
    } 
    printf("\n");

    return 0;
}