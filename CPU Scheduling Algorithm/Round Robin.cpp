#include <bits/stdc++.h>
using namespace std;
map<int,int>mp;
struct process {
    int PID, AT, BT, CT, TAT, WT, RT;
};
void findCT(process proc[], int n, int q) {
    int remtime[n];
    for (int i = 0; i < n; i++) {
    	remtime[i] = proc[i].BT;
    	mp[i] = -1;
    }
    int currentTime = 0;

    deque<int>ready;
    deque<int>::iterator it;
    ready.push_back(0);

    while(!ready.empty()) {
        int i = ready.front();
        ready.pop_front();
        if (remtime[i] > 0 && proc[i].AT<=currentTime) {
            if (remtime[i] > q) {
            	if(mp[i]==-1) mp[i]=currentTime;
                currentTime += q;
                remtime[i] -= q;
                for(int j=i+1;j<n;j++){
                   	if(proc[j].AT<=currentTime){
                   		it = find(ready.begin(), ready.end(), j);
                   		if(it==ready.end()) ready.push_back(j);
                   	}
                }
                ready.push_back(i);
            } 
            
            else {
            	if(mp[i]==-1) mp[i]=currentTime;
                currentTime += remtime[i];
                remtime[i] = 0;
                proc[i].CT = currentTime;
                for(int j=i+1;j<n;j++){
                	if(proc[j].AT<=currentTime){
                    	it = find(ready.begin(), ready.end(), j);
                   		if(it==ready.end()) ready.push_back(j);
                	}
            	}
            } 
        }
    }
}

void findTAT(process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].TAT = proc[i].CT - proc[i].AT;
    }
}

void findWT(process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].WT = proc[i].TAT - proc[i].BT;
        if (proc[i].WT < 0)
            proc[i].WT = 0;
    }
}

void findRT(process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].RT = mp[i] - proc[i].AT;
    }
}

bool compareByAT(const process &a, const process &b) {
    return a.AT < b.AT;
}
int main() {
    int n, q;
    cin >> n >> q;
    process proc[n];
    for (int i = 0; i < n; i++) {
        cin >> proc[i].PID >> proc[i].AT >> proc[i].BT;
    }
    sort(proc, proc + n, compareByAT);

    findCT(proc, n, q);
    findTAT(proc, n);
    findWT(proc, n);
    findRT(proc,n);

    cout << "RR CPU Scheduling Algorithm!\n\n";
    cout << "PID\t" << "AT\t" << "BT\t" << "CT\t" << "TAT\t" << "WT\t" <<"RT" << endl;
    for (int i = 0; i < n; i++) {
        cout << 'p' << proc[i].PID << "\t" << proc[i].AT << "\t" << proc[i].BT << "\t" << proc[i].CT << "\t" << proc[i].TAT << "\t" << proc[i].WT <<"\t"<<proc[i].RT << endl;
    }
}
/*
4 2
1 0 5
2 1 4
3 2 2
4 4 1
----------------------------
RR CPU Scheduling Algorithm!

PID	AT	BT	CT	TAT	WT	RT
p1	0	5	12	12	7	0
p2	1	4	11	10	6	1
p3	2	2	6	4	2	2
p4	4	1	9	5	4	4


6 5
1 0 7
2 1 4
3 2 15
4 3 11
5 4 20
6 4 9
----------------------------
RR CPU Scheduling Algorithm!

PID	AT	BT	CT	TAT	WT	RT
p1	0	7	31	31	24	0
p2	1	4	9	8	4	4
p3	2	15	55	53	38	7
p4	3	11	56	53	42	11
p5	4	20	66	62	42	15
p6	4	9	50	46	37	20


6 4
1 0 5
2 1 6
3 2 3
4 3 1
5 4 5
6 6 4
----------------------------
RR CPU Scheduling Algorithm!

PID	AT	BT	CT	TAT	WT	RT
p1	0	5	17	17	12	0
p2	1	6	23	22	16	3
p3	2	3	11	9	6	6
p4	3	1	12	9	8	8
p5	4	5	24	20	15	8
p6	6	4	21	15	11	11


5 2
1 0 6
2 1 3
3 2 5
4 3 1
5 4 4
----------------------------
RR CPU Scheduling Algorithm!

PID	AT	BT	CT	TAT	WT	RT
p1	0	6	16	16	10	0
p2	1	3	12	11	8	1
p3	2	5	19	17	12	2
p4	3	1	9	6	5	5
p5	4	4	18	14	10	5


5 2
1 0 5
2 1 3
3 2 1
4 3 2
5 4 3
----------------------------
RR CPU Scheduling Algorithm!

PID	AT	BT	CT	TAT	WT	RT
p1	0	5	13	13	8	0
p2	1	3	12	11	8	1
p3	2	1	5	3	2	2
p4	3	2	9	6	4	4
p5	4	3	14	10	7	5
*/