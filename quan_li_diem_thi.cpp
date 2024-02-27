#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
class thisinh{
	char ten[25];
	double toan,li,hoa;
	int id;
	public:
		void nhapdl(int id);
		void inkq(){
			printf("\n%d",id);
			printf("\n%s",ten);
			printf("\n%.2lf %.2lf %.2lf",toan,li,hoa);
			printf("\n");
			printf("%.2lf",getSum());
		};
		double getSum(){
			return toan + li + hoa;
		}
};
void thisinh::nhapdl(int id){
	this->id = id;
	printf("\nTen: ");
	scanf("%s",&ten);
	printf("\nDiemToan: ");
	scanf("%lf",&toan);
	printf("\nDiemLi: ");
	scanf("%lf",&li);
	printf("\nDiemHoa: ");
	scanf("%lf",&hoa);
}
int main(int argc, const char**argv){
	int n;
	printf("Nhap vao so thi sinh: ");
	scanf("%d",&n);
	thisinh *dsts = new thisinh[n];
	for ( int i = 0 ; i < n ; i++ ){
		printf("Nhap du lieu cho thi sinh thu %d",(i+1));
		dsts[i].nhapdl(i+1);
	}
	printf("Cac thi sinh trung tuyen la: ");
	for ( int i = 0 ; i < n ; i++ ){
		if (dsts[i].getSum() >= 18) dsts[i].inkq();
	}
	
}
