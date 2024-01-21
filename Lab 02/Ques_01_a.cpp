#include<bits/stdc++.h>
using namespace std;

vector<int> mergeSortedArrays(int arr1[], int arr2[], int size1, int size2) {
    int index1 = 0, index2 = 0;
    vector<int> resultArray;

    while (index1 < size1 && index2 < size2) {
        if (arr1[index1] < arr2[index2]) {
            resultArray.push_back(arr1[index1]);
            index1++;
        } else {
            resultArray.push_back(arr2[index2]);
            index2++;
        }
    }

    while (index2 < size2) {
        resultArray.push_back(arr2[index2]);
        index2++;
    }

    while (index1 < size1) {
        resultArray.push_back(arr1[index1]);
        index1++;
    }

    return resultArray;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input_1a.txt", "r", stdin);
    freopen("output_1a.txt", "w", stdout);
#endif

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int size1, size2;
        cin >> size1 >> size2;

        int array1[size1], array2[size2];

        for (int i = 0; i < size1; i++) cin >> array1[i];
        for (int i = 0; i < size2; i++) cin >> array2[i];

        vector<int> resultArray = mergeSortedArrays(array1, array2, size1, size2);

        for (int i = 0; i < resultArray.size(); i++) {
            cout << resultArray[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
