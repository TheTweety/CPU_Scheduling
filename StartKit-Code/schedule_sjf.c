#include <stdlib.h>
#include <stdio.h>
#include "schedulers.h"
#include "list.h"
#include "string.h"
#include "cpu.h"

int count=0;
struct node **TaskListHead = 0;

void insertByBurst(struct node **taskListHead, Task *task) {

    struct node *r, *temp = *taskListHead;

    r = (struct node *) malloc(sizeof(struct node));
    Task *t = (Task *) malloc(sizeof(Task));

    t->tid = task->tid;
    t->burst = task->burst;
    t->priority = task->priority;
    t->name = (char *) malloc(100 * sizeof(char));
    strcpy(t->name, task->name);
    r->task = t;

    /* Special case for the head end */
    if (temp == NULL || (*temp).task->burst > task->burst) {
        r->next = *taskListHead;
        *taskListHead = r;
    }
    else {
        /* Locate the node before the point of insertion */
        temp = *taskListHead;
        while (temp->next != NULL && temp->next->task->burst <= r->task->burst) {
            temp = temp->next;
        }

        r->next = temp->next;
        temp->next = r;
    }
}


// add a task to the list
void add(char *name, int priority, int burst)
{
    if(TaskListHead == 0){
        TaskListHead=(struct node**)malloc(sizeof(struct node));
    }

    Task *task = (Task*)malloc(100 * sizeof(Task));
    task->name = (char*)malloc(100*sizeof(char));

    strcpy(task->name,name);

    task->priority=priority;
    task->burst = burst;
    task->tid=count;
    count++;
    insertByBurst(TaskListHead,task);
}

// invoke the scheduler
void schedule()
{
    struct node **temp = TaskListHead;
    float taT = 0,RT = 0,WT = 0;
    int numElem = 0,burst=0;


    while ((*temp) != 0) {

        numElem = numElem + 1;

        run((*temp)->task, (*temp)->task->burst);

        burst = burst + (*temp)->task->burst;
        taT = taT + (float) burst; //5 (5+10+5)20  50      (5 + 5+10 + 5+10+15)

        if ((*temp)->next != 0) {
            RT = RT + burst;
        }
        (*temp) = (*temp)->next;
    }
    WT = taT - burst;

    printf("\nAverage waiting time = %.2f\n", (WT) / numElem);
    printf("Average turnaround time = %.2f\n", (taT) / numElem);
    printf("Average response time = %.2f\n", (RT) / numElem);

}


