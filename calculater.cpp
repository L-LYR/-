#include<stdlib.h>
#include"operation.h"
int main(void)
{

	printf("*************************************************************************************************\n");
	printf("��������Ҫ���е����������ʽ��������1.0�汾��ֻ��������A + B�����Ķ�Ԫ�������ļӼ��˳��Լ��׳�Ŷ��\n");
	printf("*************************************************************************************************\n");
	int x[N*N + 1] = { 0 }, y[N + 1] = { 0 }, z[2 * N + 1] = { 0 }, n = 0, precision;
	bool flag;
	char op = input(x, y, &n);
	if (op == '!')
	{
		printf("%d", n);
		putchar(op);
		putchar('=');
		factorial(x, n);
		output(x);
	}
	else
	{
		if (op == '/')
		{
			printf("�����뾫��:");
			scanf_s("%d", &precision);
		}
		output(x);
		putchar(op);
		output(y);
		putchar('=');
		switch (op)
		{
		case '+':plus(x, y); output(x); break;
		case'-':
			if (flag = compare(x, y))
			{
				minus(x, y);
				output(x);
			}
			else
			{
				printf("-");//����
				minus(y, x);
				output(y);
			}
			break;
		case'*':multiply(x, y, z); output(z); break;
		case'/':
			if (precision == 0)
			{
				divide(x, y, z);
				output(z);
				printf("����");
				output(x);
				break;
			}
			else
			{
				divide_decimal(x, y, z, precision);
				output(z);
				break;
			}
		}
	}
	printf("\n");
	system("pause");
	return 0;
}