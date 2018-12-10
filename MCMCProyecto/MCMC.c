#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
	double PxIni,  Pxn=0, Pxn2=0, PxIni2, RANDM;
	int delta;
	int i,n=10,dif;
  float MIni, bIni,Mx, bx;

	FILE*R;
  //Solicitamos los datos a evaluar
	printf("Escribe la pendiente y la ordenada inicial\n");
	scanf("%f",&MIni);
	scanf("%f", &bIni);
  // Esete dato nos dará las veces que se repetirá el metodo para encontrar el resultado que mejor se acople
  printf("Número de evaluaciones del programa\n");
	scanf("%i", &dif);
	R=fopen("Respuesta","w");
		for(i=0;i<dif;i++){
//Numeros randoms para obtener las diferentes pendientes
			Mx=MIni-(.1)+(.2)*(rand()/(double)RAND_MAX);
			bx=bIni-(.1)+(.2)*(rand()/(double)RAND_MAX);
      //ejecutamos el método de likelihoods
  		PxIni=likelihood(MIni,bIni);
			Pxn=likelihood(Mx,bx);
  		Pxn2=likelihood(Mx,bx);
  //    Conocer si aplica o no el valor para acercarce al valor correcto
      if(PxIni<Pxn){
			     MIni=Mx;
			     bIni=bx;
			}else{
				RANDM= rand()/(double)RAND_MAX;
				if (RANDM<Pxn2){
				MIni=Mx;
				bIni=bx;
				}
			}
			fprintf(R,"%f %f \n", MIni, bIni);
	}
fclose(R);
  return 0;
}
