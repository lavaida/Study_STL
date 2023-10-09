#include <iostream>
#include <vector>

// Non-modifying Algorithms (원소를 수정하지 않는 알고리즘)

struct Data
{
public:
	Data(int n, int m)
		: Num01(n), Num02(m)
	{}
	int Num01;
	int Num02;
};

bool Compare(const Data &lhs, const Data &rhs)
{
	if (lhs.Num01 < rhs.Num01)
	{
		return true;
	}
	else if (lhs.Num01 > rhs.Num01)
	{
		return false;
	}
	else
	{
		return lhs.Num02 < rhs.Num02;
	}
}

int main(void)
{
	std::vector<int> vec;
	vec.push_back(1);	// iter
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);	// iter02
	vec.push_back(5);

	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << ' ';
	}
	std::cout << '\n';

	std::cout << "#####################\n";

	std::vector<int>::iterator iter;
	iter = std::min_element(vec.begin(), vec.end());	// 값이 중복이라면 먼저 나온 원소의 반복자 반환.
	std::cout << *iter << '\n';

	if (iter == vec.begin())
	{
		std::cout << "vec.begin()\n";
	}

	std::cout << "#####################\n";

	std::vector<int>::iterator iter02;
	iter02 = std::max_element(vec.begin(), vec.end());	// 값이 중복이라면 먼저 나온 원소의 반복자 반환.
	std::cout << *iter02 << '\n';

	if (iter02 == vec.end() - 2)
	{
		std::cout << "vec.end() - 2\n";
	}

	std::cout << "#####################\n";

	std::vector<Data> vec02;
	vec02.push_back(Data{ 1, 1 });
	vec02.push_back(Data{ 1, 1 });
	vec02.push_back(Data{ 1, 2 });
	vec02.push_back(Data{ 2, 1 });

	std::vector<Data>::iterator iter03;
	iter03 = std::max_element(vec02.begin(), vec02.end(), Compare);
	std::cout << iter03->Num01 << ", " << iter03->Num02 << '\n';

	return 0;
}