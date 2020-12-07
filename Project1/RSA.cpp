#include <iostream>
#include <vector>

int main(void)
{
	int p, q, n;
	std::cout << "소수 p, 소수 q 를 입력하세요." << std::endl;
	std::cin >> p >> q;
	
	n = p * q;
	std::cout << "n값은 : " << n << " 입니다.";
	

	return 0;
}