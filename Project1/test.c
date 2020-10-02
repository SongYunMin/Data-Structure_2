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
//	printf("## 마술 카드 구현 프로그램에 오신것을 환영합니다 !!##\n\n");
//	printf("## 입력받을 카드 장수를 입력 해주십시오 : "); scanf("%d", &CardNumlen);
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
//	printf("걸린 시간: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
//	printf("배열요소의 길이 : %d\n", arrCount - 1);
//	printf("이카드에 당신이 생각하는 숫자가 있습니까 ?\n");
//	printf("Yes[1] No[0]\n");
//	scanf("%d", &num);
//	while (num != 1 && num != 0) {
//		printf("다시 입력하십시오 .\n");
//		printf("입력은 1과 0만 가능합니다 .\n");
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
//		printf("%d번쨰 카드\n\n", Count + 1);
//		delivery = NewCard();
//		ResultFunc(delivery);
//		Count++;
//		squre *= 2;
//	}
//	printf("당신이 생각한 숫자는 바로 %d 입니다 !!\n", Result);
//	return 0;
//}