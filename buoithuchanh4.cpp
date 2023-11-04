#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int tprime(int x);//ham kiem tra so nguyen to
int min_row(int a[][205],int dong,int cot,int m, int n);//ham kiem tra phan tu nho nhat trong dong
int max_col(int a[][205],int dong,int cot,int m,int n);//ham kiem tra phan tu nho nhat trong cot

void id(int a[][205],int m,int n);//ham nhap
void pm(int a[][205],int m,int n);//ham xuat
void max(int a[][205],int m,int n);//tim phan tu lon nhat
void min(int a[][205],int m,int n);//tim phan tu nho nhat
void cnt_pr(int a[][205],int m,int n);//dem so nguyen to trong mang
void sum(int a[][205],int m,int n);//tinh tong cac phan tu trong mang
void findx(int a[][205],int m,int n);//tim phan tu trong mang
void dyn(int a[][205],int m,int n);//tim diem yen ngua
void sapxep(int a[][205],int m,int n);//sap xep theo dong va cot
void tongcheochinh(int a[][205],int m,int n);//tinh tong duong cheo chinh 
void demchan(int a[][205],int m,int n);//dem so chan tam giac tren khong tinh duong cheo chinh
void demle(int a[][205],int m,int n);//tim va in ra cac so le nam trong tam giac duoi cua dduong cheo phu (tinh duong cheo phu)
void tongmatran(int a1[][205],int b1[][205],int c[][205],int m,int n);//tinh tong hai ma tran
void tichmatran(int a1[][205],int b1[][205],int t[][205],int m,int n,int n1);//tinh tong hai ma tran

//cac ham phu

int tprime(int x){
	for(int i = 2; i <= sqrt(x); i++){
		if(x%i==0){
			return 0;
		}
	}
	return x>1;
}

int min_row(int a[][205],int dong,int cot,int m, int n){
	int x = a[dong][cot];
	for(int i=0;i<n;i++){
		if(a[dong][i] < x){
			return 0;
		}
	}
	return 1;
}

int max_col(int a[][205],int dong,int cot,int m,int n){
	int x = a[dong][cot];
	for(int j=0;j<m;j++){
		if(a[j][cot] > x){
			return 0;
		}
	}
	return 1;
}



//ham de bai

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
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if (min_val > a[i][j]){
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
	int cnt_yn = 0;
    for(int i=0;i<m;i++){
    	for(int j=0;j<n;j++){
    		if(min_row(a,i,j,m,n)&&max_col(a,i,j,m,n)){
    			printf("\na[%d][%d] = %d la mot diem yen ngua",i,j,a[i][j]);
    			cnt_yn++;
    		}
		}
	}
	if(cnt_yn!=0){
		printf("\nso diem yen ngua la %d",cnt_yn);
	}else{printf("\nkhong ton tai diem yen ngua");}
}

void sapxep(int a[][205],int m,int n){
	int k=0;
	int tmp[205];//mang tam
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			tmp[k]=a[i][j];//chuyen mang hai chieu thanh mang mot chieu
			k++;
		}
	}
	
	for(int l=1;l<=k-1;l++){
		for(int f=0;f<k;f++){
			if(tmp[l]<tmp[f]){
				int temp = tmp[l];
				tmp[l] = tmp[f];
				tmp[f] = temp;
			}
		}
	}
	
	k =0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			a[i][j]=tmp[k];
			k++;
		}
	}
	pm(a,m,n);
}

void tongcheochinh(int a[][205],int m,int n){
	if(m!=n){
		printf("\nma tran khong co duong cheo chinh. khong the tinh tong cac phan tu tren duong cheo chinh.");
	}else{
		int tong = 0;
		for(int i=0;i<n;i++){
			tong += a[i][i];
		}
		printf("\ntong cac phan tu tren duong cheo chinh la %d",tong);
	}
}

void demchan(int a[][205],int m,int n){
		if(m!=n){
			printf("\nma tran khong co duong cheo chinh. khong the dem cac phan tu chan trong tam giac tren cua duong cheo chinh");
		}else{
			int cnt = 0;
			for(int i=0;i<n-1;i++){
				for(int j=i+1;j<n;j++){
					if(a[i][j]%2==0){
						cnt++;
					}
				}
			}
			printf("\nso cac phan tu chan trong tam giac tren cua duong cheo chinh (khong tinh duong cheo chinh) la %d",cnt);
		}
}

void demle(int a[][205],int m,int n){
			if(m!=n){
				printf("\nma tran khong co duong cheo phu. khong the tim va in ra cac so le nam trong tam giac duoi duong cheo phu (tinh luon duong cheo phu).");
			}else{
				printf("\ncac so le nam trong tam giac duoi duong cheo phu (tinh luon duong cheo phu): ");
				int cnt = 0;
				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						if((i+j>=n)&&(a[i][j]%2==1)){
							printf("\ta[%d][%d] = %d",i,j,a[i][j]);
							cnt++;
						}
					}
				}
				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						if((i+j==(n-1))&&(a[i][j]%2==1)){
							printf("\ta[%d][%d] = %d",i,j,a[i][j]);
							cnt++;
						}
					}
				}
				if(cnt==0){
					printf("khong ton tai.");
				}
			}
}

void tongmatran(int a1[][205],int b1[][205],int c[][205],int m,int n){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
				c[i][j] = a1[i][j] + b1[i][j];
			}
		}
}

void tichmatran(int a1[][205],int b1[][205],int t[][205],int m,int n,int n1){
	for(int i=0;i<m;i++){
		for(int j=0;j<n1;j++){
			t[i][j]=0;
			for(int k=0;k<n;k++){
				t[i][j]+=a1[i][k]*b1[k][j];
			}
		}
	}
}

//chuong trinh chinh

int main(){
	int a[205][205],m,n,max_m,min_m;
	//kiem tra dau vao
	do{
		printf("\nnhap so hang: ");
		scanf("%d",&m);
		if((m<0)||(m>205)){
			printf("\nso hang khong hop le, vui long nhap lai.");
		}
	}while((m<0)||(m>205));
	do{
		printf("\nnhap so cot: ");
		scanf("%d",&n);
		if((n<0)||(n>205)){
			printf("\nso cot khong hop le, vui long nhap lai.");
		}
	}while((n<0)||(n>205));
	id(a,m,n);
	printf("\nma tran vua nhap:\n ");
	pm(a,m,n);
	max(a,m,n);
	min(a,m,n);
	cnt_pr(a,m,n);
	sum(a,m,n);
	findx(a,m,n);
	dyn(a,m,n);
	printf("\nmang sau khi da sap xep:\n");
	sapxep(a,m,n);
	tongcheochinh(a,m,n);
	demchan(a,m,n);
	demle(a,m,n);
	int a1[205][205],b1[205][205],c[205][205],t[205][205],ma,mb,na,nb;
	printf("\nnhap ma tran A: \n");
	do{
		printf("\nnhap so hang: ");
		scanf("%d",&ma);
		if((ma<0)||(ma>205)){
			printf("\nso hang khong hop le, vui long nhap lai.");
		}
	}while((ma<0)||(ma>205));
	do{
		printf("\nnhap so cot: ");
		scanf("%d",&na);
		if((na<0)||(na>205)){
			printf("\nso cot khong hop le, vui long nhap lai.");
		}
	}while((na<0)||(na>205));
	id(a1,ma,na);
	printf("\nnhap ma tran B: \n");
	do{
		printf("\nnhap so hang: ");
		scanf("%d",&mb);
		if((mb<0)||(mb>205)){
			printf("\nso hang khong hop le, vui long nhap lai.");
		}
	}while((mb<0)||(mb>205));
	do{
		printf("\nnhap so cot: ");
		scanf("%d",&nb);
		if((nb<0)||(nb>205)){
			printf("\nso cot khong hop le, vui long nhap lai.");
		}
	}while((nb<0)||(nb>205));
	id(b1,mb,nb);

}
