#include <stdio.h>

int main(void) {
	int a[3] = {0, 0, 0};
	int i=0, sum=0;
	for(; i<3; i++) {
		a[i] = 100 * (i+1);
		sum += a[i];
		printf("%d ", a[i]);
	}
	printf("\n¹è¿­ ÃÑÇÕ = %d", sum);
	return 0;
}
