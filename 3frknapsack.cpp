// Time Complexity: O(n log n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
};

// Function to compare items based on value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    // Sort items by value-to-weight ratio in descending order
    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0;

    for (const auto& item : items) {
        if (W >= item.weight) {
            // If item can be fully taken, add its entire value
            W -= item.weight;
            maxValue += item.value;
        } else {
            // If only a fraction can be taken, add that fraction of its value
            maxValue += item.value * ((double)W / item.weight);
            break;
        }
    }

    return maxValue;
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    
    cout << "Enter the knapsack capacity: ";
    cin >> W;

    vector<Item> items(n);
    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> items[i].weight;
        cout << "Item " << i + 1 << " - Value: ";
        cin >> items[i].value;
    }

    double maxProfit = fractionalKnapsack(W, items);

    cout << "Maximum value in Knapsack = " << maxProfit <<endl;

    return 0;
}

// Enter the number of items: 3
// Enter the knapsack capacity: 50
// Enter the weight and value of each item:
// Item 1 - Weight: 10
// Item 1 - Value: 60
// Item 2 - Weight: 20
// Item 2 - Value: 100
// Item 3 - Weight: 30
// Item 3 - Value: 120

// Maximum value in Knapsack = 240



// Fractional Knapsack is better if the items can be split (such as liquids or perishable goods) and you want a fast, optimal solution. The greedy algorithm is efficient with a time complexity of o(n log n)

// 0/1 Knapsack is better if the items cannot be split (such as physical objects, products, or assets), where the objective is to decide whether to include an entire item or not. While it might be slower, it guarantees the most accurate result for these types of problems, especially when the capacity of the knapsack is not too large.