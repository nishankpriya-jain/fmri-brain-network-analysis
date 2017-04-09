#include<bits/stdc++.h>
using namespace std;
//note:  transitivity is not defined for individual nodes.

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



//---------------------------
double getTransitivity(int n,vector<double> g[100],vector<int>degree,vector<double>triangle_val){
  
  double transitivity=0,numerator=0,denominator=0;
  for(int i=0;i<n;i++){
     numerator+=(2*triangle_val[i]);
     if(degree[i]>1){
        denominator+=(1.0*degree[i]*(degree[i]-1));
     }
  }
  transitivity=numerator/denominator;
  return transitivity;
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
    vector<double> triangle_val= getTriangle(graph,n);
    vector<int>degree=getUnweightedDegree(graph,n);
    //---------------------------------
    double transitivity=getTransitivity(n,graph,degree,triangle_val); 
   //---------------
    cout<<"transitivity="<<transitivity<<endl;
return 0;
}
