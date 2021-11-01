#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> triplets_sum(vector<int> arr, int sum) {
    vector<vector<int>> result;
    
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size()-2; i++) {
        int j = i+1;
        int k = arr.size()-1;
        while(j < k) {
            if(arr[i] + arr[j] + arr[k] == sum) {
                result.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
                while(arr[j] == arr[j-1]) 
                    j++;
                while(arr[k] == arr[k+1])
                    k--;
            } 
            else if(arr[i] + arr[j] + arr[k] < sum) {
                j++;
            } else {
                k--;
            }
        }
        
    }
    return result;
    //retrun {};
}  

int main(){
    int n;
    cout<<"no of elements:";
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int sum;
    cout<<"sum of triplets=";
    cin >> sum;
    auto result = triplets_sum(arr, sum);
    
    for(auto x : result) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}