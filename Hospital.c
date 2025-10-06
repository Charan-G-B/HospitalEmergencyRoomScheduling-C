#include <stdio.h>
#include <string.h>
#define MAX_PATIENTS 100
typedef struct {
    char name[50];
    int severity;
    int arrival_order;
} Patient;

Patient heap[MAX_PATIENTS];
int size = 0;
int arrival_counter = 0;
void swap(int i, int j) {
    Patient temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}
int compare(Patient a, Patient b) {
    if (a.severity != b.severity)
        return a.severity > b.severity;
    return a.arrival_order < b.arrival_order;
}
void heapify_up(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (compare(heap[index], heap[parent])) {
            swap(index, parent);
            index = parent;
        } else break;
    }
}

void heapify_down(int index) {
    while (2 * index + 1 < size) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;
        if (left < size && compare(heap[left], heap[largest]))
            largest = left;
        if (right < size && compare(heap[right], heap[largest]))
            largest = right;
        if (largest != index) {
            swap(index, largest);
            index = largest;
        } else break;
    }
}
void add_patient(char name[], int severity) {
    Patient p;
    strcpy(p.name, name);
    p.severity = severity;
    p.arrival_order = arrival_counter++;
    heap[size] = p;
    heapify_up(size);
    size++;
    printf("✅ Patient %s (Severity: %d) added to queue.\n", name, severity);
}
void treat_next_patient() {
    if (size == 0) {
        printf("No patients left to treat.\n");
        return;
    }
    Patient p = heap[0];
    printf("🩺 Treating patient %s (Severity: %d)\n", p.name, p.severity);
    heap[0] = heap[size - 1];
    size--;
    heapify_down(0);
}
void show_queue() {
    printf("\n📋 Current Queue:\n");
    for (int i = 0; i < size; i++) {
        printf("- %s (Severity: %d)\n", heap[i].name, heap[i].severity);
    }
}
int main() {
    int n;
    printf("Enter number of patients: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char name[50];
        int severity;
        printf("\nEnter patient %d name: ", i + 1);
        scanf("%s", name);
        do {
            printf("Enter severity for %s (1-10): ", name);
            scanf("%d", &severity);
        } while (severity < 1 || severity > 10);
        add_patient(name, severity);
    }
    int choice;
    do {
        printf("\nChoose an action:\n");
        printf("1. Treat next patient\n");
        printf("2. Show queue\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: treat_next_patient(); break;
            case 2: show_queue(); break;
            case 3: printf("Exiting Emergency Room system.\n"); break;
            default: printf(" Invalid choice.\n");
        }
    } while (choice != 3);
    return 0;
}