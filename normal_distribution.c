#include <stdio.h>
#include <math.h>

double convert_alpha_to_z(double alpha)
{
	double z = 0.0;
	if(alpha == 90.0)
	{
		z = 1.64;
	}
	else if(alpha == 95.0)
	{
		z = 1.96;
	}
	else if(alpha == 99.0)
	{
		z = 2.58;
	}
	else if(alpha == 99.9)
	{
		z = 3.30;
	}
	else
	{
		printf("다른 알파값에 해당되는 z는 없습니다. 다시 입력해주세요.\n");
	}
	return z;
}

//표준화
//평균, 기준 범위?, 표준편차
//입력 해당 데이터의 표본평균, 표본표준편차, 범위기준, 크고 작음? 
//결과 값은 없고 출력으로
double standardization(double mu, double standard_deviation, double x, char inequality)
{
	double z = (x - mu)/standard_deviation;
	printf("표준화 결과는 다음과 같습니다.\n");
	if(inequality == '>') //x > mu => inequality = '>'
	{ 	
		printf("P(z > %.2lf)\n", z);
	}
	else //x < mu => inequality = '<'
	{ 	
		printf("P(z < %.2lf)\n", z);
	}
	return z;
}

//정규분포의 확률계산
//표준화를 활용해서 계산
//표준정규분포표를 활용해서 값을 구하기만 하면됨 
double probability_calculation(double z, char inequality)
{
	const double START_VALUE = -6.0; //6 시그마 기준
	const double INTERVAL = 0.00001;
	const double PI = 3.141592;
	double result = 0.0; 
	for(double i=START_VALUE; i<z; i+=INTERVAL)
	{
		result += INTERVAL * ((1.0/sqrt(2*PI)) * exp(-(i*i/2.0)));
	}

	if(inequality == '>')
	{
		result = 1-result;
		printf("해당 통계량과 기준에 대한 확률 값은 %.3lf입니다.\n", result);
	}
	else {
		printf("해당 통계량과 기준에 대한 확률 값은 %.3lf입니다.\n", result);
	}
		printf("해당 통계량과 기준에 대한 확률 값은 %.3lf%%입니다.\n",100*result);
	return result;
}

//구간 추정
void interval_estimation(int n, double mu, double standard_deviation, double alpha)
{
	double z = convert_alpha_to_z(alpha);
	printf("%.2lf < μ < %.2lf\n", mu-z*(standard_deviation/sqrt(n)), mu+z*(standard_deviation/sqrt(n)));
}

//표본의 크기 결정 
int sample_num_decision(double standard_error, double alpha, double standard_deviation)
{
	double z = convert_alpha_to_z(alpha);

	double number_of_sample = pow(z*standard_deviation/standard_error, 2);
	printf("최소 %.0lf개의 표본을 준비해야 합니다.\n", ceil(number_of_sample));
	return ceil(number_of_sample);
}

int main(void)
{
	int number;
	do
	{

		printf("=====================================================\n");
		printf("정규분포 관련 기능을 선택하여 수행할 수 있습니다.\n");
		printf("1. 표준화\n");
		printf("2. 정규분포 확률계산\n");
		printf("3. 구간 추정\n");
		printf("4. 표본 크기 결정\n");
		printf("5. 종료\n");
		START:
		printf("=====================================================\n");
		printf("수행할 기능의 번호를 입력해주세요: ");
		scanf("%d", &number);
		
		switch(number)
		{
			case 1:
			{
				double mu, standard_deviation, x;
				char inequality;
				printf("=====================================================\n");
				printf("표준화를 위한 기본 통계량과 정보를 입력해주세요.\n");
				printf("표본평균(μ)을 입력해주세요: ");
				scanf("%lf", &mu);
				printf("표준편차(σ)를 입력해주세요: ");
				scanf("%lf", &standard_deviation);
				printf("기준이 되는 확률변수(x)를  입력해주세요: ");
				scanf("%lf", &x);
				printf("부등호를 입력해주세요: ");
				scanf("%s", &inequality);
				
				standardization(mu, standard_deviation, x, inequality);
				break;
			}
				
			case 2:
			{
				double mu, standard_deviation, x;
				char inequality;
				printf("=====================================================\n");
				printf("정규분포 확률계산을 위한 기본 통계량과 정보를 입력해주세요.\n");
				printf("표준화를 위한 기본 통계량과 정보를 입력해주세요.\n");
				printf("표본평균(μ)을 입력해주세요: ");
				scanf("%lf", &mu);
				printf("표준편차(σ)를 입력해주세요: ");
				scanf("%lf", &standard_deviation);
				printf("기준이 되는 확률변수(x)를  입력해주세요: ");
				scanf("%lf", &x);
				printf("부등호를 입력해주세요: ");
				scanf("%s", &inequality);
				probability_calculation(standardization(mu, standard_deviation, x, inequality), inequality);
				break;
			}
			case 3:
			{
				double mu, standard_deviation, alpha;
				int n;
				printf("=====================================================\n");
				printf("구간추정을  위한 기본 통계량과 정보를 입력해주세요.\n");
				printf("표본의 개수(n)를 입력해주세요: ");
				scanf("%d", &n);
				printf("표본평균(μ)을 입력해주세요: ");
				scanf("%lf", &mu);
				printf("표준편차(σ)를 입력해주세요: ");
				scanf("%lf", &standard_deviation);
				printf("신뢰도를(90, 95, 99, 99.9만 가능) 입력해주세요: ");
				scanf("%lf", &alpha);
				interval_estimation(n, mu, standard_deviation, alpha);
				break;
			}
			case 4:
			{
				double standard_error, alpha, standard_deviation;
				printf("=====================================================\n");
				printf("표본 크기 결정을 위한 기본 통계량과 정보를 입력해주세요.\n");
				printf("표준오차(SE)를 입력해주세요: ");
				scanf("%lf", &standard_error);
				printf("신뢰도를(90, 95, 99, 99.9만 가능) 입력해주세요: ");
				scanf("%lf", &alpha);
				printf("표준편차(σ)를 입력해주세요: ");
				scanf("%lf", &standard_deviation);
				sample_num_decision(standard_error, alpha, standard_deviation);
				break;
			}
			case 5:
				printf("=====================================================\n");
				printf("정규분포 프로그램을 종료합니다.");
				break;
			default:
				printf("=====================================================\n");
				printf("올바른 입력이 아닙니다. 다시 입력해주세요.\n");
				goto START;
		}
	} while(number != 5);
	return 0;
}
