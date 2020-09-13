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
	fp = fopen("data.txt", "rt");
	int sn, sc;
	char sname[20];


	if (fp == NULL) {
		printf("File Not Found\n");
		exit(-1);
	}
	while (!feof(fp)) {
		node* newnode = (node*)malloc(sizeof(node));
		fscanf(fp, "%d %s %d", &sn, &sname, &sc);
		newnode->data.studentNum = sn;
		strcpy(newnode->data.studentName, sname);
		newnode->data.studentScore = sc;
	}

	return 0;
}