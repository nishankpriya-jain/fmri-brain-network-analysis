#include<bits/stdc++.h>
using namespace std;
/*note:  the local efficiency of node i is defined with
respect to the subgraph comprising all of i’s neighbors, after removal of i and its incident edges. 
*/
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
double shortestDist(vector<double>g[100],int refer,int u,int v,int n){
   double dist[100][100];
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         if(i==j){
            dist[i][j]=0;
         }
         else if(g[i][j]!=0 && (g[i][refer]>0 || g[j][refer]>0)){//only for neighbours
            dist[i][j]=g[i][j];
         }
         else{
            dist[i][j]=1000;   
         }
      }
   }  
   
   
   for(int k=0;k<n;k++){
      if(g[refer][k]==0)continue;
      for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
           }
      }
   }
   
  return dist[u][v];
}


//---------------------------
double getLocalEfficiency(int n,vector<double> g[100],vector<int>degree){
     double local_efficiency=0,numerator,denominator,tmp;
     for(int i=0;i<n;i++){
        if(degree[i]>1){
           //calculating numerator
           numerator=0;
           for(int j=0;j<n;j++){
               if(i==j || g[i][j]==0)continue;
               for(int h=0;h<n;h++){
                    if(g[i][h]==0)continue;
                    tmp=g[i][j]*g[i][h];
                    double sdist=shortestDist(g,i,j,h,n);//length of the shortest path between j and h, that contains only 	neighbors of i.
                  // cout<<"i="<<i<<"j="<<j<<"h="<<h<<"sd="<<sdist<<endl;
                   if(sdist==0){
                     continue;
                   }
                   else if(sdist>=1000){
                      tmp=0;
                   }
                   else{
                    tmp/=sdist;
                    tmp=pow(tmp,0.33);
                   }
          //         cout<<"tmp="<<tmp<<endl;
                   numerator+=tmp;
               }            
           }
           denominator=(1.0*degree[i]*(degree[i]-1));
        //  cout<<"numerator="<<numerator<<" denominator="<<denominator<<endl;
        //  cout<<"local efficiency of i="<<i<<" "<<(numerator/denominator)<<endl;
         local_efficiency+=(numerator/denominator);    
       }
     }
     local_efficiency/=2;
     return local_efficiency;
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
    vector<int>degree=getUnweightedDegree(graph,n);
    //---------------------------------
    double local_efficiency=getLocalEfficiency(n,graph,degree); 
   //---------------
    cout<<"local efficiency="<<local_efficiency<<endl;
return 0;
}
