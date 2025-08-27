#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

// -------- Item structure --------
struct Item {
    int value, weight;
};

// -------- Fractional Knapsack (Greedy) --------
bool cmp(struct Item a, struct Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);

    int curWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < items.size(); i++) {
        if (curWeight + items[i].weight <= W) {
            curWeight += items[i].weight;
            finalValue += items[i].value;
        } else {
            int remain = W - curWeight;
            finalValue += items[i].value * ((double)remain / items[i].weight);
            break;
        }
    }
    return finalValue;
}

// -------- 0/1 Knapsack (DP) --------
int knapSack01(int W, vector<Item>& items) {
    int n = items.size();
    vector< vector<int> > K(n + 1, vector<int>(W + 1));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (items[i - 1].weight <= w)
                K[i][w] = max(items[i - 1].value + K[i - 1][w - items[i - 1].weight], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

// -------- Main Program --------
int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter value and weight for each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    cout << "Enter maximum capacity of knapsack: ";
    cin >> W;

    // Fractional Knapsack
    vector<Item> items1 = items; // copy
    clock_t start = clock();
    double maxFractional = fractionalKnapsack(W, items1);
    clock_t end = clock();
    double tFractional = double(end - start) / CLOCKS_PER_SEC;

    // 0/1 Knapsack
    vector<Item> items2 = items; // copy
    start = clock();
    int max01 = knapSack01(W, items2);
    end = clock();
    double t01 = double(end - start) / CLOCKS_PER_SEC;

    // Results
    cout << "\n--- Results ---\n";
    cout << "Fractional Knapsack Value = " << maxFractional << "\n";
    cout << "Execution Time (Fractional) = " << tFractional << " seconds\n";
    cout << "0/1 Knapsack Value = " << max01 << "\n";
    cout << "Execution Time (0/1) = " << t01 << " seconds\n";

    return 0;
}

