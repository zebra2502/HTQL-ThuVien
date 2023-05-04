//////////////////////////////////////////////////////////////////
//	Bai project cuoi ky – Hoc phan Ky thuat lap trinh – MI3310	//
//	Chu de 4 – Xay dung chuong trinh quan ly thu vien			//
//	Ho va ten: Nguyen Phan Anh									//
//	MSSV: 20206113												//
//	Lop: Toan-Tin 02-K65										//
//	Ma lop: 133590												//
//////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*
Yeu cau can co:
Nhap thông tin sach
    so dang ky - so nguyen,
    ten sach
    ten cac tac gia
    nhà xuat ban
    nam xuat ban
    so ISBN
Cap nhat thông tin sách
Tim thông tin sach (theo so dang ky hoac ten sach hoac so ISBN)
Sap xep: theo so dang ky, theo nhà xuat ban
Luu ra file
Doc tu file
*/


// Dinh nghia cau truc luu tru thong tin sach trong thu vien sach
struct Thuviensach {
	int sodangky;
	char tensach[200];
	char tentacgia[200];
	char nhaxuatban[200];
	int namxuatban;
	char ISBN[100];
};
// Khai bao mang de luu tru sach
struct Thuviensach s[1000];
int n = 0;

void Nhapdanhsachsach() {
	printf("*********************\n");
	printf("Thao tac dang thuc hien: Nhap danh sach sach\n");
	printf("So sach ban muon nhap la: ");
	scanf("%d", & n);
	printf("Nhap so dang ky = 0 neu muon dung viec nhap ngay lap tuc.\n");
	for (int i = 0; i < n; i++) {
		printf("Quyen sach thu %d:\n", i + 1);
		printf("\tSo dang ky: ");
		scanf("%d", & s[i].sodangky);
		if (s[i].sodangky == 0) {n = i;
			break;
		}
		printf("\tTen sach: ");
		fflush(stdin);
		gets(s[i].tensach);
		printf("\tTen cac tac gia: ");
		fflush(stdin);
		gets(s[i].tentacgia);
		printf("\tTen nha xuat ban: ");
		fflush(stdin);
		gets(s[i].nhaxuatban);
		printf("\tNam xuat ban: ");
		scanf("%d", & s[i].namxuatban);
		printf("\tISBN: ");
		fflush(stdin);
		gets(s[i].ISBN);
	}
	printf("\nBam enter de tiep tuc");
	getch();
}

void Capnhatthongtinsach() {
	printf("Thao tac dang thuc hien: Cap nhat thong tin sach\n");
	printf("Ban muon cap nhat thong tin cua quyen sach co so dang ky la?\n");
	int cnsdk;
	scanf("%d", & cnsdk);
	printf("Vui long cap nhat cac thong tin moi:\n");
	for (int i = 0; i < n; i++) {
		if (cnsdk == s[i].sodangky) {
			printf("\tSo dang ky: ");
			scanf("%d", & s[i].sodangky);
			if (s[i].sodangky == 0) {
				break;
			}
			printf("\tTen sach: ");
			fflush(stdin);
			gets(s[i].tensach);
			printf("\tTen cac tac gia: ");
			fflush(stdin);
			gets(s[i].tentacgia);
			printf("\tTen nha xuat ban: ");
			fflush(stdin);
			gets(s[i].nhaxuatban);
			printf("\tNam xuat ban: ");
			scanf("%d", & s[i].namxuatban);
			printf("\tISBN: ");
			fflush(stdin);
			gets(s[i].ISBN);
		}
	}
	printf("\nBam enter de tiep tuc");
	getch();
}

void Timthongtinsach() {
	printf("Ban muon tim thong tin sach bang cach nao?\n");
	printf("1. Theo so dang ky\n");
	printf("2. Theo ten sach\n");
	printf("3. Theo so ISBN\n");
	printf("Lua chon cua ban: ");
	int lookupmodule;
	scanf("%d", & lookupmodule);
	if (lookupmodule == 1) {
		printf("Ban da chon tim kiem sach theo so dang ky.\n");
		int sdk;
		printf("Nhap vao so dang ky can tim kiem: ");
		scanf("%d", & sdk);
		int flag = 0;
		for (int i = 0; i < n; i++) {
			if (sdk == s[i].sodangky) {
				printf("Da tim thay sach!\n");
				flag += 1;
				printf("%-10s %-40s %-35s %-30s %-15s %-15s\n", "So dang ky", "Ten sach", "Ten tac gia", "Nha xuat ban", "Nam xuat ban", "ISBN");
				printf("%-10d %-40s %-35s %-30s %-15d %-15s\n", s[i].sodangky, s[i].tensach, s[i].tentacgia, s[i].nhaxuatban, s[i].namxuatban, s[i].ISBN);
			}
		}
		if (flag == 0) {
			printf("Khong tim thay sach co so dang ky ma ban vua nhap!\n");
		}
	}
	if (lookupmodule == 2) {
		printf("Ban da chon tim kiem sach theo ten sach.\n");
		char pendingname[100];
		printf("Nhap vao ten sach can tim kiem: ");
		fflush(stdin);
		gets(pendingname);
		int flag = 0;
		for (int i = 0; i < n; i++) {
			if (strcmp(pendingname, s[i].tensach) == 0) {
				printf("Da tim thay sach!\n");
				flag += 1;
				printf("%-10s %-40s %-35s %-30s %-15s %-15s\n", "So dang ky", "Ten sach", "Ten tac gia", "Nha xuat ban", "Nam xuat ban", "ISBN");
				printf("%-10d %-40s %-35s %-30s %-15d %-15s\n", s[i].sodangky, s[i].tensach, s[i].tentacgia, s[i].nhaxuatban, s[i].namxuatban, s[i].ISBN);
			}
		}
		if (flag == 0) {
			printf("Khong tim thay sach co ten ma ban vua nhap!\n");
		}
	}
	if (lookupmodule == 3) {
		printf("Ban da chon tim kiem sach theo so ISBN.\n");
		char pendingISBN[100];
		printf("Nhap vao so ISBN can tim kiem: ");
		fflush(stdin);
		gets(pendingISBN);
		int flag = 0;
		for (int i = 0; i < n; i++) {
			if (strcmp(pendingISBN, s[i].ISBN) == 0) {
				printf("Da tim thay sach!\n");
				flag += 1;
				printf("%-10s %-40s %-35s %-30s %-15s %-15s\n", "So dang ky", "Ten sach", "Ten tac gia", "Nha xuat ban", "Nam xuat ban", "ISBN");
				printf("%-10d %-40s %-35s %-30s %-15d %-15s\n", s[i].sodangky, s[i].tensach, s[i].tentacgia, s[i].nhaxuatban, s[i].namxuatban, s[i].ISBN);
			}
		}
		if (flag == 0) {
			printf("Khong tim thay sach co so ISBN ma ban vua nhap!\n");
		}
	}
	printf("\nBam enter de tiep tuc.");
	getch();
}

void Indanhsachsach() {

	for (int i = 0; i < n; i++) {
		//Ham fgets de lai ky tu cuoi cung la \n, muon print ra thi can phai loai bo no di
		strtok(s[i].tensach, "\n");
		strtok(s[i].tentacgia, "\n");
		strtok(s[i].nhaxuatban, "\n");
		strtok(s[i].ISBN, "\n");
	}
	int printmodule = 1;
	/*
		printf("\nThao tac dang thuc hien: In danh sach sach co trong thu vien.\n");
		printf("Ban muon in ra dang bang hay dang liet ke?\n");
		printf("1. Dang bang\n");
		printf("2. Dang liet ke\n");
		printf("Lua chon cua ban: ");
		scanf("%d",&printmodule);
	*/
	if (printmodule == 1) {
		printf("Thu vien sach (o dang bang): \n");
		printf("%-10s %-40s %-35s %-30s %-15s %-15s\n", "So dang ky", "Ten sach", "Ten tac gia", "Nha xuat ban", "Nam xuat ban", "ISBN");
		for (int i = 0; i < n; i++) {
			printf("%-10d %-40s %-35s %-30s %-15d %-15s\n", s[i].sodangky, s[i].tensach, s[i].tentacgia, s[i].nhaxuatban, s[i].namxuatban, s[i].ISBN);
		}
	}

	if (printmodule == 2) {
		printf("Thu vien sach (o dang liet ke): \n");
		for (int i = 0; i < n; i++) {
			printf("\nSo dang ky:   %d", s[i].sodangky);
			printf("\nTen sach:     %s", s[i].tensach);
			printf("\nTen tac gia:  %s", s[i].tentacgia);
			printf("\nNha xuat ban: %s", s[i].nhaxuatban);
			printf("\nNam xuat ban: %d", s[i].namxuatban);
			printf("\nISBN:         %s", s[i].ISBN);
			printf("\n");
		}
	}
	printf("\nBam enter de tiep tuc.");
	getch();
}

void Ghidanhsachvaoteptin() {
	FILE * fp;
	printf("Thao tac dang thuc hien: Ghi danh sach sach vao tep tin\n");
	fp = fopen("TVS-Output.txt", "w");
	if (fp == NULL) {
		printf("\nThat bai!\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		fprintf(fp, "%d\n", s[i].sodangky);
		fprintf(fp, "%s\n", s[i].tensach);
		fprintf(fp, "%s\n", s[i].tentacgia);
		fprintf(fp, "%s\n", s[i].nhaxuatban);
		fprintf(fp, "%d\n", s[i].namxuatban);
		fprintf(fp, "%s\n", s[i].ISBN);
	}
	fclose(fp);
	printf("\nThanh cong ! File du lieu: TVS-Output.\n");
	printf("\nBam enter de tiep tuc");
	getch();
}

void Docdanhsachsachtuteptin() {
	printf("Thao tac dang thuc hien: Doc danh sach sach tu tep tin\n");
	int i = 0;
	FILE * fp;
	fp = fopen("TVS-Input.txt", "r");
	if (fp == NULL) {
		printf("Loi roi!");
		return;
	}
	while (!feof(fp)) {
		fscanf(fp, "%d\n", & s[i].sodangky);
		fgets(s[i].tensach, 200, fp);
		fgets(s[i].tentacgia, 200, fp);
		fgets(s[i].nhaxuatban, 200, fp);
		fscanf(fp, "%d\n", & s[i].namxuatban);
		fgets(s[i].ISBN, 200, fp);
		i++;
	}
	n = i - 1;
	printf("Thanh cong! \n");
	printf("Tong so sach trong thu vien la: %d \n", n);
	fclose(fp);
	Indanhsachsach();
}

int Hienthimenu() {
	printf("\n\n\t***************************");
	printf("\n\tQUAN LY SACH TRONG THU VIEN\n");
	printf("1. Nhap danh sach sach\n");
	printf("2. Cap nhat thong tin sach.\n");
	printf("3. Tim thong tin sach.\n");
	printf("4. Sap xep (theo so dang ky, theo nha xuat ban)\n");
	printf("5. Ghi danh sach sach vao tep tin \n");
	printf("6. Doc danh sach sach tu tep tin \n");
	printf("7. In danh sach sach\n");
	printf("8. Thoat.\n");
	printf("Lua chon cua ban: ");
	int chon;
	scanf("%d", & chon);
	return chon;
}

int compare(const void * a,
            const void * b) {
	return ( * (int * ) a - * (int * ) b);
}

int comparator(const void * p0,
               const void * p1) {
	struct Thuviensach * ps0 = (struct Thuviensach * ) p0;
	struct Thuviensach * ps1 = (struct Thuviensach * ) p1;
	return strcmp(ps0 -> nhaxuatban, ps1 -> nhaxuatban);
}

void Sapxep() {
	printf("Ban muon sap xep thu tu sach theo cach nao?\n");
	printf("1. Theo so dang ky\n");
	printf("2. Theo nha xuat ban\n");
	printf("Lua chon cua ban: ");
	int sortmodule;
	scanf("%d", & sortmodule);
	if (sortmodule == 1) {
		printf("Ban da chon sap xep thu tu sach theo so dang ky\n");
		qsort(s, n, sizeof(struct Thuviensach), compare);
	}
	if (sortmodule == 2) {
		printf("Ban da chon sap xep thu tu sach theo nha xuat ban\n");
		qsort(s, n, sizeof(struct Thuviensach), comparator);
	}
	Indanhsachsach();
	printf("\nBam enter de tiep tuc.");
	getch();
}

void main() {
	struct Thuviensach s[1000];
	int chon;
	int sosach;
	do {
		chon = Hienthimenu();
		switch (chon) {
			case 1:
				Nhapdanhsachsach();
				break;
			case 2:
				Capnhatthongtinsach();
				break;
			case 3:
				Timthongtinsach();
				break;
			case 4:
				Sapxep();
				break;
			case 5:
				Ghidanhsachvaoteptin();
				break;
			case 6:
				Docdanhsachsachtuteptin();
				break;
			case 7:
				Indanhsachsach();
				break;
			case 8:
				printf("Chuong trinh ket thuc.");
				exit(1);
			default:
				printf("Thao tac khong hop le!");
				break;
		}
	} while (1);
}
