//page replacement algo [LRU]
//parameters : number of frames, length of reference string, count for pointing to particular location in array

#include<stdio.h>

int check(int refstr, int frame[][2], int framelength)
{
    int i;
    for(i=0;i<framelength;i++)
    {
        if(frame[i][0] == refstr)
        {
            return i;
        }
    }
    return -1;
}

void display_frameelements(int frame[][2], int framecount)
{
    int i;
    for(i=0;i<framecount;i++)
    {
        printf("%d  ", frame[i][0]);
    }
    printf("\n");
}

int min(int frame[][2], int framelength)
{
    int i, min = frame[0][1], index = 0;
    for(i=1;i<framelength;i++)
    {
        if(frame[i][1]<min)
        {
            min = frame[i][1];
            index = i;
        }
    }
    return index;
}

int main()
{
    int frame_count, refstr_len, i, flag, min_flag, count = 0, framealloc = 0;
    float page_hits, page_faults;
    printf("Enter the number of frames:");
    scanf("%d", &frame_count);
    printf("Enter the length of the ref string:");
    scanf("%d", &refstr_len);
    int frame[frame_count][2], refstr[refstr_len];
    printf("Enter the reference string:\n");
    for(i=0;i<refstr_len;i++)
    {
        scanf("%d", &refstr[i]);
    }
    //assigning the values in frames as -1
    for(i=0;i<frame_count;i++)
    {
        frame[i][0] = -1;
        frame[i][1] = 0;
    }
    //iterating throudh each reference string ans assigning the values to the frame
    for(i=0;i<refstr_len;i++)
    {
        flag = check(refstr[i], frame, frame_count);    //getting the index number if present
        if(flag != -1)
        {
            frame[flag][1] = frame[flag][1]+1;
            page_hits++;
            //count++;
            printf("The elements in the frame int iteration %d are: ", i+1);
            display_frameelements(frame, frame_count);
        }
        else
        {
            min_flag = min(frame, frame_count);
            page_faults++;
            frame[min_flag][0] = refstr[i];
            frame[min_flag][1] = 0;
            count++;
            printf("The elements in the frame int iteration %d are: ", i+1);
            display_frameelements(frame, frame_count);
        }
    }
    printf("The number of page hits are:%f\nThe number of page faults are:%f\n", page_hits, page_faults);
}

//https://www.geeksforgeeks.org/page-faults-in-lfu-implementation/