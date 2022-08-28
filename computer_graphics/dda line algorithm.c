#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void main() {
	clrscr();
	float x1,x2,y1,y2;
	int gd=DETECT,gm=DETECT;
	initgraph(&gd,&gm,"C://turboc3//bgi");
	printf("Enter end points of line(x1,y1,x2,y2)");
	scanf("%f%f%f%f",&x1,&y1,&x2,&y2);

	float dx,dy,x=x1,y=y1,m;
	int i;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>=abs(dy))
		m=abs(dx);
	else

		5

		m=abs(dy);
	printf("(%d,%d)",int(x),int(y));
	putpixel((int)x,(int)y,15);

	for(i=1; i<=m; i++) {
		x=x+dx/m;
		y=y+dy/m;
		putpixel((int)x,(int)y,15);
		printf("(%d,%d)",int(x),int(y));
	}
	getch();
	closegraph();
}