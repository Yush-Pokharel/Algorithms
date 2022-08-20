#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<math.h>


void print(int i,float Xl,float Xu,float Xm,float f_xl,float f_xu,float f_xm) {
	printf("%10i | %+08.4f | %+08.4f | %+08.4f | %+08.4f | %+08.4f | %+08.4f | %8s \n",i,Xl,Xu,Xm,f_xl,f_xu,f_xm,"remark");
}

float equation(float x) {
	return (pow(x,3) + 3*x -5);
}
inline float mid_point(float a, float b) {
	return ((a+b)/2);
}

void head() {
	printf("For the equation x^3 +3x -5 \n\n\n");
	printf("%10s | %8s | %8s | %8s | %8s | %8s | %8s | %8s \n\n","Iteration", "Xl","Xu","Xm","F(Xl)","F(Xu)","F(Xm)","Remarks");
}

float bisection(float xl,float xu,int it) {
	float xm,f_xl,f_xu,f_xm,temp;
	char remark[30];
	int i =1;
	do {
		xm = (xu+xl)/02.000;
		temp = xm;
		printf("%f\n",temp);
		f_xl=  equation(xl);
		f_xu = equation(xu);
		f_xm = equation(xm);
		if(f_xm > 0) {
			xm = xu;
		} else {
			xm=xl;
		}
		print(i,xl,xu,xm,f_xl,f_xu,f_xm);
		i++;
		it--;
		if(it == 0){
			printf("bisection couldn't solve for this'");
			return 0;
		}
	}
	while(((temp - xm)> 0.0001));
}

int main() {
	float a,b;
	int iteration = 40;
	printf("enter for Xl and Xu: \n");
	scanf("%f%f",&a,&b);
	while( equation(a)*equation(b) > 0) {
		system("cls");
		printf("the values must differ in magnitude and direction \nenter Xl and Xu again:\n");
		scanf("%f%f",&a,&b);
	}
	system("cls");
	head();
	if(equation(a) > equation(b ) ){
		float temp;
		temp =a;
		a=b;
		b=temp;
	}
	bisection(a,b,iteration);
}
