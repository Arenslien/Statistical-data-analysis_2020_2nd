// 융합소프트웨어학부 2학년 60191686 정성훈 - 스왑 
#include <stdio.h>

int main() {
	int a=20, b=1, t=0;
	printf("데이터 교환 전 : ");
	printf("%d %d \n", a, b);
	
	if(a > b) {
		t=a;
		a=b;
		b=t;
	} 
	printf("데이터 교환 후 : ");
	printf("%d %d \n", a, b);
	return 0; 
}
