//Profile a connected undirected unweighted graph for the following properties.
#include <stdlib.h>
#include "graphprofile.h"

// 1. What is average degree of a vertex in the graph?
int avgDegree(int **g, int n) {
	int i,j,deg=0;
	if(n)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(g[i][j]) deg++;
			}	
		}
		return deg/n;
	}
    return 0;
}

// 2. Is the graph a regular graph?
int isRegular(int **g, int n) {
	int i,j;
	int k=avgDegree(g,n);
	for(i=0;i<n;i++)
	{
		int degI=0;
		for(j=0;j<n;j++)
		{
			if(g[i][j])	degI++;
		}
		if(degI!=k)
			return 0; 
	}
    return 1;
}

// 3. Is the graph a complete graph?
int isComplete(int **g, int n) {
	if(isRegular(g,n) && avgDegree(g,n)==n-1)
    	return 1;
    return 0;
}

// 4. Is the graph a cycle graph?
int isCycleGraph(int **g, int n) {
	if(isRegular(g,n) && avgDegree(g,n)==2)
		return 1;
    return 0;
}

// 5. Is the graph a path graph but not a cycle graph?
int isPathGraph(int **g, int n) {
    int i,j,pendant=0;
    for(i=0;i<n;i++)
    {
    	int degI=0;
    	for(j=0;j<n;j++)
    	{
    		if(g[i][j]) degI++;
    	}
    	if(degI==1)
    		pendant++;
    	else if(degI==2)
    		continue;
    	else
    		return 0;
    }
    if(pendant==2)
    	return 1;
    return 0;
}

// 6. Does the graph has an Euler circuit?
int hasEulerCkt(int **g, int n) {
	int i,j;
	for(i=0;i<n;i++)
	{
		int degI=0;
		for(j=0;j<n;j++)
		{
			if(g[i][j]) degI++;
		}
		if(degI%2)
			return 0;
	}
    return 1;
}

// 7. Does the graph has an Euler path but not an Euler circuit?
int hasEulerPath(int **g, int n) {
	int i,j,oddcount=0;
	for(i=0;i<n;i++)
	{
		int degI=0;
		for(j=0;j<n;j++)
		{
			if(g[i][j]) degI++;
		}
		if(degI%2)
			oddcount++;
	}
	if(oddcount==2)
    	return 1;
    return 0;
}

// 8. Does the graph satisfy the sufficient condition of the Ore's theorem?
// Sufficient condition for the graph to have a Hamilton according the Ore's theorem:
// deg(u) + deg(v) ≥ n for every pair of nonadjacent vertices u and v in the graph
int satifiesOresTheorem(int **g, int n) {
    int u,v,i,degU,degV;
    for(u=0;u<n-1;u++)
    {
    	for(v=u+1;v<n;v++)
    	{
    		if(!g[u][v])
    		{
    			degU=degV=0;
    			for(i=0;i<n;i++)
    			{
    				if(g[u][i])
    					degU++;
    				if(g[v][i])
    					degV++;
    			}
    			if(degU+degV<n)	
    				return 0;
    		}
    	}
    }
    return 1;
}
