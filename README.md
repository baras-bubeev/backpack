# backpack
## Solving the knapsack problem using the greedy algorithm
### Knapsack problem
The loading problem (the knapsack problem) and its various modifications are widely used in practice in applied mathematics, cryptography, economics, logistics, to find a solution for optimal loading of various vehicles: planes, ships, railway wagons, etc.<br/>

In general terms, the problem can be formulated as follows: from a given set of objects with the properties " value" and " weight" it is required to select a subset with the maximum total value, while observing the restriction on the total weight.<br/>

### Greedy algorithm
A greedy algorithm is any algorithm that follows the problem-solving heuristic of making the locally optimal choice at each stage.[1] In many problems, a greedy strategy does not usually produce an optimal solution, but nonetheless, a greedy heuristic may yield locally optimal solutions that approximate a globally optimal solution in a reasonable amount of time.<br/>
___
To solve the problem by greedy algorithm, we need to sort things by their specific value (i.e. the ratio of the value of the item to its weight), and put items with the highest specific value into the backpack.

Suppose there is a backpack `r` with capacity `W` and `n` items `a[i]`, each having value `v[i]` and weight `w[i]`.

The strategy of the greedy algorithm is as follows:

1. The specific price of a thing `c[i] = v[i] /w[i]` is calculated;

2. Things are sorted in descending order of specific price;

3. the item with the maximum unit price is chosen first;

4. From the remaining set the item with the maximum price is chosen again, and so on.

The condition of selection is that the added item does not lead to exceeding the capacity of the backpack `W`.
___
The program consists of six functions:

1. `sort()` - sorts things by decreasing specific value;

2. `fill()` - performs filling of the backpack;

3. `add_object()` - adds an item;

4. `obj_change()` - changes item's parameters;

5. `save()` - saves the changes made to the file;

6. `main()` - main function that starts the program.
