set title "Valeurs de l'Energie"
set ylabel 'E(z)'
set xlabel 'z'
set grid
set datafile separator ','
set key off
plot '../../energy.csv' using 1:2 
replot '../../energy.csv' using 1:3
replot '../../energy.csv' using 1:4 
replot '../../energy.csv' using 1:5 
set term png
set output 'energy.png'
replot
quit