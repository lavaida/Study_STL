#include <algorithm>
#include <iostream>
#include <vector>

// Non-modifying Algorithms (���Ҹ� �������� �ʴ� �˰���)
//+ Modifying Algorithms (���Ҹ� �����ϴ� �˰���)

void Func(int &ref)	// �Է� ���� ������ ������ ���� ������(reference)�� �Ű������� �����
{
	ref += 10;
}

class Accumulation
{
public:
	explicit Accumulation()
		: total(0)
	{}
public:
	void operator() (int &ref)
	{
		total += ref;
		ref = total;	// ������ ���� ���� ���ҿ� ����� �κ�
	}
private:
	int total;
};

int main(void)
{
	std::vector<int> vec01;
	vec01.push_back(1);
	vec01.push_back(2);
	vec01.push_back(3);

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';	// 1 2 3
	}
	std::cout << '\n';

	std::for_each(vec01.begin(), vec01.end(), Func);

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';	// 11 12 13
	}
	std::cout << '\n';

	std::cout << "#####################\n";

	std::vector<int> vec02;
	vec02.push_back(1);
	vec02.push_back(2);
	vec02.push_back(3);
	vec02.push_back(4);
	vec02.push_back(5);

	std::cout << "vec02: ";
	for (size_t i = 0; i < vec02.size(); ++i)
	{
		std::cout << vec02[i] << ' ';	// 1 2 3 4 5
	}
	std::cout << '\n';

	std::for_each(vec02.begin(), vec02.end(), Accumulation());
	// "0"���� �����ؼ� ���� ���� ���� ���� ���ҿ� �����ִ� �۾��� ������.

	std::cout << "vec02: ";
	for (size_t i = 0; i < vec02.size(); ++i)
	{
		std::cout << vec02[i] << ' ';	// 1 3 6 10 15
	}
	std::cout << '\n';

	return 0;
}