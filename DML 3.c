//Profile a connected undirected unweighted graph for the following properties.
#include <stdlib.h>
#include "graphprofile.h"

// 1. What is average degree of a vertex in the graph?
int avgDegree(int **g, int n) {
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(g[i][j] == 1)
                count++;
        }
    }
    return (count/n);
}

// 2. Is the graph a regular graph?
int isRegular(int **g, int n) {
    int deg = 0;
    int count;
    for(int i = 0; i < n; i ++)
        if (g[0][i] == 1)   deg++;
    for(int i = 1; i < n; i++)
    {
        count = 0;
        for(int j = 0; j < n; j++)
            if (g[i][j] == 1)   count++;
        if(count != deg) return 0;
    }
    return 1;
}

// 3. Is the graph a complete graph?
int isComplete(int **g, int n) {
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if((i==j && g[i][j]==1) || (i!=j && g[i][j]==0))
                return 0;
        }
    }
    return 1;
}

// 4. Is the graph a cycle graph?
int isCycleGraph(int **g, int n) {
	int deg;
	for(int i = 0; i < n; i++)
	{
		deg = 0;
		for(int j = 0; j < n; j++)
		{
			if(g[i][j] == 1) 	deg++;
		}
		if (deg != 2) return 0;
	}
    return 1;
}

// 5. Is the graph a path graph but not a cycle graph?
int isPathGraph(int **g, int n) {
	int n_ones = 0;
	int n_twos = 0;
	int deg;
	for(int i = 0; i < n; i++)
	{
		deg = 0;
		for(int j = 0; j < n; j++)
		{
			if(g[i][j] == 1) 	deg++;
		}
		if (deg == 1) n_ones++;
		else if (deg == 2) n_twos++;
		else return 0;
	}
	if((n_ones != 2) && (n_twos != (n-2)))
		return 0;	
	
    return 1;
}

// 6. Does the graph has an Euler circuit?
int hasEulerCkt(int **g, int n) {
	int deg;
	for(int i = 0; i < n; i++)
	{
		deg = 0;
		for(int j = 0; j < n; j++)
		{
			if(g[i][j] == 1) 	deg++;
		}
		if ((deg%2) == 1)  return 0;
	}
    return 1;
}

// 7. Does the graph has an Euler path but not an Euler circuit?
int hasEulerPath(int **g, int n) {
	int n_odds = 0;
	int deg;
	for(int i = 0; i < n; i++)
	{
		deg = 0;
		for(int j = 0; j < n; j++)
		{
			if(g[i][j] == 1) 	deg++;
		}
		if ((deg%2) == 1) n_odds++;
	}
	if(n_odds != 2)
		return 0;	
	
    return 1;
}

// 8. Does the graph satisfy the sufficient condition of the Ore's theorem?
// Sufficient condition for the graph to have a Hamilton according the Ore's theorem:
// deg(u) + deg(v) ≥ n for every pair of nonadjacent vertices u and v in the graph
int satifiesOresTheorem(int **g, int n) {
	int deg_u;
	int deg_v;
	for(int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n ;j++)
		{
			deg_u = 0;
			deg_v = 0;
			//condition of non adjacent vertices
			if(g[i][j] == 0)
			{
				//degree of u
				for(int k = 0; k < n ; k++)
					if(g[i][k] == 1) deg_u++;
				//finding degree of v
				for(int l = 0; l < n ; l++)
					if(g[j][l] == 1) deg_v++;
				if ((deg_u + deg_v) < n) 	return 0;
					
			}
		}
	}
	
    return 1;
}
