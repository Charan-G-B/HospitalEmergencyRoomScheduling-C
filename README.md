# 🏥 Emergency Room Patient Priority Queue (C)

This project simulates an **Emergency Room (ER) patient management system** using a **max-heap priority queue** implemented in **C**.  
Patients with higher severity levels are treated first. If two patients have the same severity, the one who **arrived earlier** gets priority.

---

## 🚀 Features

- 🧍 Add patients with name and severity (1–10)
- ⚖️ Priority determined by:
  1. **Higher severity → higher priority**
  2. **Earlier arrival → higher priority if severity is equal**
- 🩺 Treat the next patient (highest priority)
- 📋 View the current queue
- 🚪 Exit the system safely

---

## 🧠 How It Works

The system uses a **binary max-heap** stored in an array to manage patient priorities efficiently.

| Operation | Description | Time Complexity |
|------------|--------------|-----------------|
| Add Patient | Inserts into heap and adjusts using `heapify_up()` | O(log n) |
| Treat Next Patient | Removes top of heap and rebalances with `heapify_down()` | O(log n) |
| Show Queue | Displays current heap (not sorted order) | O(n) |

---

## 🧩 Data Structure

Each patient is represented by a struct:

```c
typedef struct {
    char name[50];
    int severity;
    int arrival_order;
} Patient;
