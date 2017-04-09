#include<bits/stdc++.h>
using namespace std;
vector<vector<double> > getShortDistance(vector<double> graph[20],int n)
{
    int i, j, k;
    vector<vector<double> > dist(n);
    for(i=0; i<n; i++)
        dist[i].resize(n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    return dist;
}
int main()
{
    freopen("input.txt","r",stdin);
    vector<double> graph[20];
    int i,j,n,m;
    n=10,m=10;
    double x;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf("%lf",&x);
            if(x==0.0)
                graph[i].push_back(INT_MAX);
            else
                graph[i].push_back(x);
        }
    }
    vector<vector<double> > minDist = getShortDistance(graph,n);
    freopen("out.txt","w",stdout);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%lf\t\t",minDist[i][j]);
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
}
