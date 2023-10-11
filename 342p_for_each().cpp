#include <algorithm>
#include <iostream>
#include <vector>

// Non-modifying Algorithms (원소를 수정하지 않는 알고리즘)
//+ Modifying Algorithms (원소를 수정하는 알고리즘)

void Func(int &ref)	// 입력 받은 원소의 변경을 위해 참조자(reference)를 매개변수로 사용함
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
		ref = total;	// 원소의 누적 값을 원소에 덮어쓰는 부분
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
	// "0"부터 시작해서 원소 값의 누적 값을 원소에 더해주는 작업을 수행함.

	std::cout << "vec02: ";
	for (size_t i = 0; i < vec02.size(); ++i)
	{
		std::cout << vec02[i] << ' ';	// 1 3 6 10 15
	}
	std::cout << '\n';

	return 0;
}