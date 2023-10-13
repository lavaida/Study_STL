#include <algorithm>
#include <iostream>
#include <vector>

// Modifying Algorithms (원소를 수정하는 알고리즘)

template <typename T>
struct Greater
{
public:
	bool operator() (const T &lhs, const T &rhs) const
	{
		return lhs > rhs;
	}
};


int main(void)
{
	std::vector<int> vec01;	// std::less() 오름차순으로 정렬된 원소
	vec01.push_back(1);
	vec01.push_back(3);
	vec01.push_back(5);

	std::vector<int> vec02;
	vec02.push_back(2);
	vec02.push_back(4);

	std::vector<int> vec03(10);	// 원소의 값을 수정하는 것이기 때문에, 컨테이너의 원소 개수보다 많이 할당받아야 한다!

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';	// 1 3 5
	}
	std::cout << '\n';
	std::cout << "vec02: ";
	for (size_t i = 0; i < vec02.size(); ++i)
	{
		std::cout << vec02[i] << ' ';	// 2 4
	}
	std::cout << '\n';
	std::cout << "vec03: ";
	for (size_t i = 0; i < vec03.size(); ++i)
	{
		std::cout << vec03[i] << ' ';	// 0 0 0 0 0 / 0 0 0 0 0
	}
	std::cout << '\n';

	std::cout << "###################\n";

	std::vector<int>::iterator iterEnd;
	iterEnd = std::merge(vec01.begin(), vec01.end(), vec02.begin(), vec02.end(), vec03.begin());
	// 기본적으로 std::less 오름차순 합병 정렬에 의해 합쳐진 순차열의 다음 원소를 가리키는 반복자를 반환함.
	//So, 같은 기준으로 정렬되어진 순차열을 대상으로 한다!!!

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';	// 1 3 5
	}
	std::cout << '\n';
	std::cout << "vec02: ";
	for (size_t i = 0; i < vec02.size(); ++i)
	{
		std::cout << vec02[i] << ' ';	// 2 4
	}
	std::cout << '\n';
	std::cout << "vec03: ";
	for (size_t i = 0; i < vec03.size(); ++i)
	{
		std::cout << vec03[i] << ' ';	// 1 2 3 4 5 / 0 0 0 0 0
	}
	std::cout << '\n';

	std::cout << "###################\n";
	std::cout << "합병된 순차열: ";
	
	std::vector<int>::iterator iter = vec03.begin();
	for (; iter != iterEnd; ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';
	std::cout << "###################\n";

	std::vector<int> vec11;
	vec11.push_back(5);	// std::greater() 내림차순으로 정렬된 원소
	vec11.push_back(3);
	vec11.push_back(1);

	std::vector<int> vec12;
	vec12.push_back(4);
	vec12.push_back(2);

	size_t elementCount = vec11.size() + vec12.size();
	std::vector<int> vec13(elementCount);

	std::cout << "vec11: ";
	for (size_t i = 0; i < vec11.size(); ++i)
	{
		std::cout << vec11[i] << ' ';	// 5 3 1
	}
	std::cout << '\n';
	std::cout << "vec12: ";
	for (size_t i = 0; i < vec12.size(); ++i)
	{
		std::cout << vec12[i] << ' ';	// 4 2
	}
	std::cout << '\n';
	std::cout << "vec13: ";
	for (size_t i = 0; i < vec13.size(); ++i)
	{
		std::cout << vec13[i] << ' ';	// 0 0 0 0 0
	}
	std::cout << '\n';

	std::cout << "###################\n";
	iterEnd = std::merge(vec11.begin(), vec11.end(), vec12.begin(), vec12.end(), vec13.begin(), std::greater<int>());

	//iterEnd = std::merge(vec11.begin(), vec11.end(), vec12.begin(), vec12.end(), vec13.begin(), Greater<int>());

	std::cout << "vec11: ";
	for (size_t i = 0; i < vec11.size(); ++i)
	{
		std::cout << vec11[i] << ' ';	// 5 3 1
	}
	std::cout << '\n';
	std::cout << "vec12: ";
	for (size_t i = 0; i < vec12.size(); ++i)
	{
		std::cout << vec12[i] << ' ';	// 4 2
	}
	std::cout << '\n';
	std::cout << "vec13: ";
	for (size_t i = 0; i < vec13.size(); ++i)
	{
		std::cout << vec13[i] << ' ';	// 5 4 3 2 1
	}
	std::cout << '\n';

	std::cout << "###################\n";
	std::cout << "합병된 순차열: ";

	iter = vec13.begin();
	for (; iter != iterEnd; ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	return 0;
}