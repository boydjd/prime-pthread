#include <pthread.h>
#include <stdio.h>

void *runner(void *param);

int limit;

int prime(int n) {
    int i = 2;

    for (i; i<=n/2; i++) {
        if ((n%i) == 0) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    pthread_t tid;
    pthread_attr_t attr;

    printf("Enter a number: ");
    scanf("%d",&limit);
    printf("\n");

    pthread_attr_init(&attr);
    pthread_create(&tid,&attr,runner,NULL);
    pthread_join(tid,NULL);
}

void *runner(void *param)
{
    int i = 2;

    for (i; i <= limit; i++) {
        if (prime(i) == 1) {
            printf("%d\n", i);
        }
    }
    
    pthread_exit(0);
}
