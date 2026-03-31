#include <iostream>
#include <cstdint>
using namespace std;

// Manual linked list node implementation for Subtask 1
struct Node {
    int value;
    Node* next;

    Node(int v) : value(v), next(nullptr) {}
};

// Subtask 1: Simulate the magic trick with manual linked list
void subtask1(int n) {
    // Create circular linked list with cards 1 to n
    Node* head = new Node(1);
    Node* current = head;

    for (int i = 2; i <= n; i++) {
        current->next = new Node(i);
        current = current->next;
    }
    current->next = head; // Make it circular

    // Simulate n-1 rounds
    Node* prev = current; // points to last node initially
    current = head;

    for (int round = 0; round < n - 1; round++) {
        // Step 1: "Good luck stays" - move first card to end (already circular, so just move pointer)
        prev = current;
        current = current->next;

        // Step 2: "Troubles throw away" - discard current first card
        Node* toDelete = current;
        prev->next = current->next;
        current = current->next;
        delete toDelete;

        // Output the first card after this round
        cout << current->value << endl;
    }

    // Clean up the last remaining node
    delete current;
}

// Subtask 2: Mathematical solution for Josephus problem with step 2
// For this variant: move first to end, then remove next
// This is equivalent to Josephus problem with k=2
long long subtask2(long long n) {
    // For the Josephus problem with k=2:
    // If n is a power of 2, the answer is 1
    // Otherwise, find the highest power of 2 less than n
    // J(n) = 2 * (n - 2^m) + 1, where 2^m is the highest power of 2 ≤ n

    // Find the highest power of 2 less than or equal to n
    long long powerOf2 = 1;
    while (powerOf2 * 2 <= n) {
        powerOf2 *= 2;
    }

    // If n is a power of 2, answer is 1
    if (powerOf2 == n) {
        return 1;
    }

    // Otherwise, J(n) = 2 * (n - powerOf2) + 1
    return 2 * (n - powerOf2) + 1;
}

int main() {
    int id;
    long long n;
    cin >> id >> n;

    if (id == 1) {
        subtask1(n);
    } else if (id == 2) {
        cout << subtask2(n) << endl;
    }

    return 0;
}
