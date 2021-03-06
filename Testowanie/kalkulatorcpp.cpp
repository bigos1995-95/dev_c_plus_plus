#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include <string>
#include <sstream>
///////////////////////////////////////////////////////////////////////////////
using namespace std;
double i;
int znak_dzialania;
int tablica_na_liczby[10]; // tworze tablice ktora zapisuje liczby wcisniete na kalkulatorze
int liczba_klikniec;

//Funkcja do wpisywania liczby do tablicy;
void zapiszdotb(int znak);
//funkcja do przechocywania calkowitej liczby podanej przez uzytkownika
void przechow(void);
//Funkcja do zmiany stringu na int (dla pierwszej liczby)
void naintpierwsza(void);
//Funkcja do zmiany stringu na int (dla drugiej liczby)
void naintdruga(void);
//Funkcja do zmiany int na string (dla wyniku koncowego)
void nastringkoncowy(void);

//Zmienna do wyznaczania miejsca w tablicy
int miejscetb = 0;

//zmienna do przechowywania calkowitej liczby podanej przez uzytkownika
string koncowa;

//Cala pierwsza liczba wpisana przed znakiem dzialania
int pierwsza_liczba;
//Cala druga liczba wpisana miedzy znakiem dzialania a znakiem =
int druga_liczba;
//Zmienna sprawdzajaca czy przycisk zostal wcisniety
int czywcisniety;

//Zmienna przechowujaca koncowy wynik w int
int intkoncowy;

//////////////////////////////////////////////////////////////////

HWND hPrzyc0, hPrzyc1, hPrzyc2, hPrzyc3, hPrzyc4, hPrzyc5, hPrzyc6, hPrzyc7, hPrzyc8, hPrzyc9, hPrzycraz, hPrzycmin, hPrzycplu, hPrzycpod, hPrzycrow, hPrzyckas, hWnd; //globalne deklaracje uchyt�w na okna:
//hWnd - uchwyt na nasze okno rodzica
//hButton - uchwyt na przycisk
CHAR szClassName[]="OknoRodzica";
HINSTANCE* hInst;
//globalny wska�nik na uchwyt naszego programu
//uchwytu programu cz�sto b�dziemy u�ywa� w r�nych funkcjach, dlatego dobrze, mie� globalny wska�nik na niego

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

INT WINAPI WinMain(HINSTANCE hInstance,HINSTANCE,LPSTR lStart,INT nShow)
{
  hInst=&hInstance; //pobieramy uchwyt programu do globalnego wska�nika
  //tworzenie okna rodzica
  WNDCLASSEX wc;
  wc.hInstance=*hInst; //u�ywamy globalnego wska�nika
  wc.lpszClassName=szClassName;
  wc.lpfnWndProc=WndProc;
  wc.style=0;
  wc.cbSize=sizeof(WNDCLASSEX);
  wc.hIcon=LoadIcon(0,IDI_APPLICATION);
  wc.hIconSm=LoadIcon(0,IDI_APPLICATION);
  wc.hCursor=LoadCursor(0,IDC_ARROW);
  wc.lpszMenuName=0;
  wc.cbClsExtra=0;
  wc.cbWndExtra=0;
  wc.hbrBackground=(HBRUSH)COLOR_BACKGROUND;
  if(!RegisterClassEx(&wc)) return 0;
  hWnd=CreateWindowEx(0,szClassName,"Tworzenie buttona",WS_OVERLAPPEDWINDOW,500,200,200,300,0,0,*hInst,0);
  ShowWindow(hWnd,nShow);
  MSG msgs;
  while(GetMessage(&msgs,0,0,0))
  {
    TranslateMessage(&msgs);
    DispatchMessage(&msgs);
  }
  return msgs.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd,UINT msg,WPARAM wPar,LPARAM lPar)
{
  HDC hdc;
  PAINTSTRUCT ps;
  
      
  switch(msg)
  {
	case WM_PAINT:
      hdc=BeginPaint(hwnd,&ps);
      //funkcje rysuj�ce
      
HDC hDC;
hDC = GetDC(hwnd);
Rectangle( hDC, 1, 132, 113, 166);
ReleaseDC( hwnd, hDC );
      
      RECT rect; 
      SetRect(&rect, 1, 140, 110, 181); 
      
      DrawText( hdc, koncowa.c_str(), -1, &rect, DT_RIGHT | DT_BOTTOM);
      
      EndPaint(hwnd,&ps);
      break;	
		
    case WM_CREATE:
      //funkcja tworz�ca kontrolk�
      hPrzyc0 = CreateWindowEx(0,WC_BUTTON,"0",WS_CHILD|WS_VISIBLE,114,131,73,35,hwnd,(HMENU)1,*hInst,0);
      hPrzyc1 = CreateWindowEx(0,WC_BUTTON,"1",WS_CHILD|WS_VISIBLE,3,230,35,30,hwnd,(HMENU)1,*hInst,0);
      hPrzyc2 = CreateWindowEx(0,WC_BUTTON,"2",WS_CHILD|WS_VISIBLE,40,230,35,30,hwnd,(HMENU)1,*hInst,0);
      hPrzyc3 = CreateWindowEx(0,WC_BUTTON,"3",WS_CHILD|WS_VISIBLE,77,230,35,30,hwnd,(HMENU)1,*hInst,0);
      hPrzyc4 = CreateWindowEx(0,WC_BUTTON,"4",WS_CHILD|WS_VISIBLE,3,199,35,30,hwnd,(HMENU)1,*hInst,0);
      hPrzyc5 = CreateWindowEx(0,WC_BUTTON,"5",WS_CHILD|WS_VISIBLE,40,199,35,30,hwnd,(HMENU)1,*hInst,0);
      hPrzyc6 = CreateWindowEx(0,WC_BUTTON,"6",WS_CHILD|WS_VISIBLE,77,199,35,30,hwnd,(HMENU)1,*hInst,0);
      hPrzyc7 = CreateWindowEx(0,WC_BUTTON,"7",WS_CHILD|WS_VISIBLE,3,168,35,30,hwnd,(HMENU)1,*hInst,0);
      hPrzyc8 = CreateWindowEx(0,WC_BUTTON,"8",WS_CHILD|WS_VISIBLE,40,168,35,30,hwnd,(HMENU)1,*hInst,0);
      hPrzyc9 = CreateWindowEx(0,WC_BUTTON,"9",WS_CHILD|WS_VISIBLE,77,168,35,30,hwnd,(HMENU)1,*hInst,0);
      hPrzycraz = CreateWindowEx(0,WC_BUTTON,"*",WS_CHILD|WS_VISIBLE,114,230,35,30,hwnd,(HMENU)1,*hInst,0);
      hPrzycmin = CreateWindowEx(0,WC_BUTTON,"-",WS_CHILD|WS_VISIBLE,114,199,35,30,hwnd,(HMENU)1,*hInst,0);
      hPrzycplu = CreateWindowEx(0,WC_BUTTON,"+",WS_CHILD|WS_VISIBLE,114,168,35,30,hwnd,(HMENU)1,*hInst,0);
      hPrzycpod = CreateWindowEx(0,WC_BUTTON,"/",WS_CHILD|WS_VISIBLE,151,230,35,30,hwnd,(HMENU)1,*hInst,0);
      hPrzycrow = CreateWindowEx(0,WC_BUTTON,"=",WS_CHILD|WS_VISIBLE,151,199,35,30,hwnd,(HMENU)1,*hInst,0);
      hPrzyckas = CreateWindowEx(0,WC_BUTTON,"C",WS_CHILD|WS_VISIBLE,151,168,35,30,hwnd,(HMENU)1,*hInst,0);

      break;
      
      case WM_COMMAND:
			
	//Sprawdzamy czy dany przycisk jest wcisniety
	      if((HWND) lPar == hPrzyc0) {
				koncowa.erase(); // funkcja erase czyscimy caly string
				czywcisniety = 1;
				liczba_klikniec++;				
				zapiszdotb(0);
				miejscetb = 0;
				przechow();														
				RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);	
					   
		  }	else if((HWND) lPar == hPrzyc1) {
				koncowa.erase(); 
				czywcisniety = 1;
				liczba_klikniec++;				
				zapiszdotb(1);
				miejscetb = 0;
				przechow();														
				RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);
					   
		  } else if((HWND) lPar == hPrzyc2) {
				koncowa.erase();
				czywcisniety = 1;
				liczba_klikniec++;	
				zapiszdotb(2);
				miejscetb = 0;
				przechow();								
				RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);	
							
		  } else if((HWND) lPar == hPrzyc3) {
				koncowa.erase();
				czywcisniety = 1;
				liczba_klikniec++;	
				zapiszdotb(3);
				miejscetb = 0;
				przechow();							
				RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);
							
		  } else if((HWND) lPar == hPrzyc4) {
				koncowa.erase();
				czywcisniety = 1;
				liczba_klikniec++;	
				zapiszdotb(4);
				miejscetb = 0;
				przechow();								
				RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);	
							
		  } else if((HWND) lPar == hPrzyc5) {
				koncowa.erase();
				czywcisniety = 1;
				liczba_klikniec++;	
				zapiszdotb(5);
				miejscetb = 0;
				przechow();								
				RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);
							
		  } else if((HWND) lPar == hPrzyc6) {
				koncowa.erase();
				czywcisniety = 1;
				liczba_klikniec++;	
				zapiszdotb(6);
				miejscetb = 0;
				przechow();								
				RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);
							
		  } else if((HWND) lPar == hPrzyc7) {
				koncowa.erase();
				czywcisniety = 1;
				liczba_klikniec++;	
				zapiszdotb(7);
				miejscetb = 0;
				przechow();								
				RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);
								
		  } else if((HWND) lPar == hPrzyc8) {
				koncowa.erase();
				czywcisniety = 1;
				liczba_klikniec++;	
				zapiszdotb(8);
				miejscetb = 0;
				przechow();								
				RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);
							
		  } else if((HWND) lPar == hPrzyc9) {
				koncowa.erase();
				czywcisniety = 1;
				liczba_klikniec++;	
				zapiszdotb(9);
				miejscetb = 0;
				przechow();								
				RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);							
		  }
		  		  		  		 		  									   		  		  		  

		  
		  if((HWND) lPar == hPrzycraz) {
				znak_dzialania = 1;
				naintpierwsza();
				liczba_klikniec = 0;
				miejscetb = 0;
				
		  } else if((HWND) lPar == hPrzycmin) {
				znak_dzialania = 2;
				naintpierwsza();
				liczba_klikniec = 0;
				miejscetb = 0;
				
		  } else  if((HWND) lPar == hPrzycplu) {
				znak_dzialania = 3;
				naintpierwsza();
				liczba_klikniec = 0;
				miejscetb = 0;
				
		  } else if((HWND) lPar == hPrzycpod) {
				znak_dzialania = 4;
				naintpierwsza();
				liczba_klikniec = 0;
				miejscetb = 0;				
		  }		  
		  
		  
		  
		  if((HWND) lPar == hPrzycrow && czywcisniety == 1 && znak_dzialania == 1 ) {
				naintdruga();
				intkoncowy = pierwsza_liczba * druga_liczba;
				nastringkoncowy();
				liczba_klikniec = 0;
				miejscetb = 0;
				RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);	
							
		  } else if((HWND) lPar == hPrzycrow && czywcisniety == 1 && znak_dzialania == 2 ) {
				naintdruga();
				intkoncowy = pierwsza_liczba - druga_liczba;
				nastringkoncowy();
				liczba_klikniec = 0;
				miejscetb = 0;
				RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);	
							
		  }	else if((HWND) lPar == hPrzycrow && czywcisniety == 1 && znak_dzialania == 3 ) {
				naintdruga();
				intkoncowy = pierwsza_liczba + druga_liczba;
				nastringkoncowy();
				liczba_klikniec = 0;
				miejscetb = 0;
				RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);
								
		  }	else if((HWND) lPar == hPrzycrow && czywcisniety == 1 && znak_dzialania == 4 ) {
				naintdruga();
				intkoncowy = pierwsza_liczba / druga_liczba;
				nastringkoncowy();
				liczba_klikniec = 0;
				miejscetb = 0;
				RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);							
		  }	

		  
		  if((HWND) lPar == hPrzyckas) {
				koncowa.erase();				
				liczba_klikniec = 0;
				miejscetb = 0;
				RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);							
		  }
		  
	
      break;
	  
    case WM_DESTROY:
      DestroyWindow(hPrzyc1);
      DestroyWindow(hPrzyc2);
      DestroyWindow(hPrzyc3);
      DestroyWindow(hPrzyc4);
      DestroyWindow(hPrzyc5);
      DestroyWindow(hPrzyc6);
      DestroyWindow(hPrzyc7);
      DestroyWindow(hPrzyc8);
      DestroyWindow(hPrzyc9);
      DestroyWindow(hPrzycraz);
      DestroyWindow(hPrzycmin);
      DestroyWindow(hPrzycplu);
      DestroyWindow(hPrzycpod);
      DestroyWindow(hPrzyckas);
      DestroyWindow(hPrzycrow);
      PostQuitMessage(0);
      break;
    default:
      return DefWindowProc(hwnd,msg,wPar,lPar);
  }
  return 0;
}
//////////////////////////////////////////////////////////////////////////////
//////FUNKCJE//////////////////////////////////
//////////////////////////
//zapisywanie znakod do tablicy
void zapiszdotb(int znak){	
    
	if(miejscetb < 10)	{
	   if(miejscetb < liczba_klikniec)	{
		tablica_na_liczby[miejscetb] = znak;
    	miejscetb++;
 	   }
    }              	
}

//zmiana znakow z tablicy z int na string
void przechow(void) {
	int gog;	
	  for(int k = 0; k < 10; k++) {
		if(miejscetb < liczba_klikniec)	{	
         gog = tablica_na_liczby[k];
         ostringstream ss;
         ss << gog;
         string ddd = ss.str();    
         koncowa = koncowa + ddd;
         miejscetb++;
		}
     }

}	

//zmiana stringu na int (dla pierwszej liczby)
void naintpierwsza(void) {
	
    istringstream iss(koncowa);
    iss >> pierwsza_liczba;
}

//zmiana stringu na int (dla drugiej liczby)
void naintdruga(void) {
	
    istringstream iss(koncowa);
    iss >> druga_liczba;
}

//zmiana koncowego wyniku z int na string
void nastringkoncowy(void) {
	
         ostringstream yy;
         yy << intkoncowy;
         koncowa = yy.str();             
}
