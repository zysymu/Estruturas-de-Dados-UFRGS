#include <stdio.h>

#define N 5

struct Person
{
    char name[100];
    float weight;
    float height;
};

float power(float x, int y);
float bmi_calc(struct Person person); // body mass index
float mean_bmi(float bmis[]);
void print_people_data(struct Person person[], float bmis[]);

int main()
{
    struct Person people[N];
    float bmis[N];
    float mean;

    for (int i = 0; i < N; i++)
    {
        printf("\nescreva dados da pessoa %d \n", i);
        printf("nome: ");
        scanf("%s", &people[i].name);

        printf("peso (kg): ");
        scanf("%f", &people[i].weight);

        printf("altura (m): ");
        scanf("%f", &people[i].height);

        bmis[i] = bmi_calc(people[i]);
    }

    print_people_data(people, bmis);

    mean = mean_bmi(bmis);
    printf("\n\nmedia dos IMCs: %f \n", mean);

    return 0;
}


float power(float x, int y)
/*
nao consegui importar funcao pow :(
como altura sempre eh positiva essa funcao ta ok 
*/
{
    if (y == 0) return 1;
    else return x * power(x, y-1);   
}


float bmi_calc(struct Person person)
{
    return person.weight/power(person.height,2);
}


void print_people_data(struct Person person[], float bmis[])
{
    for (int i = 0; i < N; i++)
    {
        printf("\n------------");
        printf("\n||PESSOA %d|| nome: %s | peso: %f kg| altura: %f m| IMC: %f", i, person[i].name, person[i].weight, person[i].height, bmis[i]);
        printf("\n------------");
    }
}


float mean_bmi(float bmis[])
{
    float total = 0;

    for (int i = 0; i < N; i++)
    {
        total += bmis[i];
    }

    return total/N;
}
