#include <bits/stdc++.h>

using namespace std;

struct Point{
    int x,y;
};
Point c[100100];
bool cmpbyx(Point a,Point b){
    return a.x<b.x;
}
bool cmpbyy(Point a,Point b){
    return a.y<b.y;
}
double dist(Point a, Point b){
    return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+1.0*(a.y-b.y)*(a.y-b.y));
}
double bruteForce(Point P[],int n){
    double Min=2000000000;
    int i,j;
    for(i=0;i<n;++i){
        for(j=i+1;j<n;j++){
            Min=min(Min,dist(P[i],P[j]));
        }
    }
    return Min;
}

double stripClosest(Point strip[],int n, double d){
    int i,j;
     double Min=d;
     sort(strip,strip+n,cmpbyy);
     for(i=0;i<n;++i){
        for(j=i+1;j<n&&(strip[j].y-strip[i].y)<Min;++j){
            Min=min(Min,dist(strip[i],strip[j]));
        }
     }
     return Min;
}

double closest(Point P[],int n){
    if(n<=3) return bruteForce(P,n);
    int mid=n/2;
    Point midPoint = P[mid];
    double dl=closest(P,mid);
    double dr=closest(P+mid,n-mid);
    double d=min(dl,dr);
    Point strip[n+2];
    int j=0,i=0;
    for(i=0;i<n;i++){
        if(abs(P[i].x-midPoint.x)<d)
            strip[j]=P[i],j++;
    }
    return min(d,stripClosest(strip,j,d));
}

int main(){
    int i,j,n,r,d,w;
    cin>>w;
    for(i=0;i<w;i++){
        cin>>n>>r>>d;
        for(j=0;j<n;j++){
            cin>>c[j].x>>c[j].y;
        }
        sort(c,c+n,cmpbyx);
        double dist=closest(c,n);
        (d<=dist-2*r)?cout<<"Y\n":cout<<"N\n";
    }
}

