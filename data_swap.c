// ���ռ���Ʈ�����к� 2�г� 60191686 ������ - ���� 
#include <stdio.h>

int main() {
	int a=20, b=1, t=0;
	printf("������ ��ȯ �� : ");
	printf("%d %d \n", a, b);
	
	if(a > b) {
		t=a;
		a=b;
		b=t;
	} 
	printf("������ ��ȯ �� : ");
	printf("%d %d \n", a, b);
	return 0; 
}
