
i
next[i]

mutation:
+1	!0 -> 0
-1	0 -> !0
0	!0 <-> !0
	!0 <-> 0

fitness: gen
in[i]=sum(next[j]==i)
in[i]==0	i -> next[i] -> next[next[i]] -> ... -> 0	sum(dis[j][next[j]])
// calc
// validate

cross:


init:
r target_v 最小生成树
