#include <stdio.h>
 
int main(void)
{
	//기본 입력 배열 
	int array[9] = {1, 2, 3, 4, 9, 8, 7, 6, 5};
 
	
	//입력 배열 정렬(버블 정렬 사용 => 오름차순) 
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
	
	//이진 탐색 
	int left = 0, right = 9-1;
	int mid = (left+right+1)/2; //찾을 배열 범위의 가운데 인덱스 
	int search_number = 9; //찾을 숫자
	
	while(array[mid] != search_number) {
		if(right - left == 1) { // left 인덱스와 right 인덱스가 한 칸 차이 인데도 값이 없을 때 
			printf("%d는 입력된 배열 안에 없는 값입니다.", search_number);
			return 0;
		}
		if(array[mid] < search_number) { //찾을 숫자가 배열의 가운데 숫자보다 큰 경우 
			left = mid; // 좌측(left) 인덱스 값을 mid의 index로 변경 
		}
		else { //찾을 숫자가 배열의 가운데 숫자보다 작은 경우
			right = mid; // 우측(right) 인덱스 값을 mid의 index로 변경 
		}
		mid = (left+right+1)/2; // left or right의 값이 바뀌었으니 mid의 값도 재설정 
	}
	
	//결과 값 출력 
	printf("Finding number: %d", array[mid]);
	return 0;
}
