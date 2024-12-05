#include<iostream>
using namespace std;

int main()
{
    int at[10], bt[10], ct[10], tat[10], wt[10], p[10];
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter the arrival time and burst time for each process:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "For Process " << i + 1 << endl;
        cout << "Arrival Time: ";
        cin >> at[i];
        cout << "Burst Time: ";
        cin >> bt[i];
        p[i] = i + 1; // Assign process numbers
    }

    // Sort processes by arrival time, then by burst time if arrival times are equal
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j] || (at[i] == at[j] && bt[i] > bt[j])) {
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
    cout << "P\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << p[i] << "\t" << at[i] << "\t" << bt[i] << "\t" 
             << ct[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
    }

    return 0;
}
