//#include <iostream>
//
//void bubbleSort(int* list, int n)
//{
//	int i, j, temp;
//
//	// i�� n-1�� �Ͽ� ���ĵ� �κ��� �ݺ��� �ٽ� �������� �ʵ��� ��
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
//	std::cout << "���� �Ǳ� �� : " << std::endl;
//	for (int i = 0; i < 6; i++) {
//		std::cout << list[i];
//	}
//	std::cout << std::endl;
//
//	bubbleSort(list, 6);
//
//	std::cout << "���� �� ���� : " << std::endl;
//	for (int i = 0; i < 6; i++) {
//		std::cout << list[i];
//	}
//	std::cout << std::endl;
//
//	return 0;
//}