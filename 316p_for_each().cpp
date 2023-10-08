#include <algorithm>
#include <iostream>
#include <vector>

// Non-modifying Algorithms (���Ҹ� �������� �ʴ� �˰���)
//+ Modifying Algorithms(���Ҹ� �����ϴ� �˰���)

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

	// [begin, end) ������ ���ؼ� func(*iterator) �Լ��� ����
	//- ������ � �����̳Ŀ� ���� ������ ���� �����ϴ� �˰����� �� �� �ִ�.
	std::for_each(vec.begin(), vec.end(), Print);	// �Լ� �����͸� �̿��� ����
	std::cout << '\n';

	std::cout << "##################\n";

	std::for_each(vec.begin(), vec.end(), PrintFunctor());	// Function Object(Functor)�� �̿��� ����.
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