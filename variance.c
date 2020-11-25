#include <stdio.h>
// 융합소프트웨어학부 2학년 60191686 정성훈 
double power(double x, int n) { // x의 n승에 해당되는 값을 구하는 함수 
	double return_value = 1; //  
	for(int i=1; i<=n; i++) { //n만큼 곱하는 로직 
		return_value *= x;
	}
	return return_value;
}

int main() {
	int array[5] = {1, 2, 3, 4, 5}; // 분산을 구하기 위한 정수 배열 초기화 
	double sum = 0, sum_of_deviation = 0; // 평균의 합과 편차 제곱의 합을 위한 변수 초기화 
	double mean, variance = 0.0; // 평균과 분산의 값을 할당할 변수 
	
	printf("융합소프트웨어학부 2학년 60191686 정성훈\n");
	for(int i=0; i<5; i++) { // 데이터들의 값을 평균을 구하기 위한 sum 변수에 더하는 로직 
		sum += array[i];
	}
	mean = sum/5.0; // 평균 구하는 식 => sum/N(N:은 데이터의 수) 
	
	for(int i=0; i<5; i++) {//편차 제곱의 합을 더하는 로직 
		sum_of_deviation += power(array[i] - mean, 2);//power함수 활용 
	}
	printf("Variance is %.2lf\n", sum_of_deviation/5.0); // 최종 출력 값 
	
	return 0;
}

