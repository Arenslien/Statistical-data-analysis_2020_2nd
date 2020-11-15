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
	printf("ǥ��ȭ ����� ������ �����ϴ�.\n");
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
		printf("�ش� ��跮�� ���ؿ� ���� Ȯ�� ���� %.3lf�Դϴ�.\n", result);
	}
	else {
		printf("�ش� ��跮�� ���ؿ� ���� Ȯ�� ���� %.3lf�Դϴ�.\n", result);
	}
		printf("�ش� ��跮�� ���ؿ� ���� Ȯ�� ���� %.3lf%%�Դϴ�.\n",100*result);
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
	printf("�ּ� %.0lf���� ǥ���� �غ��ؾ� �մϴ�.\n", ceil(number_of_sample));
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
		printf("5. ����\n");
		START:
		printf("=====================================================\n");
		printf("������ ����� ��ȣ�� �Է����ּ���: ");
		scanf("%d", &number);
		
		switch(number)
		{
			case 1:
			{
				double mu, standard_deviation, x;
				char inequality;
				printf("=====================================================\n");
				printf("ǥ��ȭ�� ���� �⺻ ��跮�� ������ �Է����ּ���.\n");
				printf("ǥ�����(��)�� �Է����ּ���: ");
				scanf("%lf", &mu);
				printf("ǥ������(��)�� �Է����ּ���: ");
				scanf("%lf", &standard_deviation);
				printf("������ �Ǵ� Ȯ������(x)��  �Է����ּ���: ");
				scanf("%lf", &x);
				printf("�ε�ȣ�� �Է����ּ���: ");
				scanf("%s", &inequality);
				
				standardization(mu, standard_deviation, x, inequality);
				break;
			}
				
			case 2:
			{
				double mu, standard_deviation, x;
				char inequality;
				printf("=====================================================\n");
				printf("���Ժ��� Ȯ������� ���� �⺻ ��跮�� ������ �Է����ּ���.\n");
				printf("ǥ��ȭ�� ���� �⺻ ��跮�� ������ �Է����ּ���.\n");
				printf("ǥ�����(��)�� �Է����ּ���: ");
				scanf("%lf", &mu);
				printf("ǥ������(��)�� �Է����ּ���: ");
				scanf("%lf", &standard_deviation);
				printf("������ �Ǵ� Ȯ������(x)��  �Է����ּ���: ");
				scanf("%lf", &x);
				printf("�ε�ȣ�� �Է����ּ���: ");
				scanf("%s", &inequality);
				probability_calculation(standardization(mu, standard_deviation, x, inequality), inequality);
				break;
			}
			case 3:
			{
				double mu, standard_deviation, alpha;
				int n;
				printf("=====================================================\n");
				printf("����������  ���� �⺻ ��跮�� ������ �Է����ּ���.\n");
				printf("ǥ���� ����(n)�� �Է����ּ���: ");
				scanf("%d", &n);
				printf("ǥ�����(��)�� �Է����ּ���: ");
				scanf("%lf", &mu);
				printf("ǥ������(��)�� �Է����ּ���: ");
				scanf("%lf", &standard_deviation);
				printf("�ŷڵ���(90, 95, 99, 99.9�� ����) �Է����ּ���: ");
				scanf("%lf", &alpha);
				interval_estimation(n, mu, standard_deviation, alpha);
				break;
			}
			case 4:
			{
				double standard_error, alpha, standard_deviation;
				printf("=====================================================\n");
				printf("ǥ�� ũ�� ������ ���� �⺻ ��跮�� ������ �Է����ּ���.\n");
				printf("ǥ�ؿ���(SE)�� �Է����ּ���: ");
				scanf("%lf", &standard_error);
				printf("�ŷڵ���(90, 95, 99, 99.9�� ����) �Է����ּ���: ");
				scanf("%lf", &alpha);
				printf("ǥ������(��)�� �Է����ּ���: ");
				scanf("%lf", &standard_deviation);
				sample_num_decision(standard_error, alpha, standard_deviation);
				break;
			}
			case 5:
				printf("=====================================================\n");
				printf("���Ժ��� ���α׷��� �����մϴ�.");
				break;
			default:
				printf("=====================================================\n");
				printf("�ùٸ� �Է��� �ƴմϴ�. �ٽ� �Է����ּ���.\n");
				goto START;
		}
	} while(number != 5);
	return 0;
}
