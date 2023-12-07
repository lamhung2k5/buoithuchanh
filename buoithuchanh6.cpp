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
void sapxep(sv a[], int n);
void inhsgxs(sv a[], int n); 
void timkiem(int a[], int n); 

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
	if(x.kqcuoikhoa>2.5&&x.kqcuoikhoa<=3.0){
		strcpy(x.xeploai,"KHA");
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
		printf("\n|%5s|%-21s|%-6s|%10d|%-11s|%12.1f|%-10s|%-10s|",x.mssv,x.hoten,x.phai,x.namsinh,x.nganhhoc,x.kqcuoikhoa,x.xeploai,x.quequan);
}

void xuat(sv a[], int n){
	system("cls");
	  printf("\n\n|--------------------------------------------------------------------------------------------|");
    	printf("\n|ma SV| ho va ten sinh vien | phai | nam sinh | nganh hoc |Kq cuoi khoa| xep loai | que quan |");
 	for(int i = 0; i < n; i++){
  printf("\n|-----|---------------------|------|----------|-----------|------------|----------|----------|");
    xuatthongtin(a[i]);
	 }
}

void sapxep(sv a[], int n){
	system("cls"); 
	sv temp;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(a[i].kqcuoikhoa > a[j].kqcuoikhoa){
				temp = a[i];
				a[i]=a[j];
				a[j]=temp; 
			} 
			 
		} 
	} 
	xuat(a,n); 
}

void inhsgxs(sv a[], int n){
	system("cls");
	sv dshs[10]; 
	int cnt; 
	for(int i = 0; i < n; i++){
		if(a[i].kqcuoikhoa>3.0){
			dshs[i]=a[i]; 
			cnt++;
		}
	} 
	if(cnt != 0){
		xuat(dshs,cnt); 		
	}else{
		printf("\nkhong co sinh vien can tim");
	} 

}

void timkiem(sv a[], int n){
	system("cls");
	fflush(stdin); 
	char ma[10]; 
	sv dshs[10]; 
	int cnt; 
	printf("\nnhap ma so sinh vien can kiem tra");
	gets(ma);
	
	for(int i = 0; i< n; i++){
		if(strcmp(a[i].mssv,ma)==0){
			dshs[i]=a[i];
			cnt++; 
		} 
	} 
	if(cnt != 0){
		xuat(dshs,cnt); 	
	}else{
		printf("\nkhong tim thay sinh vien.");
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
			case 3:
				sapxep(a,n); 
				printf("\nnhan phim bat ki de tiep tuc!");
				getch();
				break;
			case 4:
				inhsgxs(a,n);
				printf("\nnhan phim bat ki de tiep tuc!");
				getch();
				break;
			case 5:
				timkiem(a,n); 
				printf("\nnhan phim bat ki de tiep tuc!");
				getch();
				break;
			case 0:
				exit(1);
			default:
				printf("\nkhong co yeu cau nay"); 
				printf("\nnhan phim bat ki de tiep tuc!");
				getch();
				break;
		}
		
	}
}
