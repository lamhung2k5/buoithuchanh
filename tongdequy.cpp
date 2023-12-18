#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int tong(int n){
	if(n==0){
		return 0;
	}
	if(n>0){
		return n + tong(n-1);
	}
}

int main(){
	int n;
	printf("nhap n: ");
	scanf("%d",&n);
	printf("\ntong tu 1 toi %d la: %d",n,tong(n));
	getch();
}
