set terminal png
set title "Randomly Walking"
set output "random_walk.png"
plot "random_walk.dat" using 1:2 with lines
