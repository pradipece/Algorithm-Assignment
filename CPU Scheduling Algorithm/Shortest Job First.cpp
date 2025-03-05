#include<bits/stdc++.h>
using namespace std;
struct process{
	int PID,AT,BT,CT,TAT,WT,RT;
};
void findCT(process proc[],int n){
	bool ok[n];
	proc[0].CT = proc[0].BT + proc[0].AT-0;
	ok[0] = true;
	int idx = 0,k=0;
	for(int j=1;j<n;j++){
		int mn = 1e9;
		bool test = false;
		for(int i=1;i<n;i++){
			if(proc[k].CT>=proc[i].AT && ok[i]==false){
				if(mn>proc[i].BT) {
					mn = proc[i].BT;
					idx = i;
				}
			}
		}
		proc[idx].CT = proc[idx].BT+proc[k].CT;
		ok[idx] = true;
		k=idx;
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

	cout << "SJF CPU Scheduling Algorithm!\n\n";
	cout << "PID\t" << "AT\t" <<"BT\t"<<"CT\t"<<"TAT\t" << "WT\t" <<"RT"<< endl;
	for(int i=0;i<n;i++){
		cout <<'p'<<proc[i].PID<<"\t"<<proc[i].AT<<"\t"<<proc[i].BT<<"\t"<<proc[i].CT<<"\t"<<proc[i].TAT<<"\t"<<proc[i].WT <<"\t"<<proc[i].WT << endl;
	}
}
/*
5
1 2 6
2 5 2
3 1 8
4 0 3
5 4 4
------------------------------
SJF CPU Scheduling Algorithm!

PID	AT	BT	CT	TAT	WT	RT
p4	0	3	3	3	0	0
p3	1	8	23	22	14	14
p1	2	6	9	7	1	1
p5	4	4	15	11	7	7
p2	5	2	11	6	4	4


5
1 1 2
2 3 3
3 5 4
4 4 4
5 2 9
-------------------------------
SJF CPU Scheduling Algorithm!

PID	AT	BT	CT	TAT	WT	RT
p1	1	2	3	2	0	0
p5	2	9	23	21	12	12
p2	3	3	6	3	0	0
p4	4	4	10	6	2	2
p3	5	4	14	9	5	5



5
0 0 2
1 1 6
2 2 4
3 3 9
4 4 12
--------------------------
SJF CPU Scheduling Algorithm!

PID	AT	BT	CT	TAT	WT	RT
p0	0	2	2	2	0	0
p1	1	6	12	11	5	5
p2	2	4	6	4	0	0
p3	3	9	21	18	9	9
p4	4	12	33	29	17	17



5
1 2 6
2 5 3
3 1 8
4 0 3
5 4 4
-------------------------
SJF CPU Scheduling Algorithm!

PID	AT	BT	CT	TAT	WT	RT
p4	0	3	3	3	0	0
p1	1	6	9	8	2	2
p3	1	8	24	23	15	15
p5	4	4	16	12	8	8
p2	5	3	12	7	4	4


5
1 0 5
2 2 3
3 1 8
4 4 2
5 3 4
-----------------------------
SJF CPU Scheduling Algorithm!

PID	AT	BT	CT	TAT	WT	RT
p1	0	5	5	5	0	0
p3	1	8	22	21	13	13
p2	2	3	10	8	5	5
p5	3	4	14	11	7	7
p4	4	2	7	3	1	1
*/