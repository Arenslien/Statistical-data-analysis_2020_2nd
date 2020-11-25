#include <stdio.h>
// ���ռ���Ʈ�����к� 2�г� 60191686 ������ 
double power(double x, int n) { // x�� n�¿� �ش�Ǵ� ���� ���ϴ� �Լ� 
	double return_value = 1; //  
	for(int i=1; i<=n; i++) { //n��ŭ ���ϴ� ���� 
		return_value *= x;
	}
	return return_value;
}

int main() {
	int array[5] = {1, 2, 3, 4, 5}; // �л��� ���ϱ� ���� ���� �迭 �ʱ�ȭ 
	double sum = 0, sum_of_deviation = 0; // ����� �հ� ���� ������ ���� ���� ���� �ʱ�ȭ 
	double mean, variance = 0.0; // ��հ� �л��� ���� �Ҵ��� ���� 
	
	printf("���ռ���Ʈ�����к� 2�г� 60191686 ������\n");
	for(int i=0; i<5; i++) { // �����͵��� ���� ����� ���ϱ� ���� sum ������ ���ϴ� ���� 
		sum += array[i];
	}
	mean = sum/5.0; // ��� ���ϴ� �� => sum/N(N:�� �������� ��) 
	
	for(int i=0; i<5; i++) {//���� ������ ���� ���ϴ� ���� 
		sum_of_deviation += power(array[i] - mean, 2);//power�Լ� Ȱ�� 
	}
	printf("Variance is %.2lf\n", sum_of_deviation/5.0); // ���� ��� �� 
	
	return 0;
}

