# 42_push_swap
push_swap project from the 42 main curriculum

This repo contains my version of push_swap which is a sorting algorithm for integers with the aim being to sort them into ascending order by using the fewest number of operations. The operations are described below and can also be seen in the subject pdf.


sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.

ss : sa and sb at the same time.


pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.


ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.

rr : ra and rb at the same time.


rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.

rrr : rra and rrb at the same time.


I used a few different sorting algorithms and tried even more while creating this program.
For small stacks of integers (<10), I push the smallest ranked integers to stack_b until there are only 3 nodes in stack_a, sort stack_a, and then push the nodes in stack_b back.

For medium stacks (~100), I search for the cheapest node in stack_a and then sort it into descending order as I push it over to stack_b, then push them all back over to stack_a.

For large stacks (~500), I search for the cheapest node in stack_a that is ranked in the lowest quarter of integers and push that over to stack_b, then if that node is smaller than the node below it in stack_b I will use sb to swap those 2 nodes. I also check if the top node in stack_a is larger than the second node and use ss to swap both stacks if that is the case. I repeat this until all but 2 nodes have been moved to stack_b resulting in stack_b being partially sorted in descending order, it won't be properly sorted but lower nodes will be towards the bottom and higher nodes will be towards the top. I then find the cheapest node to sort back into the correct order and do that until all nodes are back in stack_a and it is sorted in ascending order.

I also have another algorithm for sorting medium stacks that can be used by calling alt_sort() in main instead of sort(). that one will push the median node over to stack_b first and then starting with nodes that are ranked closer to and working outwards it will find the cheapest node and push it to stack_b, if the node is ranked lower than the median node it will rotate stack b so that stack_b will be partially sorted with lower ranked nodes beneath the median node and higher ranked nodes above it. I then use the same logic as the large stack algorithm to push the cheapest node back to the correct position in stack_a. I thought that this algorithm would be more efficient than my other medium stack algorithm but it seems to be about the same. Both mostly use less than 700 operations which is needed for full marks but they will both also occasionally return >700.


A good visualiser for the sorting can be found here:
https://github.com/elijahkash/push_swap_gui