#include <iostream>
#include <iomanip>
#include <string.h>
#include <time.h>
#include <fstream>
#include <unistd.h>

using namespace std;

//Declaração do arquivo e registro

FILE *ArqClientes;
FILE *ArqMembros;
FILE *ArqProd;
FILE *ArqCompras;

typedef struct Cliente {
    char NomeCli[25];
    long int CodigoCli;
    int NumDias, NumPessoas;
    char status;
    struct Data {
        int dia;
        int mes;
        int ano;
    } DataInicio, DataFim;
} RegCliente;
 
RegCliente Cli;

typedef struct Membro {
    char NomeMem[25];
    long int CodigoMem;
    int IdasMem, FreqSmna, IdadeMem;
    char sexo;
    char status;
} RegMembro;
 
RegMembro Mem;

typedef struct Prod {
    char NomeProd[25];
    long int CodigoProd;
    int Qntd;
    float preco;
    struct Data {
        int dia;
        int mes;
        int ano;
    } DataFabic, DataValid;

} RegProd;
 
RegProd Prod;

typedef struct Compras {
    char NomeMemComp[25];
    char NomeProdComp[25];
    long int CodigoComp;
    int Qntd;
    struct Data {
        int dia;
        int mes;
        int ano;
    } DataComp;
    float Preco;
    
} RegCompra;

//Declaração das sub-rotinas

void Instrucoes();
void MenuPrincipal();
void Menu_Edicula();
void CadastraCli();
void ConsultaCli();
void RemoveCli();
void Menu_Arena();
void Cadastrar();
void Consultar();
void LimpaDados();
void CadastraProd();
void ConsultaProd();
void RemoveProd();
void AtualizaProd();
void CadastraComp();
void ConsultaComp();
void RemoveComp();
void AtualizaComp();

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Portuguese");
    
    MenuPrincipal(); 
    return 0;
}

//Sub-rotina "MenuPrincipal"

void MenuPrincipal(){
    int opcao;
	do{
		system("cls");
		cout << "\n                             ***  GRUPO WL - HOLDING DE ENTRETENIMENTO  ***";
    	cout << "\n  --------------------------------------------------------------------------------------------------------------- ";
		cout << "\n           		          ** Menu para seleção de empresas **";
    	cout << "\n  ---------------------------------------------------------------------------------------------------------------\n ";
		cout << "\n  SELECIONE A EMPRESA DESEJADA:\n";
		cout << "\n  1 - SELECIONAR EDÍCULA 'RANCHO WL'";
		cout << "\n  2 - SELECIONAR ARENA WL ";
		cout << "\n  3 - INSTRUÇÕES DE USO ";
		
		cout << "\n\n  0 - SAIR DO SISTEMA\n";
		
		cout << "\n\nESCOLHA UMA OPÇÃO: ";
		cin >> opcao;
		switch(opcao){
			case 1:
				Menu_Edicula();
				break;
			case 2:
				Menu_Arena();
				break;
			case 3:
				Instrucoes();
				break;
		}
	}while(opcao != 0);
}

void Instrucoes(){
	
		system("cls");
		cout << "\n  --------------------------------------------------------------------------------------------------------------- ";
		cout << "\n           		         ** Instruções para uso do sistema **";
    	cout << "\n  ---------------------------------------------------------------------------------------------------------------\n";
		cout << "\n  INSTRUÇÕES:\n";
		cout << "\n  . Para cadastro de datas, insira os números de maneira espaçada. Ex.:(10 10 2023).\n";
		cout << "\n  . No sistema relacionado a edícula, recomenda-se que a declaração dos usuários estajam aplicadasconforme suas \n    datas de uso. Priorizando estadias mais proximas.\n";
		cout << "\n  . Para evitar bugs no sistema, certifique-se de que os dados estão corretos antes de clicar em ENTER.\n";
		cout << "\n  . O sistema apresenta-se em uma versão beta. Ou seja, tenha um rascunho de papel sempre que possível.\n";
		cout << "\n  . No cadastro de produtos, valores quebrados que teriam vírgula devem ser declarados com pontos. Ex.:(3.50).\n";
		cout << "\n  . Quando for cadastrar uma nova compra, certifique-se de três coisas: o estoque está disponível, tanto membro \n    como produto estão cadastrados e se os dados aplicados no cadastro da compra correspondem aos do membro e do produto.\n";
		cout << "\n  . Na atual versão do sistema, o processo de compras não é automatizado. Portanto, recomenda-se que, ao ser \n    efetuado uma compra, seja feita a atualização do dado de quantidade de estoque do produto. \n";
		cout << "\n  . Qualquer erro, instabilidade ou dúvidads com relação ao sistema, o desenvolvedor estará a disposição em \n    receber feedbacks.\n\n";
		
		cout << "\n\n";
		cout << "  RETORNAR AO MENU INICIAL - Clique Enter...";
		system("pause>>null");
}

//Sub-rotina "Menu_Arena"

void Menu_Arena(){
    int opcao;
	do{
		system("cls");
		cout << "\n                             ***  ARENA WL - BEACH TENNIS  ***";
    	cout << "\n  ----------------------------------------------------------------------------------------- ";
		cout << "\n           		       ** Configurações de membros **";
    	cout << "\n  -----------------------------------------------------------------------------------------\n ";
		cout << "\n  1 - CADASTRAR NOVO MEMBRO";
		cout << "\n  2 - CONSULTAR MEMBROS";
		cout << "\n  3 - REMOVER MEMBRO\n";
		cout << "\n  ----------------------------------------------------------------------------------------- ";
		cout << "\n           		       ** Configurações de estoque **";
    	cout << "\n  -----------------------------------------------------------------------------------------\n";
    	cout << "\n  4 - CADASTRAR PRODUTOS";
		cout << "\n  5 - CONSULTAR PRODUTOS";
		cout << "\n  6 - REMOVER PRODUTO";
		cout << "\n  7 - ATUALIZAR DADOS DE PRODUTO\n";
		cout << "\n  ----------------------------------------------------------------------------------------- ";
		cout << "\n           		       ** Configurações de compras **";
    	cout << "\n  -----------------------------------------------------------------------------------------\n";
    	cout << "\n  8 - CADASTRAR NOVA COMPRA";
		cout << "\n  9 - CONSULTAR COMPRAS";
		cout << "\n  10 - REMOVER COMPRA";
		cout << "\n  11 - ATUALIZAR DADOS DE COMPRA\n";


		cout << "\n  0 - RETORNAR AO MENU INICIAL\n";
		
		cout << "\n\nESCOLHA UMA OPÇÃO: ";
		cin >> opcao;
		switch(opcao){
			case 1:
				Cadastrar();
				break;
			case 2:
				Consultar();
				break;
			case 3:
				LimpaDados();
				break;
			case 4:
				CadastraProd();
				break;
			case 5:
				ConsultaProd();
				break;
			case 6:
				RemoveProd();
				break;
			case 7:
				AtualizaProd();
				break;
			case 8:
				CadastraComp();
				break;
			case 9:
				ConsultaComp();
				break;
			case 10:
				RemoveComp();
				break;
			case 11:
				AtualizaComp();
				break;
				} 
	}while(opcao != 0);
}

//Sub-rotina "Menu_Edicula"

void Menu_Edicula(){
    int opcao;
	do{
		system("cls");
		cout << "\n                             ***  RANCHO WL - EDÍCULA  ***";
    	cout << "\n  ----------------------------------------------------------------------------------------- ";
		cout << "\n           		         ** MENU DE OPÇÕES **";
    	cout << "\n  -----------------------------------------------------------------------------------------\n ";
		cout << "\n  1 - CADASTRAR NOVO CLIENTE";
		cout << "\n  2 - CONSULTAR CÇIENTES";
		cout << "\n  3 - REMOVER CLIENTE";
		
		cout << "\n\n  0 - RETORNAR AO MENU INICIAL\n";

		cout << "\n\nESCOLHA UMA OPÇÃO: ";
		cin >> opcao;
		switch(opcao){
			case 1:
				CadastraCli();
				break;
			case 2:
				ConsultaCli();
				break;
			case 3:
				RemoveCli();
				break;
		}
	} while(opcao != 0);
}

//Função para a busca de clientes

long int Busca_Clientes(int cod){		
	char opcao;  
	RegCliente Cli; 	
	
	ArqClientes = fopen("Clientes.dat","rb");

	system("cls");
	if (ArqClientes == NULL) {	
	    cout << "ERRO NA ABERTURA DO ARQUIVO - Enter continuar...\n"; 
	    system("pause"); 	    
	    exit(1);
	}
  	while (fread (&Cli, sizeof(Cli), 1, ArqClientes) != NULL){
	   if (Cli.CodigoCli == cod){
	   	  int posicao = ftell(ArqClientes) - sizeof(Cli);
	   	  fclose(ArqClientes);
	   	  return posicao;
	   }
	}
    fclose (ArqClientes);
    return -1;
}

//Função para busca de Membros

long int Busca_Membro(int cod){		
	char opcao;  
	RegMembro Mem; 	
	
	ArqMembros = fopen("Membros.dat","rb");
	
	system("cls");
	if (ArqMembros == NULL) {	
	    cout << "ERRO NA ABERTURA DO ARQUIVO - Enter continuar...\n"; 
	    system("pause"); 	    
	    exit(1);
	}
  	while (fread (&Mem, sizeof(Mem), 1, ArqMembros) != NULL){
	   if (Mem.CodigoMem == cod){
	   	  int posicao = ftell(ArqMembros) - sizeof(Mem);
	   	  fclose(ArqMembros);
	   	  return posicao;
	   }
	}
    fclose (ArqMembros);
    return -1;
}

//Função para busca de Produtos

long int Busca_Prod(int cod){		
	char opcao;  
	RegProd Prod; 	
	
	ArqProd = fopen("Produtos.dat","rb");

	system("cls");
	if (ArqProd == NULL) {	
	    cout << "ERRO NA ABERTURA DO ARQUIVO - Enter continuar...\n"; 
	    system("pause"); 	    
	    exit(1);
	}
  	while (fread (&Prod, sizeof(Prod), 1, ArqProd) != NULL){
	   if (Prod.CodigoProd == cod){
	   	  int posicao = ftell(ArqProd) - sizeof(Prod);
	   	  fclose(ArqProd);
	   	  return posicao;
	   }
	}
    fclose (ArqProd);
    return -1;
}

//Função para busca de compras

long int Busca_Compra(int cod){		
	char opcao;  
	RegCompra Comp; 	
	
	ArqCompras = fopen("Compras.dat","rb");
	
	system("cls");
	if (ArqCompras == NULL) {	
	    cout << "ERRO NA ABERTURA DO ARQUIVO - Enter continuar...\n"; 
	    system("pause"); 	    
	    exit(1);
	}
  	while (fread (&Comp, sizeof(Comp), 1, ArqCompras) != NULL){
	   if (Comp.CodigoComp == cod){
	   	  int posicao = ftell(ArqCompras) - sizeof(Comp);
	   	  fclose(ArqCompras);
	   	  return posicao;
	   }
	}
    fclose (ArqCompras);
    return -1;
}

//Sub-rotina "CadastraCli"

void CadastraCli(){
    char opcao;
    RegCliente Cli;
    
    ArqClientes = fopen("Clientes.dat", "ab");
    
    system("cls");
    if (ArqClientes == NULL){
        cout << "ERRO NA ABERTURA DO ARQUIVO - Enter continuar...\n";
        system("pause");
        exit (1);
    }
    do{
    	cout << "\n\nINSIRA OS DADOS ABAIXO:";
    	
        cout << "\n\nCPF:";
        cin >> Cli.CodigoCli;
        
        cout << "Nome:";
        cin >> Cli.NomeCli;
        
        cout << "Diárias:";
        cin >> Cli.NumDias;
        
        cout << "Data de início: ";
        int dia, mes, ano;
        cin >> dia >> mes >> ano;
        Cli.DataInicio.dia = dia;
        Cli.DataInicio.mes = mes;
        Cli.DataInicio.ano = ano;
        
        cout << "Data de fim: ";
        cin >> dia >> mes >> ano;
        Cli.DataFim.dia = dia;
        Cli.DataFim.mes = mes;
        Cli.DataFim.ano = ano;
        
        cout << "Nº de pessoas:";
        cin >> Cli.NumPessoas;
        
        cout << "Status(P/NP):";
        cin >> Cli.status;
        
        fwrite (&Cli, sizeof(Cli), 1, ArqClientes);
        
        cout << "\n\nGostaria de adicionar outro cliente (S/N)?";
        cin >> opcao;
        
    }while (toupper(opcao) == 'S');
    fclose (ArqClientes);    
}

//Sub-rotina "Cadastrar"

void Cadastrar(){
    char opcao;
    RegMembro Mem;
    
    ArqMembros = fopen("Membros.dat", "ab");
    
    system("cls");
    if (ArqMembros == NULL){
        cout << "ERRO NA ABERTURA DO ARQUIVO - Enter continuar...\n";
        system("pause");
        exit (1);
    }
    do{
    	cout << "\n\nINSIRA OS DADOS ABAIXO:";

        cout << "\n\nCPF:";
        cin >> Mem.CodigoMem;
        
        cout << "Nome:";
        cin >> Mem.NomeMem;
        
        cout << "Idade:";
        cin >> Mem.IdadeMem;
        
        cout << "Sexo(M/F):";
        cin >> Mem.sexo;       
        
        cout << "Idas:";
        cin >> Mem.IdasMem;    
        
        cout << "Status(P/NP):";
        cin >> Mem.status;
        
        fwrite (&Mem, sizeof(Mem), 1, ArqMembros);
        
        cout << "\n\nGostaria de adicionar outro cliente (S/N)?";
        cin >> opcao;
        
    }while (toupper(opcao) == 'S');
    fclose (ArqMembros);    
}

//Sub-rotina "CadastraProd"

void CadastraProd(){
    char opcao;
    RegProd Prod;
    
    ArqProd = fopen("Produtos.dat", "ab");
    
    system("cls");
    if (ArqProd == NULL){
        cout << "ERRO NA ABERTURA DO ARQUIVO - Enter continuar...\n";
        system("pause");
        exit (1);
    }
    do{
    	cout << "\n\nINSIRA OS DADOS ABAIXO:";
    	
        cout << "\n\nCódigo:";
        cin >> Prod.CodigoProd;
        
        cout << "Nome:";
        cin >> Prod.NomeProd;
        
        cout << "Fabricação: ";
        int dia, mes, ano;
        cin >> dia >> mes >> ano;
        Prod.DataFabic.dia = dia;
        Prod.DataFabic.mes = mes;
        Prod.DataFabic.ano = ano;
        
        cout << "Validade: ";
        cin >> dia >> mes >> ano;
        Prod.DataValid.dia = dia;
        Prod.DataValid.mes = mes;
        Prod.DataValid.ano = ano;
        
        cout << "Quantidade:";
        cin >> Prod.Qntd;    
        
        cout << "Preço:";
        cin >> Prod.preco;
        
        fwrite (&Prod, sizeof(Prod), 1, ArqProd);
        
        cout << "\n\nGostaria de adicionar outro produto (S/N)?";
        cin >> opcao;
        
    }while (toupper(opcao) == 'S');
    fclose (ArqProd);    
}

//Sub-rotina "CadastraComp"

void CadastraComp(){
    char opcao;
    RegCompra Comp;
    
    ArqCompras = fopen("Compras.dat", "ab");
    
    system("cls");
    if (ArqCompras == NULL){
        cout << "ERRO NA ABERTURA DO ARQUIVO - Enter continuar...\n";
        system("pause");
        exit (1);
    }
    do{
    	cout << "\n\nINSIRA OS DADOS ABAIXO:";

        cout << "\n\nCódigo da compra: ";
        cin >> Comp.CodigoComp;
        
        cout << "Produto:";
        cin >> Comp.NomeProdComp;
        
        cout << "Comprador:";
        cin >> Comp.NomeMemComp;
        
        cout << "Data de compra: ";
        int dia, mes, ano;
        cin >> dia >> mes >> ano;
        Comp.DataComp.dia = dia;
        Comp.DataComp.mes = mes;
        Comp.DataComp.ano = ano;
        
        cout << "Quantidade:";
        cin >> Comp.Qntd;    
        
        cout << "Preço:";
        cin >> Comp.Preco;
        
        fwrite (&Comp, sizeof(Comp), 1, ArqCompras);
        
        cout << "\n\nGostaria de cadastrar uma nova compra? (S/N)?";
        cin >> opcao;
        
    }while (toupper(opcao) == 'S');
    fclose (ArqCompras);    
}

//Sub-rotina "ConsultaCli"

void ConsultaCli(){
    char opcao;
    RegCliente Cli;
    
    ArqClientes = fopen("Clientes.dat", "rb");
    
    system("cls");
    if (ArqClientes == NULL){
        cout << "ERRO NA ABERTURA DO ARQUIVO - Enter continuar...\n";
        system("pause");
        exit (1);
    }
    system("cls");
    cout << "\n                             ***  CLIENTES CADASTRADOS  ***";
    cout << "\n  -----------------------------------------------------------------------------------------\n";
    cout << setw(10) << right << "Código";                
	cout << setw(6) << "Nome";
    cout << setw(10) << "Diárias";
	cout << setw(18) << "Data de início";
	cout << setw(18) << "Data de término";              
	cout << setw(16) << "Nº de pessoas";
    cout << setw(8) << right << "Status";
    cout << "\n  ----------------------------------------------------------------------------------------- ";
        
    while (fread(&Cli, sizeof(Cli), 1, ArqClientes) != NULL){
        cout << "\n";
        cout << setw(10) << right << Cli.CodigoCli;                
		cout << setw(6) << Cli.NomeCli;
        cout << setw(7) << Cli.NumDias;
		cout << setw(11) << Cli.DataInicio.dia <<"/"<< Cli.DataInicio.mes <<"/"<< Cli.DataInicio.ano;
		cout << setw(9) << Cli.DataFim.dia <<"/"<< Cli.DataFim.mes <<"/"<< Cli.DataFim.ano;               
		cout << setw(13) << Cli.NumPessoas;
        cout << setw(12) << right << Cli.status;

    }
    cout << "\n\n";
    system("pause");
    fclose(ArqClientes);
}

//Sub-rotina "Consultar"

void Consultar(){
    char opcao;
    RegMembro Mem;
    
    ArqMembros = fopen("Membros.dat", "rb");
    
	system("cls");
    if (ArqMembros == NULL){
        cout << "ERRO NA ABERTURA DO ARQUIVO - Enter continuar...\n";
        system("pause");
        exit (1);
    }
    cout << "\n                 ***  MEMROS CADASTRADOS  ***";
    cout << "\n  ---------------------------------------------------------------\n";
    cout << setw(10) << right << "Código";                
	cout << setw(6) << "Nome";
    cout << setw(8) << "Idade";
	cout << setw(12) << "Sexo(M/F)";
	cout << setw(6) << "Idas";              
	cout << setw(13) << "Frequência";
    cout << setw(8) << right << "Status";
    cout << "\n  --------------------------------------------------------------- ";
        
    while (fread(&Mem, sizeof(Mem), 1, ArqMembros) != NULL){
        cout << "\n";
        cout << setw(8) << right << Mem.CodigoMem;                
		cout << setw(8) << Mem.NomeMem;
        cout << setw(6) << Mem.IdadeMem;
		cout << setw(10) << Mem.sexo;
		cout << setw(9) << Mem.IdasMem;        
		cout << setw(10) << Mem.IdasMem/7;
        cout << setw(9) << right << Mem.status;
    }
    cout << "\n\n";
    system("pause>>null");

    fclose(ArqMembros);
}

//Sub-rotina "ConsultaProd"

void ConsultaProd(){
    char opcao;
    
    ArqProd = fopen("Produtos.dat", "rb");
    
    system("cls");
    if (ArqProd == NULL){
        cout << "ERRO NA ABERTURA DO ARQUIVO - Enter continuar...\n";
        system("pause");
        exit (1);
    }
    system("cls");
    cout << "\n                             ***  PRODUTOS CADASTRADOS  ***";
    cout << "\n  -----------------------------------------------------------------------------------------\n";
    cout << setw(10) << right << "Código";                
	cout << setw(9) << "Nome";
	cout << setw(18) << "Fabricação";
	cout << setw(14) << "Validade";              
	cout << setw(16) << "Quantidade";
    cout << setw(12) << right << "Preço";
    cout << "\n  ----------------------------------------------------------------------------------------- ";
        
    while (fread(&Prod, sizeof(Prod), 1, ArqProd) != NULL){
        cout << "\n";
        cout << setw(10) << right << Prod.CodigoProd;                
		cout << setw(10) << Prod.NomeProd;
		cout << setw(10) << Prod.DataFabic.dia <<"/"<< Prod.DataFabic.mes <<"/"<< Prod.DataFabic.ano;
		cout << setw(7) << Prod.DataValid.dia <<"/"<< Prod.DataValid.mes <<"/"<< Prod.DataValid.ano;               
		cout << setw(11) << Prod.Qntd;
        cout << setw(16) << right << "R$" << Prod.preco;
    }
    cout << "\n\n";
    system("pause");
    fclose(ArqProd);
}

//Sub-rotina "ConsultaComp"

void ConsultaComp(){
    char opcao;
    RegCompra Comp;
    
    ArqCompras = fopen("Compras.dat", "rb");
    
    system("cls");
    if (ArqCompras == NULL){
        cout << "ERRO NA ABERTURA DO ARQUIVO - Enter continuar...\n";
        system("pause");
        exit (1);
    }
    cout << "\n                                         ***  COMPRAS CADASTRADOS  ***";
    cout << "\n----------------------------------------------------------------------------------------------------------------------------\n";
    cout << setw(10) << right << "Código da Compra";                
	cout << setw(12) << "Produto";
    cout << setw(15) << "Comprador";        
    cout << setw(19) << "Data da compra";
	cout << setw(14) << "Quantidade";
	cout << setw(11) << "Preço";
    cout << setw(34) << right << "Valor total";
    cout << "\n----------------------------------------------------------------------------------------------------------------------------\n";
        
    while (fread(&Comp, sizeof(Comp), 1, ArqCompras) != NULL){
        cout << "\n";
        cout << setw(8) << right << Comp.CodigoComp;                
		cout << setw(19) << Comp.NomeProdComp;
		cout << setw(13) << Comp.NomeMemComp;
		cout << setw(11) << Comp.DataComp.dia <<"/"<< Comp.DataComp.mes <<"/"<< Comp.DataComp.ano;      
		cout << setw(11) << Comp.Qntd;
		cout << setw(14) << "R$" << Comp.Preco;
        cout << setw(30) << right << "R$" << Comp.Preco*Comp.Qntd;
    }
    cout << "\n\n";
    system("pause>>null");

    fclose(ArqCompras);
}

//Sub-rotina "RemoveCli"

void RemoveCli(){
    RegCliente Cli;
	int c;
	long int pos;
	char op;
	system("cls");
	
	cout << "\n\nQual cliente deseja remover - Código: ";
	cin >> c;
	
	pos = Busca_Clientes(c);
	
	if (pos == -1){
	   	cout << "\nCLIENTE NÃO CADASTRADO - Enter continuar...";
	    system("pause>>null");
    }
	else{
		ArqClientes = fopen("Clientes.dat","rb"); 
    	
		fseek(ArqClientes, pos, 0);
		
    	fread (&Cli, sizeof(Cli), 1, ArqClientes);
		system("cls");
	    
		cout << "\n **** DADOS DO CLIENTE ****";
		cout << "\n--------------------------- ";
		cout << "\n CPF: " << Cli.CodigoCli;
		cout << "\n Nome: " << Cli.NomeCli;
		cout << "\n Diárias: " << Cli.NumDias;
		cout << "\n Data de início: " << Cli.DataInicio.dia <<"/"<< Cli.DataInicio.mes <<"/"<< Cli.DataInicio.ano;
		cout << "\n Data de fim: " << Cli.DataFim.dia <<"/"<< Cli.DataFim.mes <<"/"<< Cli.DataFim.ano;
		cout << "\n Nº de pessoas: " << Cli.NumPessoas;
	   	cout << "\n Status(P/NP): " << Cli.status;
		
		cout << "\n\n CONFIRMA REMOÇÃO - S (sim): ";
		cin >> op;
		
		if (toupper(op) != 'S'){
			
			system("cls");
			cout << "\n REMOÇÃO ABORTADA - Enter continuar...";
			system("pause>>null");
			return;
		}
		else{
			FILE *PontAuxCli; 
			
			PontAuxCli = fopen("AuxiliaCli.dat","wb");
			rewind(ArqClientes); 
			
			int i = 0;
			while (i < pos){
				
			fread (&Cli, sizeof(Cli), 1, ArqClientes); 
			memcpy(PontAuxCli, &Cli, sizeof(Cli));
			}
			fseek(ArqClientes, pos + sizeof(Cli), 0);
			while (fread (&Cli, sizeof(Cli), 1, ArqClientes) != NULL){
			    fwrite (&Cli, sizeof(Cli), 1, PontAuxCli);	     
			}	    
		    fclose(ArqClientes);
		    fclose(PontAuxCli);
		    
	    	ArqClientes = fopen("Clientes.dat","wb"); 
    		PontAuxCli = fopen("AuxiliaCli.dat","rb"); 
	    	

		     while (fread (&Cli, sizeof(Cli), 1, PontAuxCli) != NULL){
			    fwrite (&Cli, sizeof(Cli), 1, ArqClientes);   
		    }
		    system("cls");
		    cout << "\n CLIENTE REMOVIDO COM SUCESSO - Enter para continuar...";
	    	system("pause>>null");
			
		    fclose(ArqClientes);
		    fclose(PontAuxCli);
		}
	}
}

//Sub-rotina "LimpaDados"

void LimpaDados(){
	RegMembro Mem;
	int c;
	long int pos;
	char opcao;
	system("cls");
	
	cout << "\n\nDigite o código do membro que deseja remover: ";
	cin >> c;
	
	pos = Busca_Membro(c);
	
	if (pos == -1){
	   cout << "\nMEMBRO NÃO CADASTRADO - Enter continuar...";
	   system("pause>>null");
    }
	else{
		
		ArqMembros = fopen("Membros.dat","rb"); 
    	
		fseek(ArqMembros, pos, 0);
		
    	fread (&Mem, sizeof(Mem), 1, ArqMembros);
		system("cls");
	    
		cout << "\n **** DADOS DO MEMBRO ****";
		cout << "\n--------------------------- ";
		cout << "\n CPF: " << Mem.CodigoMem;
		cout << "\n Nome: " << Mem.NomeMem;
		cout << "\n Idade: " << Mem.IdadeMem;
		cout << "\n Sexo(M/F): " << Mem.sexo;
	   	cout << "\n Idas: " << Mem.status;
		
		cout << "\n\n CONFIRMA REMOÇÃO(S/N): ";
		cin >> opcao;
		
		if (toupper(opcao) != 'S'){
			
			system("cls");
			cout << "\n REMOÇÃO ABORTADA - Enter continuar...";
			system("pause>>null");
			return;
		}
		else{
			FILE *PontAuxMem; 
			PontAuxMem = fopen("AuxiliarMem.dat","wb");
			rewind(ArqMembros); 
			
			int i = 0;
			while (i < pos){
			fread (&Mem, sizeof(Mem), 1, ArqMembros); 
				
			memcpy(PontAuxMem, &Mem, sizeof(Mem));
			
			}
			fseek(ArqMembros, pos + sizeof(Mem), 0);
			while (fread (&Mem, sizeof(Mem), 1, ArqMembros) != NULL){
			fwrite (&Mem, sizeof(Mem), 1, PontAuxMem);      
		}
		fclose(ArqMembros);
		fclose(PontAuxMem);
		
	    ArqMembros = fopen("Membros.dat","wb"); 
        PontAuxMem = fopen("AuxiliarMem.dat","rb"); 
	    	
		while (fread (&Mem, sizeof(Mem), 1, PontAuxMem) != NULL){
			fwrite (&Mem, sizeof(Mem), 1, ArqMembros);   
		}
		system("cls");
		cout << "\n MEMBRO REMOVIDO COM SUCESSO - Enter continuar...";
	    system("pause>>null");
			
		fclose(ArqMembros);
		fclose(PontAuxMem);
		}
	}
}

//Sub-rotina "RemoveProd"

void RemoveProd(){
	RegProd Prod;
	int c;
	long int pos;
	char opcao;
	system("cls");
	
	cout << "\n\nDigite o código do produto que deseja remover: ";
	cin >> c;
	
	pos = Busca_Prod(c);
	
	if (pos == -1){
	   cout << "\nPRODUTO NÃO CADASTRADO - Enter continuar...";
	    system("pause>>null");
    }
	else{
		
		ArqProd = fopen("Produtos.dat","rb"); 
    	
		fseek(ArqProd, pos, 0);
		
    	fread (&Prod, sizeof(Prod), 1, ArqProd);
		system("cls");
	    
		cout << "\n **** DADOS DO PRODUTO ****";
		cout << "\n---------------------------- ";
		cout << "\n Código: " << Prod.CodigoProd;
		cout << "\n Nome: " << Prod.NomeProd;
		cout << "\n Fabricação: " << Prod.DataFabic.dia <<"/"<< Prod.DataFabic.mes <<"/"<< Prod.DataFabic.ano;
		cout << "\n Validade: " << Prod.DataValid.dia <<"/"<< Prod.DataValid.mes <<"/"<< Prod.DataValid.ano;
	   	cout << "\n Quantidade: " << Prod.Qntd;
	   	cout << "\n Preço: " << "R$" << Prod.preco;
		
		cout << "\n\n CONFIRMA REMOÇÃO(S/N): ";
		cin >> opcao;
		
		if (toupper(opcao) != 'S'){
			
			system("cls");
			cout << "\n REMOÇÃO ABORTADA - Enter continuar...";
			system("pause>>null");
			return;
		}
		else{
			FILE *PontAuxProd; 
			PontAuxProd = fopen("AuxiliarProd.dat","wb");
			rewind(ArqProd); 
			
			int i = 0;
			while (i < pos){
			fread (&Prod, sizeof(Prod), 1, ArqProd); 
				
			memcpy(PontAuxProd, &Prod, sizeof(Prod));
			}
			fseek(ArqProd, pos + sizeof(Prod), 0);
			while (fread (&Prod, sizeof(Prod), 1, ArqProd) != NULL){
			fwrite (&Prod, sizeof(Prod), 1, PontAuxProd);      
		}
		fclose(ArqProd);
		fclose(PontAuxProd);
		
	    ArqProd = fopen("Produtos.dat","wb"); 
        PontAuxProd = fopen("AuxiliarProd.dat","rb"); 
	    	
		while (fread (&Prod, sizeof(Prod), 1, PontAuxProd) != NULL){
			fwrite (&Prod, sizeof(Prod), 1, ArqProd);   
		}

		system("cls");
		cout << "\n PRODUTO REMOVIDO COM SUCESSO - Enter continuar...";
	    system("pause>>null");
			
		fclose(ArqProd);
		fclose(PontAuxProd);
		}
	}
}

//Sub-rotina "RemoveComp"

void RemoveComp(){
	RegCompra Comp;
	int c;
	long int pos;
	char opcao;
	system("cls");
	
	cout << "\n\nDigite o código da compra para efetuar a remoção: ";
	cin >> c;
	
	pos = Busca_Compra(c);
	
	if (pos == -1){
	   cout << "\nCOMPRA NÃO CADASTRADA - Enter continuar...";
	   system("pause>>null");
    }
	else{
		
		ArqCompras = fopen("Compras.dat","rb"); 
    	
		fseek(ArqCompras, pos, 0);
		
    	fread (&Comp, sizeof(Comp), 1, ArqCompras);
		system("cls");
	    
		cout << "\n **** DADOS DA COMPRA ****";
		cout << "\n-------------------------------- ";
		cout << "\n Código da compra: " << Comp.CodigoComp;
		cout << "\n Produto: " << Comp.NomeProdComp;
		cout << "\n Comprador: " << Comp.NomeMemComp;
		cout << "\n Data de compra: " << Comp.DataComp.dia <<"/"<< Comp.DataComp.mes <<"/"<< Comp.DataComp.ano;
	   	cout << "\n Quantidade: " << Comp.Qntd;
	   	cout << "\n Preço: " << "R$" << Comp.Preco;
	   	cout << "\n Valor total: " << "R$" << Comp.Preco*Comp.Qntd;
		
		cout << "\n\n CONFIRMA REMOÇÃO(S/N): ";
		cin >> opcao;
		
		if (toupper(opcao) != 'S'){
			
			system("cls");
			cout << "\n REMOÇÃO ABORTADA - Enter continuar...";
			system("pause>>null");
			return;
		}
		else{
			FILE *PontAuxComp; 
			PontAuxComp = fopen("AuxiliarComp.dat","wb");
			rewind(ArqCompras); 
			
			int i = 0;
			while (i < pos){
			fread (&Comp, sizeof(Comp), 1, ArqCompras); 
				
			memcpy(PontAuxComp, &Comp, sizeof(Comp));
			
			}
			fseek(ArqCompras, pos + sizeof(Comp), 0);
			while (fread (&Comp, sizeof(Comp), 1, ArqCompras) != NULL){
			fwrite (&Comp, sizeof(Comp), 1, PontAuxComp);      
		}
		fclose(ArqCompras);
		fclose(PontAuxComp);
		
	    ArqCompras = fopen("Compras.dat","wb"); 
        PontAuxComp = fopen("AuxiliarComp.dat","rb"); 
	    	
		while (fread (&Comp, sizeof(Comp), 1, PontAuxComp) != NULL){
			fwrite (&Comp, sizeof(Comp), 1, ArqCompras);   
		}
		system("cls");
		cout << "\n COMPRA REMOVIDA COM SUCESSO - Enter continuar...";
	    system("pause>>null");
			
		fclose(ArqCompras);
		fclose(PontAuxComp);
		}
	}
}

//Sub-rotina "AtualizaComp"

void AtualizaComp(){
	RegCompra Comp;
	int c;
	long int pos;
	char opcao;
	int opcao_alteracao;
	system("cls");
	
	cout << "\n\nDigite o código da compra para efetuar a alteração: ";
	cin >> c;
	
	pos = Busca_Compra(c);
	
	if (pos == -1){
	   cout << "\nCOMPRA NÃO CADASTRADA - Enter continuar...";
	   system("pause>>null");
    }
	else{
		
		ArqCompras = fopen("Compras.dat","rb"); 
    	
		fseek(ArqCompras, pos, 0);
		
    	fread (&Comp, sizeof(Comp), 1, ArqCompras);
		system("cls");
	    
		cout << "\n **** DADOS DA COMPRA ****";
		cout << "\n-------------------------------- ";
		cout << "\n Código da compra: " << Comp.CodigoComp;
		cout << "\n Produto: " << Comp.NomeProdComp;
		cout << "\n Comprador: " << Comp.NomeMemComp;
		cout << "\n Data de compra: " << Comp.DataComp.dia <<"/"<< Comp.DataComp.mes <<"/"<< Comp.DataComp.ano;
	   	cout << "\n Quantidade: " << Comp.Qntd;
	   	cout << "\n Preço: " << "R$" << Comp.Preco;
	   	cout << "\n Valor total: " << "R$" << Comp.Preco*Comp.Qntd;
		
		cout << "\n\n QUAL DADO DESEJA ALTERAR?\n";
		cout << "\n 1 - Código da compra";
		cout << "\n 2 - Produto";
		cout << "\n 3 - Comprador";
		cout << "\n 4 - Data de compra";
		cout << "\n 5 - Quantidade";
		cout << "\n 6 - Preço";
		cout << "\n\n DIGITE A OPÇÃO DESEJADA: ";
		cin >> opcao_alteracao;
		
		switch(opcao_alteracao){
			case 1:
				cout << "\n\nDIGITE O NOVO CÓDIGO DA COMPRA: ";
				cin >> Comp.CodigoComp;
				break;
			case 2:
				cout << "\n\nDIGITE O NOVO NOME DO PRODUTO: ";
				cin >> Comp.NomeProdComp;
				break;
			case 3:
				cout << "\n\nDIGITE O NOVO NOME DO COMPRADOR: ";
				cin >> Comp.NomeMemComp;
				break;
			case 4:
				cout << "\n\nDIGITE A NOVA DATA DE COMPRA (DD/MM/AAAA): ";
				cin >> Comp.DataComp.dia >> Comp.DataComp.mes >> Comp.DataComp.ano;
				break;
			case 5:
				cout << "\n\nDIGITE A NOVA QUANTIDADE: ";
				cin >> Comp.Qntd;
				break;
			case 6:
				cout << "\n\nDIGITE O NOVO PREÇO: ";
				cin >> Comp.Preco;
				break;
			default:
				cout << "\n\nOPÇÃO INVÁLIDA!";
				break;
		}
		
		cout << "\n\nCONFIRMA ALTERAÇÃO(S/N): ";
		cin >> opcao;
		
		if (toupper(opcao) != 'S'){
			
			system("cls");
			cout << "\n ALTERAÇÃO ABORTADA - Enter continuar...";
			system("pause>>null");
			return;
		}
		else{
			fclose(ArqCompras);
			ArqCompras = fopen("Compras.dat","r+b"); 
			fseek(ArqCompras, pos, 0);
			
			fwrite (&Comp, sizeof(Comp), 1, ArqCompras); 
			
			system("cls");
			cout << "\n COMPRA ALTERADA COM SUCESSO - Enter continuar...";
		    system("pause>>null");
			
			fclose(ArqCompras);
			}
	}
}

//Sub-rotina "AtualizaProd"

void AtualizaProd(){
	RegProd Prod;
	int c;
	long int pos;
	char opcao;
	int opcao_alteracao;
	system("cls");
	
	cout << "\n\nDigite o código do produto para efetuar a alteração: ";
	cin >> c;
	
	pos = Busca_Prod(c);
	
	if (pos == -1){
	   cout << "\nPRODUTO NÃO CADASTRADO - Enter continuar...";
	   system("pause>>null");
    }
	else{
		
		ArqProd = fopen("Produtos.dat","rb"); 
    	
		fseek(ArqProd, pos, 0);
		
    	fread (&Prod, sizeof(Prod), 1, ArqProd);
		system("cls");
	    
		cout << "\n **** DADOS DO PRODUTO ****";
		cout << "\n---------------------------- ";
		cout << "\n Código: " << Prod.CodigoProd;
		cout << "\n Nome: " << Prod.NomeProd;
		cout << "\n Fabricação: " << Prod.DataFabic.dia <<"/"<< Prod.DataFabic.mes <<"/"<< Prod.DataFabic.ano;
		cout << "\n Validade: " << Prod.DataValid.dia <<"/"<< Prod.DataValid.mes <<"/"<< Prod.DataValid.ano;
	   	cout << "\n Quantidade: " << Prod.Qntd;
	   	cout << "\n Preço: " << "R$" << Prod.preco;
		
		cout << "\n\n QUAL DADO DESEJA ALTERAR?";
		cout << "\n 1 - Código do produto";
		cout << "\n 2 - Nome";
		cout << "\n 3 - Data de fabricação";
		cout << "\n 4 - Data de validade";
		cout << "\n 5 - Quantidade";
		cout << "\n 6 - Preço";
		cout << "\n\n DIGITE A OPÇÃO DESEJADA: ";
		cin >> opcao_alteracao;
		
		switch(opcao_alteracao){
			case 1:
				cout << "\n\nDIGITE O NOVO CÓDIGO DO PRODUTO: ";
				cin >> Prod.CodigoProd;
				break;
			case 2:
				cout << "\n\nDIGITE O NOVO NOME DO PRODUTO: ";
				cin >> Prod.NomeProd;
				break;
			case 3:
				cout << "\n\nDIGITE A NOVA DATA DE FABRICAÇÃO (DD/MM/AAAA): ";
				cin >> Prod.DataFabic.dia >> Prod.DataFabic.mes >> Prod.DataFabic.ano;
				break;
			case 4:
				cout << "\n\nDIGITE A NOVA DATA DE VALIDADE (DD/MM/AAAA): ";
				cin >> Prod.DataValid.dia >> Prod.DataValid.mes >> Prod.DataValid.ano;
				break;
			case 5:
				cout << "\n\nDIGITE A NOVA QUANTIDADE: ";
				cin >> Prod.Qntd;
				break;
			case 6:
				cout << "\n\nDIGITE O NOVO PREÇO: ";
				cin >> Prod.preco;
				break;
			default:
				cout << "\n\nOPÇÃO INVÁLIDA!";
				break;
		}
		cout << "\n\n CONFIRMA ALTERAÇÃO(S/N)";
		cin >> opcao;
		
		if (toupper(opcao) != 'S'){
			
			system("cls");
			cout << "\n ALTERAÇÃO ABORTADA - Enter continuar...";
			system("pause>>null");
			return;
		}
		else{
			fclose(ArqProd);
			ArqProd = fopen("Produtos.dat","r+b"); 
			fseek(ArqProd, pos, 0);
			
			fwrite (&Prod, sizeof(Prod), 1, ArqProd); 
			
			system("cls");
			cout << "\n PRODUTO ALTERADO COM SUCESSO - Enter continuar...";
		    system("pause>>null");
			
			fclose(ArqProd);
			}
	}
}
