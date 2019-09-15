#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
	int input[3];
	int A,B,C;
	char str[4];
			
	for(int i=0;i<3;i++){ 
		scanf("%d",&input[i]);
	}
	
	scanf("%s",str);
	
	sort(input,input+3);
	
	if(!strcmp("ABC",str)){
		printf("%d %d %d\n",input[0],input[1],input[2]);
	}
	else if(!strcmp("ACB",str)){
		printf("%d %d %d\n",input[0],input[2],input[1]);
	}
	else if(!strcmp("BAC",str)){
		printf("%d %d %d\n",input[1],input[0],input[2]);
	}
	else if(!strcmp("BCA",str)){
		printf("%d %d %d\n",input[1],input[2],input[0]);
	}
	else if(!strcmp("CAB",str)){
		printf("%d %d %d\n",input[2],input[0],input[1]);
	}
	else if(!strcmp("CBA",str)){
		printf("%d %d %d\n",input[2],input[1],input[0]);
	}
	
	return 0;
}