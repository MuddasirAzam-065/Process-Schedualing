#pragma once
#include <iostream>
#include <fstream>
#include "priority.h"

using namespace std;

struct Process {
    int pid;
    int arrival;
    int execution;
    int priority;

    int completion;
    int waiting;
};

class ProcessScheduler {

private:

    int totalProcesses;
    int priorityLevels;

    Process *processes;
    priorityQueue<Process> *pq;

public://total priority levels
//total number of process in one priority
//PID = Process ID, Process Arrival time, Execution time required, Priority level of process

    ProcessScheduler(string filename) {

        ifstream file(filename);

        if (!file) {
            cout << "Error opening file\n";
            return;
        }

        file >> priorityLevels;
        file >> totalProcesses;

        processes = new Process[totalProcesses];

        pq = new priorityQueue<Process>(priorityLevels, totalProcesses);

        for (int i = 0; i < totalProcesses; i++) {

            file >> processes[i].pid;
            file >> processes[i].arrival;
            file >> processes[i].execution;
            file >> processes[i].priority;

            processes[i].completion = 0;
            processes[i].waiting = 0;

            pq->insert(processes[i], processes[i].priority);
        }

        file.close();
    }

    void simulateCPU() {

        int currentTime = 0;

        float totalWaiting = 0;
        float totalCompletion = 0;

        cout << "\nPriority Wise Process Schedule\n";

        for (int pr = priorityLevels; pr >= 1; pr--) {

            cout << "\nPriority Level " << pr << endl;

            bool found = true;

            while (found) {

                found = false;

                for (int i = 0; i < totalProcesses; i++) {

                    if (processes[i].priority == pr &&
                        processes[i].completion == 0) {

                        if (currentTime < processes[i].arrival)
                            currentTime = processes[i].arrival;

                        processes[i].waiting = currentTime - processes[i].arrival;

                        currentTime += processes[i].execution;

                        processes[i].completion = currentTime;

                        cout << "PID: " << processes[i].pid
                             << " Start: " << currentTime - processes[i].execution
                             << " End: " << currentTime << endl;

                        totalWaiting += processes[i].waiting;
                        totalCompletion += processes[i].completion;

                        pq->remove(pr);

                        found = true;
                        break;
                    }
                }
            }
        }

        cout << "\nProcess Results\n";

        for (int i = 0; i < totalProcesses; i++) {

            cout << "PID: " << processes[i].pid
                 << " Waiting Time: " << processes[i].waiting
                 << " Completion Time: " << processes[i].completion
                 << endl;
        }

        cout << "\nAverage Waiting Time: "
             << totalWaiting / totalProcesses << endl;

        cout << "Average Completion Time: "
             << totalCompletion / totalProcesses << endl;
    }
    void printExecutionOrder()
{
    cout << "\nExecution Order of Processes\n";
    cout << "---------------------------------\n";

    int seq = 1;

    for (int pr = priorityLevels; pr >= 1; pr--)
    {
        for (int i = 0; i < totalProcesses - 1; i++)
        {
            for (int j = i + 1; j < totalProcesses; j++)
            {
                if (processes[i].priority == pr && processes[j].priority == pr)
                {
                    if (processes[i].arrival > processes[j].arrival)
                    {
                        Process temp = processes[i];
                        processes[i] = processes[j];
                        processes[j] = temp;
                    }
                }
            }
        }

        for (int i = 0; i < totalProcesses; i++)
        {
            if (processes[i].priority == pr)
            {
                cout << seq << " -> PID: " << processes[i].pid
                     << " (Priority " << processes[i].priority << ")\n";
                seq++;
            }
        }
    }

    cout << endl;
}

    ~ProcessScheduler() {

        delete[] processes;
        delete pq;
    }
};