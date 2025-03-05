#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;  cin >> n;
    int res; cin >> res;
    vector<int>Allocation[n],Need[n],Available(n);
    int x;
    for(int i=0; i<n; i++){
        for(int j=0; j<res; j++){
            cin >> x;
            Allocation[i].push_back(x);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<res; j++){
            cin >> x;
            Need[i].push_back(x);
        }
    }
    for(int i=0; i<res; i++){
        cin >> Available[i];
    }
    vector<int>Current_need[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<res; j++){
            x = Need[i][j]-Allocation[i][j];
            if(x<0) x = 0;
            Current_need[i].push_back(x);
        }
    }
    bool ok[n] = {false};
    int cunt = 0, k = 0;
    vector<int>ans;
    while(cunt<n){
        bool found = false;
        for(int i=0;i<n;i++){
            if(!ok[i]){
                bool canAllocate=true;
                for(int j=0;j<res;j++){
                    if(Available[j]<Current_need[i][j]){
                        canAllocate=false;
                        break;
                    }
                }
                if(canAllocate){
                    cunt++;
                    for(int j=0;j<res;j++){
                        Available[j]+=Allocation[i][j];
                    }
                    ans.push_back(i);
                    ok[i] = true;
                    found = true;
                    
                }

            }
        }
        if(!found){
            cout << "System is in an unsafe state.\n";
            return 0;
        }
    }
    cout << "System is in a safe state.\nSafe sequence is: ";
    for(auto it:ans) cout << 'P' << it  << ' ';
}
/*
5 4
4 0 0 1
1 1 0 0
1 2 5 4
0 6 3 3
0 2 1 2
6 0 1 2
1 7 5 0
2 3 5 6
1 6 5 3
1 6 5 6
3 2 1 1
----------------------------------
System is in a safe state.
Safe sequence is: P0 P2 P3 P4 P1 

5 3
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
7 5 3
3 2 2
9 0 2
4 2 2
5 3 3
3 3 2
----------------------------------
System is in a safe state.
Safe sequence is: P1 P3 P4 P0 P2 


5 3
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
3 3 2
----------------------------------
System is in a safe state.
Safe sequence is: P1 P3 P4 P0 P2 


5 3
0 0 1
3 0 0
1 0 0
2 3 2
0  0 3
7 6 3
3 2 2
8 0 2
2 1 2
5 2 3
2 3 2
----------------------------------
System is in a safe state.
Safe sequence is: P1 P3 P4 P0 P2

5 4
1 0 2 0
0 3 1 2
2 4 5 1
3 0 0 6
4 2 1 3
3 2 4 2
3 5 1 2
2 7 7 5
5 5 0 8
6 2 1 4
3 4 0 1
----------------------------------
System is in a safe state.
Safe sequence is: P1 P3 P4 P0 P2 
*/