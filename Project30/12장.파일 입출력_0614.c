//12��. ���� �����

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE* fp = NULL;

	fp = fopen("sample.txt", "w");

	if (fp == NULL)
		printf("���� ���� ����\n");
	else
		printf("���� ���� ����\n");

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
		fprintf(stderr, "���� �� �� X\n");
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
		fprintf(stderr, "���� ���� �� �� X\n");
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
		fprintf(stderr, "���� �� �� X\n");
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
	printf("���� ���� �̸�: ");
	scanf("%s", file1);

	printf("���� ���� �̸�: ");
	scanf("%s", file2);

	if ((fp1 = fopen(file1, "r")) == NULL)
	{
		fprintf(stderr, "���� ���� �� �� X\n", file1);
		exit(1);
	}

	if ((fp2 = fopen(file2, "w")) == NULL)
	{
		fprintf(stderr, "���� ���� �� �� X\n", file2);
		exit(1);
	}

	while ((c = fgetc(fp1)) != EOF)
		fputc(c, fp2);

	fclose(fp1);
	fclose(fp2);

	return 0;
}

//���� ���� �̸� : alphabet.txt
//���� ���� �̸� : alphabet1.txt


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE* fp;
	fp = fopen("sales.txt", "a");
	fprintf(fp, "2022.06.14 ����: %d \n", 200000);

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
		printf("���� ���� �� �� X\n");
		exit(0);
	}

	do
	{
		printf("\n�й�: ");
		scanf("%d", &number);

		printf("�̸�: ");
		scanf("%s", name);

		printf("����: ");
		scanf("%d", &score);

		fprintf(fp, "%d %s %d\n", number, name, score);
		printf("������ �߰��� ���? (y/n): ");
		ch = _getch();
	} while (ch != 'n');

	fclose(fp);

	return  0;
}

//�й�: 2
//�̸� : SON
//���� : 20
//������ �߰��� ��� ? (y / n) :


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
		fprintf(stderr, "���� �� �� X\n");
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
		fprintf(stderr, "binary.bin ���� �� �� X");

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
		printf("���� �� �� X");
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

//���� ����


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	long length;

	FILE* fp = fopen("D:/images/lena(512x512).raw", "rb");

	if (fp == NULL)
	{
		printf("���� �� �� X");
		return 1;
	}
	fseek(fp, 0, SEEK_END);

	length = ftell(fp);
	printf("���� ũ��=%d ����Ʈ\n", length);

	fclose(fp);

	return 0;
}

//���� ũ��=262144 ����Ʈ(262KB)


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE* fp;
	fp = fopen("data.txt", "w");

	if (fp == NULL)
	{
		printf("���� �� �� X");
		return 1;
	}
	fputs("This is an house.", fp);
	fseek(fp, 11, SEEK_SET);
	fputs("apple", fp);

	fclose(fp);

	return 0;
}

//"C:\Users\ironm\source\repos\Project30\Project30\data.txt"
