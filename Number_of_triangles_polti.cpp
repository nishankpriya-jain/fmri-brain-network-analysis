#include<bits/stdc++.h>
using namespace std;
vector<double> getGmOfTriangles(vector<double> graph[20],int n,int m)
{
    int i,j,k;
    double sum=0;
    vector<double> ans;
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<m;j++)
        {
            for(k=0;k<m;k++)
            {
                if(i!=j&&j!=k&&k!=i)
                {
                    if(graph[i][j]&&graph[j][k]&&graph[i][k])
                    {
                        sum+=cbrt(graph[i][j]*graph[j][k]*graph[i][k]);
                    }
                }
            }
        }
        ans.push_back(sum);
    }
    return ans;
}
vector<int> getDirectedTriangles(vector<double> graph[20],int n,int m)
{
    int i,j,a[n][m],k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(graph[i][j]!=0.0)
                a[i][j]=1;
            else
                a[i][j]=0;
        }
    }
    int sum=0;
    vector<int> ans;
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<m;j++)
        {
            for(k=0;k<m;k++)
            {
                if(i!=j&&j!=k&&k!=i)
                {
                    sum+=(a[i][j]+a[j][i])*(a[i][k]+a[k][i])*(a[j][k]+a[k][j]);
                }
            }
        }
        sum/=2;
        ans.push_back(sum);
    }
    return ans;
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
    vector<double> gmOfTriangles = getGmOfTriangles(graph,n,m);
    vector<int> directedTriangles = getDirectedTriangles(graph,n,m);
    for(i=0;i<n;i++)
    {
        printf("%lf\n",gmOfTriangles[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n",directedTriangles[i]);
    }
    fclose(stdin);
}
