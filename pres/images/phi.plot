
set title 'Valeurs de la fonction Psi'
set ylabel 'Psi(z)'
set xlabel 'z'
set grid
set datafile separator ','
plot '../../psi.csv' using 1:2
replot '../../psi.csv' using 1:3
replot '../../psi.csv' using 1:4
replot '../../psi.csv' using 1:5
set term png
set output 'psi.png'
replot
quit
