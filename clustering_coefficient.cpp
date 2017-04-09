#include<bits/stdc++.h>
using namespace std;
//note: clustering coefficient 0 to 1.

//---utilities-------------------
vector<int> getUnweightedDegree(vector<double> g[100],int n){
     vector<int>degree(100,0);
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)continue;
            if(g[i][j]>0){
               degree[i]++;
            }
        }
     }
   return degree;
}

vector<double> getGmOfTriangles(vector<double> graph[100],int n,int m)
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



//---------------------------
double getClusteringCoefficient(int n,vector<double> g[100],vector<int>degree,vector<double>triangle_val){
  
  double clustering_coefficient=0,tmp=0;
  for(int i=0;i<n;i++){
     if(degree[i]>1){
       tmp=2*triangle_val[i];
       tmp=tmp/(1.0*degree[i]*degree[i]-1);
       clustering_coefficient+=tmp; 
     }
  }
  clustering_coefficient/=(1.0*n); 
  return clustering_coefficient;
}


int main(){
    //----------previous work
    freopen("input.txt","r",stdin);
    vector<double> graph[100];
    int i,j,n,m;
    n=10;
    double x;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%lf",&x);
            graph[i].push_back(x);
        }
    }
    vector<double> triangle_val= getGmOfTriangles(graph,n, n);
    vector<int>degree=getUnweightedDegree(graph,n);
    //---------------------------------
    double clustering_coefficient=getClusteringCoefficient(n,graph,degree,triangle_val); 
   //---------------
    cout<<"Clustering coefficient="<<clustering_coefficient<<endl;
return 0;
}
