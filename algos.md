# ALGOS

## --simple alias insertion sort

L'agorithme commence par comparer les deux premieres valeurs de la liste. Si la première est supperieure à la seconde, on opère une inversion passant le seconde en tete de liste: on le sort de la stack a et on le met sur la stack b puis un rotate la stack a pour trouver l'élément supérieur. On avance et on compare avec le suivant.

```c
push_b(data)
b_max = *(int *)data->stack_b->content;
tant que (sorted < size - 1 && data->stack_a)
    - si stack_a[0] < stack_b[0]
        - push_b(data);
    sinon (stack_a[0] > stack_b[0])
        si (stack_a[0] > b_max)
        push_b(); && b_max = *(int *)data->stack_b->content; && rotate_b(data);
        sinon
            tant que (stack_b[0] < stack_a[0])
                rotate_b(data); && count++;
            push_b(data);
    tant que (count > 0)
        reverse_rotate_b(data); count--;
    sorted++;
```

## Bucket Sort

1/ Indexer tous les éléments de la stack A du plus petit au plus grand  
2/ Attribuer un bucket à chaque élément, le nombre de bucket est `sqrt(stack_size)`  
3/ Push les éléments de la stack A vers la stack B de manière à les regrouper par bucket dans la stack B  
4/ Trier l'intérieur de chaque bucket de la stack B avec un algo plus simple (i.e. insertion ou bubble sort)  
5/ Repush les éléments dans la stack A

Note: Trier les éléments à l'envers dans la stack B permettrait de les repush dans la stack A sans avoir à rotate_a entre chaque push donc probablement de gagner des instructions


## Radix sort 
With the radix sort we are stuck at 6771 moves for 500 numbers. 

```c
indexer; 
max = higthest idex;
max = count_bits;
for (bit = 0 && bit <= max, bit++)
	if (bit actuel == 0)
		push_b();
	else
		rotate_a();
	fin;
	if (bit actuel + 1 dans b == 1)
		push_a();
	else 
		rotate_b();
	fin;
push_bach_to_a;
```

## Turkish sort algorithm
Need to have more info about that one.
