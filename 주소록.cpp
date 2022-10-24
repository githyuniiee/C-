#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct _addbook {
	char name[15];
	char phone[18];
	char address[50];
	char birthday[14];
	struct _addbook* link;
};
typedef struct _addbook addbook;

void Display(addbook*);
void Insert(addbook*);
void Search(addbook*);
void Delete(addbook*);
void Freememory(addbook*);

void Freememory(addbook* ptr) {
	addbook* temp = NULL;

	while (ptr->link != NULL) {
		temp = ptr->link;
		ptr->link = temp->link;
		free(temp);
	}
}

int main(void) {
	addbook* head = (addbook*)malloc(sizeof(addbook));
	int choice = 0;

	head->link = NULL;

	do {
		printf("+--------------+\n");
		printf("l  ��  ��  �� ��\n");
		printf("+--------------+\n");
		printf("l  (1) ��Ϻ��� ��\n");
		printf("l  (2) �߰��ϱ� ��\n");
		printf("l  (3) Ž���ϱ� ��\n");
		printf("l  (4) �����ϱ� ��\n");
		printf("l  (5) ��    �� ��\n");
		printf("+--------------+\n");

		printf("\n���ϴ� �۾��� �Է��Ͻʽÿ�. :");
		choice = getchar();
		while (getchar() != '\n') {}

		switch (choice) {
		case '1':
			printf("\n�ּҷ� ��� �۾��Դϴ�. ������ �Է��Ͻʽÿ�.\n");
			Display(head);
			break;
		case '2':
			printf("\n�ּҷ� �߰� �۾��Դϴ�. ������ �Է��Ͻʽÿ�.\n");
			Insert(head);
			break;
		case '3':
			printf("\n�ּҷ� �˻� �۾��Դϴ�. ������ �Է��Ͻʽÿ�.\n");
			Search(head);
			break;
		case '4':printf("\n�ּҷ� ���� �۾��Դϴ�. ������ �Է��Ͻʽÿ�.\n");
			Delete(head);
			break;
		case '5':
			printf("\n�����մϴ�.\n");
			break;
		default:
			printf("\n�߸��� ���� �Է��Ͽ����ϴ�.\n");
		}

	} while (choice != '5');

	Freememory(head);
	free(head);
	return 0;
}


void Insert(addbook* ptr) {
	int re = 0;
	while (ptr->link != NULL)
		ptr = ptr->link;

	do {
		ptr->link = (addbook*)malloc(sizeof(addbook));
		ptr = ptr->link;

		printf("�̸� :");
		gets_s(ptr->name);
		printf("��ȭ��ȣ :");
		gets_s(ptr->phone);;
		printf("�ּ� :");
		gets_s(ptr->address);
		printf("���� :");
		gets_s(ptr->birthday);
		printf("\nl��ϿϷ��\n");

		for (;;) {
			printf("\n��� ����Ͻðڽ��ϱ�?(YIN):");
			re = getchar();
			while (getchar() != '\n') {}
			if (re != 'Y' && re != 'y' && re != 'N' && re != 'n') {
				printf("\n�߸��� ���� �Է��Ͽ����ϴ�.\n�ٽ� �Է��Ͽ� �ֽʽÿ�.\n\n");

			}
			else
				break;
		}
	} while (re != 'n' && re != 'N');

	ptr->link = NULL;
	printf("\n");
}

void Delete(addbook* ptr) {
	addbook* temp;
	char _name[15];

	printf("������ ����� ���� :");
	gets_s(_name);

	while (ptr->link != NULL) {
		temp = ptr;
		ptr = ptr->link;

		if (strcmp(_name, ptr->name) == 0) {
			temp->link = ptr->link;
			free(ptr);
			break;
		}
	}
	return;

}


void Display(addbook* ptr) {
	printf("l�ּҷ�l\n");
	printf("%-15s", "��  ��");
	printf("%-18s", "��ȭ��ȣ");
	printf("%-50s", "��  ��");
	printf("%-14s\n", "��  ��");

	while (ptr->link != NULL) {
		ptr = ptr->link;
		printf("%-15s", ptr->name);
		printf("%-18s", ptr->phone);
		printf("%-50s", ptr->address);
		printf("%-14s", ptr->birthday);
		printf("\n");
	}
	printf("\n");
}

void Search(addbook* ptr) {
	char _name[15];

	printf("ã�� ����� ���� :");
	gets_s(_name);

	printf("\n�Ӱ˻��Ϸ��\n");
	printf("%-15s", "��  ��");
	printf("%-18s", "��ȭ��ȣ");
	printf("%-50s", "��  ��");
	printf("%-14s\n", "��  ��");

	while (ptr->link != NULL) {
		ptr = ptr->link;
		if (strcmp(_name, ptr->name) == 0) {
			printf("%-15s", ptr->name);
			printf("%-18s", ptr->phone);
			printf("%-50s", ptr->address);
			printf("%-14s", ptr->birthday);
			printf("\n\n");
		}
	}
}