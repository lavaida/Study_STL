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

	// 이론상으로는 push_back() 멤버 함수를 사용할 때, emplace_back() 멤버 함수를 사용할 때보다
	//임시 객체가 1개 더 생긴다고 했지만, 컴파일러가 최적화를 해서 별 차이 없었음.
	//추후 어셈블리코드 확인해봐야 할 것 같음.

	return 0;
}