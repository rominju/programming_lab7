/*
LAB7. 동적메모리(개인 명세서 정리)
20183699 노민주 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tag//구조체 선언 
{
	char name[12];//이름
	char year[8];//생년월일 
	char month[8];
	char day[8];
	char gender[8];//성별
	char number[20];//전화번호
}Info;

int main()
{
	int n;
	Info*arr[10];
	printf("입력할 명세서의 개수를 입력하시오:");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)    // 요소 개수만큼 반복
	{
		arr[i] = malloc(sizeof(Info));    // 각 요소에 구조체 크기만큼 메모리 할당
	}

	int i = 0;
	printf("개별명세 입력 예시:홍길동 1995 10 20 남자 01012345678\n");//개별명세 입력 예시
	while (i < n)//개별명세 입력
	{

		printf("개별명세 입력%d:", i + 1);
		scanf("%s %s %s %s %s %s", &arr[i]->name, &arr[i]->year, &arr[i]->month, &arr[i]->day, &arr[i]->gender, &arr[i]->number);
		i++;
	}

	printf("\n입력자료를 그대로 출력>\n\n");	//입력자료 그대로 출력 
	printf(" 이름      생년월일      성별     전화번호\n");
	for (int i = 0; i < n; i++)
	{
		printf(" %s    %s/%s/%s    %s     %s\n", arr[i]->name, arr[i]->year, arr[i]->month, arr[i]->day, arr[i]->gender, arr[i]->number);
	}

	Info *temp = (Info*)malloc(sizeof(Info));

	for (int i = 1; i < n; i++)		//이름순으로 정렬
	{
		for (int j = i; j > 0 && strcmp(arr[j - 1]->name, arr[j]->name) > 0; j--)//문자열을 비교해서 정렬
		{
			temp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = temp;

		}
	}
	printf("\n이름 순으로 정렬>\n\n");		//이름순으로 출력 
	printf(" 이름      생년월일      성별     전화번호\n");
	for (int i = 0; i < n; i++)
	{
		printf(" %s    %s/%s/%s    %s     %s\n", arr[i]->name, arr[i]->year, arr[i]->month, arr[i]->day, arr[i]->gender, arr[i]->number);
	}


	for (int i = 1; i < n; i++)		//생년월일순으로 정렬
	{
		for (int j = i; j > 0 && strcmp(arr[j - 1]->year,arr[j]->year)>0; j--)//year을 비교해서 정렬 
		{
			temp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = temp;
		}

	}

	for (int i = 1; i < n; i++)		//year이 같을 때 month를 비교해서 정렬
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

	for (int i = 1; i < n; i++)		//year와 month가 같을때 day을 비교해서 정렬
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
	printf("\n생년월일 순으로 정렬>\n\n");	//생년월일순으로 출력 
	printf(" 이름      생년월일      성별     전화번호\n");
	for (int i = 0; i < n; i++)
	{
		printf(" %s    %s/%s/%s    %s     %s\n", arr[i]->name, arr[i]->year, arr[i]->month, arr[i]->day, arr[i]->gender, arr[i]->number);
	}

	return 0;
}
