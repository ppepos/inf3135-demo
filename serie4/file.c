#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct QueueNode {
	char content;
	struct QueueNode *prev;
	struct QueueNode *next;
};

typedef struct QueueNode QueueNode;

typedef struct Queue {
	struct QueueNode *first;
	struct QueueNode *last;
} Queue;

Queue *queueCreate()
{
	return (Queue *) calloc(1, sizeof(Queue));
}

bool queueIsEmpty(const Queue *q)
{
	return q->first == NULL;
}

void queuePush(Queue *q, char content)
{
	QueueNode *n = (QueueNode *) calloc(1, sizeof(QueueNode));
	n->content = content;

	n->prev = NULL;
	n->next = q->last;
	q->last = n;

	if(queueIsEmpty(q)) {
		q->first = n;
	} else {
		n->next->prev = n;
	}
}

char queuePop(Queue *q)
{
	char content;

	QueueNode *popped = q->first;
	q->first = popped->prev;
	content = popped->content;

	if(!queueIsEmpty(q)) {
		popped->prev->next = NULL;
	}

	free(popped);

	return content;
}

void queueDelete(Queue *q)
{
	while(q->first != NULL) {
		queuePop(q);
	}
	free(q);
}

int main(int argc, char *argv[])
{
	Queue *q = queueCreate();
	queuePush(q, 'a');
	queuePush(q, 'b');
	queuePush(q, 'c');
	queuePush(q, 'd');

	printf("%c", queuePop(q));
	printf("%c", queuePop(q));
	printf("%c", queuePop(q));

	queuePush(q, 'e');
	queuePush(q, '\n');
	printf("%c", queuePop(q));
	printf("%c", queuePop(q));
	printf("%c", queuePop(q));

	queuePush(q, 0);
	queuePush(q, 0);
	queuePush(q, 0);
	queuePush(q, 0);
	queueDelete(q);

	return 0;
}
