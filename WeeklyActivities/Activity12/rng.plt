set terminal png
set title ’Gaussian And Uniform Random Number Distribution’
set output "random_numbers.png"
plot "random_numbers.dat" using 1:2, "random_numbers.dat" using 3:4
