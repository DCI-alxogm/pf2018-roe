#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float likelihood(float MIni,float bIni){
	int i,j,n=10;
	FILE*DT;
	float r[10], r2, suma=0;
	float *xAb, *yAb, *sigM, *sigb;
//Manejo dinámico de la memoria
	yAb=(float*)malloc(10*sizeof(float));
	xAb=(float*)malloc(10*sizeof(float));
	sigM=(float*)malloc(10*sizeof(float));
	sigb=(float*)malloc(10*sizeof(float));
//obtención de los datos de la investigación
	DT = fopen("datos","r");
		for (i=0;i<n;i++){
			fscanf(DT,"%f", &xAb[i]);
			fscanf(DT,"%f", &yAb[i]);
			fscanf(DT,"%f", &sigM[i]);
			fscanf(DT,"%f", &sigb[i]);
		}

	fclose(DT);
	for (i=0;i<10;i++){
		//Logaritmo natural de la probabilidad
		r[i]= yAb[i]-(xAb[i]*(MIni)+bIni);
		r[i]= pow(r[i],2)-(sigM[i]*sigM[i]);
		suma+=r[i];
	}
	suma*=-0.5;
	r2= pow(2.718282,suma);
	return r2;
}
