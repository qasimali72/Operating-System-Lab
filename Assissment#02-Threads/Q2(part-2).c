#include <stdio.h>
#include <pthread.h>

void print_thread_id() {
    printf("Thread ID: %lu\n", pthread_self());
}

int main() {
    pthread_t threads[5];

    // Create 5 threads
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, print_thread_id, NULL);
    }

    // Wait for all threads to finish before printing the main thread ID
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the main thread ID
    printf("Main thread ID: %lu\n", pthread_self());

    return 0;
}
