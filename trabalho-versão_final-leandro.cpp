//============================================================================
// Name        : Trabalho-versão1.cpp
// Author      : Leandro
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	
	char continuar='S';

	do
	{
		string empresa, nome_fun, nome_menor_salario="a",nome_maior_salario="b";
		int num_fun, contador, categoria, categoria_maior_salario=0, categoria_menor_salario=0;
		float hora_trabalho, salario_bruto = 0, INSS, salario_descontado_inss = 0, IR = 0, salario_liquido, soma_salario_bruto=0, cont_ir=0, percentual, maior_salario=0, menor_salario=9000000;
	
		cout<<"\nDigite o nome da empresa: "; 
		cin>>empresa;
		cout<<"Digite o numero de funcionarios: ";
		cin>>num_fun;

	for(contador=1;contador<=num_fun;contador++)
	{
		cout<<"\nNome funcionario: "; 
		cin>>nome_fun;
		cout<<"Horas trabalhadas: "; 
		cin>>hora_trabalho;
		
		cout<<"Informe o numero da categoria (entre 1 ate 3): ";
		cin>>categoria;
		while(categoria<1 or categoria>3)
		{
			cout<<"Categoria invalida! Por favor, informe novamente.\n";
			cout<<"Informe o numero da categoria (entre 1 ate 3): ";
			cin>>categoria;

		}

		if(categoria == 1)
		    {
		        salario_bruto = hora_trabalho*15;
		    }
		    else if(categoria == 2)
		    {
		        salario_bruto = hora_trabalho*30;
		    }
		    else if(categoria == 3)
		    {
		        salario_bruto = hora_trabalho*50;
		    }

		    if(hora_trabalho > 160)
		    {
		        if(categoria == 1)
		        {
		            salario_bruto = (160*15)+((hora_trabalho-160)*15)+((hora_trabalho-160)*15*0.5);
		        }  
		        else if(categoria == 2)
		        {
		            salario_bruto = (160*30)+((hora_trabalho-160)*30)+((hora_trabalho-160)*30*0.5);
		        }
		        else if(categoria == 3)
		        {
		            salario_bruto = (160*50)+((hora_trabalho-160)*50)+((hora_trabalho-160)*50*0.5);
		        }
		    }

		    soma_salario_bruto=soma_salario_bruto+salario_bruto;

		    cout<<"\nNome funcionario: "<<nome_fun<<"\n";
		    cout<<"Categoria: "<<categoria<<"\n";

		    INSS = salario_bruto*0.08;
            cout<<"Salario bruto: R$"<<salario_bruto<<"\n";
            cout<<"Desconto INSS: R$"<<INSS<<"\n";
            
            salario_descontado_inss = salario_bruto-INSS;

            if(salario_descontado_inss <= 2500)
            {
                cout<<"Isento desconto imposto de renda.";
                cont_ir++;
            }
            else if(salario_descontado_inss > 2500 and salario_descontado_inss <= 5000)
            {
                IR = salario_descontado_inss*0.1;
                cout<<"Valor desconto imposto de renda: R$"<<IR;
            }
            else if(salario_descontado_inss > 5000 and salario_descontado_inss <= 8000)
            {
                IR = salario_descontado_inss*0.2;
                cout<<"Valor desconto imposto de renda: R$"<<IR;
            }
            else
            {
               IR = salario_descontado_inss*0.3;
               cout<<"Valor desconto imposto de renda: R$"<<IR;
            }
            
            salario_liquido = salario_descontado_inss-IR;
            cout<<"\nSalario liquido: R$"<<salario_liquido<<"\n";  

            if(salario_liquido>maior_salario)
            {
                maior_salario=salario_liquido;
            	nome_maior_salario=nome_fun;
            	categoria_maior_salario=categoria;
            }
            if(salario_liquido<menor_salario)
            {
                menor_salario=salario_liquido;
            	nome_menor_salario=nome_fun;
            	categoria_menor_salario=categoria;

            }
	}
		cout<<"\n==================================================================\n";
		cout<<"Informacoes da empresa";
		cout<<"\n\nEmpresa: "<<empresa;
		cout<<"\nTotal salario bruto: R$"<<soma_salario_bruto;
		cout<<"\nMedia salario bruto: R$"<<soma_salario_bruto/num_fun;

		percentual=cont_ir*100/num_fun;
		cout<<"\nPercentual de funcionarios isentos de IR: "<<percentual<<"%";

		cout<<"\nFuncionario com a menor remuneracao - "<<"\tNome: "<<nome_menor_salario<<"\tCategoria: "<<categoria_menor_salario<<"\tSalario liquido: R$"<<menor_salario;
		cout<<"\nFuncionario com a maior remuneracao - "<<"\tNome: "<<nome_maior_salario<<"\tCategoria: "<<categoria_maior_salario<<"\tSalario liquido: R$"<<maior_salario;
		cout<<"\n==================================================================\n";

	    cout<<"\n\nDeseja executar para outra empresa S/N? ";
		cin>>continuar;
	}while(continuar=='S' or continuar=='s');
		
}




