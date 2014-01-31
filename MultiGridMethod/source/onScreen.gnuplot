set title "Plot function"
splot "../Plot/plot0.txt" t "3D Plot" with pm3d
splot "../Plot/plot1.txt" t "3D Plot" with pm3d
splot "../Plot/plot5.txt" t "3D Plot" with pm3d
splot "../Plot/plot10.txt" t "3D Plot" with pm3d
splot "../Plot/plot20.txt" t "3D Plot" with pm3d
splot "../Plot/plot50.txt" t "3D Plot" with pm3d
splot "../Plot/plot100.txt" t "3D Plot" with pm3d
splot "../Plot/plot.txt250" t "3D Plot" with pm3d

# set terminal pngcairo  transparent enhanced font "arial,10" fontscale 1.0 size 500, 350 
# set output 'pm3d.1.png'
# set border 4095 front linetype -1 linewidth 1.000
# set samples 25, 25
# set isosamples 20, 20
# set title "Eigenwerte des Jacobi-Verfahrens für n=15" 
# set xlabel "x" 
# set xrange [ 0.0000 : 15.0000 ] noreverse nowriteback
# set ylabel "y" 
# set yrange [ 0.0000 : 15.0000 ] noreverse nowriteback
# set zlabel "z" 
# set zrange [ -1.00000 : 1.00000 ] noreverse nowriteback
# set pm3d implicit at s
# splot (cos(x*pi/15)+cos(y*pi/15))/2