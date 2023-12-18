#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void nhap(int a[], int n, int i){
	if(i==n){//kiem tra da nhap du phan tu chua
		return;
	}
	printf("\na[%d] = ", i);
	scanf("%d",&a[i]);
	nhap(a,n,i+1);
}

void xuat(int a[], int n, int i){
	if(i==n){//kiem tra da xuat du phan tu hay chua
		return;
	}
	printf("\t%d",a[i]);
	xuat(a,n,i+1);
}

int main(){
	int a[100], n;
	do{
		printf("\nnhap so luong phan tu mang: ");
		scanf("%d",&n);
		if(n<=0||n>100){
			system("cls");
			printf("so luong phan tu khong hop le. vui long nhap lai.");
		}
	}while(n<=0||n>100);
	nhap(a,n,0);
	printf("\nmang vua nhap: ");
	xuat(a,n,0);
	getch();
}
