#include <algorithm>
#include <iostream>


// Function Object(함수 객체), Functor(함수자)
//- "()" 연산자를 오버로딩한 클래스 객체를 의미하고 함수처럼 동작한다.
class Functor1
{
public:
	void operator() (int n)
	{
		std::cout << n << ' ';
	}
};

class Functor2
{
public:
	void operator() (int n)
	{
		std::cout << "n: " << n << '\n';
	}
};


int main(void)
{
	int arr[3] = { 1, 2, 3 };

	std::for_each(arr, arr + 3, Functor1());	// 이전 예제에서 함수 Pointer를 이용한 부분에 Function Object(Functor)를 이용함.
	std::cout << '\n';
	std::cout << "############################################\n";

	std::for_each(arr, arr + 3, Functor2());
	std::cout << "############################################\n";

	return 0;
}