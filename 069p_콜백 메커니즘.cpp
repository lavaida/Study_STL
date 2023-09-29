#include <algorithm>
#include <iostream>

// 어떤 기능이나 서비스를 제공하는 코드를 서버측 코드라 말하고,
//그 기능을 제공받는 코드를 클라이언트측 코드라고 말한다.
//일반적으로 서버는 하나지만 서버 코드를 사용하는 클라이언트는 여러 개!

// 함수 포인터를 이용한 콜백 메커니즘
//ex) 서버 함수 For_each() 함수는 int형 배열의 원소를 대상으로 클라이언트 콜백 함수를 호출함. 
//- 서버는 여러 클라이언트에 의해 호출되며 모든 클라이언트의 존재를 알 수가 없다.
//그렇기 때문에 콜백 메커니즘을 구현하려면 클라이언트가 서버를 호출할 때 클라이언트의 정보를 제공해야 한다.
void For_each(int *begin, int *end, void (*func)(int))
{
	while (begin != end)
	{
		func(*(begin++));
	}
}

// 클라이언트의 콜백 함수 역할(Print1, Print2)
void Print1(int n)
{
	std::cout << n << ' ';
}
void Print2(int n)
{
	std::cout << "n: " << n << '\n';
}

int main(void)
{
	int arr[5] = { 1, 2, 3 };

	For_each(arr, arr + 3, Print1);
	std::cout << '\n';
	std::cout << "############################################\n";

	For_each(arr, arr + 3, Print2);
	std::cout << "############################################\n";


	std::for_each(arr, arr + 3, Print1);
	std::cout << '\n';
	std::cout << "############################################\n";

	std::for_each(arr, arr + 3, Print2);
	std::cout << "############################################\n";

	return 0;
}