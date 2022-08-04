//Name: Anandhu S
//Roll No: 211
//Class: R4-A
//Program: Producer consumer problem

#include <stdio.h>
#include <stdlib.h>

int mutex = 1,full = 0,empty = 10, x = 0;

int signal(int s)
{
	return ++s;
}

int wait(int s)
{
	return --s;
}


void producer()
{
	mutex= wait(mutex);
	full= signal(full);
	empty= wait(empty);
	x++;
	printf("\nProducer produces item %d",x);
	mutex= signal(mutex);
}

void consumer()
{
	mutex=wait(mutex);
	full=wait(full);
	++empty;
	printf("\nConsumer consumes item %d",x);
	x--; 
	mutex=signal(mutex);
}

int main()
{
	int n, i;
	printf("1. Press 1 for Producer\n2. Press 2 for Consumer\n3. Press 3 for Exit");
	for (i = 1; i > 0; i++) \
	{
		printf("\nEnter your choice:");
		scanf("%d", &n);
		switch (n) {
		case 1:
			if ((mutex == 1) && (empty != 0)) 
			{
				producer();
			}
			else 
			{
				printf("\nBuffer full");
			}
			break;

		case 2:
			if ((mutex == 1) && (full != 0)) 
			{
				consumer();
			}
			else 
			{
				printf("\nBuffer empty");
			}
			break;

		case 3:
			exit(0);
			break;
		}
	}
}

