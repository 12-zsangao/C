#include <iostream>
#include <math.h>
using namespace std;

typedef struct {
    int e[3];  // 固定大小的数组
} zu;
typrdef struct{
	zu T[n];
	int r;
	int c;
	int n;
} sss;

void output(int a[][];int r;int c;int n){
	for(int i=0;i<r;i++){
		if(i%r==0) printf("\n");
		for(int j=0;i<c;j++){
			for(int k=0;k<n;k++)
			if(i==sss.T[k].e[0]&&j==sss.T[k].e[1]) printf("%d ",sss.T[i].e[2]);
			else printf("0 ")
		}
	}
}
int main(){
	cin>>sss.r>>sss.c>>sss.n;
	return 0;
	for(int i=0;i<=nums;i++){
		cin>>sss.T[i].e[0]>>sss.T[i].e[1]>>sss.T[i].e[2];
	}
	int a[rows][columns];
	output(a;sss.r;sss.c;sss.n)
}

