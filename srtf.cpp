#include<iostream>
using namespace std;

int main() {
    int at[10], bt[10], rt[10], ct[10], tat[10], wt[10], p[10];
    int n, current_time = 0, completed = 0, smallest = -1;
    bool is_found = false;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter the arrival time and burst time for each process:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "For Process " << i + 1 << endl;
        cout << "Arrival Time: ";
        cin >> at[i];
        cout << "Burst Time: ";
        cin >> bt[i];
        rt[i] = bt[i]; // Remaining time is initially the burst time
        p[i] = i + 1;  // Process ID
    }

    while (completed != n) {
        smallest = -1;
        is_found = false;

        // Find the process with the smallest remaining time that has arrived
        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && rt[i] > 0) { 
                if (!is_found || rt[i] < rt[smallest]) {
                    smallest = i;
                    is_found = true;
                }
            }
        }

        if (is_found) {
            rt[smallest]--; // Execute the selected process for 1 unit of time
            current_time++;

            // If the process is completed
            if (rt[smallest] == 0) {
                completed++;
                ct[smallest] = current_time; // Completion time
            }
        } else {
            current_time++; // No process is ready, increment time
        }
    }

    // Calculate TAT and WT
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];       // Turnaround time
        wt[i] = tat[i] - bt[i];       // Waiting time
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
