#include <algorithm>
#include <iostream>
#include <vector>

// Modifying Algorithms (원소를 수정하는 알고리즘)

int Func(void)
{
	return 0;	// 반환되는 값으로 원소를 채워 넣는다.
}

int main(void)
{
	// generate() 알고리즘과 for_each(), transform() 알고리즘의 큰 차이점은
	//매개변수로 순차열의 원소를 전달받지 않기 때문에 원소가 가지고 있는 원래 값을 활용할 수 없고,
	//단순히 일정한 값으로 채워 넣는다.

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

	// 순차열의 모든 원소를 단순한 동작의 값으로 수정할 때 사용하는 알고리즘
	std::generate(vec01.begin(), vec01.end(), Func);	// void 매개변수를 사용해야 한다!!!

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';	// 0 0 0
	}
	std::cout << '\n';

	std::cout << "#################\n";

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

	std::generate_n(vec02.begin(), 2, Func);
	//위의 Func() 함수는 단지 반환되는 "0"의 값을 넣어주지만,
	//함수 객체를 이용하면 처음에 초기화해서 넣어준 값을 통해 값을 지정할 수도 있음.

	std::cout << "vec02: ";
	for (size_t i = 0; i < vec02.size(); ++i)
	{
		std::cout << vec02[i] << ' ';	// 0 0 3 4 5
	}
	std::cout << '\n';

	return 0;
}