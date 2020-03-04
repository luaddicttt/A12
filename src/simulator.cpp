#include "define.hpp"
#include "config.hpp"
#include "individual.hpp"

vector<Individual> s, t;

void Solve() {
	IndividualInit(s, POPULATION);
	for(int k=0; k<TIMES; ++k) {
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				if(i!=j && Random(PR_CROSS)) {
					Cross(s[i], s[j], t);
				}
		for(int i=0; i<m; ++i)
			if(Random(PR_MUTATION))
				Mutation(t, i);
		Select(t, POPULATION);
		s.swap(t);
		t.clear();
	}
	//
}
