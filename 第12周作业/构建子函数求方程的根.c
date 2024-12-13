#include<stdio.h>
#include<math.h>
int main()
{	
	void A(float a,float b,float c);
	void B(float a,float b,float c);
	void C(float a,float b,float c);
	float a,b,c;
	scanf("%f,%f,%f",&a,&b,&c);
	if(b*b-a*c*4>0)
	A(a,b,c);
	if(b*b-a*c*4==0)
	B(a,b,c);
	if(b*b-a*c*4<0)
	C(a,b,c);
	return 0;
}

void A(float a,float b,float c)
{
	float x1,x2,delt=b*b-a*c*4;
	x1=(-b-sqrt(delt))/(2*a);
	x2=(-b+sqrt(delt))/(2*a);
	printf("%.3f\n%.3f\n",x1,x2);
}
void B(float a,float b,float c)
{
	float x,delt=b*b-a*c*4;
	x=-b/(2*a);
	printf("%.3f\n",x);
}
void C(float a,float b,float c)
{
	float delt=b*b-a*c*4;
	float real,image;
	//printf("have complex roots:\n")
	real=-b/(2*a);
	image=sqrt(-delt)/(2*a);
	printf("%.3f-%.3fi\n",real,image);
	printf("%.3f+%.3fi\n",real,image);
}
