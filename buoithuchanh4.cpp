#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int tprime(int x);

void id(int a[][205],int m,int n);
void pm(int a[][205],int m,int n);
void max(int a[][205],int m,int n);
void min(int a[][205],int m,int n);
void cnt_pr(int a[][205],int m,int n);
void sum(int a[][205],int m,int n);
void findx(int a[][205],int m,int n);
void dyn(int a[][205],int m,int n);
void sapxep(int a[][205],int m,int n);

int tprime(int x){
	for(int i = 2; i <= sqrt(x); i++){
		if(x%i==0){
			return 0;
		}
	}
	return x>1;
}

void id(int a[][205],int m,int n){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			printf("a[%d][%d] = ",i,j);
			scanf("%d", &a[i][j]);
		}
	}
}

void pm(int a[][205],int m,int n){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			printf("\t%d ",a[i][j]);
		}
		printf("\n");
	}
}

void max(int a[][205],int m,int n){
	int max_val = a[0][0];
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if (max_val < a[i][j]){
				max_val = a[i][j];
			}
		}
		
	}
	printf("\nphan tu co gia tri lon nhat trong ma tran la %d",max_val);
}
void min(int a[][205],int m,int n){
	int min_val = a[0][0];
	for(int i = 0; i > m; i++){
		for(int j = 0; j < n; j++){
			if (min_val < a[i][j]){
				min_val = a[i][j];
			}
		}
		
	}
	printf("\nphan tu co gia tri nho nhat trong ma tran la %d",min_val);
}

void cnt_pr(int a[][205],int m,int n){
	int count = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if (tprime(a[i][j])){
				count += 1;
			}else{continue;}
		}	
	}
	printf("\nso cac so nguyen to co trong ma tran la %d",count);
}

void sum(int a[][205],int m,int n){
	int t = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			t += a[i][j];
		}
		
	}
	printf("\ntong cac phan tu co trong ma tran la %d",t);
}

void findx(int a[][205],int m,int n){
	int count = 0,x;
	printf("\nnhap phan tu can tim: ");
	scanf("%d",&x);
	printf("\nphan tu can tim: ");
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] == x){
				printf("\t\ta[%d][%d]",i,j);
				count ++;
			}
		}
		
	}
	if(count == 0){printf("x khong ton tai.");}
	
}

void dyn(int a[][205], int m, int n) {
    for (int i = 0; i < m; i++) {
        int min = a[i][0];
        for (int j = 1; j < n; j++) {
            if (a[i][j] < min) {
                min = a[i][j];
            }
        }
        for (int k = 0; k < n; k++) {
            if (a[i][k] == min) {
                int max = a[0][k];
                for (int l = 1; l < m; l++) {
                    if (a[l][k] > max) {
                        max = a[l][k];
                    }
                }
                if (max == a[i][k]) {
                    printf("\nDiem yen ngua la %d tai vi tri [%d][%d]\n", max, i, k);
                }
            }
        }
    }
}

void sapxep(int a[][205],int m,int n){
	
}
	

int main(){
	int a[205][205],m,n,max_m,min_m;
	printf("nhap so hang: ");
	scanf("%d",&m);
	printf("nhap so cot: ");
	scanf("%d",&n);
	id(a,m,n);
	printf("\nma tran vua nhap:\n ");
	pm(a,m,n);
	max(a,m,n);
	min(a,m,n);
	cnt_pr(a,m,n);
	sum(a,m,n);
	findx(a,m,n);
	dyn(a,m,n);
}


