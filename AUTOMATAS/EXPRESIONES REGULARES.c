#include <stdio.h>
// Verificar si la cadena cumple con la expresión regular (0+1)*1(1+0)*
int main() 
{
    char cadena[100];


	//entrada
	
    printf("Ingrese una cadena :): ");
    scanf("%s", cadena);
	/*inicioamos con cumple igual a 1 para verificar si la cadena cumple con la condición y
	  el sihay=0 para verificar si se encontró al menos un '1'
	*/
    int i=0,cumple=1,sihay=0; 
	
   do 
   {
    if (cadena[i]=='0' || cadena[i]=='1') 
	{
        if (cadena[i]=='1') // Si el carácter de la cadena es '1' marcar que se encontró al menos un '1'
		{
            sihay=1;//si se marca el uno, ya no entrara en los demas if
        }
    } 
	else 
	{
        cumple=0; // No es ni '0' ni '1'
        break;
    }
    i++;
	} while (cadena[i]!='\0'); //hasta que encuentre el termino nulo


    if (!sihay || cadena[i]!='\0') 
	{
        cumple=0; // "Si no se encontró al menos un '1'  
    }

    // salida
    if (cumple) //cerifica si hubo al menos un 1, ya que depende si la variable cumple se modifico o no, esto dpende de la primera condicional.  
	{
        printf("La cadena cumple con la condicion.\n");
    } 
	else 
	{
        printf("La cadena NO cumple con la condicion.\n");
    }

    return 0;
}

