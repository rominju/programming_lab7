/*
LAB7. �����޸�(���� ���� ����)
20183699 ����� 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tag//����ü ���� 
{
	char name[12];//�̸�
	char year[8];//������� 
	char month[8];
	char day[8];
	char gender[8];//����
	char number[20];//��ȭ��ȣ
}Info;

int main()
{
	int n;
	Info*arr[10];
	printf("�Է��� ������ ������ �Է��Ͻÿ�:");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)    // ��� ������ŭ �ݺ�
	{
		arr[i] = malloc(sizeof(Info));    // �� ��ҿ� ����ü ũ�⸸ŭ �޸� �Ҵ�
	}

	int i = 0;
	printf("������ �Է� ����:ȫ�浿 1995 10 20 ���� 01012345678\n");//������ �Է� ����
	while (i < n)//������ �Է�
	{

		printf("������ �Է�%d:", i + 1);
		scanf("%s %s %s %s %s %s", &arr[i]->name, &arr[i]->year, &arr[i]->month, &arr[i]->day, &arr[i]->gender, &arr[i]->number);
		i++;
	}

	printf("\n�Է��ڷḦ �״�� ���>\n\n");	//�Է��ڷ� �״�� ��� 
	printf(" �̸�      �������      ����     ��ȭ��ȣ\n");
	for (int i = 0; i < n; i++)
	{
		printf(" %s    %s/%s/%s    %s     %s\n", arr[i]->name, arr[i]->year, arr[i]->month, arr[i]->day, arr[i]->gender, arr[i]->number);
	}

	Info *temp = (Info*)malloc(sizeof(Info));

	for (int i = 1; i < n; i++)		//�̸������� ����
	{
		for (int j = i; j > 0 && strcmp(arr[j - 1]->name, arr[j]->name) > 0; j--)//���ڿ��� ���ؼ� ����
		{
			temp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = temp;

		}
	}
	printf("\n�̸� ������ ����>\n\n");		//�̸������� ��� 
	printf(" �̸�      �������      ����     ��ȭ��ȣ\n");
	for (int i = 0; i < n; i++)
	{
		printf(" %s    %s/%s/%s    %s     %s\n", arr[i]->name, arr[i]->year, arr[i]->month, arr[i]->day, arr[i]->gender, arr[i]->number);
	}


	for (int i = 1; i < n; i++)		//������ϼ����� ����
	{
		for (int j = i; j > 0 && strcmp(arr[j - 1]->year,arr[j]->year)>0; j--)//year�� ���ؼ� ���� 
		{
			temp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = temp;
		}

	}

	for (int i = 1; i < n; i++)		//year�� ���� �� month�� ���ؼ� ����
	{
		for (int j = i; j > 0; j--)
		{
			if (strcmp(arr[j - 1]->year,arr[j]->year)==0 && strcmp(arr[j - 1]->month, arr[j]->month)>0)

			{
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}

	}

	for (int i = 1; i < n; i++)		//year�� month�� ������ day�� ���ؼ� ����
	{
		for (int j = i; j > 0; j--)
		{
			if (strcmp(arr[j - 1]->year,arr[j]->year)==0 && strcmp(arr[j - 1]->month, arr[j]->month)==0&& strcmp(arr[j - 1]->day, arr[j]->day)>0)

			{
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}

	}
	printf("\n������� ������ ����>\n\n");	//������ϼ����� ��� 
	printf(" �̸�      �������      ����     ��ȭ��ȣ\n");
	for (int i = 0; i < n; i++)
	{
		printf(" %s    %s/%s/%s    %s     %s\n", arr[i]->name, arr[i]->year, arr[i]->month, arr[i]->day, arr[i]->gender, arr[i]->number);
	}

	return 0;
}
