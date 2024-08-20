#include<iostream>

using namespace std;

#define MAX 100

class process{

public:
    int no,bt,at,tat,wt,ct,pr;

public:
    process(){
        bt=0;
        at=0;
    }

    void getval(int a, int b, int c, int d){
        no=a;
        bt=b;
        at=c;
        pr=d;
    }

    void display(){
    cout<<" P"<<no<<"\t\t\t"<<at<<"\t\t"<<bt<<"\t\t"<<pr<<"\t\t"<<ct<<"\t\t"<<tat<<"\t\t"<<wt<<"\n";
    }

};

process *rq = new process[MAX];

//making rq as efficientt queue for process with insert, delete, isfull is empty and sort by bt functions
int front=-1,rear=-1;

int isfull(){
if ((front == rear + 1) || (front == 0 && rear == MAX-1))
   return 1;
else
   return 0;
}

int isempty(){
if (front == -1)
   return 1;
else
   return 0;
}

void insert(process p){

if(isfull())
    cout<<"Queue is full\n";
else{
    if(front == -1)
        front = 0;
    rear = (rear + 1) % MAX;
    rq[rear] = p;
}
}

process del(){
if(isempty())
    cout<<"Queue is empty\n";
else{
    process p = rq[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else
        front = (front + 1) % MAX;
    return p;
}
}



void sort_process(class process *p, int n){
class process temp;
int xchange=0;
for(int i=0; i<n-1; i++){
	xchange = 0;
	for(int j=0; j<n-i-1; j++){
		if((p[j].at > p[j+1].at) || ((p[j].at == p[j+1].at) && (p[j].pr > p[j+1].pr))){
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

void sort_pr(class process *p, int n){
class process temp;
int xchange=0;
for(int i=0; i<n-1; i++){
	xchange = 0;
	for(int j=0; j<n-i-1; j++){
		if(p[j].pr > p[j+1].pr){
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

//display function for rq
void rqdisplay(){

int i;
if(isempty())
    cout<<"Queue is empty\n";
else{
    for(i=front;i!=rear;i=(i+1)%MAX)
        cout<<rq[i].no;
    cout<<rq[i].no<<"\n";
}
return;
}

void psnp(int n, class process *p){
process *ps = new process[n];
for(int i=0;i<n;i++){
    ps[i]=p[i];
}
sort_process(ps,n);
int i,tat=0,wt=0,t=0,tstmp[100],ind=0,ptr=1;
insert(ps[0]);

while(!isempty() || ptr<n){
    if(isempty()){
        insert(ps[ptr++]);
    }
    i = del().no-1;
    if(t<p[i].at){
        tstmp[ind++]=-1;
        t = p[i].at;
    }
    tstmp[ind++]=i; 
    t += p[i].bt;
    p[i].ct = t;
    p[i].tat = p[i].ct-p[i].at;
    p[i].wt = p[i].tat-p[i].bt;
    tat+=p[i].tat;
    wt+=p[i].wt;
    while(ptr<n && ps[ptr].at<=t){
        insert(ps[ptr]);
        ptr++;
    }
    sort_pr(rq,rear+1);
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

    sort_id(p,n);

    cout<<"Process \tArrival Time \tBurst Time \tPriority \tCompletion Time     Turnaround Time   Waiting Time \n";
    for(i=0;i<n;i++){
        p[i].display();
    }

    cout<<"Average Turnaround Time: "<<(float)tat/n<<"\n";
    cout<<"Average Waiting Time: "<<(float)wt/n<<"\n";

}


int main(){
int n,i,f,b,a=0,c;
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

cout<<"Enter the priority of processes:";
for(i=0;i<n;i++){
cin>>p[i].pr;
}

 cout<<"Enter the arrival time of processes:";
if(f==1){
   for(i=0;i<n;i++){
cin>>p[i].at;
}

}

psnp(n,p);   
return 0;
}











