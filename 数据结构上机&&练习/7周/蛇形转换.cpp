#include<iostream>
using namespace std;

void Turn(int (*a)[10],int (*b)[10],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i%2==0)
			b[i][j]=a[j][i];
			else 
			b[i][j]=a[n-1-j][i];
		} 
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++){
			cout<<b[i][j]<<' ';
		}
		cout<<endl;	}
}

int main()
{
	int n;
	cin>>n;
	int a[10][10],b[10][10];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];	
		}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;	
	}
	cout<<endl<<endl; 
	Turn(a,b,n);
	return 0;
}
