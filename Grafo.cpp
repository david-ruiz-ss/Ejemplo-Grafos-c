#include <iostream>
	#include <stdio.h>
		#include <conio.h>
	#include <stdlib.h>
#include <malloc.h>

using namespace std;

#define Max 20
	#define PR(x) printf ("%s",x)
		#define salto printf ("\n")
		
int nv,i,k,j;

	main(void){
	int M[Max][Max],a[Max][Max],R[Max][Max];
	int S[Max][Max];
	int nv,i;
	void producto (int a[][Max],int b[][Max],int c[][Max],int m);
	void listar_g (int g[][Max], int nv);
	void sumar (int S[][Max],int R[][Max],int nv);
	int lea_grafo (int grafo[][Max]);
   void copiar (int a[][Max], int b[][Max],int nv);
	nv = lea_grafo (M);
	listar_g (M ,nv);
	getch();
	copiar (a,M,nv);
	copiar (S,M,nv);
	for (i=1; i<nv; i++) {
		producto (a,M,R,nv);
		sumar (S,R,nv);
		listar_g (R,nv);
		salto;getch();
		copiar (a,R,nv);
	}
	listar_g (R,nv);
	salto;
	listar_g (S,nv);
	getch();
}

void sumar (int S[][Max],int R[][Max],int nv) {
	int i,j;

	for (i=1;i<=nv;i++)
		for (j=1; j<=nv;j++)
			S[i][j] += R[i][j];
}

int  lea_grafo (int grafo[][Max])
{
	int v,ad,i,j,n;
	int lea();
	PR("De numero de vertices...");
	salto;
	n = lea();
	for (i=1; i <= n; i++)
		for (j=1; j <=n; j++)
			grafo[i][j] = 0;
	PR ("Lea el primer vertice. 22 para terminar...");
	salto;
	v = lea();
	while (v != 22) {
		PR ("Lea el primer adjunto al vertice ");
		printf ("%d ",v);
		PR(". 22 para terminar");
		salto;
		ad = lea();
		while (ad != 22) {
			grafo [v][ad] = 1;
			PR ("Lea otro adjunto al vertice ");
			printf ("%d ",v);
			PR(". 22 para terminar");
			salto;
			ad = lea();
		}
		PR ("Lea otro vertice. 22 para terminar...");
		salto;
		v = lea();
	}
	return (n);
}

int lea() {
	char L[10];

	gets (L);
	return (atoi (L));
}


void listar_g (int g[][Max], int nv) {
	int i,j;

	for (i=1; i <= nv; i++) {
		for (j = 1; j <= nv; j++)
			printf ("%d ",g[i][j]);
		salto;
	}
}

void producto (int a[][Max],int b[][Max],int c[][Max],int m) {
	register int i;
	register int j;
	register int k;

	for (i=1; i<=m; i++)
		for (k=1; k<=m; k++) {
			c[i][k] = 0;
			for (j=1; j<=m; j++)
				c[i][k] += a[i][j] * b[j][k];
		}
}

void copiar (int a[][Max], int b[][Max],int nv) {
	int i,j;

	for (i=1; i<=nv; i++)
		for (j=1; j <= nv; j++)
			a[i][j] = b[i][j];
}
