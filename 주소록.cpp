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
		printf("l  주  소  록 ㅣ\n");
		printf("+--------------+\n");
		printf("l  (1) 목록보기 ㅣ\n");
		printf("l  (2) 추가하기 ㅣ\n");
		printf("l  (3) 탐색하기 ㅣ\n");
		printf("l  (4) 삭제하기 ㅣ\n");
		printf("l  (5) 종    료 ㅣ\n");
		printf("+--------------+\n");

		printf("\n원하는 작업을 입력하십시오. :");
		choice = getchar();
		while (getchar() != '\n') {}

		switch (choice) {
		case '1':
			printf("\n주소록 목록 작업입니다. 정보를 입력하십시오.\n");
			Display(head);
			break;
		case '2':
			printf("\n주소록 추가 작업입니다. 정보를 입력하십시오.\n");
			Insert(head);
			break;
		case '3':
			printf("\n주소록 검색 작업입니다. 정보를 입력하십시오.\n");
			Search(head);
			break;
		case '4':printf("\n주소록 삭제 작업입니다. 정보를 입력하십시오.\n");
			Delete(head);
			break;
		case '5':
			printf("\n종료합니다.\n");
			break;
		default:
			printf("\n잘못된 값을 입력하였습니다.\n");
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

		printf("이름 :");
		gets_s(ptr->name);
		printf("전화번호 :");
		gets_s(ptr->phone);;
		printf("주소 :");
		gets_s(ptr->address);
		printf("생일 :");
		gets_s(ptr->birthday);
		printf("\nl등록완료ㅣ\n");

		for (;;) {
			printf("\n계속 등록하시겠습니까?(YIN):");
			re = getchar();
			while (getchar() != '\n') {}
			if (re != 'Y' && re != 'y' && re != 'N' && re != 'n') {
				printf("\n잘못된 값을 입력하였습니다.\n다시 입력하여 주십시오.\n\n");

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

	printf("삭제할 사람의 성명 :");
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
	printf("l주소록l\n");
	printf("%-15s", "성  명");
	printf("%-18s", "전화번호");
	printf("%-50s", "주  소");
	printf("%-14s\n", "생  일");

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

	printf("찾을 사람의 성명 :");
	gets_s(_name);

	printf("\nㅣ검색완료ㅣ\n");
	printf("%-15s", "성  명");
	printf("%-18s", "전화번호");
	printf("%-50s", "주  소");
	printf("%-14s\n", "생  일");

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