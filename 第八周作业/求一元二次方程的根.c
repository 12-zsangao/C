#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,delt,x1,x2,real,image,x;
	scanf("%lf,%lf,%lf",&a,&b,&c);
	delt=b*b-4*a*c;
	if(a==0) 
	{
		if(b!=0) x1=-c/b,x2=x1;
		else if(c=0) printf("x无定根");
				else printf("x无解");
	}
	else 
		 {
		 	if(delt>0) 
			{ 
			 x1=(-b-sqrt(delt))/(2*a);
		  	 x2=(-b+sqrt(delt))/(2*a);
		  	 printf("%.3f\n",x1);
		  	 printf("%.3f\n",x2);
			}
		  	else 
			  {
			  if(delt=0)
		  		{x=-b/(2*a);
				printf("%.3f\n",x);}
		  		if(delt<0) 
		  		 {real=-b/(2*a);
				  image=sqrt(-delt)/(2*a);
				  printf("%.3f-%.3fi\n",real,image);
			      printf("%.3f+%.3fi\n",real,image);}
			  }
		 }
	return 0;
} 
