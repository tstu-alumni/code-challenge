# ChemProcess

A chemical is added a drop at a time to a container in which a reaction
is occuring. Each drop is measured as precisely 0.9389ml. The total amount of the chemical must be computed after each drop is added. Write a program to perform the calculation in two ways:

1. by incrementing the previous total by 0.9389ml (accumulation), and
2. by multiplying 0:9389ml by the number of drops so far.

At the beginning ask the user for the number of iterations and the reportinginterval. Print the iteration interval and both ongoing totals at the requested intervals. Print the output and report for each of the following:

1. Run the program with a reporting interval of 1 to determine the first iteration in which there is a difference between the two computations. What are the absolute and relative errors for the accumulation at that point? Is there an error for the multiplication?

2. Run the program with a reporting interval of 106. What are the absolute and relative errors for both totals?

3. Run the program with a reporting interval of 999999. What are the absolute and relative errors for both totals?

4. Run the program with a large enough number of iterations and a large reporting interval so that eventually the value for the accumulation does not change from one report to the next. What explanation do you have for this phenomenon?
