#  file: gaussian_random_new.plt 
#
#  Gnuplot plot file for gaussian_random_new histograms
#  
#  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
# 
#  Revision history
#   2004-03-05  original version for 780.20 session 12
#   2016-03-29  fixed logscale and sprintf for newer versions of gnuplot
#   2021-04-09  Changed Terminal to PNG for my own issues (Cameron Willoughby)

# record the time and date the graph was generated
set timestamp

# titles and labels
set title 'Random Number Distributions'
set xlabel 'x'
set ylabel '# in bin'

# move the legend to a free space
set key left

# set the x and y axis scales (already logs)
set xrange [-3:3]
#set yrange [0:100]

# fit the curve
f(x) = b*exp(-x**2/(2*sigma**2))
fit [-3:3] f(x) "random_histogram.dat" using ($5):($6) via b,sigma 

# set the terminal type to be the screen (which is PNG here)
set term png
set output "gaussian_random_new.png"

# add a label with the result for sigma
unset label
set label sprintf("fit sigma = %-4.1f", abs(sigma)) at graph .08,.80

# plot 
plot "random_histogram.dat" using ($5):($6) title 'gaussian 1', \
     b*exp(-x**2/(2*sigma**2)) title 'fit to gaussian 1', \
     "random_histogram.dat" using ($5):($7) title 'gaussian 2'

# output the plot to the file derivative_test_plt.ps   
set out "gaussian_random_new_plt.ps"
set term postscript 
replot
