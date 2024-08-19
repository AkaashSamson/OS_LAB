#include<iostream>
#define INTMAX 10000

using namespace std;

class process{

public:
    int no,bt,at,tat,wt,ct,rt;

public:
    process(){
        bt=0;
        at=0;
    }

	process(const process &obj){
		no=obj.no;
		bt=obj.bt;
		at=obj.at;
		tat=obj.tat;
		wt=obj.wt;
		ct=obj.ct;
		rt=obj.rt;		
}

    void getval(int a, int b, int c){
        no=a;
        bt=b;
        at=c;
		rt=b;
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
		if((p[j].at > p[j+1].at) || ((p[j].at == p[j+1].at) && (p[j].bt > p[j+1].bt))){
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

void sort_id(class process *p,int n){
class process temp;
int xchange=0;
for(int i=0; i<n-1; i++){
	xchange = 0;
	for(int j=0; j<n-i-1; j++){
		if(p[j].no > p[j+1].no){
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


void sort_rt(class process *p,int n){
class process temp;
int xchange=0;
for(int i=0; i<n-1; i++){
	xchange = 0;
	for(int j=0; j<n-i-1; j++){
		if(p[j].rt > p[j+1].rt){
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


void sjf(int n, class process *p){
sort_process(p,n);
int i,tat=0,wt=0,t=0,tstmp[100],pstmp[100],ind=0,pind=0;
process *pc = new process[n];

if(p[0].at!=0){
	pstmp[ind]=-1;
	tstmp[ind++]=-1;
}

i=0;
pc[pind++] = p[i];
t=p[i].at;

while(i<n-1){
tstmp[ind] = t;
pstmp[ind++] = pc[0].no;

if(pc[0].rt<p[i+1].at){
t += pc[0].rt;
pc[0].ct = t;
pc[0].rt=INT_MAX;
tstmp[ind++] = -1;
t=p[i+1].at;
}

else{
t += p[i+1].at-t;
pc[0].rt -= p[i+1].at-t;
}

i++;
while(p[i].at == t && i<n){
	pc[ind++] = p[i];
	i++;
}
sort_rt(pc,ind);
}




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
    sort_id(p,n);

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

for(i=0;i<n;i++){
cout<<"Enter the burst time of process p"<<i+1<<":";
cin>>b;
if(f==1){
    cout<<"Enter the arrival time of process p"<<i+1<<":";
    cin>>a;
}                                                                                                        
p[i].getval(i+1,b,a);
}

sjf(n,p);   
return 0;
}











