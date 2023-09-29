#include <algorithm>
#include <iostream>


// Function Object(�Լ� ��ü), Functor(�Լ���)
//- "()" �����ڸ� �����ε��� Ŭ���� ��ü�� �ǹ��ϰ� �Լ�ó�� �����Ѵ�.
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

	std::for_each(arr, arr + 3, Functor1());	// ���� �������� �Լ� Pointer�� �̿��� �κп� Function Object(Functor)�� �̿���.
	std::cout << '\n';
	std::cout << "############################################\n";

	std::for_each(arr, arr + 3, Functor2());
	std::cout << "############################################\n";

	return 0;
}