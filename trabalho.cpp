#include <iostream>
using namespace std;

int main(){
    int a;
    int b;
    int maximo;
    int minimo;
    double menor;
    double maior;
    double media;
    const double PI = 3.14159;
    double raio;
    double myarray[5] = {};
    int arrayint[10] = {2,5,6,9,3,1,4,7,10,12};
    int mult;

    
    cout << "digite dois valores a calcular:" << endl;
    cin >> a;
    cin >> b;

    cout << "Soma:" << a+b << endl;
    cout << "Diferença: " << a-b << endl;
    cout << "Produto :" << a*b << endl;
    cout << "Quociente: " << a/b << endl;
    cout << "Resto da Divisão: " << a%b << endl;
    
    cin.ignore();
    system("clear || cls");
    
    cout << "Qual o Raio do Circulo: " << endl;
    cin >> raio;
    cout << "Área do Circulo: " << PI * raio * raio << endl;
    
    cin.ignore();
    system("clear ||cls");



    for(int i = 0; i < 5; i++)
    {
        cout << "Nota do Alunos: " << endl;
        cin >> myarray[i];
        media = media + myarray[i];
    }
    menor = myarray[1];
    maior = myarray[1];
    for (int j = 0; j < 5; j++)
    {
        if (myarray[j] < menor)
        {   
            menor = myarray[j];
        }
        if (myarray[j] > maior)
        {
            maior = myarray[j];
        }
        
        
    }
    
    
    cout << "NOTAS:" << endl;
    cout << "Média das notas é: " << media/5 << endl;
    cout << "Menor Nota: " << menor << endl;
    cout << "Maior Nota: " << maior << endl;
    
    cin.ignore();
    system ("clear || cls");

    minimo = arrayint[1];
    maximo = arrayint[1];
    
    for (int k = 0; k < 10; k++)
    {
        if (arrayint[k] < minimo)
        {   
            minimo = arrayint[k];
        }
        if (arrayint[k] > maximo)
        {
            maximo = arrayint[k];
        }
        
    }
    
    cout << "Máximo: " << maximo << " | Mínimo: " << minimo << endl;
    cin.ignore();
    
    system("clear || cls");
    
    cout << "Qual o numero para a Tabuada" << endl;
    cin >> mult;
    
    for(int n = 1; n < 11; n++){
        cout << mult << " X " << n << " = " << mult*n << endl;
    }
    
    
        return 0; 


}
