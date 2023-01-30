//
// Created by arehm on 2021-11-15.
//

#include <stdlib.h>
#include <stdio.h>
#include "schedulers.h"
#include "list.h"
#include "string.h"
#include "cpu.h"

int id=0;
struct node **TaskListHead = 0;
int numElem=0;
// add a task to the list
void add(char *name, int priority, int burst)
{
    numElem++;
    if(TaskListHead == 0){
        TaskListHead=(struct node**)malloc(sizeof(struct node));
    }
    Task *task = (Task*)malloc(100 * sizeof(Task));
    task->name = (char*)malloc(100*sizeof(char));

    strcpy(task->name,name);

    task->priority=priority;
    task->burst = burst;
    task->tid=id;

    insert(TaskListHead,task);
}

// invoke the scheduler
void schedule()
{
    struct node *temp = *TaskListHead, *lastElem;

//    lastElem = (struct node *) malloc(sizeof(struct node));
//    lastElem = *T ;
//
//    reverse(&temp);
//
//    while(lastElem->next != 0)
//        lastElem = lastElem->next;
//
//    traverse(lastElem);
//    temp = *TaskListHead;
//    traverse(temp);


//    while ((*temp != 0))
//    {
//        if((*temp)->task->burst > 10)
//        {
//            run((*temp)->task,QUANTUM);
//            (*temp)->task->burst = (*temp)->task->burst - 10;
//            insert(lastElem,(*temp)->task);
//            (*temp) = (*temp)->next;
//        }
//        else
//        {
//            run((*temp)->task,QUANTUM);
//            (*temp) = (*temp)->next;
//        }
//
//    }
//
//    free(temp);
//    avgRT = avgW;
//
//    printf("Average waiting time = %.2f\n", avgW/numElem);
//    printf("Average turnaround time = %.2f\n",avgTA/numElem);
//    printf("Average response time = %.2f\n",avgRT/numElem);
//
    struct node * current = *TaskListHead;
    struct node * ref = *TaskListHead;
    struct node * monitor = NULL;
    monitor = malloc(sizeof ( struct node) );
    monitor = *TaskListHead;
    int newburst = 0;
    int totburst = 0;
    float turnaroundtime = 0;
    float ResponseTime = 0;
    float WaitTime = 0;
    int check = 1;
    reverse(TaskListHead);
    while (ref->next !=NULL ) {
        ref = ref->next;
    }
    traverse(ref);
    printf("---");
    traverse(*TaskListHead);

   // WaitTime = turnaroundtime - totburst;
    printf("The average turnaround time is : %.2f time units \n" , turnaroundtime/numElem);
    printf("The average response time is : %.2f time units \n" , ResponseTime/numElem);
    printf("The average Wait time is : %.2f time units \n" , WaitTime/numElem);
}




