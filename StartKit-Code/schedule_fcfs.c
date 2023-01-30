#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "schedulers.h"
#include "list.h"
#include "task.h"
#include "cpu.h"

int id=0;
struct node **TaskListHead = NULL;
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
    task->tid=id;
    id++;

    insert(TaskListHead,task);
}


void schedule()
{
    struct node **temp = TaskListHead, **temptraverse = TaskListHead;
    double avgW = 0 , w = 0 , t = 0 , avgTA =0 ,avgRT =0 , numElem = 0;
    reverse(temptraverse);
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

    printf("\n");
    printf("Average waiting time = %.2f\n", avgW/numElem);
    printf("Average turnaround time = %.2f\n",avgTA/numElem);
    printf("Average response time = %.2f\n",avgRT/numElem);


}
