#include<bits/stdc++.h>
using namespace std;
map<int,int> getWeightedDegree(vector<double> graph[20],int n,int m)
{
    int i,j,cnt=0,tmp;
    map<int,int> weightDegree;
    vector<int> inEdge,outEdge;
    for(i=0;i<n;i++)
    {
        cnt=0;
        for(j=0;j<m;j++)
        {
            if(graph[i][j]!=0.0)
                cnt++;

        }
        outEdge.push_back(cnt);
        tmp=cnt;
        for(j=0;j<m;j++)
        {
            if(graph[j][i]!=0.0)
                cnt++;
        }
        inEdge.push_back(cnt-tmp);
        weightDegree[i]=tmp;
    }
    return weightDegree;
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
    map<int,int> weightedDegree;
    weightedDegree  = getWeightedDegree(graph,n,m);
    for(i=0;i<n;i++)
    {
        printf("%d %d\n",i,weightedDegree[i]);
    }
    fclose(stdin);
}
