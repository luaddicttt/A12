#include "data.hpp"
#include <ifstream>

void Init(const char *input) {
	ifstream fin(input);
	fin >> data;
	int num=0;
	vertex[map["start_vertex"]]=0;
	for(auto &&x: data["edge"]) {

	}
}
