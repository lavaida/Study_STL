#include <iostream>

template <typename IterT, typename Func>
void For_each(IterT begin, IterT end, Func func)
{
	while (begin != end)
	{
		func(*(begin++));
	}
}

template <typename T>
class PrintFunctor
{
public:
	explicit PrintFunctor(const std::string &s = " ")
		: sep(s)
	{}

public:
	void operator() (T data) const
	{
		std::cout << data << sep;
	}

private:
	std::string sep;	// separator
};


template <typename T1, typename T2>
struct Pair	// STL에서 데이터의 쌍을 표현할 때 사용되는 Pair 클래스 객체 구현
{
public:
	Pair(const T1 &first, const T2 &second)
		: first(first), second(second)
	{}

public:
	T1 first;
	T2 second;
};

int main(void)
{
	int arr[3] = { 1, 2, 3 };
	For_each(arr, arr + 3, PrintFunctor<int>());
	std::cout << '\n';

	std::cout << "#########################\n";

	std::string arr02[3] = { "A", "AB", "ABC" };
	For_each(arr02, arr02 + 3, PrintFunctor<std::string>("*\n"));
	std::cout << "#########################\n";

	Pair<int, std::string> pair01 = { 10, "ABC" };
	std::cout << "first: " << pair01.first << '\n';
	std::cout << "second: " << pair01.second << '\n';
	std::cout << "#########################\n";

	return 0;
}