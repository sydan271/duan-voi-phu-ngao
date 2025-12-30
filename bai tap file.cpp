////input.txt: 2 so nguyen, moi so 1 dong, do lon khong gioi han 
////output.txt: ket qua phep cong 2 so tren

#include<stdio.h>
int getNumberLength(char x[]){
	int l = 0;
	int i;
	for (i=0; i < strlen(x); i++)
	if (x[i]>= '0' && x[i] <= '9')
	l++;
	else break;
	return l;
}

int main (){
	FILE *f;
	f = fopen("input.txt", "r");
	char x1[100];
	char x2[100];
	fgets(x1, 100, f);
	fgets(x2, 100, f);
	fclose(f);
	int x1len = getNumberLength(x1);////// do dai cua chuoi tinh ca ki tu xuong dong ///// -1 de bot di ki tu xuong dong con x2 thi ko
	int x2len = getNumberLength(x2);
	printf("%s, %d\n", x1, x1len);
	printf("%s, %d\n", x2, x2len);
	
	int ylen = x1len;
	if (x2len > x1len) ylen = x2len
	ylen+=2
	char y[200] ;
	y[ylen - 1] = '\0';
	int k = ylen - 2;
	int i = x1len - 1;
	int j = x2len -1;
	int mem = 0;
		while (1){
			int r = 0; 
			if(i<0 && j<0) break;
			if(i<0) r = x2[j] - 48;
			else if ( j < 0) r= x1[i];
			else r = (x1[i] - 48) + (x2[j] - 48); /// -48 de chuyen char to number
			r += mem;
			char s = ((r%10) + 48); //// tao chuoi de lay hang don vi neu ma lon hon 10 roi cong 48 de no thanh ki tu so (+48 number to char)
			////char sum[] = {s, '\0'}
			/////strcat(sum, y); //// giup ghep chuoi voi nhau			
			//printf ("%s\n", r)
			y[k] = s;
			k--;
			if (r >= 10) mem = 1;
			else mem = 0;
			i--;
			j--;
		}
		if (mem==1) y[0] = '1';
		else y[0] = ' ';
		printf("%s", y)
		f = fopen("output.txt", "w");
		fprintf(f, "%s", y);
		fclose(f);
}
