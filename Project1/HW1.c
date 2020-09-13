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

void bubbleSort(node* start)
{
	int changed, i;
	node* ptr;
	node* lptr = NULL;


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




	// ��� �ϴ� ��
	printf("�й����̿�\n");

	p = head;
	while (p != NULL) {
		printf("�й� : %d\n", p->data.studentNum);
		printf("�̸� : %s\n", p->data.studentName);
		printf("���� : %d\n", p->data.studentScore);
		p = p->next;
	}
	printf("\n\n");

	//printf("\n\n");

	fclose(fp);
	return 0;
}