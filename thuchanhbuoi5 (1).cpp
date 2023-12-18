#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void in(char s[]){
	for(int i = 0; i < strlen(s); i++){
		if(i==0||(i>0&&s[i-1]==' ')){
			if(s[i]>=97&&s[i]<=122){
				s[i]=s[i]-32;
			}
		}else{
				if(s[i]>=65&&s[i]<=90){
					s[i]=s[i]+32;
				}
			}
	}
}

void xoa(char s[]){
	int i = 0;
	while(s[i]==' '){
		for(int j = i; j < strlen(s); j++){
			s[j]=s[j+1];
		}
	}
	for(int i = 0; i < strlen(s)-1; i++){
		if(s[i]==' '&&s[i+1]==' '){
			for(int j = i; j < strlen(s); j++){
				s[j]=s[j+1];
			}
			i--; 
		}
	}
	i = strlen(s) - 1;
	while(s[i]==' '){
		s[i]='\0';
		i--;
	}
}

void chuanhoa(char s[]){
	printf("\nnhap chuoi s: ");
	gets(s);
	xoa(s);
	in(s);
	printf("\n\nchuoi sau khi da chuan hoa:\n\n");
	puts(s);
}

void dem(char s[], char c[]) {
    strupr(s);
    c[0] = toupper(c[0]); 

    int cnt = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == c[0]) {
            cnt++;
        }
    }

    if (cnt == 0) {
        printf("\nKi tu %c khong co trong chuoi s!", c[0]);
    } else {
        printf("\nCo %d ki tu %c co trong chuoi s", cnt, c[0]);
    }
}

void demtu(char s[]){
	int cnt = 1;
	for(int i = 0; i < strlen(s); i++){
		if(s[i]==' '){
			cnt++;
		}
	}
	printf("\nco %d tu trong chuoi s.", cnt);
}

int main(){
	char s[100],c[1];
	int chon;
	while(true){
		system("cls");
		printf("**********************************************\n");
        printf("**           THAO TAC TREN CHUOI            **\n");
        printf("**         1. Nhap va chuan hoa chuoi       **\n");
        printf("**         2. Nhap 1 ky tu va dem ky tu     **\n");
        printf("**         3. Dem so tu co trong chuoi      **\n");
        printf("**         0. Thoat                         **\n");
        printf("**********************************************\n");
		fflush(stdin);
	    printf("\n\t\tAN PHIM CHON: ");
        scanf("%d",&chon); 
		switch(chon){
			case 1:
				system("cls");
				fflush(stdin);
				chuanhoa(s); 
				printf("\nnhan phim bat ki de tiep tuc!");
				getch();
				break;
			case 2:
				system("cls");
				fflush(stdin);
				printf("\nnhap ki tu: ");
				scanf("%c",&c[0]); 
				dem(s,c);
				printf("\nnhan phim bat ki de tiep tuc!");
				getch();
				break;
			case 3:
				system("cls");
				fflush(stdin);
				demtu(s);
				printf("\nnhan phim bat ki de tiep tuc!");
				getch();
				break;
			case 0:
				exit(1);
			default:
				system("cls");
				fflush(stdin);
				printf("\nkhong co chuc nang nay. Bam phim bat ki de tiep tuc!");
				getch();
				break;		 
			} 
	} 
} 
