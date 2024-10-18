/*maquina simple que duplica una cadena*/
//declarar 32-bit release para que puea fucionar
//tener intalada la libreria winbgim
//en opciones de compilador poner esto: -static-libgcc -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdio.h>
#include<time.h>
#include <string>
#include <winbgim.h>

#define num 100
#define caracter #
enum Estados {
    q0,
    q1,
    q2,
    q3,
    q4,
    q5
};
void margen_total();
void gotoxy(int x, int y);
void cuadrito_a();
void pantalla_uno();
void cuadrito();
void pantalla_dos();
int pantalla_tres(char cadena1[],char cadenaf[]);
void mostrarDiagrama();
void drawArrow(int x1, int y1, int x2, int y2, int size);
void drawState(int x, int y, const std::string& stateName, bool drawArc = false);
void imprime(int c, int f);
void printTape(char *tape, int head);


main()
{
	char cadena1[num];
	char cadenaf[num];
	time_t tiempo_actual;
	time(&tiempo_actual);
	struct tm *info_tiempo=localtime(&tiempo_actual);
	
	gotoxy(52,16);system("pause");
	system("cls");
	gotoxy(95,3);printf(" %02d/%02d/%02d ",info_tiempo->tm_mday,info_tiempo->tm_mon+1,info_tiempo->tm_year+1900);
	pantalla_uno();
	pantalla_dos();
	pantalla_tres(cadena1,cadenaf);
	return 0;
}

void pantalla_uno()
{
	margen_total();
	cuadrito();
	gotoxy(55,4);printf("MAQUINA DE TURING DE UNA SOLA CINTA");
	gotoxy(105,33);system("pause");
}

void pantalla_dos()
{
	int opc;
	system("cls");
	margen_total();
	gotoxy(45,4);printf("M A Q U I N A  D E  T U R I N G  D E  U N A  S O L A  C I N T A");

	gotoxy(56,8);printf("********** Definicion Formal **********");
	gotoxy(3,10);printf("Q= {q0,q1,q2,q3,q4,q5}");
	gotoxy(3,11);printf("Alfabeto= {0,1}");
	gotoxy(3,12);printf("Alfabeto de la Cinta= {0,1,A,B,X,Y,#}");
	gotoxy(3,13);printf("S= {q0}");
	gotoxy(3,14);printf("F= {q5}");
	gotoxy(3,15);printf("Funcion de transicion: ");
	
	gotoxy(3,17);printf("(q0,0)=(q1,X,R)");
	gotoxy(3,18);printf("(q0,1)=(q2,Y,R)");
	gotoxy(3,19);printf("(q0,B)=(q4,1,R)");
	gotoxy(3,20);printf("(q0,A)=(q4,0,R)");

	gotoxy(3,22);printf("(q1,0)=(q1,0,R)");
	gotoxy(3,23);printf("(q1,1)=(q1,1,R)");
	gotoxy(3,24);printf("(q1,A)=(q1,A,R)");
	gotoxy(3,25);printf("(q1,B)=(q1,B,R)");
	gotoxy(3,26);printf("(q1,#)=(q3,A,L)");
	
	gotoxy(3,28);printf("(q2,A)=(q2,A,R)");
	gotoxy(3,29);printf("(q2,B)=(q2,B,R)");
	gotoxy(3,30);printf("(q2,0)=(q2,0,R)");
	gotoxy(3,31);printf("(q2,1)=(q2,1,R)");
	gotoxy(3,32);printf("(q2,#)=(q3,B,L)");
	
	gotoxy(25,17);printf("(q3,A)=(q3,A,L)");
	gotoxy(25,18);printf("(q3,B)=(q3,B,L)");
	gotoxy(25,19);printf("(q3,0)=(q3,0,L)");
	gotoxy(25,20);printf("(q3,1)=(q3,1,L)");
	gotoxy(25,21);printf("(q3,X)=(q0,0,R)");
	gotoxy(25,22);printf("(q3,Y)=(q3,A,L)");

	gotoxy(25,24);printf("(q4,B)=(q4,1,R)");
	gotoxy(25,25);printf("(q4,A)=(q4,0,R)");
	gotoxy(25,26);printf("(q4,1)=(q4,1,R)");
	gotoxy(25,27);printf("(q4,0)=(q4,0,R)");
	gotoxy(25,28);printf("(q4,#)=(q5,#,L)");
	
	
	
	gotoxy(56,15);printf("VER EL DIAGRAMA DE TRANSISION");
	gotoxy(56,16);printf("[SI]...................[1]");
	gotoxy(56,17);printf("[NO]...................[2]");
	gotoxy(56,18);printf("INGRESE SU ELECCION: ");scanf("%d",&opc);

	if(opc==1)
	{
		mostrarDiagrama();
	}

	gotoxy(105,33);system("pause");
}

int pantalla_tres(char cadena1[],char cadenaf[])
{
	int h,i,j,opc;
	int esBinaria=1;
	int cabezal=0;
	
	enum Estados estadoactual = q0;
	system("cls");
	margen_total();
	gotoxy(45,4);printf("M A Q U I N A  D E  T U R I N G  D E  U N A  S O L A  C I N T A");
	
	cuadrito_a();
	imprime(35,10);
	
	for(h=0;h<21;h++)
	{
		gotoxy(36+(h*4),11);printf(" #");
	}
	gotoxy(21,7);printf("INGRESE CADENA: ");scanf("%s",cadena1);

	
    	for(j=0;j<cadena1[j] != '\0';j++)
    	{
    		fflush(stdin);
    		gotoxy(48+(j*4),11);printf(" %c",cadena1[j]);
		}
		while(estadoactual!=5)
		{
			switch(estadoactual)
			{
				case q0:
    				switch(cadena1[cabezal])
    				{
    					case '0':
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						cadena1[cabezal]='X';
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    						
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						cabezal++;
    						estadoactual=q1;
    						
    						break;
    					case '1':
    						cadena1[cabezal]='Y';
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    						
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						estadoactual=q2;
    						
    						cabezal++;
    						break;
    					case 'B':
    						cadena1[cabezal]='1';
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    						
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						estadoactual=q4;
    						cabezal++;
    						break;
    					case 'A':
    						cadena1[cabezal]='0';
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    						
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						estadoactual=q4;
    						cabezal++;
    						break;
    					default:
						gotoxy(40,16);printf("cadena no valida");
						gotoxy(105,33);system("pause");
						pantalla_tres(cadena1,cadenaf);
					}
    				break;
				case q1:
					switch(cadena1[cabezal])
    				{
    					case '0':
    						
    						cadena1[cabezal]='0';
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    						
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						cabezal++;
    						estadoactual=q1;    						
    						break;
    					case '1':
    						cadena1[cabezal]='1';
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    						
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						estadoactual=q1;
    						cabezal++;
    						break;
    					case 'B':
    						cadena1[cabezal]='B';
    						gotoxy(48+(cabezal*4),13);printf("   ");
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    						
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						estadoactual=q1;
    						cabezal++;
    						break;
    					case 'A':
    						cadena1[cabezal]='A';
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    						
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						estadoactual=q1;
    						cabezal++;
    						break;
						case '\0':
							cadena1[cabezal]='A';
							cadena1[cabezal+1]='\0';
							gotoxy(48+(cabezal*4),13);printf("  ");
							gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    					
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
							estadoactual=q3;
							cabezal--;
							break;
						default:
						gotoxy(40,16);printf("cadena no valida");
						gotoxy(105,33);system("pause");
						pantalla_tres(cadena1,cadenaf);
							
					}
    				break;
    			case q2:
    				switch(cadena1[cabezal])
    				{
    					case '0':
    						cadena1[cabezal]='0';
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    						
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						estadoactual=q2;
    						cabezal++;
    						break;
    					case '1':
    						cadena1[cabezal]='1';
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    						
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						estadoactual=q2;
    						cabezal++;
    						break;
    					case 'B':
    						cadena1[cabezal]='B';
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    						
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						estadoactual=q2;
    						cabezal++;
    						break;
    					case 'A':
    						cadena1[cabezal]='A';
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    						
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						estadoactual=q2;
    						cabezal++;
    						break;
						case '\0':
							cadena1[cabezal] = 'B';
							cadena1[cabezal+1]='\0';
							      // Asigna 'B' al carácter en la posición del cabezal
							gotoxy(48+(cabezal*4),13);printf("  ");
							gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    						
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
							estadoactual=q3;
							cabezal--;
							break;
			
						default:
						gotoxy(40,16);printf("cadena no valida");
						gotoxy(105,33);system("pause");
						pantalla_tres(cadena1,cadenaf);
							
					}
					break;
				case q3:
					switch(cadena1[cabezal])
    				{
    					case '0':
    						cadena1[cabezal]='0';
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    						
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						estadoactual=q3;
    						cabezal=cabezal-1;
    						break;
    					case '1':
    						cadena1[cabezal]='1';
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    						
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						estadoactual=q3;
    						cabezal--;
    						break;
    					case 'B':
    						cadena1[cabezal]='B';
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    						
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						estadoactual=q3;
    						cabezal--;
    						break;
    					case 'A':
    						cadena1[cabezal]='A';
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    						
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						estadoactual=q3;
    						cabezal--;
    						break;
						case 'X':
							cadena1[cabezal]='0';
							gotoxy(48+(cabezal*4),13);printf("  ");
							gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    					
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
							estadoactual=q0;
							cabezal++;
							break;	
						case 'Y':
							cadena1[cabezal]='1';
							gotoxy(48+(cabezal*4),13);printf("  ");
							gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    						
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
							estadoactual=q0;
							cabezal++;
							break;
							default:
						gotoxy(40,16);printf("cadean no valida");
						gotoxy(105,33);system("pause");
						pantalla_tres(cadena1,cadenaf);
						break;
							
					}
					break;
				case q4:
					switch(cadena1[cabezal])
    				{
    					case '0':
    						cadena1[cabezal]='0';
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    					
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						estadoactual=q4;
    						cabezal++;
    						break;
    					case '1':
    						cadena1[cabezal]='1';
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("   ");
    						estadoactual=q4;
    						cabezal++;
    						break;
    					case 'B':
    						cadena1[cabezal]='1';
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    	
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						estadoactual=q4;
    						cabezal++;
    						break;
    					case 'A':
    						cadena1[cabezal]='0';
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
    						gotoxy(48+(cabezal*4),13);printf(" ^");
    						gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
    					
    						Sleep(1000);
    						gotoxy(48+(cabezal*4),14);printf("    ");
    						gotoxy(48+(cabezal*4),13);printf("  ");
    						estadoactual=q4;
    						cabezal++;
    						break;
						case '\0':
							gotoxy(48+(cabezal*4),13);printf("  ");
							gotoxy(48+(cabezal*4),14);printf("  ");
							
							cadena1[cabezal]='#';
							cadena1[cabezal+1]='\0';
							
    						gotoxy(48+(cabezal*4),11);printf(" %c",cadena1[cabezal]);
							estadoactual=q5;
							cabezal--;
							gotoxy(48+(cabezal*4),13);printf(" ^");
							gotoxy(48+(cabezal*4),14);printf(" q%d",estadoactual);
							
							Sleep(2001);
							break;
							default:
							gotoxy(40,16);printf("cadena no valida");
							break;
							
					}
					break;
						default:
						gotoxy(40,16);printf("cadena no valida");
						gotoxy(105,33);system("pause");
						pantalla_tres(cadena1,cadenaf);
			}
		
		}
		
		if(estadoactual==q5)
		{
			gotoxy(40,16);printf("Cadena valida");
			gotoxy(105,33);system("pause");
		}
		
		
		
		gotoxy(9,25);printf("QUIERE INGRESAR OTRA CADENA?");
		gotoxy(9,26);printf("[Si]..............[1]");
		gotoxy(9,27);printf("[No]..............[2]");
		gotoxy(9,28);printf("Ver informacion...[3]");
		gotoxy(9,29);printf("ingrese opcion: ");scanf("%d",&opc);
		
		switch(opc)
		{
			case 1:
				pantalla_tres(cadena1,cadenaf);
			break;
			case 3:
				pantalla_dos();
				break;
			case 2:
				return 1;
				break;
		}
	

    gotoxy(105,33);system("pause");
}













void imprime(int c, int f)
{
	int i;
	int n=21;
	gotoxy(c,f);
	printf("%c",218);
	gotoxy(c,f+1);
	printf("%c",179);
	gotoxy(c,f+2);
	printf("%c",192);
	
	for(i=0;i<n-1;i++)
	{
		gotoxy(c+(i*4)+1,f);
		printf("%c%c%c%c",196,196,196,194);
		gotoxy(c+(i*4)+1,f+1);
		printf("   %c",179);
		gotoxy(c+(i*4)+1,f+2);
		printf("%c%c%c%c",196,196,196,193);
	}
	gotoxy(c+(i*4)+1,f);
	printf("%c%c%c%c",196,196,196,191);
	gotoxy(c+(i*4)+1,f+1);
	printf("   %c",179);
	gotoxy(c+(i*4)+1,f+2);
	printf("%c%c%c%c",196,196,196,217);
}



















void drawArrow(int x1, int y1, int x2, int y2, int size) {
    // Dibujar la línea
    line(x1, y1, x2, y2);

    // Calcular la posición de la punta de la flecha
    float angle = atan2(y2 - y1, x2 - x1);
    int arrowX = x2 - size * cos(angle);
    int arrowY = y2 - size * sin(angle);

    // Ángulo más pequeño para hacer las flechas más cerradas
    float smallAngle = 0.7;

    // Dibujar la parte superior de la flecha
    line(x2, y2, arrowX + size * cos(angle + smallAngle), arrowY + size * sin(angle + smallAngle));

    // Dibujar la parte inferior de la flecha
    line(x2, y2, arrowX + size * cos(angle - smallAngle), arrowY + size * sin(angle - smallAngle));

}
void drawState(int x, int y, const std::string& stateName, bool drawArc){
    // Dibujar el círculo del estado
    circle(x, y, 30);

    // Dibujar el nombre del estado dentro del círculo
    char* mutableLabel = const_cast<char*>(stateName.c_str());
    outtextxy(x - textwidth(mutableLabel) / 2, y - textheight(mutableLabel) / 2, mutableLabel);

    // Dibujar arco en lugar de línea recta si drawArc es true
    if (drawArc) {
        int radius = 15;
        int startAngle = -10;      // Ángulo inicial del arco
        int endAngle = 240;      // Ángulo final del arco
        arc(x, y - 40, startAngle, endAngle, radius);

        // Calcular la posición de inicio de la flecha en el lado derecho del arco
        float angleStart = startAngle;  // Utilizamos el ángulo inicial del arco como punto de inicio de la flecha
        int arrowStartX = x + radius * cos(angleStart);
        int arrowStartY = y - 40 + radius * sin(angleStart);

        // Calcular la posición de la punta de la flecha en el lado derecho del arco
        float angleEnd = (startAngle + endAngle) / 2;
        int arrowEndX = x + radius * cos(angleEnd);
        int arrowEndY = y - 40 + radius * sin(angleEnd);

        // Dibujar la flecha desde la posición de inicio hasta la posición final del arco
        drawArrow(arrowStartX+28, arrowStartY-7, arrowEndX+20, arrowEndY-2, 5);
    	
        
    }
  
}
void mostrarDiagrama(){
	
	int ventanaAncho = 1366;
	int ventanaAlto = 768;
    initwindow(ventanaAncho, ventanaAlto);  // Inicializar la ventana

    // Coordenadas de los nodos
    int q0_x = 450, q0_y = 550;
    int q1_x = 450, q1_y = 150;
    int q2_x = 700, q2_y = 280;
    int q3_x = 1150, q3_y = 150;
    int q4_x = 830, q4_y = 598;
    int q5_x = 1150, q5_y = 555;

    // Dibujar nodos con nombres y posibilidad de arco
    drawState(q0_x, q0_y, "q0",false);
    drawState(q1_x, q1_y, "q1", true);
    drawState(q2_x, q2_y, "q2", true);
    drawState(q3_x, q3_y, "q3", true);
    drawState(q4_x, q4_y, "q4", true);
    drawState(q5_x, q5_y, "q5",false);

    // Dibujar aristas con flechas y texto de transición
    drawArrow(q0_x, q0_y - 30, q1_x, q1_y + 32, 10);  // Arista entre q0 y q1 (hacia arriba) con etiqueta "a"
    drawArrow(q1_x + 30, q1_y, q3_x - 32, q3_y, 10);  // q1 y q3 con etiqueta "b"
    drawArrow(q3_x - 13, q3_y + 27, q0_x + 32, q0_y - 15, 10);  // q3 y q0 con etiqueta "c"
    drawArrow(q2_x + 30, q2_y, q3_x - 27, q3_y + 15, 10);  // q2 y q3 con etiqueta "d"
    drawArrow(q0_x + 15, q0_y - 25, q2_x - 20, q2_y + 25, 10);  // Arista entre q0 y q2 con etiqueta "e"
    drawArrow(q0_x + 30, q0_y, q4_x - 32, q4_y, 10);  // Arista entre q0 y q4 con etiqueta "f"
    drawArrow(q4_x + 30, q4_y, q5_x - 32, q5_y, 10);  // Arista entre q4 y q5 con etiqueta "g"
    circle(q5_x, q5_y, 27);

    drawArrow(390, 550, q0_x - 32, q0_y, 10);  // Ejemplo adicional con etiqueta "h"
	outtextxy(400, 350, "0;X,R");
   	
   	outtextxy(435,20,"0;0,R");
   	outtextxy(435,35,"1;1,R");
	outtextxy(435,50,"A;A,R");
	outtextxy(435,65,"B;B,R");
	
	outtextxy(800,130,"#;A,L");
	
	outtextxy(1145,20,"A;A,L");
	outtextxy(1145,35,"B;B,L");
	outtextxy(1145,50,"0;0,L");
	outtextxy(1145,65,"1;1,L");

	outtextxy(800,360,"X;0,R");
	outtextxy(800,375,"Y;1,R");

	outtextxy(850,215,"#;B,L");
	
	outtextxy(680,165,"A;A,R");
	outtextxy(680,180,"B;B,R");
	outtextxy(680,195,"0;0,R");
	outtextxy(680,210,"1;1,R");
	
	outtextxy(550, 374, "1;Y,R");
	
	outtextxy(600, 575, "A;0,R");
	outtextxy(600, 590, "B;1,R");
	
	outtextxy(815,475,"A;A,R");
	outtextxy(815,490,"B;B,R");
	outtextxy(815,505,"0;0,R");
	outtextxy(815,520,"1;1,R");
	
	outtextxy(1005,550,"#;#,L");
    getch();
    closegraph(); // Cerrar la ventana
}
void cuadrito_a(){
	int x=20,y=6,k;
	
	gotoxy(x,y);printf("%c",218);
	for(k=0;k<50;k++)
	{
		gotoxy(x+k+1,y);printf("%c",196);
		gotoxy(x+k+1,y+2);printf("%c",196);
	}
	gotoxy(x,y+1);printf("%c",179);
	gotoxy(x+k,y+1);printf("%c",179);
	
	gotoxy(x+k,y);printf("%c",191);
	gotoxy(x,y+2);printf("%c",192);
	gotoxy(x+k,y+2);printf("%c",217);
}
void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
void margen_total() {
    int ancho = 148;
    int alto = 34;
    int i, j;

    // Imprimir la parte superior del margen
    for (i = 0; i < ancho; i++) {
        gotoxy(i, 0);
        printf("%c", 219);
    }

    // Imprimir los lados del margen
    for (j = 0; j < alto; j++) {
        gotoxy(0, j);
        printf("%c", 219);

        gotoxy(ancho - 1, j);
        printf("%c", 219);
    }

    // Imprimir la parte inferior del margen
    for (i = 0; i < ancho; i++) {
        gotoxy(i, alto);
        printf("%c", 219);
    }
}
void cuadrito(){
	int x=53,y=3,m;
	/*Esquina superior derecha*/
	gotoxy(x,y);printf("%c",218);
	
	for(m=0;m<37;m++)
	{
		gotoxy(x+1+m,y);printf("%c",196);
		gotoxy(x+1+m,y+2);printf("%c",196);
	}
	gotoxy(x,y+1);printf("%c",179);
	gotoxy(x+38,y+1);printf("%c",179);
	
	/*Esquina superior izquirerda*/
	gotoxy(x+38,y);printf("%c",191);
	/*Esquina inferior izquierda y derecha*/
	gotoxy(x+38,y+2);printf("%c",217);
	gotoxy(x,y+2);printf("%c",192);

	gotoxy(100, 23); printf("        oooO");
    gotoxy(100, 24); printf("       (....)     Oooo");
    gotoxy(100, 25); printf("        \\..(     (....)");
    gotoxy(100, 26); printf("         \\_)      )../");
    gotoxy(100, 27); printf("                  (_/");
    Sleep(1000);
    
    gotoxy(100, 17); printf("        oooO");
    gotoxy(100, 18); printf("       (....)     Oooo");
    gotoxy(100, 19); printf("        \\..(     (....)");
    gotoxy(100, 20); printf("         \\_)      )../");
    gotoxy(100, 21); printf("                  (_/");
    Sleep(1000);

    gotoxy(100, 11); printf("        oooO");
    gotoxy(100, 12); printf("       (....)     Oooo");
    gotoxy(100, 13); printf("        \\..(     (....)");
    gotoxy(100, 14); printf("         \\_)      )../");
    gotoxy(100, 15); printf("                  (_/");
    Sleep(1000);
   
	gotoxy(100, 5); printf("        oooO");
    gotoxy(100, 6); printf("       (....)     Oooo");
    gotoxy(100, 7); printf("        \\..(     (....)");
    gotoxy(100, 8); printf("         \\_)      )../");
    gotoxy(100, 9); printf("                  (_/");


	int i,k,n=11,a=0,b=1;
	int c=50,f=17;
	
	gotoxy(c,f);
	printf("%c",218);
	gotoxy(c,f+1);
	printf("%c",179);
	gotoxy(c,f+2);
	printf("%c",192);
	
	for(i=0;i<n-1;i++)
	{
		gotoxy(c+(i*4)+1,f);
		printf("%c%c%c%c",196,196,196,194);
		gotoxy(c+(i*4)+1,f+1);
		printf("   %c",179);
		gotoxy(c+(i*4)+1,f+2);
		printf("%c%c%c%c",196,196,196,193);
	}
	gotoxy(c+(i*4)+1,f);
	printf("%c%c%c%c",196,196,196,191);
	gotoxy(c+(i*4)+1,f+1);
	printf("   %c",179);
	gotoxy(c+(i*4)+1,f+2);
	printf("%c%c%c%c",196,196,196,217);
	
	for ( k = 0; k < n; k++) {
        gotoxy(52 + ((k * 4)), f + 1);
        if (k % 2 == 0) {
            printf("%d", a);
        } else {
            printf("%d", b);
        }
    }
    gotoxy(c+22,f+3);printf("^");
    gotoxy(c+22,f+4);printf("q0");
    
}
