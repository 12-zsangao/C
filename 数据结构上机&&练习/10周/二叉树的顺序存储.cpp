#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct{
	char str;
	int num[2];
}Node;
Node k[100];
int search(char a,int n){
	int j=1;
	for(int i=1;i<n;i++){
		if(k[i].str==a){
		j++;
		break;}
	}
	printf("%c",a/2);
	cout<<endl;
	if(k[j].num[0]==0) cout<<"no lchild";
	else printf("%c",2*a);
	cout<<endl;
	if(k[j].num[0]==0) cout<<"no lchild";
	else printf("%c",2*a+1);
	cout<<endl;
}
void des(char a,int n){
	int i=1;
	for(int j=1;j<n;j++){
		if(k[j].str==a){
		i++;
		break;}
	}
	if(k[i].num[0]!=0)
	des(k[k[i].num[0]].str,n);
	if(k[i].num[1]!=0)
	des(k[k[i].num[1]].str,n);
	free(&k[i].str);
}
void output(){
	for(int i=1;k[i].num[0]!=0&&k[i].num[1]!=0;i++){
		printf("%c %d %d",k[i].str,k[i].num[0],k[i].num[1]);
		cout<<endl;
	}
}
int main(){
	int j=1;
	for(int i=1;i<100;i++){
		scanf("%c",&k[i].str);
		if(k[i].str=='#') break;
		scanf("%c %c",&k[i].num[0],&k[i].num[1]);
		j++;
	}
	int count=j;
	char z1,z2;
	scanf("%c %c",&z1,&z2);
	search(z1,count);
	des(z2,count);
	output();
	return 0;
} 
