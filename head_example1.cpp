#include <stdio.h>
#include <stdlib.h>

#define queuesize 12
struct node{
    int data[queuesize];
    int cnt;
};
typedef struct node node;
typedef node* heap;

void initialize(heap q){
    q->cnt=0;
    for(int i=0;i<queuesize;i++)
        q->data[i]=0;
}
void swap(int* x,int* y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void enqueue_heap(heap q,int data){
    q->cnt++;
    if(q->cnt==queuesize)
        printf("heap dolu\n\n");
    else{
        int index=q->cnt;
        q->data[index]=data;
        while(index!=1&&q->data[index/2]>q->data[index]){
            swap(&q->data[index],&q->data[index/2]);
            index=index/2;
        }
    }
}
int dequeue_heap(heap q){
    if(q->cnt==0){
        printf("heap bos\n\n");
        return -1;
    }
    else{
        if(q->cnt==queuesize)
            q->cnt--;
        int index=1;
        int min=q->data[index];
        if(q->data[index+1]==0){
            q->data[index]=0;
            q->cnt--;
        }
        else{
            q->data[index]=q->data[q->cnt];
            q->data[q->cnt]=0;
            q->cnt--;

                while((q->data[index]>q->data[index*2]||q->data[index]>q->data[(index*2)+1])&&index*2<queuesize){
                    if(q->data[index*2]<=q->data[(index*2)+1]){
                        if(q->data[index*2]!=0){
                            swap(&q->data[index],&q->data[index*2]);
                            index*=2;
                        }
                        else
                            break;
                    }
                    else{
                        if(q->data[(index*2)+1]!=0){
                            swap(&q->data[index],&q->data[(index*2)+1]);
                            index=(index*2)+1;
                        }
                        else if(q->data[index]>q->data[index*2]){
                            swap(&q->data[index],&q->data[index*2]);
                            index*=2;
                        }
                        else
                            break;
                    }
                }
            }

        return min;
    }
}
void enqueue_heap2(heap q,int data){
    q->cnt++;
    if(q->cnt==queuesize)
        printf("heap dolu\n\n");
    else{
        int index=q->cnt;
        q->data[index]=data;
        while(index!=1&&q->data[index/2]<q->data[index]){
            swap(&q->data[index],&q->data[index/2]);
            index=index/2;
        }
    }
}
void print(heap h){
    if(h->cnt==0)
        printf("heap bos\n\n");
    else{
        int i=1;
        while(i<=h->cnt){
            printf("%d\t",h->data[i]);
            i++;
        }
    }
}
heap *convert(heap q,heap maxheap){
    while (q->cnt!=0){
        int data=dequeue_heap(q);
        enqueue_heap2(maxheap,data);
        }
return maxheap;
}

void newline(){
    printf("\n\n");
}
int main(){
    node heap;
    initialize(&heap);
    enqueue_heap(&heap,10);
    enqueue_heap(&heap,20);
    enqueue_heap(&heap,25);
    enqueue_heap(&heap,30);
    enqueue_heap(&heap,35);
    enqueue_heap(&heap,40);
    enqueue_heap(&heap,60);
    enqueue_heap(&heap,90);
    enqueue_heap(&heap,85);
    printf("\nKuyruk(Min)= ");
    print(&heap);
    node maxheap;
    initialize(&maxheap);
    convert(&heap,&maxheap);
    printf("\nCevrilmis Kuyruk(Max)= ");
    print(&maxheap);
    newline();

    return 0;
}
