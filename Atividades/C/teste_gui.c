#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main (){

int sal,res,total,cont,op;
sal=1000;
cont=1;
while (cont == 1){
  printf("[1] Saldo\n");
  printf("[2] Saque\n");
  printf("[3] Depósito\n");
  printf("[4] Sair\n");
  scanf ("%d",&op);
 switch(op){ 
    case 1 :
      if (op ==1) {
       printf ("saldo: %d\n",sal);
                  } 
		break;
	case 2 :
      if (op ==2) {
       printf ("valor de saque: \n");
       scanf ("%d",&res);
       if (res <=0){
       printf("Digite apenas valores positivos\n");
                     }
       else{
           total=sal-res;
           if (total>=0){
         printf ("Saldo: %d\n",total);
         sal=total;
           }
           else{
               printf("Saldo Insuficiente\n");
           }
           }
                     }
        break;
    case 3 :
       if (op==3) {
          printf("valor do depósito: \n");
          scanf("%d",&res);
          if (res<0){
              printf("Apenas valores positivos\n");
          }
          else {
          total=sal+res;
          sal=total;
          printf("Saldo: %d\n",total);
             }
       }
       break;
       case 4 :
       if(op==4) exit (0);
       
 	default :
 	   printf("Opção inválida\n");
 }
  

}
    
}