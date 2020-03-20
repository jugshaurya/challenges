#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool gotcha = false;

void printways(int arr[],int n, int i, int target, vector<int> &ans){
   
    if(target < 0 or i >= n) return;

    if(target == 0){
        gotcha = true;
        for (int i=0;i<ans.size();i++){
          cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }

    ans.push_back(arr[i]);
    printways(arr,n, i, target-arr[i], ans);
    ans.pop_back();
    printways(arr, n, i+1, target, ans);


}

int main(){
  int n;
  cin>>n;

  int arr[10000]={0};
  for (int i=0;i<n;i++){
    cin>>arr[i];
  }

  sort(arr, arr+n)
  int target;
  cin>>target;

  vector<int> ans;
  printways(arr,n,0,target,ans);
  if(!gotcha){
    cout<<"G@me |0$t"<<endl;
  }
  return 0;
}
