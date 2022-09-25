//page replacement algo [FIFO]
//parameters : number of frames, length of reference string, count for pointing to particular location in array
#include<stdio.h>

int check(int refstr, int* frame, int framelength)
{
    int i;
    for(i=0;i<framelength;i++)
    {
        if(frame[i] == refstr)
        {
            return 1;
        }
    }
    return -1;
}

void display_frameelements(int* frame, int framecount)
{
    int i;
    for(i=0;i<framecount;i++)
    {
        printf("%d  ", frame[i]);
    }
    printf("\n");
}

int main()
{
    int frame_count, refstr_len, i, count = 0;
    float page_hits, page_faults;
    printf("Enter the number of frames:");
    scanf("%d", &frame_count);
    printf("Enter the length of the ref string:");
    scanf("%d", &refstr_len);
    int frame[frame_count], refstr[refstr_len];
    printf("Enter the reference string:\n");
    for(i=0;i<refstr_len;i++)
    {
        scanf("%d", &refstr[i]);
    }
    //assigning the values in frames as -1
    for(i=0;i<frame_count;i++)
    {
        frame[i] = -1;
    }
    //iterating throudh each reference string ans assigning the values to the frame
    for(i=0;i<refstr_len;i++)
    {
        if(check(refstr[i], frame, frame_count) == 1)
        {
            page_hits++;
            printf("The elements in the frame int iteration %d are: ", i+1);
            display_frameelements(frame, frame_count);
        }
        else
        {
            page_faults++;
            frame[count] = refstr[i];
            count = (count+1)%frame_count;
            printf("The elements in the frame int iteration %d are: ", i+1);
            display_frameelements(frame, frame_count);
        }
    }
    printf("The number of page hits are:%f\nThe number of page faults are:%f\n", page_hits, page_faults);
}


//https://www.geeksforgeeks.org/page-replacement-algorithms-in-operating-systems/
//https://www.javatpoint.com/os-gate-2015-question-on-lru-and-fifo