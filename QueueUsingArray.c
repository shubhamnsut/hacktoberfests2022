#include<stdio.h>
#include<stdlib.h>
 
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("\nEnqued element: %d", val);
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("\nThis Queue is empty");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}
void display(struct queue *q){
	int i;
	printf("Elements:  ");
	for(i=q->f;i<q->size;i++){
		printf(" %d ",q->arr[i]);
	}
}
 
int main(){
    struct queue q;
    printf("Size: ");
    scanf("%d",&q.size);
    q.f = q.r = 0;
    int i=q.size-1,val;
    q.arr = (int*) malloc(q.size*sizeof(int));
    while(i--){
	
    printf("\nValue you want to insert: ");
    scanf("%d",&val);
    enqueue(&q, val);
    }
    printf("\nThe number of items you to dequeue: ");
    scanf("%d",&i);
    while(i--){
	


    printf("Dequeuing element %d\n", dequeue(&q));
    }
    display(&q);
   
 
   
 
    return 0;
}
