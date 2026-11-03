# ALGOS

## --simple alias insertion sort

L'agorithme commence par comparer les deux premieres valeurs de la liste. Si la première est supperieure à la seconde, on opère une inversion passant le seconde en tete de liste: on le sort de la stack a et on le met sur la stack b puis un rotate la stack a pour trouver l'élément supérieur. On avance et on compare avec le suivant.

```c
int i;
i = 0;
while(stack_a){
	i = stack_a->content[0];
	stack = stack->next;
	if (i > stack->content[0]){
		swap_a;
		rotate_a;
	}
	else {
		rotate_a;
	}
}
```

## Bucket Sort

1/ Indexer tous les éléments de la stack A du plus petit au plus grand  
2/ Attribuer un bucket à chaque élément, le nombre de bucket est `sqrt(stack_size)`  
3/ Push les éléments de la stack A vers la stack B de manière à les regrouper par bucket dans la stack B  
4/ Trier l'intérieur de chaque bucket de la stack B avec un algo plus simple (i.e. insertion ou bubble sort)  
5/ Repush les éléments dans la stack A

Note: Trier les éléments à l'envers dans la stack B permettrait de les repush dans la stack A sans avoir à rotate_a entre chaque push donc probablement de gagner des instructions
