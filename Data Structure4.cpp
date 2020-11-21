
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<iostream>
using namespace std;

#define CODE_NUMBER 56

typedef char** HuffmanCode;

typedef struct CW
{
	char num;
	int count;
	int charNum;
}CCounter, * CharCounter;

typedef struct HT
{
	char ch;
	int weight, lchild, rchild, parent;
}HTNode, * HuffmanTree;

CharCounter cc = new CCounter[CODE_NUMBER];

char sourceFileName[64];
//C:\Users\admin\code.txt

int FileChoose()
{
	FILE* fp;
	bool isFileOpen = false;
	char singleChar;
	while (!isFileOpen)
	{
		printf("�������ļ�����·��:");
		scanf("%s", sourceFileName);
		if ((fp = fopen(sourceFileName, "r")) == NULL)
		{
			printf("�ļ��򿪴��������ԣ�");
			continue;
		}
		isFileOpen = true;
	}
	for (int i = 0; i < CODE_NUMBER; i++)
	{
		cc[i].num = '\0';
		cc[i].count = 0;
	}
	int CharNum = 0;
	while ((singleChar = fgetc(fp)) != EOF)
	{
		for (int i = 0; i < CODE_NUMBER; i++)
		{
			if (singleChar == cc[i].num)
			{
				cc[i].count++;
				break;
			}
			if (i == CODE_NUMBER - 1 && cc[CODE_NUMBER - 1].num != singleChar)
			{
				cc[CharNum].num = singleChar;
				cc[CharNum].count++;
				CharNum++;
				continue;
			}
		}
	}
	printf("�ļ���ȡ�ɹ���\n");
	fclose(fp);
	cc[0].charNum = CharNum;
	return CharNum;
}

void Select(HuffmanTree& HT, int num, int* S1, int* S2)
{
	int firstMin = 0, secondMin = 0;
	int findFirst = -1, findSecond = -1;
	HTNode N1, N2;
	int i;
	for (i = num; i >= 1; i--)
	{
		if (HT[i].parent == 0 && findSecond == -1)
		{
			findSecond = i;
		}
		else if (HT[i].parent == 0 && findFirst == -1)
		{
			findFirst = i;
		}

		if (findFirst != -1 && findSecond != -1)
		{
			break;
		}
	}

	if (HT[findSecond].weight > HT[findFirst].weight)
	{
		N1 = HT[findSecond];
		N2 = HT[findFirst];
		firstMin = findFirst;
		secondMin = findSecond;
	}
	else
	{
		N1 = HT[findFirst];
		N2 = HT[findSecond];
		firstMin = findSecond;
		secondMin = findFirst;
	}

	for (i = num; i >= 1; i--)
	{
		if ((HT[i].weight < N2.weight) && (HT[i].parent == 0) && i != findSecond && i != findFirst)
		{
			N1 = N2;
			N2 = HT[i];
			secondMin = firstMin;
			firstMin = i;
		}
		else if ((HT[i].weight < N1.weight) && (HT[i].parent == 0) && i != findSecond && i != findFirst)
		{
			N1 = HT[i];
			secondMin = i;
		}
	}
	*S1 = firstMin;
	*S2 = secondMin;
}

void CreateHuffmanTree(HuffmanTree& HT, int childNodeNum)
{
	if (childNodeNum <= 1)
	{
		printf("��������󣡴���ʧ�ܣ�\n");
		return;
	}
	int allNodeNum = childNodeNum * 2 - 1;
	HT = new HTNode[allNodeNum + 1];
	int i;
	for (i = 1; i <= allNodeNum; i++)
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (i = 1; i <= childNodeNum; i++)
	{
		HT[i].ch = cc[i - 1].num;
		HT[i].weight = cc[i - 1].count;
	}
	int S1, S2;
	for (i = childNodeNum + 1; i <= allNodeNum; i++)
	{
		Select(HT, i - 1, &S1, &S2);
		HT[S1].parent = i;
		HT[S2].parent = i;
		HT[i].lchild = S1;
		HT[i].rchild = S2;
		HT[i].weight = HT[S1].weight + HT[S2].weight;
	}
	printf("�������������ɹ���\n");
	return;
}

void CreateHuffmanCode(HuffmanTree& HT, HuffmanCode& HC, int charNum)
{
	char fileName[64];
	printf("���������뱾�ļ��ı���·��:");
	scanf("%s", fileName);
	FILE* fp;
	bool isFileOpen = false;
	while (!isFileOpen)
	{
		if ((fp = fopen(fileName, "w")) == NULL)
		{
			printf("�ļ��򿪴���!������\n");
			continue;
		}
		isFileOpen = true;
	}
	HC = new char* [charNum + 1];
	char* cd = new char[charNum];
	cd[charNum - 1] = '\0';
	int start, arrNum, parentNum;
	char ch;
	for (int i = 1; i <= charNum; i++)
	{
		start = charNum - 1;
		arrNum = i;
		parentNum = HT[i].parent;
		ch = HT[i].ch;
		while (parentNum != 0)
		{
			start--;
			if (HT[parentNum].lchild == arrNum)
			{
				cd[start] = '0';
			}
			else
			{
				cd[start] = '1';
			}
			arrNum = parentNum;
			parentNum = HT[parentNum].parent;
		}
		HC[i] = new char[charNum - start];
		strcpy(HC[i], &cd[start]);
		fprintf(fp, "%c %s\n", ch, &cd[start]);
	}
	delete[] cd;
	fclose(fp);
	printf("���뱾�ļ�����ɹ���\n");
	FILE* codefp, * sourcefp;
	char codeFileName[64];
	isFileOpen = false;
	while (!isFileOpen)
	{
		printf("����������ļ�����·��:");
		scanf("%s", codeFileName);
		if ((codefp = fopen(codeFileName, "w")) == NULL)
		{
			printf("�����ļ��򿪴��������ԣ�\n");
			continue;
		}
		isFileOpen = true;
	}
	isFileOpen = false;
	while (!isFileOpen)
	{
		if ((sourcefp = fopen(sourceFileName, "r")) == NULL)
		{
			printf("Դ���ļ��򿪴��������ԣ�\n");
			scanf("%s", sourceFileName);
			continue;
		}
		isFileOpen = true;
	}
	char singleChar;
	while ((singleChar = fgetc(sourcefp)) != EOF)
	{
		for (int i = 0; i < cc[0].charNum; i++)
		{
			if (singleChar == cc[i].num)
			{
				fprintf(codefp,"%s",HC[i+1]);
			}
		}
	}
	printf("�����ļ�����ɹ���\n");
	fclose(codefp);
	fclose(sourcefp);
}

void TranslateCode(HuffmanTree& HT,int childNodeNum)
{
	int allNodeNum = 2 * childNodeNum - 1;
	FILE *codefp;
	char fileName[64];
	bool isFileOpen = false;
	while (!isFileOpen)
	{
		printf("��������Ҫ������ļ�·��:");
		scanf("%s", fileName);
		if ((codefp = fopen(fileName, "r")) == NULL)
		{
			printf("�ļ��򿪴��������ԣ�\n");
			continue;
		}
		isFileOpen = true;
	}
	FILE *finalfp;
	char finalfileName[64];
	isFileOpen = false;
	while (!isFileOpen)
	{
		printf("�����������ļ�����·��:");
		scanf("%s", finalfileName);
		if ((finalfp = fopen(finalfileName, "w")) == NULL)
		{
			printf("�ļ��򿪴��������ԣ�");
			continue;
		}
		isFileOpen = true;
	}
	char singleChar;
	int arrNum = allNodeNum;
	while ((singleChar = fgetc(codefp)) != EOF)
	{
		if (singleChar == '0')
		{
			arrNum = HT[arrNum].lchild;
		}
		else
		{
			arrNum = HT[arrNum].rchild;
		}

		if ((HT[arrNum].lchild == 0) && (HT[arrNum].rchild == 0))
		{
			fprintf(finalfp,"%c",HT[arrNum]);
			arrNum = allNodeNum;
		}
	}
	printf("����ɹ���\n");
	fclose(codefp);
	fclose(finalfp);
}

void CompressFile()
{
	FILE* codefp, * pressfp;
	char codeFileName[64], pressFileName[64];
	bool isFileOpen = false;
	while (!isFileOpen)
	{
		printf("����������ļ�·��:");
		scanf("%s",codeFileName);
		if ((codefp = fopen(codeFileName, "r")) == NULL)
		{
			printf("�ļ��򿪴��������ԣ�\n");
			continue;
		}
		isFileOpen = true;
	}
	isFileOpen = false;
	while (!isFileOpen)
	{
		printf("������ѹ���ļ�����·��:");
		scanf("%s",pressFileName);
		if ((pressfp = fopen(pressFileName, "w")) == NULL)
		{
			printf("�ļ��򿪴��������ԣ�\n");
			continue;
		}
		isFileOpen = true;
	}
	int sum = 0, in = 0;
	int twopower[11] = { 1,2,4,8,16,32,64,128,256,512,1024 };
	char SingleChar=fgetc(codefp);
	while (!feof(codefp))
	{
		sum += int(SingleChar - '0') * twopower[7 - in];
		in++;
		SingleChar = fgetc(codefp);
		if (in == 8 || feof(codefp))
		{
			in = 0;
			fprintf(pressfp,"%d ",sum);
			sum = 0;
		}
	}
	fclose(codefp);
	fclose(pressfp);
	printf("�ļ�ѹ���ɹ���\n");
}

void choice()
{
	int choice;
	int charNum = 0;
	HuffmanTree HT;
	HuffmanCode HC;
	printf("**********************************************************************\n");
	printf("*                                                                                    \n");
	printf("*                          ����������������                                   \n");
	printf("*                      1.ѡ����Ҫ���б�����ļ�                            \n");
	printf("*                      2.������������                                          \n");
	printf("*                      3.�������뱾�����ļ�����                            \n");
	printf("*                      4.ѡ����Ҫ���н�����ļ�������                    \n");
	printf("*                      5.��λѹ����ʽ���ļ�����ѹ��                      \n");
	printf("*                      6.�˳�                                                     \n");
	printf("*                                                                                    \n");
	printf("**********************************************************************\n");
	while (true)
	{
		printf("��ѡ����: ");
		cin >> choice;
		switch (choice)
		{
		case 1:
			charNum = FileChoose();
			break;
		case 2:
			CreateHuffmanTree(HT, charNum);
			break;
		case 3:
			CreateHuffmanCode(HT,HC,charNum);
			break;
		case 4:
			TranslateCode(HT,charNum);
			break;
		case 5:
			CompressFile();
			break;
		case 6:
			exit(0);
		default:
			printf("������������ԣ�\n");
			break;
		}
	}
}
/*
int main()
{
	choice();
	return 0;
}
*/