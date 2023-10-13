#include <algorithm>
#include <iostream>
#include <vector>

// Modifying Algorithms (���Ҹ� �����ϴ� �˰���)

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
	std::vector<int> vec01;	// std::less() ������������ ���ĵ� ����
	vec01.push_back(1);
	vec01.push_back(3);
	vec01.push_back(5);

	std::vector<int> vec02;
	vec02.push_back(2);
	vec02.push_back(4);

	std::vector<int> vec03(10);	// ������ ���� �����ϴ� ���̱� ������, �����̳��� ���� �������� ���� �Ҵ�޾ƾ� �Ѵ�!

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
	// �⺻������ std::less �������� �պ� ���Ŀ� ���� ������ �������� ���� ���Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ��.
	//So, ���� �������� ���ĵǾ��� �������� ������� �Ѵ�!!!

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
	std::cout << "�պ��� ������: ";
	
	std::vector<int>::iterator iter = vec03.begin();
	for (; iter != iterEnd; ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';
	std::cout << "###################\n";

	std::vector<int> vec11;
	vec11.push_back(5);	// std::greater() ������������ ���ĵ� ����
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
	std::cout << "�պ��� ������: ";

	iter = vec13.begin();
	for (; iter != iterEnd; ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	return 0;
}