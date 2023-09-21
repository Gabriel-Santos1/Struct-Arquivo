#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

int menu()
{
    int op;
    cout << ("Opções") << endl;
    cout << ("1. Ler do teclado") << endl;
    cout << ("2. Ler do arquivo") << endl;
    cout << ("3. Exibir Relatorio") << endl;
    cout << ("4. Gravar relatorio") << endl;
    cout << ("0. Sair") << endl;
    cin >> op;
    return op;
}

struct Banco
{
    double salario;
    string nome;
    int idade;
    int filho;
    char sexo;
};

const int QTDPESSOAS = 1;
Banco b[QTDPESSOAS];
double mediaSal, medFil, maior, percent;

void ledoteclado()
{
    double salario;
    string nome;
    int idade, filho;
    char sexo;

    for (int i = 0; i < QTDPESSOAS; i++)
    {
        cout << ("Nome: ") << endl;
        cin >> b[i].nome;
        cout << ("Salario: ") << endl;
        cin >> b[i].salario;
        cout << ("Idade: ") << endl;
        cin >> b[i].idade;
        cout << ("Filhos: ") << endl;
        cin >> b[i].filho;
        cout << ("Sexo F or M: ") << endl;
        cin >> b[i].sexo;
    }
}
void ledoarquivo()
{
    ofstream arquivo("banco.txt");

    for (int i = 0; i < QTDPESSOAS; i++)
    {
        arquivo << b[i].nome;
        arquivo << b[i].salario;
        arquivo << b[i].idade;
        arquivo << b[i].filho;
        arquivo << b[i].sexo;
    }
    arquivo.close();
}
void exibirtela()
{
    for (int i = 0; i < QTDPESSOAS; i++)
    {
        cout << ("Média Salarial: ") << mediaSal << endl;
        cout << ("Média de Filhos: ") << medFil << endl;
        cout << ("Maior: ") << maior << endl;
        cout << ("Porcentagem: ") << percent << endl;
        getchar();
    }
}
void gravarrelatorio()
{
    ofstream arquivo("relatorio.txt");

    arquivo << mediaSal << endl;
    arquivo << medFil << endl;
    arquivo << maior << endl;
    arquivo << percent << endl;

    arquivo.close();
}
void realizarcalc()
{
    mediaSal = 0;
    medFil = 0;
    maior = 0;
    percent = 0;

    for (int i = 0; i < QTDPESSOAS; i++)
    {
        mediaSal += b[i].salario;
        medFil += b[i].filho;

        if (maior < b[i].salario)
        {
            maior = b[i].salario;
        }
        if (b[i].sexo == 'F' && b[i].salario >= 1000)
        {
            percent++;
        }
    }

    mediaSal /= QTDPESSOAS;
    medFil /= QTDPESSOAS;
    percent = (percent / QTDPESSOAS) * 100;
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int op;
    op = menu();
    while (op != 0)
    {
        switch (op)
        {
        case 1:
            system ("cls");      
            ledoteclado();
            ledoarquivo();
            realizarcalc();
            break;

        case 2:
            system ("cls");
            ledoarquivo();
            realizarcalc();
            system ("pause");
            break;

        case 3:
            system ("cls");
            exibirtela();
            system ("pause");
            break;

        case 4:
            system ("cls");
            gravarrelatorio();
            system ("pause");
            break;

        case 5:
            system ("cls");
            realizarcalc();
            system ("pause");
            break;

        case 0:
        {
            cout << ("Saindo...");
        }
        default:
            cout << ("Error 404");
            break;
        }
        op = menu();
    }

    cout << endl
         << endl;
    return 0;
}