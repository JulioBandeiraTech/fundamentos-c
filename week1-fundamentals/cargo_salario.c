#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    float salario,aumento;
    int codCargo;
    
    printf("Digite seu salario:");
    scanf("%f",&salario);
    printf("Digite o codigo do seu cargo:");
    scanf("%d",&codCargo);
    
    if (codCargo == 1 ){
      printf("\nSeu cargo e de servicos gerais");
      aumento = salario*(50.0/100);
      salario= salario+aumento; 
      printf("\nSeu aumento foi de:%.2f",aumento);
      printf("\nSeu novo salario e de:%.2f",salario);
    } else if (codCargo == 2 ) {
       printf("\nSeu cargo e de vigia");
      aumento = salario*(30.0/100);
      salario= salario+aumento; 
      printf("\nSeu aumento foi de:%.2f",aumento);
      printf("\nSeu novo salario e de:%.2f",salario);    
    } else if (codCargo == 3 ) {
      printf("\nSeu cargo e de recpcionista");
      aumento = salario*(25.0/100);
      salario= salario+aumento; 
      printf("\nSeu aumento foi de:%.2f",aumento);
      printf("\nSeu novo salario e de:%.2f",salario);     
    } else if (codCargo == 4 ) {
      printf("\nSeu cargo e de vendedor");
      aumento = salario*(15.0/100);
      salario= salario+aumento; 
      printf("\nSeu aumento foi de:%.2f",aumento);
      printf("\nSeu novo salario e de:%.2f",salario);     
    }
    
  
  system("PAUSE");	
  return 0;
}
