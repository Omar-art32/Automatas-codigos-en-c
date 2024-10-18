#include <stdio.h>
#include <windows.h>
#include <stdio.h>
#include<time.h>


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
void pantalla_tres(char cadena1[],char cadenaf[]);



main()
{
	char cadena1[100];
	char cadenaf[100];
	time_t tiempo_actual;
	time(&tiempo_actual);
	struct tm *info_tiempo=localtime(&tiempo_actual);
	
	gotoxy(52,16);system("pause");
	system("cls");
	gotoxy(95,3);printf(" %02d/%02d/%02d ",info_tiempo->tm_mday,info_tiempo->tm_mon+1,info_tiempo->tm_year+1900);
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
	gotoxy(3,26);printf("(q1,#)=(q3,0,L)");
	
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

	gotoxy(105,33);system("pause");
}

void pantalla_tres(char cadena1[],char cadenaf[])
{
	system("cls");
	margen_total();
	gotoxy(45,4);printf("M A Q U I N A  D E  T U R I N G  D E  U N A  S O L A  C I N T A");
	
	cuadrito_a();
	gotoxy(21,7);printf("INGRESE CADENA: ");scanf("%s",cadena1);
}









void cuadrito_a()
{
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
void cuadrito()
{
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
    sleep(1);
    
    gotoxy(100, 17); printf("        oooO");
    gotoxy(100, 18); printf("       (....)     Oooo");
    gotoxy(100, 19); printf("        \\..(     (....)");
    gotoxy(100, 20); printf("         \\_)      )../");
    gotoxy(100, 21); printf("                  (_/");
    sleep(1);

    gotoxy(100, 11); printf("        oooO");
    gotoxy(100, 12); printf("       (....)     Oooo");
    gotoxy(100, 13); printf("        \\..(     (....)");
    gotoxy(100, 14); printf("         \\_)      )../");
    gotoxy(100, 15); printf("                  (_/");
    sleep(1);
   
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
