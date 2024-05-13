#include <stdio.h>
struct item_weight_combo{
    double cost;
    int weight;
};

struct item_weight_combo* knapsack_Sort(struct item_weight_combo []);
int main(){
    int sack_weight = 15;
    struct item_weight_combo itc[7];
    
    //Assigning Weights and Cost
    itc[0].cost = 5;
    itc[0].weight = 2;
    
    itc[1].cost = 1.66;
    itc[1].weight = 3;
    
    itc[2].cost = 3;
    itc[2].weight = 5;
    
    itc[3].cost = 1;
    itc[3].weight = 7;
    
    itc[4].cost = 6;
    itc[4].weight = 1;
    
    itc[5].cost = 4.5;
    itc[5].weight = 4;
    
    itc[6].cost = 3;
    itc[6].weight = 1;
    
    //Sort the struct array in decreasing order on the basis of cost & weights
    struct item_weight_combo* uitc = knapsack_Sort(itc);
    int i = 0;
 
    double max_profit = 0;
    while(i < 7){
        if(sack_weight < (uitc+i)->weight){
            max_profit += sack_weight*(uitc+i)->cost;
            sack_weight -= sack_weight;
        } else {
            max_profit += (uitc+i)->cost*(uitc+i)->weight;
            sack_weight -= (uitc+i)->weight;
        }
        i++;
    }
    printf("%.1f",max_profit);
    return 0;
}

struct item_weight_combo* knapsack_Sort(struct item_weight_combo itc[]){
    int swap_count = 1;
    int array_length = 7;
    int i = 0;
    struct item_weight_combo temp;
    do{
        swap_count = 0;
        i = 0;
        while(i < array_length-1){
            if(itc[i].cost < itc[i+1].cost){
                temp = itc[i];
                itc[i] = itc[i+1];
                itc[i+1] = temp;
                swap_count ++;
            } else if((itc[i].weight > itc[i+1].weight)&&(itc[i].cost == itc[i+1].cost)){
            	/**inCase if weights are different but cost are same*/
                temp = itc[i];
                itc[i] = itc[i+1];
                itc[i+1] = temp;
            }
            i = i+1;
        }
    }while(swap_count != 0);
    //print_struct_elements(itc);
    return itc;
}
