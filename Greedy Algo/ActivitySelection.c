/*
Activity 1: 1 4
Activity 2: 2 5
Activity 3: 4 5
Activity 4: 3 2
*/
#include<stdio.h>

typedef struct {
    int start;
    int finish;
}Activity;

void sortActivities(Activity activities[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (activities[i].finish > activities[j].finish)
            {
                Activity temp = activities[i];
                activities[i] = activities[j];
                activities[j] = temp;
            }
        }
    }
}

void ActivitySelection(Activity activities[], int n)
{
    int i = 0;
    printf("Selected activities: \n");
    printf("Activity %d: (%d, %d) ", i+1, activities[i].start, activities[i].finish);
    for (int j = 1; j < n; j++)
    {
        if(activities[j].start >= activities[i].finish)
        {
            printf("Activity %d: (%d, %d) ", j+1, activities[j].start, activities[j].finish);
        }  
    }
}

int main()
{
    int n; 
    printf("Enter the no. of activities: ");
    scanf("%d", &n);
    Activity activities[n];
    printf("Enter the Activites(Start, finish) times: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Activity %d: ", i+1);
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }

    sortActivities(activities, n);
    ActivitySelection(activities, n);
}