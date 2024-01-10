#include <stdio.h>
float convert_to_celsius(float fahr);

int main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;

    printf("Celsius:\tFahrenheit:\n");
    while (fahr <= upper) {
   	 celsius = convert_to_celsius(fahr);
   	 printf("%6.1f \t\t%3.0f\n",celsius, fahr);
   	 fahr = fahr + step;
    }
    return 0;
}

float convert_to_celsius(float fahr){
   	 return ((5.0/9.0) * (fahr-32.0));
}
