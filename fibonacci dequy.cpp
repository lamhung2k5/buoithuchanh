#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int fibo(int n){
	if(n==0||n==1){
		return n;
	}
	if(n>1){
		return fibo(n-1) + fibo(n-2);
	}
}

int main(){
	printf("10 so dau tien trong day fibonacci la:\n");
	for(int i = 0; i < 10; i++){
		printf("\n%d",fibo(i));
	}
	getch();
}
