#include "stdio.h"
#include "string.h"
#include "stdlib.h"
 
/*Cau truc ho ten*/
struct HoTen {
	char ho[20];
	char dem[20];
	char ten[20];
};
/*Cau truc nhan vien*/
struct nhanvien{
	int manv;
	char phong[5];
	struct HoTen hovaten;
	int tuoi;
	char gioitinh[10];
	char chucvu[20];
};
 
/*Ham nhap ho va ten*/
void nhaphoten(struct HoTen* ten){
	printf("Ho: ");scanf("%s",ten->ho);
	printf("Dem: ");
	getchar();
	gets(ten->dem);
	printf("Ten: ");scanf("%s",ten->ten);
}

/*cau truc nhap thong tin*/
void add_employee(struct nhanvien* list, int* count) {
    struct nhanvien new_employee;
    int duplicate_code = 0;
    fflush(stdin);

    printf("Enter employee code: ");
    scanf("%d", &new_employee.manv);

    for (int i = 0; i < *count; i++) {
        if (list[i].manv == new_employee.manv) {
            printf("Error: Employee code already exists.\n");
            duplicate_code = 1;
            break;
        }
    }

    if (!duplicate_code) {
    	fflush(stdin);
        printf("Enter department: ");
        scanf("%s", new_employee.phong);
        printf("Enter last name: ");
        scanf("%s", new_employee.hovaten.ho);

        printf("Enter middle name: ");
        getchar();
        gets(new_employee.hovaten.dem);

        printf("Enter first name: ");
        scanf("%s", new_employee.hovaten.ten);

        printf("Enter age: ");
        scanf("%d", &new_employee.tuoi);

        printf("Enter gender: ");
        scanf("%s", new_employee.gioitinh);
        fflush(stdin);

        printf("Enter job title: ");
        getchar();
        gets(new_employee.chucvu);

        list[*count] = new_employee;
        (*count)++;
        printf("Employee added to the list.\n");
    }
}
 
void hienthittnhanvien(struct nhanvien nv){
	printf("%-10d %-10s %-10s %-10s %-10d %-10s %-10s %-10s\n",
	nv.manv,nv.hovaten.ho,nv.hovaten.dem,nv.hovaten.ten,nv.tuoi,nv.gioitinh,nv.chucvu,nv.phong );
}
/*Tao ham sap xep nhan vien theo ten tu a-z*/
void sapxeptheotenaz(struct nhanvien* ds, int slnv){
	int i,j;
	for (i=0; i<slnv-1;i++){
		for(j=slnv-1;j>i;j--){
			if(strcmp(ds[j].hovaten.ten,ds[j-1].hovaten.ten)<0){
				struct nhanvien nv=ds[j];
				ds[j]=ds[j-1];
				ds[j-1]=nv;
			}
		}
	}
}
/*Ham tim nhan vien theo ten cua nhan vien do*/
void timtheoten(struct nhanvien* ds, int  slnv){
    char ten[20];
    printf("Nhap ten: ");
    scanf("%s", ten);
    printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n",
	"MaNV","Ho","Dem","Ten","Tuoi","Gioi Tinh","Chuc vu","So phong");
    int i, timnv=0;
    for (i =0; i<slnv;i++ ){
    	if(strcmp(ten, ds[i].hovaten.ten)==0){
    		hienthittnhanvien(ds[i]);
            timnv=1;
		}
	}
	if (timnv==0){
		printf("Khong co nhan vien %s trong danh sach\n");
	}
}
/*Ghi thong tin cua mot nhan vien ra file txt*/
void ghifile(struct nhanvien* ds, int  slnv){
	FILE* fOut=fopen("D:\\danhsachnhanvien2","a" );
	int i;
	for(i = 0;i<slnv;i++){
		struct nhanvien nv=ds[i];
		fprintf(fOut, "%-10d %-10s %-10s %-10s %-10d %-10s %-10s %-10s\n",
	nv.manv,nv.hovaten.ho,nv.hovaten.dem,nv.hovaten.ten,nv.tuoi,nv.gioitinh,nv.chucvu,nv.phong );
}
fclose(fOut);	}
 
int main()
{
	{
	  int n, i, *ptr;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
 
    // N?u không th? c?p phát, 
    // hàm malloc s? tr? v? con tr? NULL
    if (ptr == NULL)
    {
        printf("Co loi! khong the cap phat bo nho.");
        exit(0);
    }
     free(ptr);
}
	/*in ra bang thong tin nhan vien*/
	struct nhanvien dsnv[100];
	int slnv=0;
	int tuychon;
	/*Vong lap cac chuc nang cua chuong trinh*/
	do{
		printf("==========M E N U=========");
		printf("\n1. Them moi nhan vien.");
		printf("\n2. Hien thi danh sach nhan vien.");
		printf("\n3. Sap xep danh sach nhan vien theo ten.");
		printf("\n4. Tim nhan vien.");
		printf("\n5. Ghi thong tin nhan vien ra file txt.");
		printf("\n0. Thoat chuong trinh.");
		printf("\nVui long chon 1 chuc nang\n");
		
		scanf("%d",&tuychon);
		struct nhanvien nv;
		switch(tuychon){
			case 0:break;
			case 1: 	
	                    add_employee(dsnv, &slnv);
	                    break;
	        case 2:
			            printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n",
                      	"MaNV","Ho","Dem","Ten","Tuoi","Gioi Tinh","Chuc vu","So phong");      
						int i;
	                    for(i=0;i<slnv;i++){
		                hienthittnhanvien(dsnv[i]);}
		                break;
		    case 3:
			            sapxeptheotenaz(dsnv, slnv);
	                    	printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n",
	                        "MaNV","Ho","Dem","Ten","Tuoi","Gioi Tinh","Chuc vu","So phong");	             
			                for(i=0;i<slnv;i++){
		                    hienthittnhanvien(dsnv[i]);}
			break;
			case 4:
				timtheoten(dsnv,slnv);
			break;
			case 5: ghifile(dsnv,slnv);
			break;
			default: printf("\nNhap sai, vui long nhap lai!");
		}
	}while(tuychon);
	
	return 0;
}
