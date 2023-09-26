set title "Intensity Reduction of X-ray"
set xlabel "Depth"
set ylabel "Intensity (y=N/N[0])"
set grid

plot "datafile_Al_0_1.txt" using 1:2 with lines title "Al (0.1 nm)", \
     "datafile_Pb_0_1.txt" using 1:2 with lines title "Pb (0.1 nm)", \
     "datafile_Al_0_03.txt" using 1:2 with lines title "Al (0.03 nm)", \
     "datafile_Pb_0_03.txt" using 1:2 with lines title "Pb (0.03 nm)"
