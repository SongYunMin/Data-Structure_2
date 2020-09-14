#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ������ ����
typedef struct element {
	int studentNum;
	char studentName[20];
	int studentScore;
} element;

// ��� ����
typedef struct node {
	struct element data;
	struct node* next;
} node;


// �й� ���� ����
node* sortNumber(node* start)
{
	node* i = NULL;					// �ݺ��� ���� Node ������ ����
	node* j = NULL;
	
	for (i = start; i->next != NULL; i = i->next) {
		for (j = start; j->next != NULL; j = j->next) {
			// ���� ���� ���� ����� ��Ҹ� ��
			if (j->data.studentNum > j->next->data.studentNum) {	
				// Swap
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
			// '������'�� ������ ���� strcmp ���
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
	node* i = NULL;			// �ݺ��� ���� Node �����ͻ���
	node* j = NULL;

	for (i = start; i->next != NULL; i = i->next) {
		for (j = start; j->next != NULL; j = j->next) {
			// ���� ���� ��������� ��Ҹ� ��
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
	FILE* fp;					// ���� ������
	element data;				// ������ ����ü
	node* head = NULL;			// ��� ������
	node* p;					// �ӽ�(����) ������
	int sn, sc;					// fscanf �Է� �� �о� ���� ����
	char sname[20];

	// ���� Open �� ���� ó��
	fp = fopen("data.txt", "rt");
	if (fp == NULL) {
		printf("File Not Found\n");
		exit(-1);
	}

	// ���� �а� Node ����
	while (!feof(fp)) {
		node* newnode = (node*)malloc(sizeof(node));		// ���� �Ҵ�
		// ���� �Է�
		fscanf(fp, "%d %s %d", &sn, &sname, &sc);
		// Node data�� File value ����
		newnode->data.studentNum = sn;
		strcpy(newnode->data.studentName, sname);
		newnode->data.studentScore = sc;

		// �Ҵ���� newnode�� Link�� Head�� ����
		newnode->next = head;
		head = newnode;			// head �����Ϳ� newnode�� ����
	}

	// node ����ó��
	if (head == NULL) {
		printf("Node Not Found!!\n");
		return;
	}

	printf("====================\n");
	printf("== �й� ���� ���� ==\n");
	printf("�й�  \t �̸�\t����\n");
	printf("====================\n");
	head = sortNumber(head);
	p = head;
	while (p != NULL) {
		printf("%d %s %d\n", p->data.studentNum, p->data.studentName, p->data.studentScore);
		p = p->next;
	}
	printf("====================\n");
	printf("\n\n");


	// �̸�(������)��
	printf("====================\n");
	printf("== �̸� ���� ���� ==\n");
	printf("�й�  \t �̸�\t����\n");
	printf("====================\n");
	head = sortName(head);
	p = head;
	while (p != NULL) {
		printf("%d %s %d\n", p->data.studentNum, p->data.studentName, p->data.studentScore);
		p = p->next;
	}
	printf("====================\n");
	printf("\n\n");

	// ������
	printf("====================\n");
	printf("== ���� ���� ���� ==\n");
	printf("�й�  \t �̸�\t����\n");
	printf("====================\n");
	head = sortScore(head);
	p = head;
	while (p != NULL) {
		printf("%d %s %d\n", p->data.studentNum, p->data.studentName, p->data.studentScore);
		p = p->next;
	}
	printf("====================\n");

	fclose(fp);
	return 0;
}