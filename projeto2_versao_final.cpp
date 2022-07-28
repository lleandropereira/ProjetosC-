//
//  main.cpp
//  Trabalho2
//
//  Created by Leandro Pereira on 15/07/22.
//

#include <iostream>
using namespace std;

int main()
{
    int N, M;
    
    cout<<"Informe a quantidade de candidatos: "; cin>>N;
    cout<<"Informe a quantidade de questoes: "; cin>>M;
    
    int i, j, cont_acerto=0, cont_classificado=0, cont_desclassificado=0;
    char gabarito[M], resposta[N][M];
    string nome[N], melhor_candidato[N];
    float valor_da_questao, nota[N], soma_media=0, perc_classificado=0, perc_desclassificado=0, melhor_nota=0;
    
    for(i=0;i<M;i++)
    {
        do
        {
            cout<<"Informe o gabarito da questao "<<i+1<<": "; cin>>gabarito[i];
            gabarito[i]=toupper(gabarito[i]);
            if(gabarito[i]<'A' or gabarito[i]>'E')
            {
                cout<<"Gabarito invalido. Por favor, tente novamente.\n";
            }
        }while(gabarito[i]<'A' or gabarito[i]>'E');
    }
    
    valor_da_questao=10.0/M; //calculo do valor das questoes
    
    for(j=0;j<N;j++) //entrada dos dados dos candidatos
    {
        cont_acerto=0;
        cout<<"\nNome: "; cin>>nome[j];
        for(i=0;i<M;i++)
        {
            do
            {
                cout<<"Informe a resposta da questao "<<i+1<<": "; cin>>resposta[j][i];
                resposta[j][i] = toupper(resposta[j][i]);
                if(resposta[j][i]==gabarito[i])
                   {
                    cont_acerto++;
                  }
                  if(resposta[j][i]<'A' or resposta[j][i]>'E')
                {
                    cout<<"Resposta invalida. Por favor, tente novamente.\n";
                }
            }while(resposta[j][i]<'A' or resposta[j][i]>'E');
                
        }
        nota[j]=cont_acerto*valor_da_questao; //calculo da nota de cada candidato
        soma_media+=nota[j]; //soma para fazer a media geral
        
        if(nota[j]>=5) //para calcular o percentual de alunos classificados e desclassificados
        {
            cont_classificado++;
        }
        else
        {
            cont_desclassificado++;
        }
    }
    
    //dados de saida
    cout<<"--------------------------------------\n";
    cout<<"Relatorio geral:\n";
    cout<<"Nome\tNota"<<endl; //relatorio do nome e da nota
    for(j=0;j<N;j++)
    {
        cout<<nome[j]<<"\t"<<nota[j]<<endl;
    }
    
    cout<<"--------------------------------------\n";
    
    cout<<"Media geral dos candidatos: "<<soma_media/N<<endl; //media geral dos candidatos
    
    cout<<"--------------------------------------\n";
    
    cout<<"Percentual dos candidatos classificados e desclassificados:\n\n"; //percentual de classificados
    perc_classificado=cont_classificado*100.0/N;
    perc_desclassificado=cont_desclassificado*100.0/N;
    
    cout<<"Percentual de alunos classificados: "<<perc_classificado<<"%";
    cout<<"\nPercentual de alunos desclassificados: "<<perc_desclassificado<<"%"<<endl;
    
    cout<<"--------------------------------------\n";
    
    cout<<"Lista dos candidatos aprovados:\n"; //lista dos aprovados, apenas com o nome
    for(j=0;j<N;j++)
    {
        if(nota[j]>=5)
        {
            cout<<nome[j]<<endl;
        }
    }
    cout<<"--------------------------------------\n";

    cout<<"Melhor nota e nome do candidato:\n"; //candidato com a melhor nota
    for(j=0;j<N;j++)
    {
        if(nota[j]>=melhor_nota)
        {
            melhor_nota=nota[j];
            melhor_candidato[j]=nome[j];
        }
    }
    for(j=0;j<N;j++)
    {
        if(nota[j]==melhor_nota)
        {
            cout<<melhor_candidato[j]<<": ";
            cout<<melhor_nota<<endl;
        }
    }
    
}

