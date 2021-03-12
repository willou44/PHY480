# plot file for diffeq_oscillations


# simple plot versus time
set term x11 1 title "Time Dependence"  # plot window 1
set timestamp
set title 'Oscillations: Time Dependence'
pi = 3.141592653589793
k = (2.*pi)**2
m = 1
omega = sqrt(k/m)
set xlabel 't'
set ylabel 'y(t)'
plot "diffeq_oscillations.dat" using ($1):($2) title 'p=?' with lines 
#plot "diffeq_oscillations.dat" using ($1):($2) title 'p=?' with lines # , \
#  (1/omega)*sin(omega*x)


# phase space plot
set term x11 2 title "Phase Space"  # plot window 2
set timestamp
set title 'Oscillations: Phase Space'
set xlabel 'x(t)'
set ylabel 'v(t)'
plot "diffeq_oscillations.dat" using ($2):($3) title 'phase-space plot' with lines


# plot the potential
set term x11 3 title "Potential V(x)"  # plot window 3
set timestamp
set title 'Oscillations: Potential V(x)'
set xlabel 'x'
set ylabel 'V(x)'
plot "diffeq_oscillations.dat" using ($2):($5) title 'V(x)' with lines


# plot of kinetic energy and potential energy versus time
set term x11 4 title "Energy"  # plot window 4
set timestamp
set title 'Oscillations: Energy'
set xlabel 't'
set ylabel 'energy'
plot "diffeq_oscillations.dat" using ($1):($4) title 'KE(t)' with lines, \
     "diffeq_oscillations.dat" using ($1):($5) title 'PE(t)' with lines
 
