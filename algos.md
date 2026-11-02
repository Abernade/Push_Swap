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
