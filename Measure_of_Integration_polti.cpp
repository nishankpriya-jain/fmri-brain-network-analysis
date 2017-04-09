#include<bits/stdc++.h>
using namespace std;
double getWeightPath(vector<double> graph[20],int n,int m)
{
    int i,j;
    double sum=0,tmp=0,N=n;
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<m;j++)
        {
            if(j!=i&&graph[i][j]!=INT_MAX)
                sum+=graph[i][j];
        }
        tmp+=(sum/(N-1.0));
    }
    return tmp/N;
}
int main()
{
    //out.txt is the matrix obtained from Shortest path matrix
    freopen("out.txt","r",stdin);
    vector<double> graph[20];
    int i,j,n,m;
    n=10,m=10;
    double x;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%lf",&x);
            graph[i].push_back(x);
        }
    }
    double weightPath = getWeightPath(graph,n,m);
    printf("%lf\n",weightPath);
    fclose(stdin);
}
