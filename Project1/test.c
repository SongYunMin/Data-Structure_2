//#include <stdio.h>
//
//int main(void)
//{
//	int a[5] = { 5,4,2,1,3 };
//	int i, j, temp, count = 0;
//
//	for (i = 0; i < 5; i++) {
//		for (j = 0; j < 5 - 1 - i; j++) {
//			count++;
//			if (a[j] > a[j + 1]) {
//				temp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = temp;
//			}
//		}
//	}
//
//	printf("%d", count);
//
//	for (i = 0; i < 5; i++) {
//		printf("%d ", a[i]);
//	}
//	
//
//	return 0;
//}