#include <stdlib.h>
#include <stdio.h>
#include "schedulers.h"
#include "list.h"
#include "string.h"
#include "cpu.h"

int count=0;
struct node **TaskListHead = 0;

void insertByPriority(struct node **TaskListHead, Task *task){
    struct node *r,*temp = *TaskListHead;
    r = (struct node *)malloc(sizeof(struct node));
    Task *t = (Task *)malloc(sizeof(Task));
    t->tid = task->tid ;
    t->burst = task->burst;
    t->priority = task->priority;
    t->name = (char*)malloc(100*sizeof(char));
    strcpy(t->name ,task->name);
    r->task = t;
    if(*TaskListHead==NULL || (*TaskListHead)->task->priority >= task->priority)
    {   *TaskListHead = r;
        (*TaskListHead)->next = temp;
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->task->priority < task->priority && ( (temp->next == NULL) || (temp->next->task->priority >= task->priority) ))
            {
                r->next = temp->next;
                temp->next = r;

            }
            temp = temp->next;
        }
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
    insertByPriority(TaskListHead,task);
}

// invoke the scheduler
void schedule()
{
    reverse(TaskListHead);
    struct node **temp = TaskListHead;
    double avgW = 0 , w = 0 , t = 0 , avgTA =0 ,avgRT =0 , numElem = 0;

    while ((*temp != 0))
    {
        t += (*temp)->task->burst;
        avgTA += t;

        avgW += w;
        w += (*temp) -> task -> burst;
        run((*temp)->task,(*temp)->task->burst);
        (*temp) = (*temp)->next;
        numElem++;
    }

    free(temp);
    avgRT = avgW;

    printf("Average waiting time = %.2f\n", avgW/numElem);
    printf("Average turnaround time = %.2f\n",avgTA/numElem);
    printf("Average response time = %.2f\n",avgRT/numElem);

}


