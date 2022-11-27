#include <stdio.h>

main(){
	long int sum,a,i,j,b=9;
	printf("User Input : ");
	scanf("%d",&a);
	printf("Series = ");
	for(i=0;i<a;i++){
		sum += b;
		printf("%d+",b);
		b=b*10+9;
	}
	printf("\nSum = %d",sum);
}
