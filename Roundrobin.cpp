#include<iostream>
using namespace std;

int main() {
    int at[10], bt[10], rt[10], ct[10], tat[10], wt[10], p[10];
    int n, time_quantum, current_time = 0;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter the arrival time and burst time for each process:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "For Process " << i + 1 << endl;
        cout << "Arrival Time: ";
        cin >> at[i];
        cout << "Burst Time: ";
        cin >> bt[i];
        rt[i] = bt[i]; // Remaining time
        p[i] = i + 1;  // Process ID
    }

    cout << "Enter time quantum: ";
    cin >> time_quantum;

    int completed = 0;
    bool done;
    do {
        done = true;
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= current_time) {
                done = false; // There is still a process left to execute
                if (rt[i] > time_quantum) {
                    current_time += time_quantum;
                    rt[i] -= time_quantum;
                } else {
                    current_time += rt[i];
                    ct[i] = current_time; // Completion time
                    rt[i] = 0;
                    completed++;
                }
            }
        }
    } while (!done);

    // Calculate TAT and WT
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i]; // Turnaround time
        wt[i] = tat[i] - bt[i]; // Waiting time
    }

    // Display the results
    cout << "Solution\n\n";
    cout << "P\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << p[i] << "\t" << at[i] << "\t" << bt[i] << "\t"
             << ct[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
    }

    return 0;
}
