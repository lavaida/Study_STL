#include <iostream>
#include <vector>

template <typename T1, typename T2>
struct Pair
{
public:
	Pair()
		: first(0), second(0)
	{
		std::cout << "Pair()\n";
	}
	Pair(T1 first, T2 second)
		: first(first), second(second)
	{
		std::cout << "Pair(T1 first, T2 second)\n";
	}
	Pair(const Pair &ref)
		: first(ref.first), second(ref.second)
	{
		std::cout << "Pair(const Pair &ref)\n";
	}
	~Pair()
	{
		std::cout << "~Pair()\n";
	}
public:
	T1 first;
	T2 second;
};


int main(void)
{
	std::vector<Pair<int, int>> vec;
	std::cout << "###################\n";
	vec.push_back(Pair<int, int>(1, 10));
	std::cout << "###################\n";
	vec.emplace_back(2, 20);
	std::cout << "###################\n";

	// �̷л����δ� push_back() ��� �Լ��� ����� ��, emplace_back() ��� �Լ��� ����� ������
	//�ӽ� ��ü�� 1�� �� ����ٰ� ������, �����Ϸ��� ����ȭ�� �ؼ� �� ���� ������.
	//���� ������ڵ� Ȯ���غ��� �� �� ����.

	return 0;
}