#include <stdio.h>
#include <string.h>
#include <locale.h>

// Função para calcular se o valor do empréstimo é adequado com base na renda
int validarRenda(float rendaMensal, int tempoEmprestimo, float valorEmprestimo) {
    /*
     * Para a liberação do empréstimo, o cliente precisa solicitar um valor
     * de empréstimo cuja parcela não seja superior a 30% do salário base.
     */
    float porcentagem = rendaMensal * 0.3;  // 30% da renda mensal
    float parcela = valorEmprestimo / tempoEmprestimo;  // Cálculo da parcela mensal

    if (parcela > porcentagem) {
        return 0;  // Rejeitado
    }
    return 1;  // Aprovado
}

// Função para validar o histórico de crédito
int validarHistoricoCredito(int historicoCredito) {
    switch (historicoCredito) {
        case 1: return 1;  // Ótimo
        case 2: return 1;  // Bom
        case 3: return 1;  // Razoável
        case 0: return 0;  // Péssimo/Negativado
        default: return 0;  // Caso padrão para valores inesperados
    }
}

// Função para validar estabilidade no emprego
int validarEstabilidadeEmprego(int tempoEmprego) {
    /*
     * O tempo de emprego para o cálculo do empréstimo será em meses.
     * É necessário no mínimo 24 meses de trabalho para a liberação do empréstimo.
     */
    return tempoEmprego >= 24;
}

// Função para validar o valor da entrada
int validarEntrada(float valorEmprestimo, float valorEntrada) {
    // O valor mínimo da entrada será de 20% do valor do empréstimo.
    float porcentagemMinima = valorEmprestimo * 0.2;

    if (valorEntrada >= porcentagemMinima) return 1;  // Aprovado
    return 0;  // Rejeitado
}

// Função principal para análise de aprovação de empréstimo
void analisarEmprestimo(float rendaMensal, int tempoEmprestimo, float valorEmprestimo,
                        int historicoCredito, int tempoEmprego,float valorEntrada) {
    if (validarRenda(rendaMensal, tempoEmprestimo, valorEmprestimo) &&
        validarHistoricoCredito(historicoCredito) &&
        validarEstabilidadeEmprego(tempoEmprego) &&
        validarEntrada(valorEmprestimo, valorEntrada)) {
        printf("Parabens!!!\nEmprestimo Aprovado!\n");
    } else {
        printf("Desculpe.\nEmprestimo Rejeitado!\n");
    }
}

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

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    float rendaMensal, valorEmprestimo, valorEntrada;
    int historicoCredito, tempoEmpregoMeses, tempoEmprestimo;

    // Entrada dos dados do cliente
    printf("INFORME A RENDA MENSAL DO CLIENTE: ");
    scanf("%f", &rendaMensal);
    printf("INFORME O VALOR DO EMPRESTIMO SOLICITADO: ");
    scanf("%f", &valorEmprestimo);
    printf("INFORME O TEMPO DO EMPRESTIMO SOLICITADO (em meses): ");
    scanf("%d", &tempoEmprestimo);
    printf("\nHISTORICO DE CREDITO\n\n");
    menuHistoricoCredito();
    printf("INFORME A OPCAO DESEJADA: ");
    scanf("%d", &historicoCredito);
    printf("INFORME O TEMPO DE TRABALHO DO CLIENTE (em meses): ");
    scanf("%d", &tempoEmpregoMeses);
    printf("\nO VALOR DA ENTRADA TEM QUE SER MINIMO DE '20%' DO EMPRESTIMO.\n");
    printf("INFORME O VALOR DA ENTRADA: R$");
    scanf("%f", &valorEntrada);
    printf("\nAnalisando dados...\n\n");
    printf("----RESULTADO-----\n");
    // Análise do empréstimo
    analisarEmprestimo(rendaMensal, tempoEmprestimo, valorEmprestimo, historicoCredito, tempoEmpregoMeses, valorEntrada);
    return 0;
}
