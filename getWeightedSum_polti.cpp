#include<bits/stdc++.h>
using namespace std;
double getWeightSum(vector<double> graph[20],int n,int m)
{
    int i,j;
    double sum=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            sum+=graph[i][j];
    }
    return sum;
}
int main()
{
    freopen("input.txt","r",stdin);
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
    double sum = getWeightSum(graph,n,m);
    printf("%lf\n",sum);
    fclose(stdin);
}
