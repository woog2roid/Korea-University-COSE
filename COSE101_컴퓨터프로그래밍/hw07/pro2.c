#include <stdio.h>
#include <ctype.h>
#include <string.h>

//�������迭�� �̿��غ���
int main(void)
{
	printf("Enter three lines of text:\n");

	char string[3][80];

	for (int i = 0; i < 3; i++)
	{
		gets(&string[i][0]);
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			string[i][j] = tolower(string[i][j]);
		}
	}

	/*
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			printf("%c", string[i][j]);
		}
	}
	��ҹ��� ���� �Ϸ�!!
	*/


	int cnt[26];
	for (int i = 0; i < 26; i++)
	{
		cnt[i] = 0;
	}
	//ī���� 0���� �ʱ�ȭ

	char* ptr;

	//int j = 0; j < 3; j++
	//int i = 'a'; i <= 'z'; i++
	for (int j = 0; j < 3; j++)
	{
		for (int i = 'a'; i <= 'z'; i++)
		{
			ptr = strchr(&string[j][0], i);
			while (ptr != NULL)
			{
				cnt[i - 'a']++;
				ptr++;
				ptr = strchr(ptr, i);
			}
		}
	}


	printf("\nThe total occurrences of each character:\n");
	for (int i = 'a'; i <= 'z'; i++)
	{
		printf("%c:%4d\n", i, cnt[i - 'a']);
	}
}