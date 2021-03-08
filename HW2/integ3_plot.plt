set term png
set output "integ3_plot.png"
set title "Simpson and Milne integration of exp(exp(4*x/3))"
f(x) = m/x
g(x) = b/x
fit [0:500] f(x) "integ3.dat" using 1:2 via m
fit [0:500] g(x) "integ3.dat" using 1:3 via b
plot "integ3.dat" using 1:2 title "Simpson", m/x title "fit", "integ3.dat" using 1:3 title "Milne", b/x title "fit"