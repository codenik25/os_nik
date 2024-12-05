#include<iostream>
using namespace std;

int main()
{
    int at[10],bt[10],ct[10],tat[10],wt[10],rt[10],p[10];
    int n;

    cout<<"Enter number of proceesee:";
    cin>>n;
    cout<<"Enter the arrival time and burst time for each processes"<<endl;
    for(int i=0;i<n;i++){
        cout<<"For Process "<<i+1<<endl;
        cout<<"Arrival Time:";
        cin>>at[i];
        cout<<"Burst Time:";
        cin>>bt[i];
    }
        int sum=at[0];
        for(int j=0;j<n;j++){
            sum=sum+bt[j];
            ct[j]=sum;
        }
        for(int k=0;k<n;k++){
            tat[k]=ct[k]-at[k];
        }
        for(int l=0;l<n;l++){
            wt[l]=tat[l]-bt[l];
        }
        cout<<"Solution\n\n";
        cout<<"AT\tBT\tCT\tTAT\tWT\t\n\n";
        for(int i=0;i<n;i++){
            cout<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl; 
        }
    
    return 0;
}