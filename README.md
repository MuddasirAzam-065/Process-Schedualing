# Priority Process Scheduler (C++)

This project implements a **Priority Based Process Scheduling System** in C++ using **Data Structures concepts** such as Circular Queue, Priority Queue, and dynamic memory allocation.

The system simulates how an **Operating System CPU scheduler** selects processes based on their **priority level**. Processes with higher priority are executed first, while processes with the same priority follow the **First Come First Served (FCFS)** rule.

---

## Features

- Dynamic **Circular Queue implementation using templates**
- **Priority Queue built using multiple circular queues**
- Supports **multiple priority levels (1–N)**
- Reads processes from a **text input file**
- Simulates **CPU scheduling**
- Calculates:
  - Waiting Time
  - Completion Time
  - Average Waiting Time
  - Average Completion Time
- Displays **process execution sequence**

---

## Process Structure

Each process contains:

| Attribute | Description |
|--------|-------------|
| PID | Process ID |
| Arrival Time | Time at which process arrives |
| Execution Time | CPU burst time |
| Priority | Priority level of process |
| Waiting Time | Time process waits before execution |
| Completion Time | Time when process finishes execution |
