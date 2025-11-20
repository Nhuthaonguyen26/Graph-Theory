#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main(){
    int n,s,t; cin>>n>>s>>t;
    double x[10001],y[10001],r[10001];
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i]>>r[i];

    // T?o ma tr?n k? (??n gi?n)
    int cost[10001][10001];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cost[i][j]=INF;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) if(i!=j){
            double d = hypot(x[i]-x[j],y[i]-y[j])-(r[i]+r[j]);
            if(d<=60){
                cost[i][j] = (d>50) ? 1 : 0;
            }
        }

    int jump[10001], step[10001], trace[10001], used[10001];
    for(int i=1;i<=n;i++){jump[i]=INF; step[i]=INF; trace[i]=-1; used[i]=0;}
    jump[s]=0; step[s]=0;

    for(int k=1;k<=n;k++){
        int u=-1;
        for(int i=1;i<=n;i++)
            if(!used[i] && (u==-1 || make_pair(jump[i],step[i])<make_pair(jump[u],step[u])))
                u=i;
        if(u==-1) break;
        used[u]=1;
        for(int v=1;v<=n;v++) if(cost[u][v]!=INF){
            int nj = jump[u]+cost[u][v];
            int ns = step[u]+1;
            if(make_pair(nj,ns)<make_pair(jump[v],step[v])){
                jump[v]=nj; step[v]=ns; trace[v]=u;
            }
        }
    }

    if(jump[t]==INF){cout<<0;return 0;}
    cout<<1<<"\n"<<jump[t]<<" "<<step[t]<<"\n";
    vector<int> path; vector<int> action;
    for(int v=t;v!=-1;v=trace[v]){
        path.push_back(v);
        if(trace[v]!=-1) action.push_back(cost[trace[v]][v]);
    }
    reverse(path.begin(),path.end());
    reverse(action.begin(),action.end());
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" "<<(i==0?0:action[i-1])<<"\n";
    }
}

