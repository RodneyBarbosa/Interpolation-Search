#include <stdio.h>


//Função para realizar pesquisa de interpolação
int interpolationSearch ( int A[] , int n, int e)
{
int inicio, fim , pos;
inicio = 0;
fim = n-1;

while( inicio<=fim && e>=A[inicio] && e<=A[fim])
{

 pos = inicio + (((double)(fim-inicio)/(A[fim]-A[inicio]))*(e-A[inicio]));

 if (A[pos] == e)
  return pos;
 if (e > A[pos])
  inicio = pos + 1;
 else
  fim = pos-1;
 }
return -1;

}

int main()
{
 int n,i,j,x,e, aux;
 printf("======== Descreva a quantidade de elementos da Lista ========\n");
 scanf("%d", &n);
 int A[n];
 printf("Adicione os elementos\n");
 for(i=0;i<n;i++){
 scanf("%d", &A[i]);
 }
 
 printf("Lista ordenada crescentemente:\n");
 for(j=0; j<n; j++){
 	for( x=j+1; x<n; x++){
 		if (A[j] > A[x]){
 			aux = A[j];
 			A[j] = A[x];
 			A[x] = aux;
		 }
	 }
	 
	 printf("%d\t", A[j]);
 }

 printf("\nDigite o elemento a ser procurado\n");
 scanf("%d", &e);

 //Chamada da função "Busca interpolada"
 int indice = interpolationSearch(A, n, e);
 if(indice != -1)
 printf("Elemento encontrado na  posicao %d da Lista", indice);
 else
 printf("Elemento inexistente!");

 return 0;
}
