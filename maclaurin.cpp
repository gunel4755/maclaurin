#include <stdio.h>
#include <stdlib.h>
/*
Maclaurin Açýlýmý = 1 + x + (x^2)/2! + (x^3)/3! + (x^4)/4! + ..... + (x^n)/n!
5, 6 ve 7. Sorularda
	x=1.01 ve
	n=10
*/
int usAlRecursive(int taban,int us){
	
	if(us == 0 || taban==1){
		return 1;
	}
	else
		return taban* usAlRecursive(taban,us -1);
}


int faktoriyelRec(int sayi){
	
	if(sayi== 0 )
		return 0;
	else{
		if(sayi==1)
			return 1;
		
		return sayi * faktoriyelRec(sayi-1);	
	}
}

float calcMac(float x, int n){
	//1 + x + (x^2)/2! + (x^3)/3! + (x^4)/4! + ..... + (x^n)/n!
	float result=0;
	result=x+1;
	for(int i=n; i > 1 ; i--){
		result += usAlRecursive(x,i) / faktoriyelRec(i);
	}
	return result;
}
float calcMacRec(float x, int n){
	//1 + x + (x^2)/2! + (x^3)/3! + (x^4)/4! + ..... + (x^n)/n!
	float result=0;
	if(n > 1)
	{
		result += usAlRecursive(x,n) / faktoriyelRec(n);
		return calcMacRec(x,n-1);
	}
	else
		return result+x+1;
}

main(){
		
	float x=1.01;
	int n=1;
	printf("\n\n*******x=1.01, n=10 calcMac sonucu*******\n%f\n", calcMac(x,n));
	printf("\n\n*******x=1.01, n=10 calcMacRec sonucu*******\n%f\n", calcMac(x,n));
}
