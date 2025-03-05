#include<bits/stdc++.h>
using namespace std;
struct process{
	int PID,AT,BT,CT,TAT,WT,RT;
};
void findCT(process proc[],int n){
	proc[0].CT = proc[0].BT + proc[0].AT-0;
	for(int i=1;i<n;i++){
		proc[i].CT = proc[i-1].CT + proc[i].BT;
	}
}
void findTAT(process proc[],int n){
	for(int i=0;i<n;i++){
		proc[i].TAT = proc[i].CT - proc[i].AT;
	}
}
void findWT(process proc[],int n){
	for(int i=0;i<n;i++){
		proc[i].WT = proc[i].TAT - proc[i].BT;
		if(proc[i].WT<0) proc[i].WT = 0;
	}
}
bool compareByAT(const process &a, const process &b) {
    return a.AT < b.AT;
}
int main(){
	int n;	cin >> n;
	process proc[n];
	for(int i=0;i<n;i++){
		cin >> proc[i].PID >> proc[i].AT >> proc[i].BT;
	}
	sort(proc, proc+n, compareByAT);
	
	findCT(proc,n);
	findTAT(proc,n);
	findWT(proc,n);

	cout << "FCFS CPU Scheduling Algorithm!\n\n";
	cout << "PID\t" << "AT\t" <<"BT\t"<<"CT\t"<<"TAT\t" << "WT\t" <<"RT"<< endl;
	for(int i=0;i<n;i++){
		cout <<'p'<<proc[i].PID<<"\t"<<proc[i].AT<<"\t"<<proc[i].BT<<"\t"<<proc[i].CT<<"\t"<<proc[i].TAT<<"\t"<<proc[i].WT <<"\t"<<proc[i].WT << endl;
	}
}
/*
5
0 0 2
1 1 6
2 2 4
3 3 9
4 4 12

FCFS CPU Scheduling Algorithm!

PID	AT	BT	CT	TAT	WT	RT
p0	0	2	2	2	0	0
p1	1	6	8	7	1	1
p2	2	4	12	10	6	6
p3	3	9	21	18	9	9
p4	4	12	33	29	17	17

---------------------------------------


5
1 2 6
2 5 3
3 1 8
4 0 3
5 4 4

FCFS CPU Scheduling Algorithm!

PID	AT	BT	CT	TAT	WT	RT
p4	0	3	3	3	0	0
p3	1	8	11	10	2	2
p1	2	6	17	15	9	9
p5	4	4	21	17	13	13
p2	5	3	24	19	16	16
*/