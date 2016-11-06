# Quadratic Equation Solver

Remember, back in high school you learned about the quadratic equation
    ax^2 + bx + c = 0 (1)
which has an analytic solution that can be written as
    x_(1,2) = -b +- sqrt(b^2 - 4ac) / 2a (2)

Inspection of equation (2) indicates that substractive cancellation arises
when b2 >> 4ac.

1. Write a program that calculates all four solutions for arbitrary values
of a; b; c.
2. Investigate how errors in your answers become large as the subtractive
cancellation increases and relate this to the known machine precision.
3. Extend your program so that it indicates the most precise solutions.