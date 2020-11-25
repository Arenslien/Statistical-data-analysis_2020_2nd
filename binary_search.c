#include <stdio.h>
 
int main(void)
{
	//�⺻ �Է� �迭 
	int array[9] = {1, 2, 3, 4, 9, 8, 7, 6, 5};
 
	
	//�Է� �迭 ����(���� ���� ��� => ��������) 
	for(int i=0; i<9-1; i++) {
		for(int j=0; j<9-(i+1); j++) {
			if(array[j] > array[j+1]) {
				int tmp;
				tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}
		}
	}
	
	//���� Ž�� 
	int left = 0, right = 9-1;
	int mid = (left+right+1)/2; //ã�� �迭 ������ ��� �ε��� 
	int search_number = 9; //ã�� ����
	
	while(array[mid] != search_number) {
		if(right - left == 1) { // left �ε����� right �ε����� �� ĭ ���� �ε��� ���� ���� �� 
			printf("%d�� �Էµ� �迭 �ȿ� ���� ���Դϴ�.", search_number);
			return 0;
		}
		if(array[mid] < search_number) { //ã�� ���ڰ� �迭�� ��� ���ں��� ū ��� 
			left = mid; // ����(left) �ε��� ���� mid�� index�� ���� 
		}
		else { //ã�� ���ڰ� �迭�� ��� ���ں��� ���� ���
			right = mid; // ����(right) �ε��� ���� mid�� index�� ���� 
		}
		mid = (left+right+1)/2; // left or right�� ���� �ٲ������ mid�� ���� �缳�� 
	}
	
	//��� �� ��� 
	printf("Finding number: %d", array[mid]);
	return 0;
}
