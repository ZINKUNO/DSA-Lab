#include<bits/stdc++.h>
using namespace std;
void sorting(int *arr[],int size()){
    bool flag;
    for (int i=0;i<size-1;i++){
        flag=false;
        for(int j=0;j<size-i-1;j++){
            if (arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=true;
            }
        }
    }
}
int main(){
    vector<int> arr;
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    arr.resize(size);
    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout<<"Orginal array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    sorting(arr[], size);
}