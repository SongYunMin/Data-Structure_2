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


// �й� ���� ����
node* sortNumber(node* start)
{
	node* i = NULL;
	node* j = NULL;
	
	for (i = start; i->next != NULL; i = i->next) {
		for (j = start; j->next != NULL; j = j->next) {
			if (j->data.studentNum > j->next->data.studentNum) {
				element temp = j->data;
				j->data = j->next->data;
				j->next->data = temp;
			}
		}
	}
	return start;
}

// �̸� ���� ����
node* sortName(node* start)
{
	node* i = NULL;
	node* j = NULL;

	for (i = start; i->next != NULL; i = i->next) {
		for (j = start; j->next != NULL; j = j->next) {
			if (strcmp(j->data.studentName,j->next->data.studentName) == 1) {
				element temp = j->data;
				j->data = j->next->data;
				j->next->data = temp;
			}
		}
	}
	return start;
}

// ���� ���� ����
node* sortScore(node* start)
{
	node* i = NULL;
	node* j = NULL;

	for (i = start; i->next != NULL; i = i->next) {
		for (j = start; j->next != NULL; j = j->next) {
			if (j->data.studentScore < j->next->data.studentScore) {
				element temp = j->data;
				j->data = j->next->data;
				j->next->data = temp;
			}
		}
	}
	return start;
}



int main(void)
{
	// �ʿ��� ������ �� ���� ����
	FILE* fp;
	element data;
	node* head = NULL;
	node* p;
	fp = fopen("data.txt", "rt");
	int sn, sc, i, j, count = 0, status = 1;
	char sname[20];
	int changed = 0;

	// ���� ����ó��
	if (fp == NULL) {
		printf("File Not Found\n");
		exit(-1);
	}

	// ���� �а� Node ����
	while (!feof(fp)) {
		node* newnode = (node*)malloc(sizeof(node));
		// ���� �Է�
		fscanf(fp, "%d %s %d", &sn, &sname, &sc);
		// Node data�� File value ����
		newnode->data.studentNum = sn;
		strcpy(newnode->data.studentName, sname);
		newnode->data.studentScore = sc;

		newnode->next = head;
		head = newnode;
	}

	if (head == NULL) {
		printf("Node Not Found!!\n");
		return;
	}

	// �й���
	printf("�й����̿�\n");
	head = sortNumber(head);
	p = head;
	while (p != NULL) {
		printf("�й� : %d\n", p->data.studentNum);
		printf("�̸� : %s\n", p->data.studentName);
		printf("���� : %d\n", p->data.studentScore);
		p = p->next;
	}
	printf("\n\n");


	// �̸�(������)��
	printf("�̸����̿�\n");
	head = sortName(head);
	p = head;
	while (p != NULL) {
		printf("�й� : %d\n", p->data.studentNum);
		printf("�̸� : %s\n", p->data.studentName);
		printf("���� : %d\n", p->data.studentScore);
		p = p->next;
	}
	printf("\n\n");

	// ������
	printf("�������̿�\n");
	head = sortScore(head);
	p = head;
	while (p != NULL) {
		printf("�й� : %d\n", p->data.studentNum);
		printf("�̸� : %s\n", p->data.studentName);
		printf("���� : %d\n", p->data.studentScore);
		p = p->next;
	}
	printf("\n\n");

	fclose(fp);
	return 0;
}