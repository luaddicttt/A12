#include "data.hpp"

int main(int argc, const char *argv[]) {
	if(argc!=2) {
		puts("error: no input files");
		return 1;
	} else {
		Init(argv[1]);
	}
	return 0;
}
