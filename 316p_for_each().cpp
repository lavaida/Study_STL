#include <algorithm>
#include <iostream>
#include <vector>

// Non-modifying Algorithms (원소를 수정하지 않는 알고리즘)
//+ Modifying Algorithms(원소를 수정하는 알고리즘)

void Print(int num)
{
	std::cout << num << ' ';
}

class PrintFunctor
{
public:
	explicit PrintFunctor(char delimiter = ' ')
		: m_delimiter(delimiter)
	{}
public:
	void operator() (int num) const
	{
		std::cout << num << m_delimiter;
	}
private:
	char m_delimiter;
};

int main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	// [begin, end) 범위에 대해서 func(*iterator) 함수를 수행
	//- 내부의 어떤 연산이냐에 따라서 원소의 값을 수정하는 알고리즘이 될 수 있다.
	std::for_each(vec.begin(), vec.end(), Print);	// 함수 포인터를 이용한 예제
	std::cout << '\n';

	std::cout << "##################\n";

	std::for_each(vec.begin(), vec.end(), PrintFunctor());	// Function Object(Functor)를 이용한 예제.
	std::cout << '\n';

	std::cout << "##################\n";

	std::for_each(vec.begin(), vec.end(), PrintFunctor(','));
	std::cout << '\n';

	std::cout << "##################\n";

	std::for_each(vec.begin(), vec.end(), PrintFunctor('\n'));
	std::cout << '\n';

	std::cout << "##################\n";
	return 0;
}