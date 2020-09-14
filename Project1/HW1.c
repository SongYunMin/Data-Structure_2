#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 데이터 정의
typedef struct element {
	int studentNum;
	char studentName[20];
	int studentScore;
} element;

// 노드 정의
typedef struct node {
	struct element data;
	struct node* next;
} node;


// 학번 기준 정렬
node* sortNumber(node* start)
{
	node* i = NULL;					// 반복을 위한 Node 포인터 선언
	node* j = NULL;
	
	for (i = start; i->next != NULL; i = i->next) {
		for (j = start; j->next != NULL; j = j->next) {
			// 현재 노드와 다음 노드의 대소를 비교
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

// 이름 기준 정렬
node* sortName(node* start)
{
	node* i = NULL;
	node* j = NULL;

	for (i = start; i->next != NULL; i = i->next) {
		for (j = start; j->next != NULL; j = j->next) {
			// '가나다'순 정렬을 위해 strcmp 사용
			if (strcmp(j->data.studentName,j->next->data.studentName) == 1) {	
				element temp = j->data;
				j->data = j->next->data;
				j->next->data = temp;
			}
		}
	}
	return start;
}

// 총점 기준 정렬
node* sortScore(node* start)
{
	node* i = NULL;			// 반복을 위한 Node 포인터생성
	node* j = NULL;

	for (i = start; i->next != NULL; i = i->next) {
		for (j = start; j->next != NULL; j = j->next) {
			// 현재 노드와 다음노드의 대소를 비교
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
	// 필요한 포인터 및 변수 선언
	FILE* fp;					// 파일 포인터
	element data;				// 데이터 구조체
	node* head = NULL;			// 헤드 포인터
	node* p;					// 임시(버퍼) 포인터
	int sn, sc;					// fscanf 입력 시 읽어 들일 변수
	char sname[20];

	// 파일 Open 및 예외 처리
	fp = fopen("data.txt", "rt");
	if (fp == NULL) {
		printf("File Not Found\n");
		exit(-1);
	}

	// 파일 읽고 Node 만듬
	while (!feof(fp)) {
		node* newnode = (node*)malloc(sizeof(node));		// 공간 할당
		// 파일 입력
		fscanf(fp, "%d %s %d", &sn, &sname, &sc);
		// Node data에 File value 대입
		newnode->data.studentNum = sn;
		strcpy(newnode->data.studentName, sname);
		newnode->data.studentScore = sc;

		// 할당받은 newnode의 Link에 Head를 대입
		newnode->next = head;
		head = newnode;			// head 포인터에 newnode를 대입
	}

	// node 예외처리
	if (head == NULL) {
		printf("Node Not Found!!\n");
		return;
	}

	printf("====================\n");
	printf("== 학번 기준 정렬 ==\n");
	printf("학번  \t 이름\t총점\n");
	printf("====================\n");
	head = sortNumber(head);
	p = head;
	while (p != NULL) {
		printf("%d %s %d\n", p->data.studentNum, p->data.studentName, p->data.studentScore);
		p = p->next;
	}
	printf("====================\n");
	printf("\n\n");


	// 이름(가나다)순
	printf("====================\n");
	printf("== 이름 기준 정렬 ==\n");
	printf("학번  \t 이름\t총점\n");
	printf("====================\n");
	head = sortName(head);
	p = head;
	while (p != NULL) {
		printf("%d %s %d\n", p->data.studentNum, p->data.studentName, p->data.studentScore);
		p = p->next;
	}
	printf("====================\n");
	printf("\n\n");

	// 총점순
	printf("====================\n");
	printf("== 총점 기준 정렬 ==\n");
	printf("학번  \t 이름\t총점\n");
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