//Name:Smiti Chandwadkar
//PRN_NO:72293277E
// Bankers Algorithm

#include<stdio.h>

void main()
{
  int process, resource, i, j, instance, k=0, count=0, temp=0;
  printf("\n Enter No. of Process : ");
  scanf("%d", &process);
  printf(" Enter No. of Resources : ");
  scanf("%d",&resource);
  int available[resource], max[process][resource], allocated[process][resource], need[process][resource], completed[process];

  for(i=0; i<process; i++)
    completed[i] = 0;

  printf("\n Enter AVAILABLE resources for processes\n\n");
  for(i=0; i<resource;i++)
  {  
    printf(" Resources[%d] : ", i);
    scanf("%d", &instance);
    available[i] = instance;
  }

  printf("\n------------------------------------------------------------------------------\n");
  printf("\n Enter MAXIMUM matrix for process :\n");
  for(i=0; i<process; i++)
  {
    printf("\n For Process[%d] \n", i);
    for(j=0; j<resource; j++)
    {
        printf(" Resource[%d] : ", j);
        scanf("%d", &instance);
        max[i][j] = instance;
    }
  }

  printf("\n------------------------------------------------------------------------------\n");
  printf("\n Enter Allocation matrix :\n");
  for(i=0; i<process; i++)
  {
    printf("\n For Process[%d] \n", i);
    for(j=0; j<resource; j++)
    {
      printf(" Resource[%d] : ", j);
      scanf("%d", &instance);
      allocated[i][j] = instance;
      need[i][j] = max[i][j] - allocated[i][j];// need matrix
    }
  }

  printf("\n------------------------------------------------------------------------------\n");
  printf("\nSafe Sequence is : ");
  while(count != process)
  {
    count = temp;
    for(i=0; i<process; i++)
    {
      for(j=0; j<resource; j++)
      {
        if(need[i][j] <= available[j])
        {
          k++;
        }
      }
      if(k == resource && completed[i] == 0 )
      {
        printf(" > P[%d] ", i);
        completed[i] = 1;
        for(j=0; j<resource; j++)
        {
          available[j] = available[j] + allocated[i][j];
        }      
        count++;
      }
      k=0;
    }

    if(count == temp)
    {
      break;
    }
  }

  for(i=0; i<process; i++)
  {
    if(completed[i] != 1)
    {
      printf("\n\n P[%d] not able to allocate", i);
    }
  }
  printf("\n");
}


#include<stdio.h>

int main() {
    int process, resource, i, j, instance, k=0, count=0, temp=0;
    printf("\n Enter No. of Process : ");
    scanf("%d", &process);
    printf(" Enter No. of Resources : ");
    scanf("%d",&resource);

    int available[resource], max[process][resource], allocated[process][resource], need[process][resource], completed[process];

    for(i=0; i<process; i++)
        completed[i] = 0;

    printf("\n Enter AVAILABLE resources for processes\n\n");
    for(i=0; i<resource; i++) {
        printf(" Resources[%d] : ", i);
        scanf("%d", &instance);
        available[i] = instance;
    }

    printf("\n------------------------------------------------------------------------------\n");
    printf("\n Enter MAXIMUM matrix for process :\n");
    for(i=0; i<process; i++) {
        printf("\n For Process[%d] \n", i);
        for(j=0; j<resource; j++) {
            printf(" Resource[%d] : ", j);
            scanf("%d", &instance);
            max[i][j] = instance;
        }
    }

    printf("\n------------------------------------------------------------------------------\n");
    printf("\n Enter Allocation matrix :\n");
    for(i=0; i<process; i++) {
        printf("\n For Process[%d] \n", i);
        for(j=0; j<resource; j++) {
            printf(" Resource[%d] : ", j);
            scanf("%d", &instance);
            allocated[i][j] = instance;
            need[i][j] = max[i][j] - allocated[i][j]; // need matrix
        }
    }

    printf("\n------------------------------------------------------------------------------\n");
    printf("\nSafe Sequence is : ");
    while(count != process) {
        count = temp;
        for(i=0; i<process; i++) {
            if(completed[i] == 0) {
                int can_allocate = 1;
                for(j=0; j<resource; j++) {
                    if(need[i][j] > available[j]) {
                        can_allocate = 0;
                        break;
                    }
                }
                if(can_allocate) {
                    printf(" > P[%d] ", i);
                    completed[i] = 1;
                    for(j=0; j<resource; j++) {
                        available[j] += allocated[i][j];
                    }
                    count++;
                }
            }
        }
        if(count == temp) {
            printf("\nDeadlock detected!\n");
            break;
        }
        temp = count;
    }

    if(count == process) {
        printf("\nNo deadlock detected.\n");
    } else {
        printf("\nDeadlock detected. The processes not able to allocate resources are:\n");
        for(i=0; i<process; i++) {
            if(completed[i] != 1) {
                printf("P[%d]\n", i);
            }
        }
    }

    return 0;
}






