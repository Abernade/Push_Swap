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

## RADIX

```c
equenceDiagram
    participant PS as push_swap
    participant A as Stack A
    participant B as Stack B

    PS->>A: assign_indices()
    note right of PS: Replace each value in A with its sorted index

    loop For each bit in 0..bit_count
        alt bit = 0
            A->>B: pb
            note over A,B: Move top from A to B
        else bit = 1
            A->>A: ra
            note over A: Rotate stack A upwards
        end

        alt Next bit in B
            B->>A: pa
            note over B,A: Push top from B to A if bit=1
            B->>B: rb
            note over B: Rotate B if bit=0
        end
    end

    PS->>B: push_all_from_b_to_a()
    note right of PS: Gather all elements back into A

    PS->>A: give_values_back()
    note right of PS: Convert indexed values back to the original integers
```

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

Found online :

> The algorithm
> Small cases are handled separately for maximum efficiency:

    2 elements: at most one sa
    3 elements: hardcoded decision tree, at most 2 moves
    4–5 elements: the smallest element(s) are pushed to b, the remaining 3 are sorted with the 3-element handler, then pushed back

    Large cases (6+ elements) use the Turk algorithm:

    Push the first two elements to stack b — these seed the sorted structure in b.
    For each remaining element in a, calculate its total_cust to reach its correct insertion position in b.
    Select the node with the lowest total cost (calculate_cust).
    Move both stacks simultaneously when both require rotation in the same direction (rr / rrr), then individually for the remainder — this is the key optimization that reduces operation count.
    Push the selected node to b.
    Repeat until a is empty.
    Rotate b so its maximum element is on top, then push everything back to a with pa — stack b was kept in descending order throughout, so this produces a correctly sorted a.

    //maybe ne pas reverse back à chaque fois mais juste trouver le top de b puis rien qu'a la fin rotate dans le bon sens pour n'avoir qu'une seule fois du revrse rotate ?
