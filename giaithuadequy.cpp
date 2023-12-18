#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int giaithua(int n){
	if(n==0){
		return 1;
	}
	if(n>0){
		return n*giaithua(n-1);
	}
}

int main(){
	long long n;
	printf("nhap n: ");
	scanf("%d",&n);
	printf("\n%d! = %d",n,giaithua(n));
	getch();
}
