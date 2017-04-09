#include<bits/stdc++.h>
using namespace std;
/*note: 
*/
//---utilities-------------------
vector<vector<double> > getShortDistance(vector<double>g[100],int n)
{
    int i, j, k;
    vector<vector<double> > dist(n);
    for(i=0; i<n; i++)
        dist[i].resize(n);
    
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         if(g[i][j]!=0 ){
            dist[i][j]=g[i][j];
         }
         else{
            dist[i][j]=10000;   
         }
      }
   }  
   for(int k=0;k<n;k++){
      for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
           }
      }
   }
    return dist;
}

//---------------------------
vector<double> closenessCentrality (int n,vector<double>g[100]){
     vector<double>cc(n,0);
     vector<vector<double> > dist=getShortDistance(g,n);
     double numerator=n-1,denominator;
     for(int i=0;i<n;i++){
        denominator=0;
        for(int j=0;j<n;j++){
           if(i==j)continue;
           if(dist[i][j]<10000 && dist[i][j]>0){
               denominator+=dist[i][j];
           }
        }
        cc[i]=numerator/denominator;             
     }
  return cc;   
}

int main(){
    //----------previous work
    freopen("input.txt","r",stdin);
    vector<double> graph[100];
    int i,j,n,m;
    n=7;
    double x;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%lf",&x);
            graph[i].push_back(x);
        }
    }
    //---------------------------------
    vector<double> cc=closenessCentrality(n,graph); 
   //---------------
   for(int i=0;i<n;i++){
     cout<<"cc["<<i<<"]="<<cc[i]<<endl;
   }
return 0;
}
