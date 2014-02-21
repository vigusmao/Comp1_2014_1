int main()
{
    printf("\nQual a velocidade inicial (Km/h)? ");
    float v0;
    scanf("%f", &v0);
    v0 = v0 / 3.6;

    printf("\nQual a aceleracao? ");
    float a;
    scanf("%f", &a);

    float t;
    t = (-1)*v0/a;

    printf("O carro leva %f segundos para parar.", t);

    return 0;
}

