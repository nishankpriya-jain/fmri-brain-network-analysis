#include<bits/stdc++.h>
using namespace std;

//---utilities-------------------
void printWD(vector<double> wd,int n){
   cout<<"node wdeg\n";
   for(int i=0;i<n;i++){
      cout<<i<<" "<<wd[i]<<endl;
   }
   cout<<"------------\n";
}
void printDP(vector<pair<double,double> >deg_prob){
   cout<<"deg prob\n";
   for(int i=0;i<deg_prob.size();i++ ){
       cout<<deg_prob[i].first<<" "<<deg_prob[i].second<<endl;
   }
   cout<<"----------------\n";
} 

vector<double> getWeightedDegree(vector<double> g[100],int n){
     vector<double>wd(100,0);
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<g[i][j]<<" ";
            if(i==j)continue;
            if(g[i][j]>0){
               wd[i]+=g[i][j];
            }
        }
        cout<<endl;
     }
   return wd;
}

vector<pair<double,double> > getDegProb(vector<double> g[100],vector<double>wd,int n){
    map<double,double> deg_freq;
    set<double> uni_deg; 
    vector<pair<double,double> > deg_p;
    for(int i=0;i<n;i++){
      deg_freq[wd[i]]++;
      uni_deg.insert(wd[i]);
    }
    double prob=0;
    for(set<double>::iterator it=uni_deg.begin();it!=uni_deg.end();it++){
      //   cout<<"deg="<<*it<<endl;
       prob=(deg_freq[*it])/(1.*n);
       deg_p.push_back( make_pair(*it,prob) );
    }   
   return deg_p; 
}

//---------------------------
vector< pair<double,double> > findDegDistribution( vector<pair<double,double> > deg_prob){
      double total=0,prev=0,deg,prob;
      vector<pair<double,double> >  dd;
      for(int i=0;i<deg_prob.size();i++){
         total+=deg_prob[i].second;
      }
      for(int i=0;i<deg_prob.size();i++){
         deg=deg_prob[i].first;
         prob=deg_prob[i].second;
         dd.push_back( make_pair(deg,total-prev) );
         prev+=prob;
      }
      return dd;
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
    vector<double>wdegree=getWeightedDegree(graph,n);
    vector<pair<double,double> > deg_prob=getDegProb(graph,wdegree,n);
    //---------------------------------
    vector<pair<double,double> > degree_distribution=findDegDistribution(deg_prob);
   //---------------
 printWD(wdegree,n);
 printDP(deg_prob);
   cout<<"deg==>distribution:\n";
   for(int i=0;i<degree_distribution.size();i++){
      cout<<degree_distribution[i].first<<" "<<degree_distribution[i].second<<endl;
   }
return 0;
}
