#include<iostream>
using namespace std;

int main()
{
    int at[10], bt[10], priority[10], ct[10], tat[10], wt[10], p[10];
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter the arrival time, burst time, and priority for each process:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "For Process " << i + 1 << endl;
        cout << "Arrival Time: ";
        cin >> at[i];
        cout << "Burst Time: ";
        cin >> bt[i];
        cout << "Priority (lower number = higher priority): ";
        cin >> priority[i];
        p[i] = i + 1; // Assign process numbers
    }

    // Sort processes by priority, then by arrival time if priorities are equal
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[i] > priority[j] || 
                (priority[i] == priority[j] && at[i] > at[j])) {
                swap(priority[i], priority[j]);
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum < at[i]) {
            sum = at[i]; // Wait for the next process to arrive
        }
        sum += bt[i];
        ct[i] = sum; // Completion time
    }

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i]; // Turnaround time
        wt[i] = tat[i] - bt[i]; // Waiting time
    }

    cout << "Solution\n\n";
    cout << "P\tAT\tBT\tPriority\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << p[i] << "\t" << at[i] << "\t" << bt[i] << "\t" 
             << priority[i] << "\t\t" << ct[i] << "\t" << tat[i] 
             << "\t" << wt[i] << endl;
    }

    return 0;
}
