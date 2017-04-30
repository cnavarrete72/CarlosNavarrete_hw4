import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm

n_x=101
n_y=101
x=np.linspace(0, 1.0, n_x)
y=np.linspace(0, 1.0, n_y)
t=np.linspace(0, 2500,2500)

def transformer(i,j):
    return i*n_x+j

def vuelvematriz(vector):
    matriz=np.ones((n_x, n_y))
    for i in range (0, n_x):
        for j in range(0, n_y):
            matriz[i][j]=vector[transformer(i,j)]
    return matriz
            

T_0_1=vuelvematriz(np.loadtxt('0_1.txt'))
T_0_2=vuelvematriz(np.loadtxt('0_2.txt'))
T_100_1_cerradas=vuelvematriz(np.loadtxt('100_1_cerradas.txt'))
T_2500_1_cerradas=vuelvematriz(np.loadtxt('2500_1_cerradas.txt'))
T_100_2_cerradas=vuelvematriz(np.loadtxt('100_2_cerradas.txt'))
T_2500_2_cerradas=vuelvematriz(np.loadtxt('2500_2_cerradas.txt'))
T_100_1_periodicas=vuelvematriz(np.loadtxt('100_1_periodicas.txt'))
T_2500_1_periodicas=vuelvematriz(np.loadtxt('2500_1_periodicas.txt'))
T_100_2_periodicas=vuelvematriz(np.loadtxt('100_2_periodicas.txt'))
T_2500_2_periodicas=vuelvematriz(np.loadtxt('2500_2_periodicas.txt'))
T_100_1_abiertas=vuelvematriz(np.loadtxt('100_1_abiertas.txt'))
T_2500_1_abiertas=vuelvematriz(np.loadtxt('2500_1_abiertas.txt'))
T_100_2_abiertas=vuelvematriz(np.loadtxt('100_2_abiertas.txt'))
T_2500_2_abiertas=vuelvematriz(np.loadtxt('2500_2_abiertas.txt'))
promedios_1=np.loadtxt('promedios_caso1.txt')
promedios_2=np.loadtxt('promedios_caso2.txt')

#Hacemos la grilla
x, y = np.meshgrid(x, y)
#Graficamos la situacion inicial
plt.figure()
plt.axes(projection='3d').plot_surface(x, y, T_0_1, cmap=plt.cm.jet, rstride=1, cstride=1, linewidth=0)
plt.xlabel('X(m)')
plt.ylabel('Y(m)')
plt.savefig('Inicial_Caso1')

plt.figure()
plt.axes(projection='3d').plot_surface(x, y, T_0_2, cmap=plt.cm.jet, rstride=1, cstride=1, linewidth=0)
plt.xlabel('X(m)')
plt.ylabel('Y(m)')
plt.savefig('Inicial_Caso2')

plt.figure()
plt.axes(projection='3d').plot_surface(x, y, T_100_1_cerradas, cmap=plt.cm.jet, rstride=1, cstride=1, linewidth=0)
plt.xlabel('X(m)')
plt.ylabel('Y(m)')
plt.savefig('Caso1_Cerradas_t100')

plt.figure()
plt.axes(projection='3d').plot_surface(x, y, T_100_2_cerradas, cmap=plt.cm.jet, rstride=1, cstride=1, linewidth=0)
plt.xlabel('X(m)')
plt.ylabel('Y(m)')
plt.savefig('Caso2_Cerradas_t100')

plt.figure()
plt.axes(projection='3d').plot_surface(x, y, T_2500_1_cerradas, cmap=plt.cm.jet, rstride=1, cstride=1, linewidth=0)
plt.xlabel('X(m)')
plt.ylabel('Y(m)')
plt.savefig('Caso1_Cerradas_t2500')

plt.figure()
plt.axes(projection='3d').plot_surface(x, y, T_2500_2_cerradas, cmap=plt.cm.jet, rstride=1, cstride=1, linewidth=0)
plt.xlabel('X(m)')
plt.ylabel('Y(m)')
plt.savefig('Caso2_Cerradas_t2500')

plt.figure()
plt.axes(projection='3d').plot_surface(x, y, T_100_1_periodicas, cmap=plt.cm.jet, rstride=1, cstride=1, linewidth=0)
plt.xlabel('X(m)')
plt.ylabel('Y(m)')
plt.savefig('Caso1_Periodicas_t100')

plt.figure()
plt.axes(projection='3d').plot_surface(x, y, T_2500_1_periodicas, cmap=plt.cm.jet, rstride=1, cstride=1, linewidth=0)
plt.xlabel('X(m)')
plt.ylabel('Y(m)')
plt.savefig('Caso1_Periodicas_t2500')

plt.figure()
plt.axes(projection='3d').plot_surface(x, y, T_100_2_periodicas, cmap=plt.cm.jet, rstride=1, cstride=1, linewidth=0)
plt.xlabel('X(m)')
plt.ylabel('Y(m)')
plt.savefig('Caso2_Periodicas_t100')

plt.figure()
plt.axes(projection='3d').plot_surface(x, y, T_2500_2_periodicas, cmap=plt.cm.jet, rstride=1, cstride=1, linewidth=0)
plt.xlabel('X(m)')
plt.ylabel('Y(m)')
plt.savefig('Caso2_Periodicas_t2500')

plt.figure()
plt.axes(projection='3d').plot_surface(x, y, T_100_1_abiertas, cmap=plt.cm.jet, rstride=1, cstride=1, linewidth=0)
plt.xlabel('X(m)')
plt.ylabel('Y(m)')
plt.savefig('Caso1_Abiertas_t100')

plt.figure()
plt.axes(projection='3d').plot_surface(x, y, T_100_2_abiertas, cmap=plt.cm.jet, rstride=1, cstride=1, linewidth=0)
plt.xlabel('X(m)')
plt.ylabel('Y(m)')
plt.savefig('Caso2_Abiertas_t100')

plt.figure()
plt.axes(projection='3d').plot_surface(x, y, T_2500_1_abiertas, cmap=plt.cm.jet, rstride=1, cstride=1, linewidth=0)
plt.xlabel('X(m)')
plt.ylabel('Y(m)')
plt.savefig('Caso1_Abiertas_t2500')

plt.figure()
plt.axes(projection='3d').plot_surface(x, y, T_2500_2_abiertas, cmap=plt.cm.jet, rstride=1, cstride=1, linewidth=0)
plt.xlabel('X(m)')
plt.ylabel('Y(m)')
plt.savefig('Caso2_Abiertas_t2500')

plt.figure()
plt.plot(t,promedios_1[:,0], label='Cerradas')
plt.plot(t,promedios_1[:,1], label='Periodicas')
plt.plot(t,promedios_1[:,2], label='Abiertas')
plt.legend(loc=0)
plt.xlabel('Tiempo(s)')
plt.ylabel('Temperatura(grados)')
plt.savefig('promedios_caso1')

plt.figure()
plt.plot(t,promedios_2[:,0], label='Cerradas')
plt.plot(t,promedios_2[:,1], label='Periodicas')
plt.plot(t,promedios_2[:,2], label='Abiertas')
plt.legend(loc=0)
plt.xlabel('Tiempo(s)')
plt.ylabel('Temperatura(grados)')
plt.savefig('promedios_caso2')


              





