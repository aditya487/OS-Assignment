#include<stdio.h> 
 
int main() 
{ 
      int i, size, total = 0, x, count = 0, TimeQuantum; 
      int waitTime = 0, TAT = 0, AT[10], BT[10], Temp[10]; 
      float AWT, ATAT;
      printf("\nEnter Total Number of Processes:\t"); 
      scanf("%d", &size); 
      x = size; 
      for(i = 0; i < size; i++) 
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &AT[i]);
            printf("Burst Time:\t");
            scanf("%d", &BT[i]); 
            Temp[i] = BT[i];
      } 
      printf("\nEnter Time Quantum:\t"); 
      scanf("%d", &TimeQuantum); 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;) 
      { 
            if(Temp[i] <= TimeQuantum && Temp[i] > 0) 
            { 
                  total = total + Temp[i]; 
                  Temp[i] = 0; 
                  count = 1; 
            } 
            else if(Temp[i] > 0) 
            { 
                  Temp[i] = Temp[i] - TimeQuantum; 
                  total = total + TimeQuantum; 
            } 
            if(Temp[i] ==0) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, BT[i], total - AT[i], total - AT[i] - BT[i]);
                  waitTime = waitTime + total - AT[i] - BT[i]; 
                  TAT = TAT + total + AT[i]; 
                  count = 0; 
            } 
            if(i == size - 1) 
            {
                  i = 0; 
            }
            else if(AT[i + 1] <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
      } 
      AWT = waitTime * 1.0 / size;
      ATAT = TAT * 1.0 / size;
      printf("\n\nAverage Waiting Time:\t%f", AWT); 
      printf("\nAvg Turnaround Time:\t%f\n", ATAT); 
      return 0; 
}
