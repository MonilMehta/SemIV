#include <stdio.h>
#define max 15

struct item{
    int profit, weight;
    float profitByWeight, includes;
}items[10];
    
void main(){
    int n, w = max;
    float max_profit;
    printf("Enter no. of items : ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        printf("Enter profit and Weight of item %d : ",i+1);
        scanf("%d%d",&items[i].profit, &items[i].weight);
        items[i].profitByWeight = (float)items[i].profit/items[i].weight;
        items[i].includes = 0;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<(n-i); j++){
            if(items[j].profitByWeight < items[j+1].profitByWeight){
                struct item temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(items[i].weight <= w){
            w -= items[i].weight;
            items[i].includes = 1;
            max_profit += items[i].profit;
        }else{
            float ratio = (float)w/items[i].weight;
            items[i].includes = ratio;
            w -= (int)items[i].weight*ratio;
            max_profit += (float)items[i].profit*ratio;
        }
    }

    printf("\nProfit\t\tWeight\t\tP/W\t\tIncludes\n");
    for(int i=0; i<n; i++){
        printf("%d\t\t%d\t\t%.2f\t\t%.2f\n", items[i].profit, items[i].weight, items[i].profitByWeight, items[i].includes);
    }
    printf("\n");
    printf("The MAX profit : %.2f\n ",max_profit); 
}