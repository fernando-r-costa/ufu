#include <stdio.h>
#include <math.h>

int main()
{
	int v[10]= {1,2,3,4,5,6,7,8,9,10};
	float qte = 0;
	int soma_media = 0;

	for(int i=0; i<10; i++) {
	    qte++;
		soma_media = soma_media + v[i];
	}

	float media = soma_media/qte;
	
	float somatorio = 0;
	
	for(int i=0; i<10; i++) {
	    float dif = pow((v[i]-media),2);
	    somatorio = somatorio + dif;
	}
	
	float dp = 0;
	
	dp =  sqrt(somatorio/qte);

	printf("A média é: %.2f / O desvio padrão é: %.4f", media, dp);

	return 0;
}