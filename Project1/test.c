//#include <stdio.h>
//#include <math.h>
//#include <time.h> 
//#define CRT_SECURE_NO_WARNINGS
//int CardNumlen = 0;
//int squre = 2;
//int Count = 0;
//int Result = 0;
//clock_t start, end;
//void opening(void)
//{
//	printf("----------------------------------------------------\n");
//	printf("## ���� ī�� ���� ���α׷��� ���Ű��� ȯ���մϴ� !!##\n\n");
//	printf("## �Է¹��� ī�� ����� �Է� ���ֽʽÿ� : "); scanf("%d", &CardNumlen);
//	start = clock();
//	printf("----------------------------------------------------\n");
//}
//int NewCard(void)
//{
//	unsigned int i;
//	double arrlen;
//	int arrCount = 1;
//	int num;
//	arrlen = pow(2, CardNumlen);
//	for (i = 0; i <= arrlen; i++) {
//		if (i % squre >= squre / 2 && i % squre < squre) {
//			printf("%u ", i);
//				arrCount++;
//		}
//	}
//	end = clock();
//	printf("\n");
//	printf("�ɸ� �ð�: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
//	printf("�迭����� ���� : %d\n", arrCount - 1);
//	printf("��ī�忡 ����� �����ϴ� ���ڰ� �ֽ��ϱ� ?\n");
//	printf("Yes[1] No[0]\n");
//	scanf("%d", &num);
//	while (num != 1 && num != 0) {
//		printf("�ٽ� �Է��Ͻʽÿ� .\n");
//		printf("�Է��� 1�� 0�� �����մϴ� .\n");
//		scanf("%d", &num);
//	}
//	printf("\n");
//	return num;
//}
//void ResultFunc(int delivery_)
//{
//	int i;
//	if (Count == 0 && delivery_ == 1) {
//		Result += delivery_;
//	}
//	else if (Count != 0 && delivery_ == 1) {
//		Result += delivery_ + (pow(2, Count) - 1);
//	}
//}
//int main(void)
//{
//	int i;
//	int delivery;
//	opening();
//	for (i = 0; i < CardNumlen; i++) {
//		printf("\n");
//		printf("%d���� ī��\n\n", Count + 1);
//		delivery = NewCard();
//		ResultFunc(delivery);
//		Count++;
//		squre *= 2;
//	}
//	printf("����� ������ ���ڴ� �ٷ� %d �Դϴ� !!\n", Result);
//	return 0;
//}