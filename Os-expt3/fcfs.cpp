#include<iostream>

using namespace std;

class process{

public:
    int no,bt,at,tat,wt,ct;

public:
    process(){
        bt=0;
        at=0;
    }

    void getval(int a, int b, int c){
        no=a;
        bt=b;
        at=c;
    }

    void display(){
        cout<<" P"<<no<<"\t\t\t"<<bt<<"\t\t"<<at<<"\t\t"<<tat<<"\t\t"<<wt<<"\t\t"<<ct<<"\n";
    }

};

void sort_process(class process *p, int n){
class process temp;
int xchange=0;
for(int i=0; i<n-1; i++){
	xchange = 0;
	for(int j=0; j<n-i-1; j++){
		if((p[j].at > p[j+1].at)){
			temp = p[j];
			p[j] = p[j+1];
			p[j+1] = temp;
			xchange++;
		}
	}

	if(xchange==0)
		break;
}
}


void fcfs(int n, class process *p){

    int i,tat=0,wt=0,t=0,tstmp[100],ind=0;
sort_process(p,n);
if(p[0].at!=0)
tstmp[ind++]=-1;
tstmp[ind++]=0;
t = p[0].at+p[0].bt;
    p[0].tat=p[0].bt-p[0].at;
    p[0].ct = t;
    p[0].wt = 0;

    for(i=1;i<n;i++){
if (t < p[i].at){
t += p[i].at - t;
tstmp[ind++]=-1;
}
tstmp[ind++]=i;
        p[i].ct = t + p[i].bt;
t=p[i].ct;
        p[i].tat = p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
    }


    cout<<"Gantt Chart\n |";
    for(i=0;i<ind;i++){
if(tstmp[i]==-1 && i==0)
	continue;
if(tstmp[i]==-1)
	cout<<" idle |";
else
        cout<<"  P"<<p[tstmp[i]].no<<"  |";
    }

    cout<<"\n ";
	if(tstmp[0]!=-1)
	cout<<"0";

    for(i=0;i<ind;i++){
if(tstmp[i]==-1 && i==0){
	cout<<p[tstmp[i+1]].at;
	continue;
}
if(tstmp[i]==-1)
cout<<"      "<<p[tstmp[i+1]].at;
else
        cout<<"      "<<p[tstmp[i]].ct;
    }
    cout<<"\n";

    for(i=0;i<n;i++){
        tat+=p[i].tat;
        wt+=p[i].wt;
    }

    cout<<"Process \tBurst Time \tArrival Time \tTurnaround Time \tWaiting Time\t CT \n";
    for(i=0;i<n;i++){
        p[i].display();
    }

    cout<<"Average Turnaround Time: "<<(float)tat/n<<"\n";
    cout<<"Average Waiting Time: "<<(float)wt/n<<"\n";

}


int main(){
int n,i,f,b,a=0;
cout << "Enter the number of processes: ";
cin >> n;
process *p = new process[n];

cout<<"are the arrival times provided?(1 for yes/ 0 for no):";
cin>>f;

cout<<"Enter the burst time of processes:";
for(i=0;i<n;i++){
cin>>p[i].bt;
p[i].no=i+1;

}
 cout<<"Enter the arrival time of processes:";
if(f==1){
   for(i=0;i<n;i++){
cin>>p[i].at;
}

}
                                                                                                                         


// for(i=0;i<n;i++){
// p[i].display();
// }

fcfs(n,p);
return 0;
}
