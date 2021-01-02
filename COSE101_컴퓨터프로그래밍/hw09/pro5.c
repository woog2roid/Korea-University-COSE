#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

//����ü
typedef struct _employee
{
	int employee_id;
	char* name;
}EMP;

//����
FILE* fpw;
FILE* fpr;
FILE* fpu;

//���÷���
void menu(void);
void case1(EMP emp, char employee_name[]);
void case2(int id_read , char name_read[]);
void case3(int id_read, char name_read[]);

//���
void back_to_main();


//�����Լ�
int main(void)
{
	//����ü
	EMP emp;

	//������ �ʱ�ȭ
	char employee_name[30] = {' '};
	emp.name = employee_name;
	//����
	int opt;
	int id_read = 0; char name_read[30];
	char text[100];

	//����
	menu();
	while (1)
	{
		printf("Enter your choice: ");
		scanf("%d", &opt);
	
		switch (opt)
		{
		case 1:
			case1(emp, employee_name);
			break;
		case 2:
			case2(id_read, name_read);
			break;
		case 3:
			case3(id_read, name_read);
			break;
		case 4:
			return 0;
			break;
		}
	}
}

//��ɱ���
void back_to_main()
{
	_getch();
	system("cls");
	menu();
}
//_getch();�� �����°� ������ ��� ����?


//���÷��̱���
void menu(void)
{
	printf("============================\n");
	printf("MENU:\n");
	printf("============================\n");
	printf("1. Add a record\n");
	printf("2. Display the file\n");
	printf("3. Update the record\n");
	printf("4. Exit\n");
	printf("============================\n");
}

void case1(EMP emp, char employee_name[])
{
	for(int i=0; i<30; i++)
	employee_name[i] = ' ';
	static int add_cnt;

	if (!add_cnt)
		fpw = fopen("record.txt", "w");
	else
	{
		fpw = fopen("record.txt", "a");
		fprintf(fpw, "\n");
	}
	char tmp;
	printf("\n");
	printf("ENTER THE EMPLOYEE ID : \n");
	scanf("%d", &emp.employee_id);
	printf("ENTER THE EMPLOYEE NAME : \n");
	scanf(" ");
	gets(emp.name);

	int i;
	for(i=0; employee_name[i]!=NULL; i++)
	{
		;
	}
	for(i; i<29; i++)
	employee_name[i] = ' ';

	employee_name[28] = 0;

	fprintf(fpw, "%d", emp.employee_id);//���Ͽ� ���
	fprintf(fpw, "%s", emp.name);//���Ͽ� ���

	//������ �۾�
	add_cnt++;
	fclose(fpw);
	*emp.name = 0;
	

	//���÷��� ������
	system("cls");
	menu();
}

void case2(int id_read, char name_read[])
{



	fpr = fopen("record.txt", "r");

	printf("============================\n");
	printf("ID      NAME                \n");
	printf("============================\n");

	while(!feof(fpr))
	{
		fscanf(fpr, "%d ", &id_read);
		fgets(name_read,30,fpr);
		if (name_read[0]==0)
		{
			;
		}
		else
		{
			printf("%-3d     %s                  \n", id_read, name_read);
		}

		name_read[0] = 0;
	}
	printf("============================\n");
	//���÷��� �ߵǴ°� Ȯ��
	
	fclose(fpr);

	back_to_main();
}

void case3(int id_read, char name_read[])//������Ʈ
{
	fpu = fopen("record.txt", "r+");
	
	
	int id; 
	printf("ENTER THE EMPLOYEE ID FOR UPDATE : \n");
	scanf("%d", &id);//������ ���̵� Ȯ��
	
	
	char new[25] = {' '};//���� ������ �̸�
	char check[50] = { 0 };
	
	char zero[1] = { ' ' };

	while (!feof(fpu))
	{
		fscanf(fpu, "%d", &id_read);
		fgets(name_read, 30, fpu);
		if (id == id_read)
		{
			int counter;
			for (counter = 0; name_read[counter] != NULL; counter++)
				;

			fseek(fpu, -1 * (counter), SEEK_CUR);//������ �ڷ� �̵���Ű��

			printf("ENTER THE EMPLOYEE NAME TO BE UPDATED : \n");
			scanf(" ");//���� ������ �̸� Ȯ�� 
			gets(new);

			int i;
			for(i=0; new[i]!=NULL; i++)
			{
				;
			}
			new[i] = ' ';
			new[24] = 0;

			fprintf(fpu, "%s\n", new);


			break;
		}

	}

	fclose(fpu);
	back_to_main();
}