set term png
set output "random_numbers.png"
plot "random_numbers.dat" using 1:3
