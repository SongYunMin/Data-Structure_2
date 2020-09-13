#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element {
	int studentNum;
	char studentName[20];
	int studentScore;
} element;

typedef struct node {
	struct element data;
	struct node* next;
} node;

int main(void)
{
	FILE* fp;
	element data;
	node* head = NULL;
	node* p, pp;
	fp = fopen("data.txt", "rt");
	int sn, sc, i, j, count = 0;
	char sname[20];


	if (fp == NULL) {
		printf("File Not Found\n");
		exit(-1);
	}
	// ���� �а� Node ����
	while (!feof(fp)) {
		node* ptr = head;
		node* p;
		node* newnode = (node*)malloc(sizeof(node));
		fscanf(fp, "%d %s %d", &sn, &sname, &sc);
		newnode->data.studentNum = sn;
		strcpy(newnode->data.studentName, sname);
		newnode->data.studentScore = sc;
		newnode->next = NULL;

		if (head == NULL) {
			(head) = newnode;
			newnode->next = NULL;
		}
		else {
			while (ptr != NULL) {
				p = ptr;
				ptr = ptr->next;
			}
			ptr = newnode;
			p->next = ptr;
		}
		count++;
	}

	node* buf = head;
	// �й��� �����̿�
	for (p=head; p->next != NULL; p=p->next) {
		if (buf->data.studentNum > buf->next->data.studentNum) {
			int tempNum = buf->next->data.studentNum;
			buf->next->data.studentNum = buf->data.studentNum;
			buf->data.studentNum = tempNum;

			char tempName[20];
			strcpy(tempName, buf->next->data.studentName);
			strcpy(buf->next->data.studentName, buf->data.studentName);
			strcpy(buf->data.studentName, tempName);

			int tempScore = buf->next->data.studentScore;
			buf->next->data.studentScore = buf->data.studentScore;
			buf->data.studentScore = tempScore;
		}
	}

	// ��� �ϴ� ��
	p = head;
	printf("�й����̿�\n");

	while (p != NULL) {
		printf("�й� : %d\n", p->data.studentNum);
		printf("�̸� : %s\n", p->data.studentName);
		printf("���� : %d\n", p->data.studentScore);
		p = p->next;
	}
	printf("\n\n");

	//buf = head;
	//// �̸��� �����̿�
	//for (i = 0; i < count; i++) {
	//	for (j = 0; j < count - 1; j++) {
	//		if (strcmp(buf->data.studentName, buf->next->data.studentName) == 1) {
	//			int tempNum = buf->next->data.studentNum;
	//			buf->next->data.studentNum = buf->data.studentNum;
	//			buf->data.studentNum = tempNum;

	//			char tempName[20];
	//			strcpy(tempName, buf->next->data.studentName);
	//			strcpy(buf->next->data.studentName, buf->data.studentName);
	//			strcpy(buf->data.studentName, tempName);

	//			int tempScore = buf->next->data.studentScore;
	//			buf->next->data.studentScore = buf->data.studentScore;
	//			buf->data.studentScore = tempScore;

	//		}
	//	}
	//}

	//// ��� �ϴ� ��
	//p = head;
	//printf("�̸����̿�\n");

	//while (p != NULL) {
	//	printf("�й� : %d\n", p->data.studentNum);
	//	printf("�̸� : %s\n", p->data.studentName);
	//	printf("���� : %d\n", p->data.studentScore);
	//	p = p->next;
	//}
	//printf("\n\n");

	//buf = head;
	//// ������ �����̿�
	//for (i = 0; i < count; i++) {
	//	for (j = 0; j < count - 1; j++) {
	//		if (buf->data.studentScore < buf->next->data.studentScore) {
	//			int tempNum = buf->next->data.studentNum;
	//			buf->next->data.studentNum = buf->data.studentNum;
	//			buf->data.studentNum = tempNum;

	//			char tempName[20];
	//			strcpy(tempName, buf->next->data.studentName);
	//			strcpy(buf->next->data.studentName, buf->data.studentName);
	//			strcpy(buf->data.studentName, tempName);

	//			int tempScore = buf->next->data.studentScore;
	//			buf->next->data.studentScore = buf->data.studentScore;
	//			buf->data.studentScore = tempScore;

	//		}
	//	}
	//}

	//// ��� �ϴ� ��
	//p = head;
	//printf("�������̿�\n");


	//while (p != NULL) {
	//	printf("�й� : %d\n", p->data.studentNum);
	//	printf("�̸� : %s\n", p->data.studentName);
	//	printf("���� : %d\n", p->data.studentScore);
	//	p = p->next;
	//}

	//printf("\n\n");


	return 0;
}