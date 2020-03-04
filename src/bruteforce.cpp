#include <algorithm>

const int MAXN=20;
int n, m, num, s;

int num_truck;
struct Truck {
	int weight, cost;
	operator int() {
		return weight;
	}
} trucks[200];

int x[MAXN];
int weight[1<<MAXN];

int dis[MAXN][MAXN];

int cost[1<<MAXN];
int end_by[1<<MAXN];
int path[1<<MAXN][MAXN];
int from[1<<MAXN][MAXN];

int f[1<<MAXN];
int p[1<<MAXN];

int main() {
	scanf("%d%d%d", &n, &m, &s);
	memset(dis, 0x7F, sizeof(dis));
	while(m--) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		dis[x][y]=dis[y][x]=z;
	}
	for(int k=0; k<n; ++k)
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				dis[i][j]=std::min(dis[i][j], dis[i][k]+dis[k][j]);
	scanf("%d", &num);
	for(int i=0; i<num; ++i) {
		int w;
		scanf("%d%d", &x[i], &w);
		for(int j=0; j<(1<<i); ++j)
			weight[j|1<<i]=weight[j]+w;
	}
	scanf("%d", &num_truck);
	for(int i=0; i<num_truck; ++i)
		scanf("%d%d", &trucks[i].weight, &trucks[i].cost);
	sort(trucks, trucks+num_truck);
	memset(cost, 0x7F, sizeof(cost));
	memset(path, 0x7F, sizeof(path));
	for(int i=0; i<(1<<num); ++i)
		for(int j=0; j<num; ++j)
			if(i&1<<j) {
				int g=path[i][j]+dis[x[j]][s];
				if(g<cost[i]) {
					cost[i]=g;
					end_by[i]=j;
				}
			} else {
				if(i==0) path[1<<j][j]=min(path[1<<j][j], dis[s][x[j]]);
				else {
					for(int k=0; k<num; ++k)
						if(i&1<<k) {
							int g=path[i][k]+dis[x[k]][x[j]];
							if(g<path[i|1<<j][j]) {
								path[i|1<<j][j]=g;
								from[i|1<<j][j]=k;
							}
						}
				}
			}
	memset(f, 0x7F, sizeof(f));
	f[0]=0;
	for(int i=0; i<(1<<num); ++i) {
		for(int j=i; j>0; j=(j-1)&i) {
			int k=lower_bound(trucks, trucks+num_truck, weight[j])-trucks;
			if(k<num_truck) {
				int g=f[i^j]+cost[j]+trucks[k].cost;
				if(g<f[i]) {
					f[i]=g;
					p[i]=j;
				}
			}
		}
	}
	int i=(1<<num)-1;
	while(i>0) {
		int j=p[i]; i^=j;
		printf("%d %d %d", weight[j], cost[j], s);
		int k=end_by[j];
		while(j>0) {
			printf("-%d", x[k]);
			tie(j, k)=tuple(j^(1<<k), from[j][k]);
		}
		printf("-%d\n", s);
	}
	return 0;
}
