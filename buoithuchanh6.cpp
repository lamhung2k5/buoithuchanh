#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct sinhvien{
	char mssv[10];
	char hoten[30];
	int namsinh;
	char phai[10];
	char nganhhoc[30];
	float kqcuoikhoa;
	char xeploai[30];
	char quequan[30];
};
typedef struct sinhvien sv;

void nhap(sv a[], int n);
void nhapthongtin(sv &x);
void xuat(sv a[], int n);
void xuatthongtin(sv x);

void nhapthongtin(sv &x){
	fflush(stdin);
	printf("\nnhap MSSV:");
	gets(x.mssv);
	fflush(stdin);
	printf("\nnhap ho va ten:");
	gets(x.hoten);
	fflush(stdin);
	printf("\nnhap gioi tinh:");
	gets(x.phai);
	fflush(stdin);
	printf("\nnhap nganh hoc:");
	gets(x.nganhhoc);
	fflush(stdin);
	printf("\nnhap que quan:");
	gets(x.quequan);
	do{
		printf("\nnhap nam sinh:");
		scanf("%d",&x.namsinh);
		if((x.namsinh<1980)||(x.namsinh>2010)){
			printf("\nnam sinh khong hop le. vui long nhap lai!");
		}
	}while((x.namsinh<1980)||(x.namsinh>2010));	
	do{
		printf("\nnhap ket qua cuoi khoa:");
		scanf("%f",&x.kqcuoikhoa);
		if((x.kqcuoikhoa<0)||(x.kqcuoikhoa>4)){
			printf("\ndiem vua nhap khong hop le. vui long nhap lai!");
		}
	}while((x.kqcuoikhoa<0)||(x.kqcuoikhoa>4));	
	fflush(stdin);
	if(x.kqcuoikhoa<=1.5){
		strcpy(x.xeploai,"YEU");
	}
	if(x.kqcuoikhoa>1.5&&x.kqcuoikhoa<=2.5){
		strcpy(x.xeploai,"TRUNG BINH");
	}
	if(x.kqcuoikhoa>3.0&&x.kqcuoikhoa<=3.8){
		strcpy(x.xeploai,"GIOI");
	}
	if(x.kqcuoikhoa>3.8&&x.kqcuoikhoa<=4.0){
		strcpy(x.xeploai,"XUAT SAC");
	}
}

void nhap(sv a[], int n){
	for(int i = 0; i < n; i++){
		printf("\nnhap sinh vien thu %d:", i+1);
		nhapthongtin(a[i]);
	}
}

void xuatthongtin(sv x){
		printf("|%5s|%-18s|%-6s|%10d|%-11s|%12.1f|%-10s|%-10s|",x.mssv,x.hoten,x.phai,x.namsinh,x.nganhhoc,x.kqcuoikhoa,x.xeploai,x.quequan);
}

void xuat(sv a[], int n){
	system("cls");
	  printf("\n\n|--------------------------------------------------------------------------------------|\n");
 	printf("|ma SV| ho va ten sinh vien | phai | nam sinh | nganh hoc |Kq cuoi khoa| xep loai | que quan |");
 	for(int i = 0; i < n; i++){
  printf("\n|-----|---------------------|------|----------|-----------|------------|----------|----------|");
    xuatthongtin(a[i]);
	 }
}

int main(){
	int n, chon;
	sv x, a[10];
	while(true){
		system("cls");
		  printf("**********************************************");
		printf("\n**      CHUONG TRINH QUAN LY SINH VIEN      **");
		printf("\n**      1.nhap DS sinh vien                 **");
		printf("\n**      2.in DS sinh vien                   **");
		printf("\n**      3.sap xep theo kq cuoi khoa         **");
		printf("\n**      4.in SV gioi, xuat sac              **");
		printf("\n**      5.tim kiem SV theo MSSV             **");
		printf("\n**      0.thoat                             **");
	    printf("\n**********************************************");
	    printf("\n\n\t NHAN PHIM CHON THAO TAC: ");
	    scanf("%d",&chon);
	    switch(chon){
	    	case 1:
	    		do{
	    			printf("\nnhap so luong sinh vien:");
	    			scanf("%d",&n);
				}while(n<=0);
				nhap(a,n);
				printf("\nnhan phim bat ki de tiep tuc!");
				getch();
				break;
			case 2:
				xuat(a,n);
				printf("\nnhan phim bat ki de tiep tuc!");
				getch();
				break;	
		}
		
	}
}
