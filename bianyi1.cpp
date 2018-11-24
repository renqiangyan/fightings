#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void yuchuli()
{FILE *p,*q;
int num=0,i;
char ch,a[10000];
if((p=fopen("shiyan.txt","r"))==NULL){
	printf("无法打开此文件\n");
	exit(0);
}
a[0]=fgetc(p);
while((ch=fgetc(p))!=EOF){
	num++;
	a[num]=ch;
}
fclose(p);
if((q=fopen("yufile.txt","w"))==NULL){
	printf("无法打开此文件\n");
	exit(0);
}
for(i=0;i<=num;i++)
{
	if(a[i]=='\n'){
		fprintf(q," ");
		continue;
	}
	if(a[i]==' '){
		fputc(a[i],q);
		i++;
		while(a[i]==' '){
			i++;
		}
	}
	if(a[i]=='/'){
		i++;
		if(a[i]=='/'){
			i++;
			while(a[i]!='\n'){
				i++;
			}
		}
		else if(a[i]=='*'){
			i++;
			while(a[i]!='*'){
				i++;
			}
			i++;
		}
		continue;
	}
	fputc(a[i],q);
}
}


bool isletter(char k){
	if(k>='a'&&k<='z'||k>='A'&&k<='Z')
	return true;
	else 
	return false;
}

bool isdight(char k){
	if(k>='0'&&k<='9')
	return true;
	else 
	return false;
}

int panduan(char u[20]){
			 if(strcmp(u,"main")==0) return 1;
			else if(strcmp(u,"if")==0) return 2;
			 else if(strcmp(u,"then")==0) return 3;
			 else if(strcmp(u,"while")==0) return 4;
			else if(strcmp(u,"do")==0) return 5;
			else if(strcmp(u,"static")==0) return 6;
		else	 if(strcmp(u,"int")==0) return 7;
			else if(strcmp(u,"double")==0) return 8;
			else if(strcmp(u,"struct")==0) return 9;
			else if(strcmp(u,"break")==0) return 10;
			else if(strcmp(u,"else")==0) return 11;
			else if(strcmp(u,"long")==0) return 12;
			else if(strcmp(u,"switch")==0) return 13;
			else if(strcmp(u,"case")==0) return 14;
			else if(strcmp(u,"typedef")==0) return 15;
			else if(strcmp(u,"char")==0) return 16;
			else if(strcmp(u,"return")==0) return 17;
			else if(strcmp(u,"const")==0) return 18;
			else if(strcmp(u,"float")==0) return 19;
			else if(strcmp(u,"short")==0) return 20;
			else if(strcmp(u,"continue")==0) return 21;
			else if(strcmp(u,"for")==0) return 22;
			else if(strcmp(u,"void")==0) return 23;
			else if(strcmp(u,"sizeof")==0) return 24;
			else if(strcmp(u,"default")==0) return 39;
			else return 25;	
}




void function()
{
int syn,num,flag=1;
char ch,b[10000],token[20];
FILE *z,*y;
if((z=fopen("yufile.txt","r"))==NULL){
printf("不能打开预处理文件\n");
exit(0);	
} 

ch=fgetc(z);
b[0]=ch;
while((ch=fgetc(z))!=EOF){
	num++;
	b[num]=ch;
}
num++;
b[num]='$';
num=0;
while(b[num]!='$'){
	int c=0;
	while(b[num]==' '){
		num++;
	}
	if(isletter(b[num])){
		token[c]=b[num];
		num++;
		c++;
		while(isletter(b[num])||isdight(b[num])){
			token[c]=b[num];
			c++;
			num++;
		}
		
		
		token[c]='\0';
		num--;
		syn=panduan(token);
		if(syn==25){
		printf("%s 25\n",token);	
		}
		else
		printf("%s %d\n",token,syn);
	}
	else if(isdight(b[num])){
	token[c]=b[num];
	c++;
	num++;
	while(isletter(b[num])||isdight(b[num])){
		token[c]=b[num];
		c++;
		num++;
	}	
	token[num]='\0';
	printf("%s",token);
	num--;
	for(int i=1;i<c;i++){
		if(isletter(token[i])){
			printf("非法标识符:%s\n",token);
			flag=0;
			break;
		}
	}
	if(flag){
		printf("%s 26\n",token);
	}
	} 
	else if(b[num]=='+')
	printf("+ 27\n");
	else if(b[num]=='-')
	printf("- 28\n");
	else if(b[num]=='*')
	printf("* 29\n");
	else if(b[num]=='/')
	printf("/ 30\n");
	else if(b[num]==':'){
		num++;
		if(b[num]=='='){
			printf(":= 31\n");
		} else{printf(": 30\n");
		num--;
		}
	}else if(b[num]=='<'){
		num++;
		if(b[num]=='>'){
			printf("<> 34\n");
		}else if(b[num]=='='){
			printf("<= 35\n");
		}else {
			printf("< 33\n");
			num--;
		}
	}else if(b[num]=='>'){
		num++;
		if(b[num]=='=')
		printf(">= 37\n");
		else {printf("> 36\n");
		num--;
		}
	}else if(b[num]=='=')
	printf("= 38\n");
	else if(b[num]==';')
	printf("; 41\n");
	else if(b[num]=='(')
	printf("( 42\n");
	else if(b[num]==')')
	printf(") 43\n");
	else if(b[num]=='#')
	printf("# 0\n");
	else printf("%c error\n",b[num]);
	num++;
}
}
int main()
{
yuchuli();
function();
return 0;
}

