#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int mssv;
	char hoten[30];
	int age;
	int gender;
} SinhVien;

int main(){
	SinhVien*dsSV = calloc(100, sizeof(*dsSV));
	int count = 0;
		int choice = 0;
    while (choice != 99){
    printf("1. Them SV\n");
	printf("2. Hien thi danh sach SV\n");
	printf("3. Luu file\n");
	printf("99. Thoat\n");
	printf("Lua chon chuc nang:");
	scanf("%d", &choice);
	if (choice==1){
		SinhVien sv;
		printf("Nhap MSSV:");
		scanf("%d", &sv.mssv);
		printf("Nhap ho ten: ");
		getchar();
		scanf("%[^\n]s", &sv.hoten);
		printf("Nhap tuoi:");
		scanf("%d", &sv.age);
		printf("Nhap gioi tinh (Nam: 0, Nu: 1): ");
		scanf("%d", &sv.gender);
		
		printf("%d %s %d %d", sv.mssv, sv.hoten, sv.age, sv.gender);
		dsSV[count] = sv;
		count++;
		}
		else if (choice==2){
			int i;
			for ( i = 0; i < count; i++)
			printf("%d %s %d %d", dsSV[i].mssv, dsSV[i].hoten, dsSV[i].age, dsSV[i].gender);
		}
		else if (choice == 3){
			FILE *f;
			f = fopen("sv.txt", "w");
			fprintf(f, "%d\n", count);
			int i;
			for(i = 0; i < count ; i++){
				fprintf(f,"%d\n", dsSV[i].mssv );
				fprintf(f,"%d\n", dsSV[i].hoten);
				fprintf(f,"%d\n", dsSV[i].age);
				fprintf(f,"%d\n", dsSV[i].gender);
			}
			fclose(f);
			printf("Data written to sv.txt\n");
		}
	}

}
