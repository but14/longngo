#include "stdio.h"
#include "string.h"

/*Cau truc ho ten*/
struct HoTen {
	char ho[20];
	char dem[21];
	char ten[20];
};
/*Cau truc nhan vien*/
struct nhanvien{
	char manv;
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
struct nhanvien nhapnv() {
	struct nhanvien nv;
	printf("Nhap ma: ");
	scanf("%d",&nv.manv);
	nhaphoten(&nv.hovaten);
	printf("Tuoi: ");
	scanf("%d",&nv.tuoi);
	printf("Gioi tinh: ");
	scanf("%s",nv.gioitinh);
	printf("Chuc vu: ");
	getchar();
	gets(nv.chucvu);
	printf("Phong: ");
	scanf("%s",&nv.phong);
	return nv;
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

	FILE* fp=fopen("D:\\danhsachnhanvien1.txt","a" );
	int i;
	for(i = 0;i<slnv;i++){
		struct nhanvien nv=ds[i];
		fprintf(fp, "%-10d %-10s %-10s %-10s %-10d %-10s %-10s %-10s\n",
	nv.manv,nv.hovaten.ho,nv.hovaten.dem,nv.hovaten.ten,nv.tuoi,nv.gioitinh,nv.chucvu,nv.phong );
}
fclose(fp);	}

//Infile
void docfile(struct nhanvien* ds, int* slnv){
	FILE* fp=fopen("D:\\danhsachnhanvien1.txt","r" );
	int i=0;
	if(fp) {
		
		for(;;){
		struct nhanvien nv=ds[i];
		fscanf(fp, "%10d %10s %10s %10s %10d %10s %10s %10s\n",
	&nv.manv,&nv.hovaten.ho,&nv.hovaten.dem,&nv.hovaten.ten,&nv.tuoi,&nv.gioitinh,&nv.chucvu,&nv.phong );
		if(feof(fp)) { break;
		}
		ds[i++]=nv;
	}
}
fclose(fp);
*slnv = i;
}


int main()
{
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
		printf("\n5. Ghi thong tin nhan vien ra file");
		printf("\n0. Thoat chuong trinh.");
		printf("\nVui long chon 1 chuc nang\n");
		
		scanf("%d",&tuychon);
		struct nhanvien nv;
		switch(tuychon){
			case 0: return 0;
			case 1: 	
	                    nv= nhapnv();
	                    dsnv[slnv++]=nv;
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
			default: printf("\nNhap sai, vui long nhap lai!\n");
			         printf("                              \n");
		}
	}while(tuychon);
	/*Cau truc hien thi thong tin nhan vien dang bang*/
	struct nhanvien nv;
	nv= nhapnv();
	dsnv[slnv++]=nv;
	printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n",
	"MaNV","Ho","Dem","Ten","Tuoi","Gioi Tinh","Chuc vu","So phong");
	/*Cau truc lap de hien thi toan bo thong tin cac nhan vien*/
	int i;
	for(i=0;i<slnv;i++){
		hienthittnhanvien(dsnv[i]);
	}
	
	ghifile(dsnv,slnv);
	
	return 0;
}

