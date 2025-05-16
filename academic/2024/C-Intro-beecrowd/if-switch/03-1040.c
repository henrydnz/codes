//https://judge.beecrowd.com/pt/problems/view/1040

#include <stdio.h>

int main() {
    // vars notas e media
    float n1, n2, n3, n4, md;
    scanf("%f%f%f%f", &n1, &n2, &n3, &n4);
    // calcula media
    md = ((2*n1)+(3*n2)+(4*n3)+n4)/10;
    printf("Media: %.1f\n", md);
    // computa aprovacao com media
    if (md >= 7.0) 
        printf("Aluno aprovado.\n");
    else if (md < 5.0) 
        printf("Aluno reprovado.\n");
    else {
        // vars nota exame e media exame
        float exame, md2;
        scanf("%f", &exame);
        printf("Aluno em exame.\nNota do exame: %.1f", exame);
        // calcula nova media
        md2 = (md + exame) / 2;
        // computa aprovacao com nova media
        if (md2 >= 5.0) 
            printf("Aluno aprovado.\n");
        else 
            printf("Aluno reprovado.\n");
        // mostra nota final
        printf("Media final: %.1f\n", md2);
    }
    return 0;
}


