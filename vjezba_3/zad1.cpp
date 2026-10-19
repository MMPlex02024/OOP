#include <iostream>
#include <vector>
#include <algorithm>

void input_vector(std::vector <int>& v) {

	int num = {2};
	while (num !=0 ) {
		std::cin >> num;
		v.push_back(num);
		std::cout << v.size()<< "\n";
		std::cout << v.capacity() <<"\n";
	}
	v.pop_back();

}
void print_vector(const std::vector<int>& v) {

	std::cout << "****Normalni redoslijed******\n";
	for (int num : v) std::cout << num << " ";
	std::cout << '\n' << std::endl;
	
	std::cout << "*****Obrunti redoslijed******\n";
	for (auto bn = v.rbegin(); bn != v.rend(); bn++) {
		std::cout << *bn << " ";
	}
}



int main() {

	std::vector <int> niz{};
	niz.reserve(100);

	input_vector(niz);
	niz.shrink_to_fit();
	std::cout << niz.capacity();
	print_vector(niz);

	return 0;
}