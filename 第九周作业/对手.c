#include<stdio.h>
int main() 
{
	char i,j,k;	//a-z b-x c-y
	for(i='x';i<='z';i++)
		for(j='x';j<='z';j++)
		{
			if(i!=j)
			for(k='x';k<='z';k++)
			{
				if(i!=k&&j!=k)
				{
					if(i!='x'&&k!='x'&&k!='z')
					printf("a-%c b-%c c-%c",i,j,k) ;
				}
			}			
		}
		return 0;
}
