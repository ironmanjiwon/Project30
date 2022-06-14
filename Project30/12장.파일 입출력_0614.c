//12장. 파일 입출력

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE* fp = NULL;

	fp = fopen("sample.txt", "w");

	if (fp == NULL)
		printf("파일 열기 실패\n");
	else
		printf("파일 열기 성공\n");

	fclose(fp);

	return 0;
}

//"C:\Users\ironm\source\repos\Project30\Project30\sample.txt"


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp = NULL;
	char c;
	
	fp = fopen("alphabet.txt", "w");

	if (fp == NULL)
	{
		fprintf(stderr, "파일 열 수 X\n");
		exit(1);
	}

	for (c = 'a'; c <= 'z'; c++)
		fputc(c, fp);

	fclose(fp);

	return 0;
}

//"C:\Users\ironm\source\repos\Project30\Project30\alphabet.txt"


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp = NULL;
	int c;

	fp = fopen("alphabet.txt", "r");
	if (fp == NULL)
	{
		fprintf(stderr, "원본 파일 열 수 X\n");
		exit(1);
	}

	while ((c = fgetc(fp)) != EOF)
		putchar(c);
	fclose(fp);

	return 0;
}

//abcdefghijklmnopqrstuvwxyz


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE* fp;
	char str[100];
	fp = fopen("file.txt", "w");

	if (fp == NULL)
	{
		fprintf(stderr, "파일 열 수 X\n");
		exit(0);
	}

	do
	{
		gets_s(str, sizeof(str));
		fputs(str, fp);
	} while (strlen(str) != 0);

	fclose(fp);

	return 0;
}

//abcdefgh
//ijklmnop


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp1, * fp2;

	char file1[100], file2[100];
	char buffer[100];

	int c;
	printf("원본 파일 이름: ");
	scanf("%s", file1);

	printf("복사 파일 이름: ");
	scanf("%s", file2);

	if ((fp1 = fopen(file1, "r")) == NULL)
	{
		fprintf(stderr, "원본 파일 열 수 X\n", file1);
		exit(1);
	}

	if ((fp2 = fopen(file2, "w")) == NULL)
	{
		fprintf(stderr, "복사 파일 열 수 X\n", file2);
		exit(1);
	}

	while ((c = fgetc(fp1)) != EOF)
		fputc(c, fp2);

	fclose(fp1);
	fclose(fp2);

	return 0;
}

//원본 파일 이름 : alphabet.txt
//복사 파일 이름 : alphabet1.txt


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE* fp;
	fp = fopen("sales.txt", "a");
	fprintf(fp, "2022.06.14 매출: %d \n", 200000);

	fclose(fp);

	return 0;
}

//"C:\Users\ironm\source\repos\Project30\Project30\sales.txt"


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp;
	int number;
	char name[30];

	int score;
	char ch;

	fp = fopen("scores.txt", "w");
	if (fp == NULL)
	{
		printf("성적 파일 열 수 X\n");
		exit(0);
	}

	do
	{
		printf("\n학번: ");
		scanf("%d", &number);

		printf("이름: ");
		scanf("%s", name);

		printf("성적: ");
		scanf("%d", &score);

		fprintf(fp, "%d %s %d\n", number, name, score);
		printf("데이터 추가를 계속? (y/n): ");
		ch = _getch();
	} while (ch != 'n');

	fclose(fp);

	return  0;
}

//학번: 2
//이름 : SON
//성적 : 20
//데이터 추가를 계속 ? (y / n) :


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

int main(void)
{
	int buffer[] = { 10,20,30,40,50,60,70,80,90,100 };
	FILE* fp = NULL;

	fp = fopen("binary.bin", "wb");

	if (fp == NULL)
	{
		fprintf(stderr, "파일 열 수 X\n");
		return 1;
	}

	fwrite(buffer, sizeof(int), SIZE, fp);
	fclose(fp);

	return 0;
}

//"C:\Users\ironm\source\repos\Project30\Project30\binary.bin"


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

int main(void)
{
	int buffer[SIZE];
	FILE* fp = NULL;
	int i;

	fp = fopen("binary.bin", "rb");
	if (fp == NULL)
	{
		fprintf(stderr, "binary.bin 파일 열 수 X");

		return 1;
	}
	fread(buffer, sizeof(int), SIZE, fp);

	for (i = 0; i < SIZE; i++)
		printf("%d ", buffer[i]);
	fclose(fp);
}
	//10 20 30 40 50 60 70 80 90 100


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

int main(void)
{
	HDC hdc = GetWindowDC(GetForegroundWindow());
	int r, c, red, green, blue;
	char image[512][512];

	FILE* fp = fopen("D:/images/lena(512x512).raw", "rb");

	if (fp == NULL)
	{
		printf("파일 열 수 X");
		exit(1);
	}
	fread(image, 1, 512 * 512, fp);
	fclose(fp);

	for (r = 0; r < 512; r++)
	{
		for (c = 0; c < 512; c++)
		{
			red = image[r][c];
			green = image[r][c];
			blue = image[r][c];

			SetPixel(hdc, c, r, RGB(red, green, blue));
		}
	}
}

//파일 열림


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	long length;

	FILE* fp = fopen("D:/images/lena(512x512).raw", "rb");

	if (fp == NULL)
	{
		printf("파일 열 수 X");
		return 1;
	}
	fseek(fp, 0, SEEK_END);

	length = ftell(fp);
	printf("파일 크기=%d 바이트\n", length);

	fclose(fp);

	return 0;
}

//파일 크기=262144 바이트(262KB)


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE* fp;
	fp = fopen("data.txt", "w");

	if (fp == NULL)
	{
		printf("파일 열 수 X");
		return 1;
	}
	fputs("This is an house.", fp);
	fseek(fp, 11, SEEK_SET);
	fputs("apple", fp);

	fclose(fp);

	return 0;
}

//"C:\Users\ironm\source\repos\Project30\Project30\data.txt"
