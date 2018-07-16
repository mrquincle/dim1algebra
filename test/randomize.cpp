#include <dim1algebra.hpp>

using namespace algebra;

int main() {
	std::vector<int> test = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

	print(test.begin(), test.end());

	random_order(test.begin(), test.end());
	print(test.begin(), test.end());

	std::vector<int> output = { 0, 0, 0, 0};
	random_subset(test.begin(), test.end(), output.size(), output.begin());

	print(output.begin(), output.end());

}
