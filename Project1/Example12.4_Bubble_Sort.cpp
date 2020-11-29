//#include <iostream>
//
//void bubbleSort(int* list, int n)
//{
//	int i, j, temp;
//
//	// i를 n-1로 하여 정렬된 부분의 반복은 다시 수행하지 않도록 함
//	for (i = n - 1; i > 0; i--) {
//		for (j = 0; j < i; j++) {
//			if (list[j] > list[j + 1]) {
//				temp = list[j];
//				list[j] = list[j + 1];
//				list[j + 1] = temp;
//			}
//		}
//	}
//}
//
//int main(void)
//{
//	int list[6] = { 3,5,8,1,2,7 };
//
//	std::cout << "정렬 되기 전 : " << std::endl;
//	for (int i = 0; i < 6; i++) {
//		std::cout << list[i];
//	}
//	std::cout << std::endl;
//
//	bubbleSort(list, 6);
//
//	std::cout << "정렬 된 이후 : " << std::endl;
//	for (int i = 0; i < 6; i++) {
//		std::cout << list[i];
//	}
//	std::cout << std::endl;
//
//	return 0;
//}