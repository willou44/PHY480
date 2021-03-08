#  file: derivative_test.plt 
#
#  Gnuplot plot file for derivative_test output
#  
#  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
# 
#  Revision history
#   2004-01-24  original version for 780.20 session 5
#   2004-01-16  added postscript enhanced and comments for session 4
#

# record the time and date the graph was generated
set timestamp

# titles and labels
set title 'Test of Numerical Derivatives using exp(-x)'
set xlabel 'log10(mesh size)'
set ylabel 'relative error'

# move the legend to a free space
set key left

# set the x and y axis scales (already logs)
set xrange [-10:-1]
set yrange [-12:0]

# fit the curve
f1(x) = a1*x + b1
fit [-8:-1] f1(x) "derivative_test.dat" using ($1):($2) via a1,b1 
fit1_title = sprintf("%-+4.1f*x %-+4.1f",a1,b1)

f2(x) = a2*x + b2
fit [-8:-1] f2(x) "derivative_test.dat" using ($1):($3) via a2,b2 
fit2_title = sprintf("%-+4.1f*x %-+4.1f",a1,b1)


# set the terminal type to be the screen (which is x11 here)
set term png #Cameron Willoughby: I edited this because I cannot get my Xterminal working with Cygwin, however can easilly generate pngs!
set out "derivative_test_plt.png"

# plot the data as well as the fit, with appropriate titles 
plot "derivative_test.dat" using ($1):($2) title 'forward difference',\
	a1*x + b1 title fit1_title,\
	"derivative_test.dat" using ($1):($3) title 'central derivative', \
	a2*x + b2 title fit2_title,\
	"derivative_test.dat" using ($1):($4) title 'extrapolated central derivative'  

#set term postscript color enhanced
replot