#include "stdio.h"

/*
- Qualquer ano igualmente divisivel por 4, é ano bissexto.
- Qualquer ano que seja igualmente divisivel por 100 (ex: 1900), é um ano bissexto SOMENTE se ele tambem for divisivel por 400.  Ex: 1600, 2000 e 2400.
*/

// Verifica se é ano bissexto
bool isLeapYear(int year)
{
  if (year % 4 == 0 && (year % 400 == 0 || year % 100 != 0)) 
    return true;  
  else 
    return false;
}

// Calcula os dias do mês
int calculateDaysOfMonth(int year, int month)
{
  int retDays=0;

  // mes invalido
  if((month < 1) && (month > 12))
    return 0;

  switch (month)
  {
    case 4:
    case 6:
    case 9:
    case 11:
        retDays = 30;
      break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        retDays = 31;
      break;
    case 2:
        if(isLeapYear(year))
          retDays = 29;
        else
          retDays = 28;
      break;
  }
  return retDays;
}


int main()
{
  int year,month;
  int calcDays;
 
  while(true)
  {
    // A função printf() escreve na tela.
    printf("Digite o ano: ");
    // A função scanf obtém o valor digitado.
    scanf("%d", &year);

    printf("Digite o mes: ");
    scanf("%d", &month);

    calcDays = calculateDaysOfMonth(year,month);

    if(isLeapYear(year))
      printf("Este ano e' bissexto e o mes tem %d dias.\n",calcDays);
    else
      printf("Este ano NAO e' bissexto e o mes tem %d dias.\n",calcDays);
  }
  return 0;
}


