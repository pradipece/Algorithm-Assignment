#include <bits/stdc++.h>
using namespace std;
map<int,int>mp;
struct process {
    int PID, AT, BT, CT, TAT, WT, RT,Priority;
};
void findCT(process proc[], int n) {
    int currentTime = 0;
    vector<bool> done(n, false);
    int completed = 0;

    while (completed < n) {
        int highestPriority = -1e9, idx = -1;
        for (int i = 0; i < n; i++) {
            if (!done[i] && proc[i].AT <= currentTime && proc[i].Priority > highestPriority) {
                highestPriority = proc[i].Priority;
                idx = i;
            }
        }
        if (idx != -1) {
            proc[idx].CT = currentTime + proc[idx].BT;
            done[idx] = true;
            completed++;
            currentTime = proc[idx].CT;
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
        if (proc[i].WT < 0) proc[i].WT = 0;
    }
}

void findRT(process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].RT = proc[i].CT - proc[i].BT - proc[i].AT;
    }
}

bool compareByAT(const process &a, const process &b) {
    return a.AT < b.AT;
}
int main() {
    int n; cin >> n;
    process proc[n];
    for (int i = 0; i < n; i++) {
        cin >> proc[i].PID >> proc[i].Priority >> proc[i].AT >> proc[i].BT;
    }
    sort(proc, proc + n, compareByAT);

    findCT(proc, n);
    findTAT(proc, n);
    findWT(proc, n);
    findRT(proc,n);

    cout << "PS CPU Scheduling Algorithm!\n\n";
    cout << "PID\t" << "Pri\t"<< "AT\t" << "BT\t" << "CT\t" << "TAT\t" << "WT\t" <<"RT" << endl;
    for (int i = 0; i < n; i++) {
        cout << 'p' << proc[i].PID << "\t"<< proc[i].Priority << "\t" << proc[i].AT << "\t" << proc[i].BT << "\t" << proc[i].CT << "\t" << proc[i].TAT << "\t" << proc[i].WT <<"\t"<<proc[i].RT << endl;
    }
}
/*
7
1 2 0 3
2 6 2 5
3 3 1 4
4 5 4 2
5 7 6 9
6 4 5 4
7 10 7 10
-------------------(Higher the number higher the priority)
PS CPU Scheduling Algorithm!

PID Pri AT  BT  CT  TAT WT  RT
p1  2   0   3   3   3   0   0
p3  3   1   4   37  36  32  32
p2  6   2   5   8   6   1   1
p4  5   4   2   29  25  23  23
p6  4   5   4   33  28  24  24
p5  7   6   9   27  21  12  12
p7  10  7   10  18  11  1   1


5
1 4 0 4
2 3 1 3
3 2 2 1
4 1 3 5
5 1 4 2
-------------------(Higher the number higher the priority)
PS CPU Scheduling Algorithm!

PID Pri AT  BT  CT  TAT WT  RT
p1  4   0   4   4   4   0   0
p2  3   1   3   7   6   3   3
p3  2   2   1   8   6   5   5
p4  1   3   5   13  10  5   5
p5  1   4   2   15  11  9   9


7
1 2 0 4
2 4 1 2
3 6 2 3
4 10 3 5
5 8 4 1
6 12 5 4
7 9 6 6
-------------------(Higher the number higher the priority)
PS CPU Scheduling Algorithm!

PID Pri AT  BT  CT  TAT WT  RT
p1  2   0   4   4   4   0   0
p2  4   1   2   25  24  22  22
p3  6   2   3   23  21  18  18
p4  10  3   5   9   6   1   1
p5  8   4   1   20  16  15  15
p6  12  5   4   13  8   4   4
p7  9   6   6   19  13  7   7

7
1 3 0 8
2 4 1 2
3 4 3 4
4 5 4 1
5 2 5 6
6 6 6 5
7 1 10 1
-------------------(Lower the number higher the priority)
PS CPU Scheduling Algorithm!

PID Pri AT  BT  CT  TAT WT  RT
p1  3   0   8   8   8   0   0
p2  4   1   2   17  16  14  14
p3  4   3   4   21  18  14  14
p4  5   4   1   22  18  17  17
p5  2   5   6   14  9   3   3
p6  6   6   5   27  21  16  16
p7  1   10  1   15  5   4   4

7
1 2 0 3
2 6 2 5
3 3 1 4
4 5 4 2
5 7 6 9
6 4 5 4
7 10 7 10
-------------------(Lower the number higher the priority)
PS CPU Scheduling Algorithm!

PID Pri AT  BT  CT  TAT WT  RT
p1  2   0   3   3   3   0   0
p3  3   1   4   7   6   2   2
p2  6   2   5   18  16  11  11
p4  5   4   2   13  9   7   7
p6  4   5   4   11  6   2   2
p5  7   6   9   27  21  12  12
p7  10  7   10  37  30  20  20


*/