#include <stdio.h>

void TOH(int, char, char, char); 

int main()
{
int n;
clrscr();
printf("Enter number of disks ");
scanf(" %d", &n);
TOH(n,'S','D','T');
}

void TOH(int n, char A, char B, char C)
{
if(n>0)
{
TOH(n-1, A, C, B);
printf("Move disk %d from %c to %c \n", n, A, B);
TOH(n-1, C, B, A);
}
}