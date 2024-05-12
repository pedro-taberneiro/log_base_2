/***************************************************************/
/**                                                           **/
/**   Nome:       Pedro Filipe Geraldo De Faria               **/
/**   Professor:  Flávio Soares                               **/
/**   Turma:      (01)                                        **/
/**   NumeroUSP:  14602394                                    **/
/**   Exercicio-Programa 02                                   **/
/**                                                           **/
/***************************************************************/
#include<stdio.h>
double media(int medida1, int medida2, double tudo){
    double x;
    x = (medida1 + medida2)/tudo;
    return x;
    }
double logador (double valor, double precisao){
    double fator = (valor-1) / (valor+1) ;
    int divisor = 1;
    double variavel = fator;
    double soma,resultado;
    double acumula = (valor-1)/(valor+1);
    double pedagio = precisao + 1;
    double check = (valor-1)/(valor+1);
    if(check<0){
        check=-check;
    }
    while (check>precisao){
        variavel *= fator*fator;
        check = variavel;
        if(check<0){
            check=-check;
        }
        divisor = divisor + 2;
        soma = variavel / divisor;  /* multiplicar a parte de numero com o z+1/z-1 */
        acumula = acumula + soma;
    }

    acumula = 2*acumula;
    resultado = acumula/0.693147180559945;

    return resultado;
}

double InformacaoMutua(int medida1,int medida2,int medida3,int medida4, double precisao){
    int espantalho;
    double tudo,x,n11n10,n01n00,n11n01,n10n00,n11,n10,n01,n00,eps,somatoria00,somatoria01,somatoria10,somatoria11,somador;
    espantalho = 0;
    tudo = medida1 + medida2 + medida3 +medida4;
    n11n10 = media(medida1,medida2,tudo); /* x=1 */
    n01n00 = media(medida3,medida4,tudo); /* x=0 */
    n11n01 = media(medida1,medida3,tudo); /* y=1 */
    n10n00 = media(medida2,medida4,tudo); /* y=0 */
    n11 = media(medida1,espantalho,tudo); /* x=1 y=1 */
    n10 = media(medida2,espantalho,tudo); /* x=1 y=0 */
    n01 = media(medida3,espantalho,tudo); /* x=0 y=1 */
    n00 = media(medida4,espantalho,tudo); /* x=0 y=0 */
    /* p(xy)/p(x)p(y)*/
    somatoria00 = logador(n00/(n01n00*n10n00), precisao); /* para x=0 y=0 */
    somatoria00 = somatoria00*n00;
    somatoria01 = logador(n01/(n01n00*n11n01),precisao); /* para x=0 y=1 */
    somatoria01 = somatoria01*n01;
    somatoria10 = logador(n10/(n11n10*n10n00),precisao); /* para x=1 y=0 */
    somatoria10 = somatoria10*n10;
    /*tudo certo*/
    somatoria11 = logador(n11/(n11n10*n11n01),precisao); /* para x=1 y=1 */
    somatoria11 = somatoria11*n11;
    somador = somatoria11 + somatoria10 + somatoria00 + somatoria01;
    return somador;
}
int main()
{
   int funcionalidade;
   double valor, precisao;

   printf("Selecione a funcionalidade f do programa (1 ou 2): ");
   scanf("%d", &funcionalidade);
   if(funcionalidade==1){
       double x;
       printf("Entre com x e eps: ");
       scanf("%lf %lf", &valor, &precisao);
       x = logador (valor,precisao);
       printf("O logaritmo de %g com precisao %g eh %g" , valor, precisao,x);

   }
   if(funcionalidade==2){
        int medida1,medida2,medida3,medida4;
        double precisao,n;
        printf("Entre com contadores N11, N10, N01, N00 e com eps: \n ");
        scanf("%d %d %d %d %lg", &medida1,&medida2,&medida3,&medida4,&precisao);
        n = InformacaoMutua(medida1,medida2,medida3,medida4,precisao);
        printf("A informacao mutua entre as duas variaveis aleatorias eh %g", n);
        return 0;
   }
}




