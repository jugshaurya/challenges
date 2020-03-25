#include <iostream>
#include<map>
using namespace std;

int main() {
	// your code goes here
	int t,n, arr[300];
	cin>>n;
	cin>>t;

	for (int i=0;i<n;i++){
		cin>>arr[i]
	}

	for(int i=0;i<n;i++){
		for(int j=i+1;i<n;i++){
			for(int k=j+1;i<n;i++){
				for(int l+1=k;i<n;i++){
					if(arr[i]+arr[j]+arr[k]+arr[l] == t){
						print(arr[i],arr[j],arr[k],arr[l])
					}
				}
			}
		}
	}



	return 0;
}
