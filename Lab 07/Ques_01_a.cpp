#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;
    return ratio1 > ratio2;
}

pair<vector<Item>, int> knapsackGreedy(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compare);

    vector<Item> selectedItems;
    int totalValue = 0;
    int totalWeight = 0;

    for (int i = 0; i < items.size(); ++i) {
        if (totalWeight + items[i].weight <= capacity) {
            selectedItems.push_back(items[i]);
            totalValue += items[i].value;
            totalWeight += items[i].weight;
        }
    }

    return {selectedItems, totalValue};
}

int main() {
    freopen("input1_a.txt", "r", stdin);
    freopen("output1_a.txt", "w", stdout);

    int t; cin>>t;
    while(t--){
        int n; cin >> n;

        vector<Item> items(n);
        for (int i = 0; i < n; ++i) {
            cin >> items[i].weight;
        }
        for (int i = 0; i < n; ++i) {
            cin >> items[i].value;
        }

        int capacity; cin >> capacity;

        pair<vector<Item>, int> selectedItems = knapsackGreedy(items, capacity);

        cout<<selectedItems.second<<endl;
    }

    return 0;
}
