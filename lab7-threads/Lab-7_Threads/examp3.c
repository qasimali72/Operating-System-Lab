#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>
int glob_data = 5;
void *kidfunc(void *p)
{
    printf ("Kid here:- Global data was %d.\n", glob_data);
    glob_data = 15;
    printf ("Kid Again:- Global data was now %d.\n", glob_data);
}
// void *kidfunc2(void *p)
// {
//     printf ("Kid2 here:- Global data was %d.\n", glob_data);
//     glob_data += 12;
//     printf ("Kid2 Again:- Global data was now %d.\n", glob_data);
// }
int main()
{
    pthread_t kid, kid2;
    pthread_create (&kid, NULL, kidfunc, NULL);
    // pthread_create (&kid2, NULL, kidfunc2, NULL);
    printf ("Parent at Start:- Global data = %d\n", glob_data);
    pthread_join(kid, NULL);
    // pthread_join(kid2, NULL);
    // glob_data = 10;
    printf ("End of program.\nGlobal data = %d\n", glob_data);
    return 0;
}


