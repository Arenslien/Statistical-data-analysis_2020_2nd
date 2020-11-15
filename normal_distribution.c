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
		printf("�ٸ� ���İ��� �ش�Ǵ� z�� �����ϴ�. �ٽ� �Է����ּ���.\n");
	}
	return z;
}

//ǥ��ȭ
//���, ���� ����?, ǥ������
//�Է� �ش� �������� ǥ�����, ǥ��ǥ������, ��������, ũ�� ����? 
//��� ���� ���� �������
double standardization(double mu, double standard_deviation, double x, char inequality)
{
	double z = (x - mu)/standard_deviation;
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

//���Ժ����� Ȯ�����
//ǥ��ȭ�� Ȱ���ؼ� ���
//ǥ�����Ժ���ǥ�� Ȱ���ؼ� ���� ���ϱ⸸ �ϸ�� 
double probability_calculation(double z, char inequality)
{
	const double START_VALUE = -6.0; //6 �ñ׸� ����
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
		printf("%.3lf\n", result);
	}
	else {
		printf("%.3lf\n", result);
	}
		printf("%.3lf%%\n",100*result);
	return result;
}

//���� ����
void interval_estimation(int n, double mu, double standard_deviation, double alpha)
{
	double z = convert_alpha_to_z(alpha);
	printf("%.2lf < �� < %.2lf\n", mu-z*(standard_deviation/sqrt(n)), mu+z*(standard_deviation/sqrt(n)));
}

//ǥ���� ũ�� ���� 
int sample_num_decision(double standard_error, double alpha, double standard_deviation)
{
	double z = convert_alpha_to_z(alpha);

	double number_of_sample = pow(z*standard_deviation/standard_error, 2);
	printf("%d\n", ceil(number_of_sample));
	return ceil(number_of_sample);
}

int main(void)
{
	int number;
	do
	{
		printf("=====================================================\n");
		printf("���Ժ��� ���� ����� �����Ͽ� ������ �� �ֽ��ϴ�.\n");
		printf("1. ǥ��ȭ\n");
		printf("2. ���Ժ��� Ȯ�����\n");
		printf("3. ���� ����\n");
		printf("4. ǥ�� ũ�� ����\n");
		printf("0. ����");
		printf("=====================================================\n");
		printf("������ ����� ��ȣ�� �Է����ּ���: ");
		scanf("%d", &number);
		
		switch(number)
		{
			case 1:
				printf("ǥ��ȭ�� ���� �⺻ ��跮�� ������ �Է����ּ���.\n");
				break;
			case 2:
				printf("���Ժ��� Ȯ������� ���� �⺻ ��跮�� ������ �Է����ּ���.\n");
				break;
			case 3:
				printf("����������  ���� �⺻ ��跮�� ������ �Է����ּ���.\n");
				break;
			case 4:
				printf("ǥ�� ũ�� ������ ���� �⺻ ��跮�� ������ �Է����ּ���.\n");
				break;
			default:
				printf("�ùٸ� �Է��� �ƴմϴ�. �ٽ� �Է����ּ���."); 
		}
	} while(number != 0);
	//ǥ��ȭ
	//���ϰ��� �ϴ� Ȯ���� ǥ�����Ժ����� �����ϰ� �ϴ� ���

	//���Ժ��� Ȯ�����
	probability_calculation(standardization(170, 10, 185, '>'), '>');
	interval_estimation(200, 30000, 500, 95.0);
	sample_num_decision(100, 99, 150);
	//��������
	
	//ǥ���� ũ�� ����
	
	return 0;
}
