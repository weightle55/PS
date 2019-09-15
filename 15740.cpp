#include <cstdio>
#include <cstring>
using namespace std;

bool compAbsol(bool siA, bool siB,int Abeg, int Aend, int Bbeg, int Bend);

char A[10002];
char B[10002];

char big[10002];
char small[10002];

char res[10002];
int rescnt=0;

bool add(bool siA, bool siB,int Abeg, int Aend, int Bbeg, int Bend){
    bool retsign;

    memset(res,'0',sizeof(res));

    int bigb,bige,smallb,smalle;
    if(compAbsol(siA,siB,Abeg,Aend,Bbeg,Bend)){
        memcpy(big,A,sizeof(A));
        bigb=Abeg;
        bige=Aend;
        memcpy(small,B,sizeof(B));
        smallb=Bbeg;
        smalle=Bend;
        retsign=siA;
    }
    else{
        memcpy(big,B,sizeof(B));
        bigb=Bbeg;
        bige=Bend;
        memcpy(small,A,sizeof(A));
        smallb=Abeg;
        smalle=Aend;
        retsign=siB;
    }
    if(siA!=siB){
        rescnt=bige-bigb;
        int i=0;
        // printf("%d %d size: %d\n",bigb,bige,bige-bigb);
        // printf("%d %d size: %d\n",smallb, smalle,smalle-smallb);
            
        for(;i<smalle-smallb;i++){
            char tA=big[bige-1-i]-'0';
            char tB=small[smalle-1-i]-'0';
            char tr=tA-tB;
            if(tr<0){
                res[i]+=10+tr;
                int pre=1;
                while(big[bige-1-i-pre]-'0'==0){
                    big[bige-1-i-pre]='9';
                    pre++;
                }
                big[bige-1-i-pre]--;
            }
            else{
                res[i]+=tr;
            }
            //printf("%c",res[i]);
        }
        for(;i<bige-bigb;i++){
            res[i]+=big[bige-1-i]-'0';
            //printf("%c",res[i]);
        }

        for(int j=rescnt-1;j>=0;j--){
            if(res[j]=='0') rescnt--;
            else break;
        }
        //printf("\n");
    }else{
        int i=0;
        for(;i<smalle-smallb;i++){
            char tA=big[bige-1-i]-'0';
            char tB=small[smalle-1-i]-'0';
            char tr=tA+tB;
            if(tr>9){
                res[i]+=tr-10;
                res[i+1]++;
                if(i==bige-bigb-1) rescnt++;
            }
            else{
                res[i]+=tr;
                if(res[i]-'0'>9){
                    res[i+1]++;
                    res[i]-=10;
                    if(i==bige-bigb-1) rescnt++;
                }
            }
            rescnt++;
        }
        for(;i<bige-bigb;i++){
            res[i]+=big[bige-1-i]-'0';
            if(res[i]-'0'>9){
                res[i+1]++;
                res[i]-=10;
                if(i==bige-bigb-1) rescnt++;
            }
            rescnt++;
        }
    }

    return retsign;
}

bool compAbsol(bool siA, bool siB,int Abeg, int Aend, int Bbeg, int Bend){
    if(Aend-Abeg==Bend-Bbeg){
        for(int i=0;i<Aend-Abeg;i++){
            if(A[Abeg+i]!=B[Bbeg+i]) return A[Abeg+i]>=B[Bbeg+i];
        }
    }
    return Aend-Abeg >= Bend-Bbeg;
}

int main(){
    bool signA;
    bool signB;
    int abegin,aend;
    int bbegin,bend;

    scanf("%s",A);
    scanf("%s",B);

    if(A[0]=='-'){ 
        signA=true;
        abegin=1;
    }
    else{
        signA=false;
        abegin=0;       
    } 
    aend=strlen(A);

    if(B[0]=='-'){
        signB=true;
        bbegin=1;
    } 
    else{
        signB=false;
        bbegin=0;
    } 
    bend=strlen(B);

    bool issign=add(signA,signB,abegin,aend,bbegin,bend);

    if(rescnt==0){
        printf("0\n");
    }
    else if(issign){
        printf("-");
        for(int i=1;i<=rescnt;i++){
        printf("%c",res[rescnt-i]);
        }
        printf("\n");
            
    }
    else{
        for(int i=1;i<=rescnt;i++){
        printf("%c",res[rescnt-i]);
        }
        printf("\n");
        
    }
    
    return 0;
}