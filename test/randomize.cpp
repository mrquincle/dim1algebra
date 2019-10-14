#include <dim1algebra.hpp>

#include <unordered_map>

using namespace algebra;

int main() {
//	std::vector<int> test = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int> test = {1, 2, 3, 4};

	print(test.begin(), test.end());

//	random_order(test.begin(), test.end());
//	print(test.begin(), test.end());

	std::unordered_map<int,int> occurances;
	
	std::unordered_map<int,int> uniq_occurances;

	std::vector<int> base5 = { 5*5*5, 5*5, 5, 1};
	std::vector<int> output = { 1, 2, 3, 4};
	int sum = std::inner_product(output.begin(), output.end(), base5.begin(), 0);
	std::cout << "Sum: " << sum << std::endl;

	int T = 100000;
	for (int i = 0; i < T; i++) {
		std::vector<int> output = { 0, 0, 0, 0};
		random_subset(test.begin(), test.end(), output.size(), output.begin());

		std::set<int> test1;
		test1.clear();
		for (int j = 0; j < output.size(); j++) {
			test1.insert(output[j]);
			int fj = output[j];
			occurances[fj]++;
		}

		if (test1.size() != 4) {
			print(output.begin(), output.end());
			assert (test1.size() == 4);
			break;
		} else {
			print(output.begin(), output.end());
		}
		int sum = std::inner_product(output.begin(), output.end(), base5.begin(), 0);
		uniq_occurances[sum]++;
	}
	for (auto it: occurances) {
		std::cout << "" << it.second << " ";
	}
	std::cout << std::endl;
	for (auto it: uniq_occurances) {
		std::cout << it.first << ": " << it.second << " " << std::endl;
	}
	std::cout << std::endl;

}
