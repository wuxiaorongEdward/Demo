#include<stdio.h>
#include<limits.h>

int priceOfFog(int price[], int n)
{
     int i, d, min;
     d = INT_MIN;
     min = INT_MAX;
     for(i = 0; i < n; i++)
        {
          if(price[i] < min)
              min = price[i];
          if(price[i] - min > d)
              d = price[i] - min;
        }
    return d;
}

int main()
{
    int price[5] = {4, 1, 9, 3};
    int profit;
    profit = priceOfFog(price, 5);
    printf("You can get %d\n", profit);
    return 0;
   
}
