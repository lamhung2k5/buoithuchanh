#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

void nhap(int *a, int n);
void xuat(int *a, int n);
void max(int *a, int n);
void tich(int *a, int n);
int kiemNT(int x);
void demNT(int *a, int n);
void tongNT(int *a, int n);
void timx(int *a, int n, int x);
void sapxep(int *a, int n);
void chen(int *a, int n);
void xoa(int *a, int n);

void nhap(int *a, int n){
	for(int i = 0; i < n; i ++){
		printf("\na[%d] = ",i);
		scanf("%d", (a+i));
	}	
}

void xuat(int *a, int n){
	for(int i = 0; i < n; i ++){
		printf("\t%d",*(a+i));
	}
}

void max(int *a, int n){
	int imax = 0;
	for(int i = 1; i < n; i++){
		if (*(a + imax) < *(a + i)){
			imax = i;
		}
	}
	printf("\nphan tu lon nhat trong mang la %d", *(a+imax));
}

void tich(int *a, int n){
	int t = 1;
	for(int i = 0; i < n; i++){
		t *= *(a + i);
	}
	printf("\ntich cac phan tu trong mang la %d",t);
}

int kiemNT(int x){
	for(int i = 2; i <= sqrt(x); i++){
		if(x % i == 0){
			return 0;
		}
	}
	return x > 1;
}

void demNT(int *a, int n){
	int count = 0;
	for(int i = 0; i < n; i ++){
		if((kiemNT(*(a+i)))){
			count ++;
		}else{continue;}
	}
	printf("\nso cac so nguyen to co trong mang la %d",count);
}

void tongNT(int *a, int n){
	int tong = 0;
	for(int i = 0; i < n; i ++){
		if((kiemNT(*(a+i)))){
			tong += *(a+i);
		}else{continue;}
	}
	printf("\ntong cac so nguyen to co trong mang la %d",tong);
}

void timx(int *a, int n, int x){
	int count = 0;
	printf("\nphan tu x can tim: ");
	for(int i = 0; i < n; i++){
		if(*(a+i) == x){
			printf("\ta[%d]",i);
			count ++;
		}
	}
	if(count == 0){
		printf(" x khong ton tai");
	}
}

void sapxep(int *a, int n){
	for(int i = 1; i <= (n - 1); i++){
		for(int j = 0; j < n; j++){
			if(*(a+i) < *(a+j)){
				int temp = *(a+i); *(a+i) = *(a+j); *(a+j) = temp;
			}
		}
	}
	xuat(a,n);
}

void chen(int *a, int n){
	int x,k;
	n++;
	a = (int*)realloc(a,n);
	printf("\nnhap gia tri can chen: ");
	scanf("%d",&x);
	printf("\nnhap vi tri can chen (tu 0 den %d): ",n-1);
	scanf("%d",&k);	
	for(int i = n -1; i >= k; i--){
		*(a+i+1) = *(a+i);
	}
	*(a+k) = x;
	printf("\nmang sau khi da chen: ");
	xuat(a,n);	
}

void xoa(int *a, int n){
	int *p, k = 0, x;
	p = a;
	printf("\nnhap phan tu can xoa: ");
	scanf("%d",&x);
	for(int i = 0; i <= n; i++){
		if(*(p+i) != x){
			*(p+k) = *(p+i);
			k++;
		}
	}
	n = k;
	p = (int*)realloc(a,n*sizeof(int));
	printf("\nmang sau khi xoa: ");
	xuat(a,n);
}

int main(){
	int *a, n, x;
	a = (int*)malloc(n*sizeof(int));
	do{
		printf("nhap so phan tu mang: ");
		scanf("%d", &n);
	}while(n<=0);//kiem tra neu n la so am hoac bang 0 thi nhap lai.
	nhap(a,n);
	xuat(a,n);
	max(a,n);
	tich(a,n);
	demNT(a,n);
	tongNT(a,n);
	printf("\nnhap phan tu can tim: ");
	scanf("%d", &x);
	timx(a,n,x);
	printf("\nmang sau khi da sap xep: ");
	sapxep(a,n);
	chen(a,n);
	xoa(a,n);
	free(a);
}
