/*maquina multicinta que suma binarios */
//declarar 32-bit release para que puea fucionar
//tener intalada la libreria winbgim
//en opciones de compilador poner esto: -static-libgcc -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <winbgim.h>
#define  ORANGE   "\x1B[38;2;255;128;0m"
#define AMARILLO_T "\x1b[33m"
#define RESET   "\x1b[0m"
#define RESET_COLOR "\x1b[0m"
#define LBLUE   "\x1B[38;2;53;149;240m"
#define max 20


void gotoxy(int x, int y);
void presentacion();
void margen_total();
void cuadrito_a(int x,int y);
void cuadrito(int x,int y);
void dibujar();
void mostrar();
void funcional();
void imprime(int c, int f);
void q0(char cad1[],char cad2[], char cad3[],char cad4[],int cab1, int cab2, int cab3, int cab4);
void q1(char cad1[],char cad2[], char cad3[],char cad4[],int cab1, int cab2, int cab3, int cab4);
void q2(char cad1[],char cad2[], char cad3[],char cad4[],int cab1, int cab2, int cab3, int cab4);
void logica(char cad1[],char cad2[],char cad3[],char cad4[],int cab1, int cab2, int cab3, int cab4);



main()
{
	gotoxy(52,16);system("pause");
	system("cls");
	presentacion();
	funcional();
	gotoxy(105, 33);system("pause");
	return 0;
}

void presentacion(){
	int opc;
	margen_total();
	
	cuadrito_a(45,4);
	gotoxy(46,5);printf("M A Q U I N A S  D E  T U R I N G  M U L T I C I N T A S");
	
	
	cuadrito(49,8);gotoxy(61,9);printf("Suma De Numeros Binarios:)");
	
	gotoxy(7,14);printf("* * * * * D E F I N I C I O N   F O R M A L * * * * *");
	gotoxy(17,16);printf("Q={q0, q1, q2}");
	gotoxy(17,17);printf("Alfabeto={0, 1}");
	gotoxy(17,18);printf("Alfabeto de la cinta={0, 1, #}");
	gotoxy(17,19);printf("S={q0}");
	gotoxy(17,20);printf("F={q2}");
	gotoxy(17,21);printf("Funcion de Transicion: ");
	gotoxy(17,22);printf("(q0,(0, 0, #, #))=(q0,(0, 0, 0, #),(L, L, L, S))");
	gotoxy(17,23);printf("(q0,(0, 1, #, #))=(q0,(0, 1, 1, #),(L, L, L, S))");
	gotoxy(17,24);printf("(q0,(1, 0, #, #))=(q0,(1, 0, 1, #),(L, L, L, S))");
	gotoxy(17,25);printf("(q0,(1, 1, #, #))=(q1,(1, 1, 0, 1),(L, L, L, S))");
	gotoxy(17,26);printf("(q0,(#, #, #, #))=(q2,(#, #, #, #),(S, S, S, S))");
	
	gotoxy(17,28);printf("(q1,(0, 0, #, 1))=(q0,(0, 0, 1, #),(L, L, L, S))");
	gotoxy(17,29);printf("(q1,(0, 1, #, 1))=(q1,(0, 1, 0, 1),(L, L, L, S))");
	gotoxy(17,30);printf("(q1,(1, 1, #, 1))=(q1,(1, 1, 1, 1),(L, L, L, S))");
	gotoxy(17,31);printf("(q1,(1, 0, #, 1))=(q1,(1, 0, 0, 1),(L, L, L, S))");
	gotoxy(17,32);printf("(q1,(#, #, #, 1))=(q2,(#, #, 1, #),(L, L, L, S))");


	gotoxy(90,16);printf("Mostrar Grafico.");
	gotoxy(90,17);printf("SI..........[1]");
	gotoxy(90,18);printf("NO..........[2]");
	gotoxy(90,19);printf("Elija Opcion: ");scanf("%d",&opc);
	
	if(opc==1)
	{
		mostrar();
	}
	
	/*gotoxy(105, 33);system("pause");*/
	

}

void mostrar() {
    
    initwindow(1366, 768);
    
    // Llamar a la función dibujar
    dibujar();

    // Esperar una entrada del usuario antes de cerrar la ventana
    getch();

    // Cerrar la ventana
    closegraph();
}

void dibujar() {
    int radio = 30;
    // Coordenadas de los nodos
    int q1_x = 800, q1_y = 150;
    int q0_x = 400, q0_y = 150;
    int q2_x = 600, q2_y = 550;

    // Dibujar los círculos en las coordenadas especificadas
    circle(q0_x, q0_y, radio);
    circle(q1_x, q1_y, radio);
    circle(q2_x, q2_y, radio);
    circle(q2_x, q2_y, 27);

	line(q0_x+30,q0_y-10,q1_x-30,q1_y-10);
    line(q1_x-30,q1_y+10,q0_x+30,q0_y+10);
    line(q0_x,q0_y+radio,q2_x-10,q2_y-radio);
    line(q1_x,q1_y+radio,q2_x+10,q2_y-radio);
    

	//arcos
	ellipse(q0_x, q0_y-radio, 0, 180, 20, 40);
	ellipse(q1_x, q1_y-radio, 0, 180, 20, 40);

	
	// Dibujar la flecha q0
    line(q0_x+18, q0_y-radio, q0_x+ 23, q0_y - radio-10);
    line(q0_x+18, q0_y-radio, q0_x+ 13, q0_y - radio-10);

    // Dibujar la flecha q1
    line(q1_x+18, q1_y-radio, q1_x+ 23, q1_y - radio-10);
    line(q1_x+18, q1_y-radio, q1_x+ 13, q1_y - radio-10);
    
    //dibujar la flecha de q0 a q1 
    line(q1_x-radio, q1_y-10, q1_x-radio-10, q1_y - 15);//el ultimo numero es el alto de la flecha
    line(q1_x-radio, q1_y-10, q1_x-radio-10, q1_y-5 );//el ultimo numero es el alto de la flecha
	//dibujar la flecha de q1 a q0
	line(q0_x+radio, q0_y+10, q0_x+radio+10, q0_y +5);//el ultimo numero es el alto de la flecha
	line(q0_x+radio, q0_y+10, q0_x+radio+10, q0_y +15);//el ultimo numero es el alto de la flecha
 
 	//dibujar la flechade q0 a q3
 	line(q2_x-10, q2_y-radio, q2_x-20, q2_y -radio-7);
 	line(q2_x-10, q2_y-radio, q2_x-9, q2_y -radio-11);
 	
 	//de q1 a q3
	line(q2_x+10, q2_y-radio, q2_x+8, q2_y -radio-11);
	line(q2_x+10, q2_y-radio, q2_x+22, q2_y -radio-5);

	//declarando inicio
	line(q0_x-radio, q0_y, q0_x-radio- 13, q0_y +10);
    line(q0_x-radio, q0_y, q0_x-radio- 13, q0_y -10);

    line(q0_x-radio-26,q0_y,q0_x-radio,q0_y);
    
    // Etiquetas para los nodos
    char nombre_q0[] = "q0";
    char nombre_q1[] = "q1";
    char nombre_q2[] = "q2";

	//etquetas de las transiciones
	char t1[]="0;0,L | 0;0,L | #;0,L | #;#,S";
	char t2[]="0;0,L | 1;1,L | #;1,L | #;#,S";
	char t3[]="1;1,L | 1;1,L | #;0,L | #;1,S";
	char t4[]="1;1,L | 0;0,L | #;1,L | #;#,S";
	char t5[]="#;#,S | #;#,S | #;#,S | #;#,S";
	char j1[]="#;#,L | #;#,L | #;1,L | 1;#,S";
	char k1[]="1;1,L | 1;1,L | #;0,L | #;1,S";
	char p1[]="0;0,L | 0;0,L | #;1,L | 1;#,S";
	
	//q1
	char l[]="0;0,L | 1;1,L | #;0,L | 1;1,S";
	char l1[]="1;1,L | 1;1,L | #;1,L | 1;1,S";
	char l2[]="1;1,L | 0;0,L | #;0,L | 1;1,S";
	
	
    // Etiquetas para los nodos
    outtextxy(q0_x - 10, q0_y - 10, nombre_q0);
    outtextxy(q1_x - 10, q1_y - 10, nombre_q1);
    outtextxy(q2_x - 10, q2_y - 10, nombre_q2);
    
    //q0
    outtextxy(q0_x-70,q0_y-90,t1);
    outtextxy(q0_x-70,q0_y-107,t2);
    outtextxy(q0_x-70,q0_y-120,t3);
    outtextxy(q0_x-70,q0_y-137,t4);
    outtextxy(300,q0_y+200,t5);
    
    //q1
    outtextxy(q1_x-70,q1_y-90,l);
    outtextxy(q1_x-70,q1_y-107,l1);
    outtextxy(q1_x-70,q1_y-120,l2);
    //q2 conexion
    outtextxy(720,q0_y+200,j1);
    
    //Q1 conexion
	outtextxy(530,q0_y-35,k1);  
	outtextxy(530,q0_y+15,p1);    
}	

void funcional()
{
	char cad1[max];
	char cad2[max];
	char cad3[20]={'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','\0'};
	char cad4[20]={'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','\0'};
	char cadaux1[20] ,cadaux2[20];
	int h,j,k,i,a,lar=21;
	system("cls");
	//decoracion
	margen_total();
	cuadrito_a(45,3);
	gotoxy(46,4);printf("M A Q U I N A S  D E  T U R I N G  M U L T I C I N T A S");
	gotoxy(110,4);printf("Nota.");
	gotoxy(110,5);printf("Acomplete con Ceros");
	gotoxy(110,6);printf("Si es necesario.");
	gotoxy(10,6);printf("Cadena 1: ");scanf("%s",cadaux1);
	gotoxy(10,7);printf("Cadena 1: ");scanf("%s",cadaux2);
	cad1[0]='#';
	cad2[0]='#';
	
	
	for(a=0; cadaux1[a]!='\0'; a++)
	{
		cad1[a+1]=cadaux1[a];
		cad2[a+1]=cadaux2[a];
	}
	cad1[a+1]='\0';
	cad2[a+1]='\0';
	
	gotoxy(1,10);printf("Cinta 1");
	gotoxy(1,16);printf("Cinta 2");
	gotoxy(1,22);printf("Cinta 3");
	gotoxy(1,23);printf("Resultado");
	gotoxy(1,28);printf("Cinta 4");
	gotoxy(1,29);printf("Acarreo");
	//impriomo celdas aqui
	imprime(10,9);
	imprime(10,15);
	imprime(10,21);
	imprime(10,27);
	//rellenar lo arreglos
	for(h=0;h<lar;h++)
	{
		gotoxy(11+(h*4),10);printf(" #");
		gotoxy(11+(h*4),16);printf(" #");
		gotoxy(11+(h*4),22);printf(" #");
		gotoxy(11+(h*4),28);printf(" #");
	}
	// Inicialización de cabezales
	int cab1 = 0, cab2 = 0, cab3 = 0, cab4 = 0;
	
	int len_cad1 = strlen(cad1);
	
	for(h=0; h<len_cad1; h++)
	{
	    gotoxy(52+(h*4),10);printf(ORANGE"%c"RESET,cad1[h]);
	    cab1++;
	}
	
	int len_cad2 = strlen(cad2);
	for(j=0; j<len_cad2; j++)
	{
	    gotoxy(52+(j*4),16);printf(ORANGE"%c"RESET,cad2[j]);
	    cab2++;
	    cab3++;
	    cab4++;
	}

	int temp_cab3 = cab3;
	for(k=0; k<temp_cab3; k++)
	{
	    gotoxy(52+(k*4),22);printf(ORANGE"%c"RESET,cad3[k]);

	}
	
	int temp_cab4=cab4;
	for(i=0; i<temp_cab4; i++)
	{
	    gotoxy(52+(i*4),28);printf(ORANGE"%c"RESET,cad4[i]);

	}
	//simular cabezaes
	gotoxy(52+((cab4-1)*4),12);printf("^");
	
	gotoxy(52+((cab4-1)*4),18);printf("^");
	
	gotoxy(52+((cab4-1)*4),24);printf("^");
	
	gotoxy(52+((cab4-1)*4),30);printf("^");
	
	logica(cad1,cad2,cad3,cad4,cab1,cab2,cab3,cab4);
}

//implementa mejor las cadenas
void logica(char cad1[],char cad2[],char cad3[],char cad4[],int cab1, int cab2, int cab3, int cab4)
{
	int band=0;
	/*cad3[cab3-1]='#';
	cad4[cab4-1]='#';*/
	gotoxy(110,16);printf("Estado: q%d",band);

	
	while(band!=2)
	{
		Sleep(2000);
	
		if(band==0)
		{
			if(cad1[cab1-1]=='0'&&cad2[cab2-1]=='0'&&cad3[cab3-1]=='#'&&cad4[cab4-1]=='#')
			{
				
				band=0;
				cad1[cab1-1]='0';
				cad2[cab2-1]='0';
				cad3[cab3-1]='0';
				cad4[cab4-1]='#';
				gotoxy(110,16);printf("Estado: q%d",band);
				//imprimir lo que sobreescribe la cinta
				///cab1
				gotoxy(52+((cab1-1)*4),10);printf("  ");
				gotoxy(52+((cab1-1)*4),10);printf(AMARILLO_T"%c"RESET_COLOR,cad1[cab1-1]);
				///cab2
				gotoxy(52+((cab2-1)*4),16);printf("  ");
				gotoxy(52+((cab2-1)*4),16);printf(AMARILLO_T"%c"RESET_COLOR,cad2[cab2-1]);
				///cab3
				gotoxy(52+((cab3-1)*4),22);printf("  ");
				gotoxy(52+((cab3-1)*4),22);printf(AMARILLO_T"%c"RESET_COLOR,cad3[cab3-1]);
				///cab4
				gotoxy(52+((cab4-1)*4),28);printf("  ");
				gotoxy(52+((cab4-1)*4),28);printf(AMARILLO_T"%c"RESET_COLOR,cad4[cab4-1]);
				
				//flechitas(borar)
				gotoxy(52+((cab1-1)*4),12);printf("  ");
				gotoxy(52+((cab2-1)*4),18);printf("  ");
				gotoxy(52+((cab3-1)*4),24);printf("  ");
				gotoxy(52+((cab4-1)*4),30);printf("  ");
				//actualizacion de los cabezales
				cab1--;
				cab2--;
				cab3--;
				//mostrar flechitas con autualizacion
				gotoxy(52+((cab1-1)*4),12);printf("^");
				gotoxy(52+((cab2-1)*4),18);printf("^");
				gotoxy(52+((cab3-1)*4),24);printf("^");
				gotoxy(52+((cab4-1)*4),30);printf("^");
				
			}else if(cad1[cab1-1]=='0'&&cad2[cab2-1]=='1'&&cad3[cab3-1]=='#'&&cad4[cab4-1]=='#')
			{
				band=0;
				cad1[cab1-1]='0';
				cad2[cab2-1]='1';
				cad3[cab3-1]='1';
				gotoxy(110,16);printf("Estado: q%d",band);
				//imprimir lo que sobreescribe la cinta
				///cab1
				gotoxy(52+((cab1-1)*4),10);printf("  ");
				gotoxy(52+((cab1-1)*4),10);printf(AMARILLO_T"%c"RESET_COLOR,cad1[cab1-1]);
				///cab2
				gotoxy(52+((cab2-1)*4),16);printf("  ");
				gotoxy(52+((cab2-1)*4),16);printf(AMARILLO_T"%c"RESET_COLOR,cad2[cab2-1]);
				///cab3
				gotoxy(52+((cab3-1)*4),22);printf("  ");
				gotoxy(52+((cab3-1)*4),22);printf(AMARILLO_T"%c"RESET_COLOR,cad3[cab3-1]);
				///cab4
				gotoxy(52+((cab4-1)*4),28);printf("  ");
				gotoxy(52+((cab4-1)*4),28);printf(AMARILLO_T"%c"RESET_COLOR,cad4[cab4-1]);
				
				//flechitas(borar)
				gotoxy(52+((cab1-1)*4),12);printf("  ");
				gotoxy(52+((cab2-1)*4),18);printf("  ");
				gotoxy(52+((cab3-1)*4),24);printf("  ");
				gotoxy(52+((cab4-1)*4),30);printf("  ");
				//actualizacion de los cabezales
				cab1--;
				cab2--;
				cab3--;
				//mostrar flechitas con autualizacion
				gotoxy(52+((cab1-1)*4),12);printf("^");
				gotoxy(52+((cab2-1)*4),18);printf("^");
				gotoxy(52+((cab3-1)*4),24);printf("^");
				gotoxy(52+((cab4-1)*4),30);printf("^");
			}else if(cad1[cab1-1]=='1'&&cad2[cab2-1]=='0'&&cad3[cab3-1]=='#'&&cad4[cab4-1]=='#')
			{
				band=0;
				cad1[cab1-1]='1';
				cad2[cab2-1]='0';
				cad3[cab3-1]='1';
				gotoxy(110,16);printf("Estado: q%d",band);
				//imprimir lo que sobreescribe la cinta
				///cab1
				gotoxy(52+((cab1-1)*4),10);printf("  ");
				gotoxy(52+((cab1-1)*4),10);printf(AMARILLO_T"%c"RESET_COLOR,cad1[cab1-1]);
				///cab2
				gotoxy(52+((cab2-1)*4),16);printf("  ");
				gotoxy(52+((cab2-1)*4),16);printf(AMARILLO_T"%c"RESET_COLOR,cad2[cab2-1]);
				///cab3
				gotoxy(52+((cab3-1)*4),22);printf("  ");
				gotoxy(52+((cab3-1)*4),22);printf(AMARILLO_T"%c"RESET_COLOR,cad3[cab3-1]);
				///cab4
				gotoxy(52+((cab4-1)*4),28);printf("  ");
				gotoxy(52+((cab4-1)*4),28);printf(AMARILLO_T"%c"RESET_COLOR,cad4[cab4-1]);
				
				//flechitas(borar)
				gotoxy(52+((cab1-1)*4),12);printf("  ");
				gotoxy(52+((cab2-1)*4),18);printf("  ");
				gotoxy(52+((cab3-1)*4),24);printf("  ");
				gotoxy(52+((cab4-1)*4),30);printf("  ");
				//actualizacion de los cabezales
				cab1--;
				cab2--;
				cab3--;
				//mostrar flechitas con autualizacion
				gotoxy(52+((cab1-1)*4),12);printf("^");
				gotoxy(52+((cab2-1)*4),18);printf("^");
				gotoxy(52+((cab3-1)*4),24);printf("^");
				gotoxy(52+((cab4-1)*4),30);printf("^");

			}else if(cad1[cab1-1]=='1'&&cad2[cab2-1]=='1'&&cad3[cab3-1]=='#'&&cad4[cab4-1]=='#')
			{
				band=1;
				cad1[cab1-1]='1';
				cad2[cab2-1]='1';
				cad3[cab3-1]='0';
				cad4[cab4-1]='1';
				gotoxy(110,16);printf("Estado: q%d",band);
				//imprimir lo que sobreescribe la cinta
				///cab1
				gotoxy(52+((cab1-1)*4),10);printf("  ");
				gotoxy(52+((cab1-1)*4),10);printf(AMARILLO_T"%c"RESET_COLOR,cad1[cab1-1]);
				///cab2
				gotoxy(52+((cab2-1)*4),16);printf("  ");
				gotoxy(52+((cab2-1)*4),16);printf(AMARILLO_T"%c"RESET_COLOR,cad2[cab2-1]);
				///cab3
				gotoxy(52+((cab3-1)*4),22);printf("  ");
				gotoxy(52+((cab3-1)*4),22);printf(AMARILLO_T"%c"RESET_COLOR,cad3[cab3-1]);
				///cab4
				gotoxy(52+((cab4-1)*4),28);printf("  ");
				gotoxy(52+((cab4-1)*4),28);printf(AMARILLO_T"%c"RESET_COLOR,cad4[cab4-1]);
				
				//flechitas(borar)
				gotoxy(52+((cab1-1)*4),12);printf("  ");
				gotoxy(52+((cab2-1)*4),18);printf("  ");
				gotoxy(52+((cab3-1)*4),24);printf("  ");
				gotoxy(52+((cab4-1)*4),30);printf("  ");
				//actualizacion de los cabezales
				cab1--;
				cab2--;
				cab3--;
				//mostrar flechitas con autualizacion
				gotoxy(52+((cab1-1)*4),12);printf("^");
				gotoxy(52+((cab2-1)*4),18);printf("^");
				gotoxy(52+((cab3-1)*4),24);printf("^");
				gotoxy(52+((cab4-1)*4),30);printf("^");
				
			}else if(cad1[cab1-1]=='#'&&cad2[cab2-1]=='#'&&cad3[cab3-1]=='#'&&cad4[cab4-1]=='#')
			{
				band=2;
				cad1[cab1-1]='#';
				cad2[cab2-1]='#';
				cad3[cab3-1]='#';
				cad4[cab4-1]='#';
				gotoxy(110,16);printf("Estado: q%d",band);
				//imprimir lo que sobreescribe la cinta
				///cab1
				gotoxy(52+((cab1-1)*4),10);printf("  ");
				gotoxy(52+((cab1-1)*4),10);printf(AMARILLO_T"%c"RESET_COLOR,cad1[cab1-1]);
				///cab2
				gotoxy(52+((cab2-1)*4),16);printf("  ");
				gotoxy(52+((cab2-1)*4),16);printf(AMARILLO_T"%c"RESET_COLOR,cad2[cab2-1]);
				///cab3
				gotoxy(52+((cab3-1)*4),22);printf("  ");
				gotoxy(52+((cab3-1)*4),22);printf(AMARILLO_T"%c"RESET_COLOR,cad3[cab3-1]);
				///cab4
				gotoxy(52+((cab4-1)*4),28);printf("  ");
				gotoxy(52+((cab4-1)*4),28);printf(AMARILLO_T"%c"RESET_COLOR,cad4[cab4-1]);
				
				//flechitas(borar)
				gotoxy(52+((cab1-1)*4),12);printf("  ");
				gotoxy(52+((cab2-1)*4),18);printf("  ");
				gotoxy(52+((cab3-1)*4),24);printf("  ");
				gotoxy(52+((cab4-1)*4),30);printf("  ");
				//actualizacion de los cabezales

				//mostrar flechitas con autualizacion
				gotoxy(52+((cab1-1)*4),12);printf("^");
				gotoxy(52+((cab2-1)*4),18);printf("^");
				gotoxy(52+((cab3-1)*4),24);printf("^");
				gotoxy(52+((cab4-1)*4),30);printf("^");
			}else
			{
				
				gotoxy(110,18);printf("Cadena No valida %d",band);
				break;
			}
		}
		else if(band==1)
		{//aqui me quede
			if(cad1[cab1-1]=='0'&&cad2[cab2-1]=='0'&&cad3[cab3-1]=='#'&&cad4[cab4-1]=='1')
			{
				band=0;
				cad1[cab1-1]='0';
				cad2[cab2-1]='0';
				cad3[cab3-1]='1';
				cad4[cab4-1]='#';
				gotoxy(110,16);printf("Estado: q%d",band);
				//imprimir lo que sobreescribe la cinta
				///cab1
				gotoxy(52+((cab1-1)*4),10);printf("  ");
				gotoxy(52+((cab1-1)*4),10);printf(AMARILLO_T"%c"RESET_COLOR,cad1[cab1-1]);
				///cab2
				gotoxy(52+((cab2-1)*4),16);printf("  ");
				gotoxy(52+((cab2-1)*4),16);printf(AMARILLO_T"%c"RESET_COLOR,cad2[cab2-1]);
				///cab3
				gotoxy(52+((cab3-1)*4),22);printf("  ");
				gotoxy(52+((cab3-1)*4),22);printf(AMARILLO_T"%c"RESET_COLOR,cad3[cab3-1]);
				///cab4
				gotoxy(52+((cab4-1)*4),28);printf("  ");
				gotoxy(52+((cab4-1)*4),28);printf(AMARILLO_T"%c"RESET_COLOR,cad4[cab4-1]);
				
				//flechitas(borar)
				gotoxy(52+((cab1-1)*4),12);printf("  ");
				gotoxy(52+((cab2-1)*4),18);printf("  ");
				gotoxy(52+((cab3-1)*4),24);printf("  ");
				gotoxy(52+((cab4-1)*4),30);printf("  ");
				//actualizacion de los cabezales
				cab1--;
				cab2--;
				cab3--;
				//mostrar flechitas con autualizacion
				gotoxy(52+((cab1-1)*4),12);printf("^");
				gotoxy(52+((cab2-1)*4),18);printf("^");
				gotoxy(52+((cab3-1)*4),24);printf("^");
				gotoxy(52+((cab4-1)*4),30);printf("^");
				
			}else if(cad1[cab1-1]=='0'&&cad2[cab2-1]=='1'&&cad3[cab3-1]=='#'&&cad4[cab4-1]=='1'){
				band=1;
				cad1[cab1-1]='0';
				cad2[cab2-1]='1';
				cad3[cab3-1]='0';
				cad4[cab4-1]='1';
				gotoxy(110,16);printf("Estado: q%d",band);
				//imprimir lo que sobreescribe la cinta
				///cab1
				gotoxy(52+((cab1-1)*4),10);printf("  ");
				gotoxy(52+((cab1-1)*4),10);printf(AMARILLO_T"%c"RESET_COLOR,cad1[cab1-1]);
				///cab2
				gotoxy(52+((cab2-1)*4),16);printf("  ");
				gotoxy(52+((cab2-1)*4),16);printf(AMARILLO_T"%c"RESET_COLOR,cad2[cab2-1]);
				///cab3
				gotoxy(52+((cab3-1)*4),22);printf("  ");
				gotoxy(52+((cab3-1)*4),22);printf(AMARILLO_T"%c"RESET_COLOR,cad3[cab3-1]);
				///cab4
				gotoxy(52+((cab4-1)*4),28);printf("  ");
				gotoxy(52+((cab4-1)*4),28);printf(AMARILLO_T"%c"RESET_COLOR,cad4[cab4-1]);
				
				//flechitas(borar)
				gotoxy(52+((cab1-1)*4),12);printf("  ");
				gotoxy(52+((cab2-1)*4),18);printf("  ");
				gotoxy(52+((cab3-1)*4),24);printf("  ");
				gotoxy(52+((cab4-1)*4),30);printf("  ");
				//actualizacion de los cabezales
				cab1--;
				cab2--;
				cab3--;
				//mostrar flechitas con autualizacion
				gotoxy(52+((cab1-1)*4),12);printf("^");
				gotoxy(52+((cab2-1)*4),18);printf("^");
				gotoxy(52+((cab3-1)*4),24);printf("^");
				gotoxy(52+((cab4-1)*4),30);printf("^");
				
			}else if(cad1[cab1-1]=='1'&&cad2[cab2-1]=='1'&&cad3[cab3-1]=='#'&&cad4[cab4-1]=='1'){
				band=1;
				cad1[cab1-1]='1';
				cad2[cab2-1]='1';
				cad3[cab3-1]='1';
				cad4[cab4-1]='1';
				gotoxy(110,16);printf("Estado: q%d",band);
				//imprimir lo que sobreescribe la cinta
				///cab1
				gotoxy(52+((cab1-1)*4),10);printf("  ");
				gotoxy(52+((cab1-1)*4),10);printf(AMARILLO_T"%c"RESET_COLOR,cad1[cab1-1]);
				///cab2
				gotoxy(52+((cab2-1)*4),16);printf("  ");
				gotoxy(52+((cab2-1)*4),16);printf(AMARILLO_T"%c"RESET_COLOR,cad2[cab2-1]);
				///cab3
				gotoxy(52+((cab3-1)*4),22);printf("  ");
				gotoxy(52+((cab3-1)*4),22);printf(AMARILLO_T"%c"RESET_COLOR,cad3[cab3-1]);
				///cab4
				gotoxy(52+((cab4-1)*4),28);printf("  ");
				gotoxy(52+((cab4-1)*4),28);printf(AMARILLO_T"%c"RESET_COLOR,cad4[cab4-1]);
				
				//flechitas(borar)
				gotoxy(52+((cab1-1)*4),12);printf("  ");
				gotoxy(52+((cab2-1)*4),18);printf("  ");
				gotoxy(52+((cab3-1)*4),24);printf("  ");
				gotoxy(52+((cab4-1)*4),30);printf("  ");
				//actualizacion de los cabezales
				cab1--;
				cab2--;
				cab3--;
				//mostrar flechitas con autualizacion
				gotoxy(52+((cab1-1)*4),12);printf("^");
				gotoxy(52+((cab2-1)*4),18);printf("^");
				gotoxy(52+((cab3-1)*4),24);printf("^");
				gotoxy(52+((cab4-1)*4),30);printf("^");
			}else if(cad1[cab1-1]=='1'&&cad2[cab2-1]=='0'&&cad3[cab3-1]=='#'&&cad4[cab4-1]=='1'){
				band=1;
				cad1[cab1-1]='1';
				cad2[cab2-1]='0';
				cad3[cab3-1]='0';
				cad4[cab4-1]='1';
				gotoxy(110,16);printf("Estado: q%d",band);
				//imprimir lo que sobreescribe la cinta
				///cab1
				gotoxy(52+((cab1-1)*4),10);printf("  ");
				gotoxy(52+((cab1-1)*4),10);printf(AMARILLO_T"%c"RESET_COLOR,cad1[cab1-1]);
				///cab2
				gotoxy(52+((cab2-1)*4),16);printf("  ");
				gotoxy(52+((cab2-1)*4),16);printf(AMARILLO_T"%c"RESET_COLOR,cad2[cab2-1]);
				///cab3
				gotoxy(52+((cab3-1)*4),22);printf("  ");
				gotoxy(52+((cab3-1)*4),22);printf(AMARILLO_T"%c"RESET_COLOR,cad3[cab3-1]);
				///cab4
				gotoxy(52+((cab4-1)*4),28);printf("  ");
				gotoxy(52+((cab4-1)*4),28);printf(AMARILLO_T"%c"RESET_COLOR,cad4[cab4-1]);
				
				//flechitas(borar)
				gotoxy(52+((cab1-1)*4),12);printf("  ");
				gotoxy(52+((cab2-1)*4),18);printf("  ");
				gotoxy(52+((cab3-1)*4),24);printf("  ");
				gotoxy(52+((cab4-1)*4),30);printf("  ");
				//actualizacion de los cabezales
				cab1--;
				cab2--;
				cab3--;
				//mostrar flechitas con autualizacion
				gotoxy(52+((cab1-1)*4),12);printf("^");
				gotoxy(52+((cab2-1)*4),18);printf("^");
				gotoxy(52+((cab3-1)*4),24);printf("^");
				gotoxy(52+((cab4-1)*4),30);printf("^");
				
			}else if(cad1[cab1-1]=='#'&&cad2[cab2-1]=='#'&&cad3[cab3-1]=='#'&&cad4[cab4-1]=='1'){
				band=2;
				cad1[cab1-1]='#';
				cad2[cab2-1]='#';
				cad3[cab3-1]='1';
				cad4[cab4-1]='#';
				gotoxy(110,16);printf("Estado: q%d",band);
				//imprimir lo que sobreescribe la cinta
				///cab1
				gotoxy(52+((cab1-1)*4),10);printf("  ");
				gotoxy(52+((cab1-1)*4),10);printf(AMARILLO_T"%c"RESET_COLOR,cad1[cab1-1]);
				///cab2
				gotoxy(52+((cab2-1)*4),16);printf("  ");
				gotoxy(52+((cab2-1)*4),16);printf(AMARILLO_T"%c"RESET_COLOR,cad2[cab2-1]);
				///cab3
				gotoxy(52+((cab3-1)*4),22);printf("  ");
				gotoxy(52+((cab3-1)*4),22);printf(AMARILLO_T"%c"RESET_COLOR,cad3[cab3-1]);
				///cab4
				gotoxy(52+((cab4-1)*4),28);printf("  ");
				gotoxy(52+((cab4-1)*4),28);printf(AMARILLO_T"%c"RESET_COLOR,cad4[cab4-1]);
				
				//flechitas(borar)
				gotoxy(52+((cab1-1)*4),12);printf("  ");
				gotoxy(52+((cab2-1)*4),18);printf("  ");
				gotoxy(52+((cab3-1)*4),24);printf("  ");
				gotoxy(52+((cab4-1)*4),30);printf("  ");
				//actualizacion de los cabezales
				cab1--;
				cab2--;
				cab3--;
				//mostrar flechitas con autualizacion
				gotoxy(52+((cab1-1)*4),12);printf("^");
				gotoxy(52+((cab2-1)*4),18);printf("^");
				gotoxy(52+((cab3-1)*4),24);printf("^");
				gotoxy(52+((cab4-1)*4),30);printf("^");
				
			}
			else
			{
				gotoxy(110,18);printf("Cadena No valida");
				break;
			}
			
		}
		
	}

	if(band==2)
	{
		gotoxy(110,22);printf(LBLUE"Cadena valida Y la suma se ha Echo"RESET);
	}
	
	int opc;
	
	gotoxy(110,25);printf("Ingresar Otra Suma:");
	gotoxy(110,26);printf("SI.......[1]");
	gotoxy(110,27);printf("NO.......[2]");
	gotoxy(110,28);printf("Res: ");scanf("%d",&opc);
	
	if(opc==1)
	{
		funcional();
	}
	else
	{
		
		return;
	}
}





void imprime(int c, int f){
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
void cuadrito_a(int x,int y){
	int k;
	
	gotoxy(x,y);printf("%c",218);
	for(k=0;k<57;k++)
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

void cuadrito(int x,int y){
	int k;
	
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


