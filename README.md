
``` console
                                     d8
                                     88
          88d888b. dP    dP ,d888'   88d8888b.        ,d888'   dP  dP  dP .d8888b. 88d888b.
          88'  '88 88    88 Y8ooooo. 88'   `88        Y8ooooo. 88  88  88 88'  `88 88'  '88
          88.  .88 88.  .88       88 88     88              88 88.88b.88' 88.  .88 88.  .88
          8Y888P'  `888888' `88888P' 8P     dP d8888P `88888P' 8888P Y8P  `88888P8 8Y888P' 
          88                                                                       88
          8P                                                                       8P
```

Push_swap
=========

School algorithm project **push_swap**: the aim is to sort data using only two stacks and a limited set of instructions.  
Norminette codestyle.   
[**subject.pdf**](https://cdn.intra.42.fr/pdf/pdf/36359/en.subject.pdf)  

------------

Sorting 100 numbers takes an average of 660 steps  
Sorting 500 numbers takes an average of 4930 steps  
Evaluation of the algorithm by subject: `125/100`

Commands
--------

Only these moves are allowed:
- `sa` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- `sb` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- `ss` : `sa` and `sb` at the same time.
- `pa` : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
- `pb` : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
- `ra` : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
- `rb` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : `ra` and `rb` at the same time.
- `rra` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : `rra` and `rrb` at the same time.

Installation
------------
```
git clone https://github.com/a-parfenov/Push_swap.git && cd push_swap && make
```
Run
---
``` bash
./push_swap 3 0 2 1 4
```
```
ARG="5 3 6 0 2 1 4"; ./push_swap $ARG | ./checker $ARG
```
```
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
```

Visualization
-------------
![pushswap](https://user-images.githubusercontent.com/6814254/39968014-7caf603a-56c6-11e8-8859-6231562d3ae8.gif)
