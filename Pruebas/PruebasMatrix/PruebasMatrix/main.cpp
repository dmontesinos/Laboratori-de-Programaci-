#include <iostream>
#include <vector>

int main()
{
	std::vector <std::vector<int> > vec2D(10, std::vector<int>(4, 0));

	for (auto vec : vec2D)
	{
		for (auto x : vec)
			std::cout << x << " , ";

		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 4; j++)
			vec2D[i][j] = i * j;

	for (auto vec : vec2D)
	{
		for (auto x : vec)
			std::cout << x << " , ";

		std::cout << std::endl;
	}


	vec2D.push_back(std::vector<int>(4, 11));

	std::cout << std::endl;

	for (auto vec : vec2D)
	{
		for (auto x : vec)
			std::cout << x << " , ";

		std::cout << std::endl;
	}
	return 0;
}