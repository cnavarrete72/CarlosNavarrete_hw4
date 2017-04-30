#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

int n_x=101;
int n_y = 101;
int n_t = 2500;
double nu = 0.0001;
double sigma = 0.3;
double dx = 0.01;
double dy=0.01;

int transformer(int i, int j);
void initial_condition(double *T);
void copy(double *T_new, double *T_past);
void update_T(double *T_present, double *T_past, double alpha, double beta, int caso);
void print_T(double *T, FILE *out);
void solucionar(double *T_present, double alpha, double beta, int caso, int condicion );
double promedio(double *lista);
void print_prom(double *prom1, double *prom2, double *prom3, FILE *archivo);



int main()
{	
	int tam=n_x*n_y;
	double dt = sigma*pow(dx,2)/nu;
	double alpha = dt/pow(dx,2);
	double beta=dt/pow(dy, 2);

	double *T_0_1 = malloc(tam*sizeof(double));
	double *T_100_1_cerradas = malloc(tam*sizeof(double));
	double *T_2500_1_cerradas = malloc(tam*sizeof(double));
	double *T_0_2 = malloc(tam*sizeof(double));
	double *T_100_2_cerradas = malloc(tam*sizeof(double));
	double *T_2500_2_cerradas = malloc(tam*sizeof(double));
	double *T_100_1_periodicas = malloc(tam*sizeof(double));
	double *T_2500_1_periodicas = malloc(tam*sizeof(double));
	double *T_100_2_periodicas = malloc(tam*sizeof(double));
	double *T_2500_2_periodicas = malloc(tam*sizeof(double));
	double *T_100_1_abiertas = malloc(tam*sizeof(double));
	double *T_2500_1_abiertas = malloc(tam*sizeof(double));
	double *T_100_2_abiertas = malloc(tam*sizeof(double));
	double *T_2500_2_abiertas = malloc(tam*sizeof(double));

	double *prom_1_cerradas = malloc(n_t*sizeof(double));
	double *prom_1_periodicas = malloc(n_t*sizeof(double));
	double *prom_1_abiertas = malloc(n_t*sizeof(double));
	double *prom_2_cerradas = malloc(n_t*sizeof(double));
	double *prom_2_periodicas = malloc(n_t*sizeof(double));
	double *prom_2_abiertas = malloc(n_t*sizeof(double));
	
					 
	initial_condition(T_100_1_cerradas);
	initial_condition(T_2500_1_cerradas);
	initial_condition(T_100_2_cerradas);
	initial_condition(T_2500_2_cerradas);
	initial_condition(T_100_1_periodicas);
	initial_condition(T_2500_1_periodicas);
	initial_condition(T_100_2_periodicas);
	initial_condition(T_2500_2_periodicas);
	initial_condition(T_100_1_abiertas);
	initial_condition(T_2500_1_abiertas);
	initial_condition(T_100_2_abiertas);
	initial_condition(T_2500_2_abiertas);

	copy(T_2500_1_cerradas, T_0_1);
	copy(T_2500_2_cerradas, T_0_2);

	for(int t=0;t<n_t;t+=1){
	  solucionar(T_2500_1_cerradas, alpha, beta, 1, 1);
	  
	  solucionar(T_2500_1_periodicas, alpha, beta, 1, 2);
	  solucionar(T_2500_1_abiertas, alpha, beta, 1, 3);
	  solucionar(T_2500_2_cerradas, alpha, beta, 2, 1);
	  solucionar(T_2500_2_periodicas, alpha, beta, 2, 2);
	  solucionar(T_2500_2_abiertas, alpha, beta, 2, 3);

	  prom_1_cerradas[t]=promedio(T_2500_1_cerradas);
	  prom_1_periodicas[t]=promedio(T_2500_1_periodicas);
	  prom_1_abiertas[t]=promedio(T_2500_1_abiertas);
	  prom_2_cerradas[t]=promedio(T_2500_2_cerradas);
	  prom_2_periodicas[t]=promedio(T_2500_2_periodicas);
	  prom_2_abiertas[t]=promedio(T_2500_2_abiertas);

	  if(t==100)
	    {
	      copy(T_2500_1_cerradas, T_100_1_cerradas);
	      copy(T_2500_1_periodicas, T_100_1_periodicas);
	      copy(T_2500_1_abiertas, T_100_1_abiertas);
	      copy(T_2500_2_cerradas, T_100_2_cerradas);
	      copy(T_2500_2_periodicas, T_100_2_periodicas);
	      copy(T_2500_2_abiertas, T_100_2_abiertas);
	    }

	}
	FILE *out1 = fopen("0_1.txt","w+"); /* Abrir el archivo*/
	FILE *out2 = fopen("100_1_cerradas.txt","w+"); /* Abrir el archivo*/
	FILE *out3 = fopen("2500_1_cerradas.txt","w+"); //Abrir el archivo
	FILE *out4 = fopen("0_2.txt","w+"); /* Abrir el archivo*/
	FILE *out5 = fopen("100_2_cerradas.txt","w+"); /* Abrir el archivo*/
	FILE *out6 = fopen("2500_2_cerradas.txt","w+"); /* Abrir el archivo*/
	FILE *out8 = fopen("100_1_periodicas.txt","w+"); /* Abrir el archivo*/
	FILE *out9 = fopen("2500_1_periodicas.txt","w+"); /* Abrir el archivo*/
	FILE *out11 = fopen("100_2_periodicas.txt","w+"); /* Abrir el archivo*/
	FILE *out12 = fopen("2500_2_periodicas.txt","w+"); /* Abrir el archivo*/
	FILE *out14 = fopen("100_1_abiertas.txt","w+"); /* Abrir el archivo*/
	FILE *out15 = fopen("2500_1_abiertas.txt","w+"); /* Abrir el archivo*/
	FILE *out17 = fopen("100_2_abiertas.txt","w+"); /* Abrir el archivo*/
	FILE *out18 = fopen("2500_2_abiertas.txt","w+"); /* Abrir el archivo*/

	FILE *out19= fopen("promedios_caso1.txt","w+"); /* Abrir el archivo*/
	FILE *out20 = fopen("promedios_caso2.txt","w+"); /* Abrir el archivo*/
	
	print_T(T_0_1, out1 );
	print_T(T_100_1_cerradas, out2);
        print_T(T_2500_1_cerradas, out3);
        print_T(T_0_2, out4);
        print_T(T_100_2_cerradas, out5);
        print_T(T_2500_2_cerradas, out6);
        print_T(T_100_1_periodicas, out8);
	print_T(T_2500_1_periodicas, out9);
	print_T(T_100_2_periodicas, out11);
	print_T(T_2500_2_periodicas, out12);
	print_T(T_100_1_abiertas, out14);
        print_T(T_2500_1_abiertas, out15);
	print_T(T_100_2_abiertas, out17);
	print_T(T_2500_2_abiertas, out18);

	print_prom(prom_1_cerradas, prom_1_periodicas, prom_1_abiertas, out19);
	print_prom(prom_2_cerradas, prom_2_periodicas, prom_2_abiertas, out20);
        
	
	return 0;

}

void solucionar(double *T_present, double alpha, double beta, int caso, int condicion )
{
        
  double *T_past = malloc((n_x*n_y)*sizeof(double));
        copy(T_present, T_past);
	if(condicion==2)
	  {
	    for(int j=0; j<n_y; j++)
	    {
	      T_present[transformer(0,j)]=T_present[transformer(n_x-2,j)];
	      T_present[transformer(n_x-1,j)]=T_present[transformer(1,j)];
	    }
	    for(int i=0; i<n_x; i++)
	    {
	      T_present[transformer(i,0)]=T_present[transformer(i,n_y-2)];
	      T_present[transformer(i,n_y-1)]=T_present[transformer(i,1)];
	    }
	  }
	if(condicion==3)
	  {
	    for(int j=0; j<n_y; j++)
	      {
		T_present[transformer(0,j)]=T_present[transformer(1,j)];
		T_present[transformer(n_x-1,j)]=T_present[transformer(n_x-2,j)];
	      }
	    for(int i=0; i<n_x; i++)
	      {
		T_present[transformer(i,0)]=T_present[transformer(i,1)];
		T_present[transformer(i,n_y-1)]=T_present[transformer(i,n_y-2)];
	      }
	  }
	update_T(T_present, T_past, alpha, beta, caso);
}

int transformer(int i, int j)
{	
	
	return i*n_x + j;
}

void initial_condition(double *T){
	
	int i;
	int j;
	for(i=0;i<n_x;i++){
	  for(j=0; j<n_y; j++){
		if(i>=20 && i<40 && j >= 45 && j < 55){
		  T[transformer(i,j)]=100.0;}
		else{
		  T[transformer(i,j)]=50.0;}
	  }
	}
}

void copy(double *T_new, double *T_past){
	int i;
	int j;
	for(i=0;i<n_x;i++){
	  for(j=0;j<n_y;j++){
	    T_past[transformer(i,j)] = T_new[transformer(i,j)];
	  }
	}
}

void update_T(double *T_present, double *T_past, double alpha, double beta, int caso){
	int i;
	int j;
	for(i=1;i<n_x-1;i++){
	  for(j=1;j<n_y-1;j++){
	    T_present[transformer(i,j)] = nu*alpha*T_past[transformer(i+1,j)] + nu*beta*T_past[transformer(i,j+1)] + nu*alpha*T_past[transformer(i-1,j)] + nu*beta*T_past[transformer(i,j-1)] + (1.0 - 2.0*nu*alpha - 2.0*nu*beta)*T_past[transformer(i,j)];
	    if(caso==2)
	      {
		if(i>=20 && i<40 && j>=45 && j<55){
		  T_present[transformer(i,j)]=100.0;
		}
	    
	    
	      }
	    
	      
	  }
	}
}
					   

void print_T(double *T, FILE *archivo){
	int i;
	int j;
	for(i=0;i<n_x;i++){
	  for(j=0;j<n_y;j++){
	    fprintf(archivo,"%lf\n", T[transformer(i,j)]);
	  }
	}

	fclose(archivo);

}

					   
					   
void print_prom(double *prom1, double *prom2, double *prom3, FILE *archivo){
	int i;
	for(i=0;i<n_t;i++){
	  fprintf(archivo,"%lf %lf %lf \n", prom1[i], prom2[i], prom3[i]);
	}

	fclose(archivo);
}

double promedio(double *lista)
{
  double suma=0;
  for(int i=0; i<(n_x*n_y);i++)
    {
      suma+=lista[i];
    }

  double promedio = suma/(n_x*n_y);
    return promedio;
}

