#include <stdio.h>

int main(void) {
	int array1[4] = {40, 30, 10, 20};
	
	for(int i=0; i<4-1; i++) {
		for(int j=0; j<4-i-1; j++) {
			int cnt = 0;
			if(array1[j] < array1[j+1]) {
				cnt = array1[j];
				array1[j] = array1[j+1];
				array1[j+1] = cnt;
			}
		}
	}
	printf("�迭�� �� �������� ���� ���\n");
	for(int i=0; i<4; i++) {
		printf("%d ", array1[i]);
	} 
	
	
	return 0;
}




