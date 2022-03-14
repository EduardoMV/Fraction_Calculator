#include <iostream>
using namespace std;

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"
#define CYNB "\e[1;96m"

struct racional{
  int num;
  int den;
};

void multiplicar(racional *pa, racional *pb, racional *pc);
void dividir(racional *pa, racional *pb, racional *pc);
void suma(racional *pa, racional *pb, racional *pc);
void resta(racional *pa, racional *pb, racional *pc);
void agregarNumero(racional *pNum);
void imprimir(racional *pNum);


int main() 
{
  racional *pa = new racional;
  racional *pb = new racional;
  racional *pc = new racional;
  
   int casos;
    bool exit = true;
    while(exit)
    {
      cout << endl << REDB "---------MENU--------" NC;
      cout << endl  <<  "Selecciona la opción: " << CYNB "(1 al 5)" << NC << endl;
      cout << NC "1.- Ingresar fracciones" << endl;
      cout << endl  << "2.- Multiplicar" << endl;
      cout << endl << "3.- Dividir" << endl;
      cout << endl << "4.- Sumar" << endl;
      cout << endl << "5.- Restar" << endl;

      cout << "Para salir escriba: 0 " << endl;

      cin >> casos;
      cout << endl << endl; 
      switch(casos)
      {
          case 1:
            agregarNumero(pa);
            agregarNumero(pb);
          break;
          case 2:
            multiplicar(pa,pb,pc);
            imprimir(pc); 
          break;
          case 3:
            dividir(pa, pb, pc);
            imprimir(pc);
          break;
          case 4:
            suma(pa, pb, pc);
            imprimir(pc);
          break;
          case 5:
            resta(pa, pb, pc);
            imprimir(pc);
          break;
          case 0:
            cout << GRN "Gracias por usar la interfaz" << endl;
          exit = false;
          break;
          default:
          cout << "Opción fuera de rango" << endl << endl;
          break;
      }
    }
} 


void agregarNumero(racional *pNum)
{
  for(int i=0; i<1; i++)
     {
       cout << "Ingresa el numerador " << i+1 << ":" << endl;
       cin >> pNum -> num;
       cout << "Ingresa el denominador " << i+1 << ":" << endl;
       cin >> pNum -> den;
     }
}

void multiplicar(racional *pa, racional *pb, racional *pc)
{
  pc -> num = pa -> num * pb -> num;
  pc -> den = pa -> den * pb -> den;
}

void imprimir(racional *pNum)
{
  cout << "Tu resultado es: " << endl;
  cout << pNum -> num << " / " << pNum -> den << endl;
}

void dividir(racional *pa, racional *pb, racional *pc)
{
  pc -> num = pa -> num * pb -> den;
  pc -> den = pa -> den * pb -> num;
}

void suma(racional *pa, racional *pb, racional *pc)
{
  pc -> num = (pa -> num * pb -> den) + (pa -> den * pb -> num);
  pc -> den = pa -> den * pb -> den;
}

void resta(racional *pa, racional *pb, racional *pc)
{
  pc -> num = (pa -> num * pb -> den) - (pa -> den * pb -> num);
  pc -> den = pa -> den * pb -> den;
}