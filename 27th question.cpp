#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t semaphore;
void* process(void* process_id) {
    int pid = *(int*)process_id;
	 printf("Process P%d is waiting...\n", pid);
    sem_wait(&semaphore);
    printf("Process P%d has acquired the resource.\n", pid);
    printf("Process P%d is releasing the resource.\n", pid);
    sem_post(&semaphore);
	 pthread_exit(NULL);
}
int main() {
    int num_instances = 4;
    int num_processes = 4;
    int process_ids[] = {1, 2, 3, 4};
	sem_init(&semaphore, 0, num_instances);																																																																																		
pthread_t threads[num_processes];
    for (int i = 0; i < num_processes; i++) {
        pthread_create(&threads[i], NULL, process, &process_ids[i]);
    }
	for (int i = 0; i < num_processes; i++) {
        pthread_join(threads[i], NULL);
    }
	printf("Process P5 is waiting...\n");b4
    sem_wait(&semaphore);
    printf("Process P5 has acquired the resource.\n");
    printf("Process P5 is releasing the resource.\n");
    sem_post(&semaphore); 
    sem_destroy(&semaphore);
    return 0;
}
