set terminal png
set output "random_walks.png"

set title "Randomly Walking A Whole Lot"
set xlabel "N (steps)"
set ylabel "Average R for 100 trials"

f(x) = m*x + b
fit [0:50000] f(x) "random_walks.dat" using 1:2 via m,b


plot "random_walks.dat" using 1:2, m*x+b