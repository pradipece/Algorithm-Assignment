#include<bits/stdc++.h>
using namespace std;
void code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int main(){
	code();
	int n;	cin >> n;
	int arr[n],idx[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
		idx[i] = i;
	}
	for(int i=0;i<n;i++) cout << idx[i] <<" ";
	cout << endl;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[idx[i]]>arr[idx[j]]){
				swap(idx[i],idx[j]);
			}
		}
	}
	for(int i=0;i<n;i++) cout << idx[i] <<" ";
	cout << endl;
	for(int i=0;i<n;i++) cout << arr[idx[i]] <<" ";
	cout << endl;
}
