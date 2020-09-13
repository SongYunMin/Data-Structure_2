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
	// 필요한 포인터 및 변수 선언
	FILE* fp;
	element data;
	node* head = NULL;
	node* p;
	fp = fopen("data.txt", "rt");
	int sn, sc, i, j, count = 0, status = 1;
	char sname[20];
	int changed = 0;

	// 파일 예외처리
	if (fp == NULL) {
		printf("File Not Found\n");
		exit(-1);
	}

	// 파일 읽고 Node 만듬
	while (!feof(fp)) {
		node* newnode = (node*)malloc(sizeof(node));
		// 파일 입력
		fscanf(fp, "%d %s %d", &sn, &sname, &sc);
		// Node data에 File value 대입
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




	// 출력 하는 놈
	printf("학번순이요\n");

	p = head;
	while (p != NULL) {
		printf("학번 : %d\n", p->data.studentNum);
		printf("이름 : %s\n", p->data.studentName);
		printf("총점 : %d\n", p->data.studentScore);
		p = p->next;
	}
	printf("\n\n");

	//printf("\n\n");

	fclose(fp);
	return 0;
}