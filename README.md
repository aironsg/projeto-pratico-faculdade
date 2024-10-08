# projeto-pratico-faculdade
# Sistema de Aprovação de Empréstimos

## Introdução

Este programa em C foi desenvolvido para analisar as informações financeiras fornecidas por clientes e determinar se um empréstimo pode ser aprovado. O sistema considera diversos critérios, como a relação entre renda e valor do empréstimo, histórico de crédito, estabilidade no emprego e valor da entrada.

## Estrutura do Código

### 1. Inclusão de Bibliotecas
- **`stdio.h`**: Necessária para entrada e saída de dados.
- **`string.h`**: Usada para operações com strings.
- **`locale.h`**: Utilizada para configurar o idioma e permitir acentos no texto.

```
#include <stdio.h>
#include <string.h>
#include <locale.h>
```
- **Função `validarRenda`**
    - *Descrição*: Calcula se o valor do empréstimo é adequado com base na renda mensal do cliente. A parcela mensal não pode exceder 30% da renda mensal.
    - *Parâmetros*:
        - `rendaMensal`: Renda mensal do cliente.
        - `tempoEmprestimo`: Tempo de pagamento em meses.
        - `valorEmprestimo`: Valor total do empréstimo solicitado.
    - *Retorno*: Retorna 1 se a parcela for aceitável, ou 0 se não for.

```
int validarRenda(float rendaMensal, int tempoEmprestimo, float valorEmprestimo) {
    float parcela = valorEmprestimo / tempoEmprestimo;
    if(parcela > rendaMensal * 0.3) {
        return 0;
    }
    return 1;
}

```
- **Função `validarHistoricoCredito`**
    - *Descrição*: Verifica o histórico de crédito do cliente.
    - *Parâmetros*:
        - `historicoCredito`: Indica a classificação do histórico de crédito.
    - *Retorno*: Retorna 1 para histórico positivo (1, 2, 3) e 0 para negativo (0).

```
int validarHistoricoCredito(int historicoCredito) {
    return (historicoCredito > 0 && historicoCredito <= 3) ? 1 : 0;
}

```
- **Função `validarEstabilidadeEmprego`**
    - *Descrição*: Avalia a estabilidade no emprego do cliente.
    - *Parâmetros*:
        - `tempoEmprego`: Tempo de trabalho do cliente em meses.
    - *Retorno*: Retorna 1 se o cliente trabalha há pelo menos 24 meses, ou 0 caso contrário.

```
int validarEstabilidadeEmprego(int tempoEmprego) {
    return tempoEmprego >= 24;
}

```
- **Função `validarEntrada`**
    - *Descrição*: Verifica se o valor da entrada é no mínimo 20% do valor do empréstimo.
    - *Parâmetros*:
        - `valorEmprestimo`: Valor total do empréstimo.
        - `valorEntrada`: Valor da entrada oferecida pelo cliente.
    - *Retorno*: Retorna 1 se o valor da entrada for suficiente, ou 0 caso contrário.

```
int validarEntrada(float valorEmprestimo, float valorEntrada) {
    return valorEntrada >= valorEmprestimo * 0.2;
}

```
- **Função `analisarEmprestimo`**
    - *Descrição*: Combina todos os critérios para decidir se o empréstimo será aprovado.
    - *Parâmetros*:
        - `rendaMensal`: Renda mensal do cliente.
        - `tempoEmprestimo`: Tempo de pagamento do empréstimo.
        - `valorEmprestimo`: Valor total do empréstimo.
        - `historicoCredito`: Classificação do histórico de crédito.
        - `tempoEmprego`: Tempo de emprego em meses.
        - `valorEntrada`: Valor da entrada.
    - *Retorno*: Exibe uma mensagem informando se o empréstimo foi aprovado ou rejeitado.

```
void analisarEmprestimo(float rendaMensal,int tempoEmprestimo, float valorEmprestimo, int historicoCredito, int tempoEmprego, float valorEntrada) {
    if (validarRenda(rendaMensal, tempoEmprestimo, valorEmprestimo) &&
        validarHistoricoCredito(historicoCredito) &&
        validarEstabilidadeEmprego(tempoEmprego) &&
        validarEntrada(valorEmprestimo, valorEntrada)) {
        printf("Parabens!!!\nEmpréstimo Aprovado!\n");
    } else {
        printf("Desculpe.\nEmprestimo Rejeitado!\n");
    }
}

```
- **Função `menuHistoricoCredito`**
    - *Descrição*: Exibe um menu para que o usuário selecione a classificação do histórico de crédito.

```
void menuHistoricoCredito() {
    printf("|===========================================================|\n");
    printf("|*************** HISTORICO DE CREDITO **********************|\n");
    printf("|===========================================================|\n");
    printf("|ESCOLHA A OPCAO QUE CARACTERIZA O HISTORICO DO CLIENTE     |\n");
    printf("|1- OTIMO                                                   |\n");
    printf("|2- BOM                                                     |\n");
    printf("|3- RAZOAVEL                                                |\n");
    printf("|0- PESSIMO/NEGATIVADO                                      |\n");
    printf("|===========================================================|\n");
}

```
- **Função `main`**
    - *Descrição*: Função principal que coleta os dados do cliente, chama as funções de validação e exibe o resultado.
    - *Fluxo*:
        1. Configura o idioma para permitir acentos.
        2. Solicita ao usuário a entrada dos dados financeiros e pessoais do cliente.
        3. Chama a função `analisarEmprestimo` para verificar se o empréstimo pode ser aprovado.
```
int main() {
    setlocale(LC_ALL, "pt_BR");

    float rendaMensal, valorEmprestimo, valorEntrada;
    int historicoCredito, tempoEmpregoMeses, tempoEmprestimo;

    printf("INFORME A RENDA MENSAL DO CLIENTE:");
    scanf("%f", &rendaMensal);

    printf("INFORME O VALOR DO EMPRESTIMO SOLICITADO: ");
    scanf("%f", &valorEmprestimo);

    printf("INFORME O TEMPO DO EMPRESTIMO SOLICITADO (MESES): ");
    scanf("%d", &tempoEmprestimo);

    printf("HISTORICO DE CREDITO\n\n");
    menuHistoricoCredito();
    printf("INFORME A OPCAO DESEJADA:");
    scanf("%d", &historicoCredito);

    printf("INFORME O TEMPO DE TRABALHO DO CLIENTE (MESES):");
    scanf("%d", &tempoEmpregoMeses);

    printf("\nO VALOR DA ENTRADA TEM QUE SER MINIMO DE '20%' DO EMPRESTIMO.\n");
    printf("INFORME O VALOR DA ENTRADA: R$");
    scanf("%f", &valorEntrada);

    printf("Analisando dados...\n\n");
    printf("----RESULTADO-----\n");

    analisarEmprestimo(rendaMensal, tempoEmprestimo, valorEmprestimo, historicoCredito, tempoEmpregoMeses, valorEntrada);

    return 0;
}

```

