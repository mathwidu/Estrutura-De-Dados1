#include <stdio.h>
#include <locale.h>

int main (void){
    setlocale(LC_ALL, "portuguese");

    float peso, altura;

    printf("Digite seu peso em quilos: ");
    scanf("%f", &peso);

    printf("Digite sua altura em metros: ");
    scanf("%f", &altura);

    float pesog, alturacm;

    pesog = peso * 100;
    alturacm = altura * 100;

    printf("Seu peso em gramas é: %.2fg\n", pesog);
    printf("Sua altura em centímetros é: %.2fcm ", alturacm);

    return 0;
}
