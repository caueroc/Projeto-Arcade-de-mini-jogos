#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void perguntaEResposta() {
    int resposta, acertos;
    char jogarNovamente;

    do {
        acertos = 0;

        printf("\nPergunta 1: Qual o maior oceano do mundo?\n");
        printf("1. Atlantico\n2. Pacifico\n3. Indico\n4. Artico\n");
        printf("Digite a resposta: ");
        scanf("%d", &resposta);
        if (resposta == 2) {
            printf("Voce acertou! A resposta certa e: Pacifico.\n");
            acertos++;
        } else {
            printf("Voce errou! A resposta certa e: Pacifico.\n");
        }

        printf("\nPergunta 2: Quem pintou a Mona Lisa?\n");
        printf("1. Vincent van Gogh\n2. Pablo Picasso\n3. Leonardo da Vinci\n4. Michelangelo\n");
            printf("Digite a resposta: ");
        scanf("%d", &resposta);
        if (resposta == 3) {
            printf("Voce acertou! A resposta certa e: Leonardo da Vinci.\n");
            acertos++;
        } else {
            printf("Voce errou! A resposta certa e: Leonardo da Vinci.\n");
        }

        printf("\nPergunta 3: Em que ano o homem pisou na Lua?\n");
        printf("1. 1965\n2. 1969\n3. 1972\n4. 1959\n");
        printf("Digite a resposta: ");
        scanf("%d", &resposta);
        if (resposta == 2) {
            printf("Voce acertou! A resposta certa e: 1969.\n");
            acertos++;
        } else {
            printf("Voce errou! A resposta certa e: 1969.\n");
        }

        printf("\nPergunta 4: Qual e a capital do Japao?\n");
        printf("1. Seul\n2. Pequim\n3. Toquio\n4. Bangkok\n");
        printf("Digite a resposta: ");
        scanf("%d", &resposta);
        if (resposta == 3) {
            printf("Voce acertou! A resposta certa e: Toquio.\n");
            acertos++;
        } else {
            printf("Voce errou! A resposta certa e: Toquio.\n");
        }

        printf("\nPergunta 5: Qual e o simbolo quimico do ouro?\n");
        printf("1. Au\n2. Ag\n3. Pb\n4. Fe\n");
        printf("Digite a resposta: ");
        scanf("%d", &resposta);
        if (resposta == 1) {
            printf("Voce acertou! A resposta certa e: Au.\n");
            acertos++;
        } else {
            printf("Voce errou! A resposta certa e: Au.\n");
        }

        printf("Voce acertou %d de 5 questoes!\n", acertos);
        printf("Jogar novamente? (s/n): ");
        scanf(" %c", &jogarNovamente);
    } while (jogarNovamente == 's' || jogarNovamente == 'S');

    printf("Obrigado por jogar!\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void cobraNaCaixa() {
    char nomes[7][20] = {"Indiana", "Lara", "Rick", "Evelyn", "Nathan", "Sofia", "Jack"};
    char jogador1[20], jogador2[20];
    int escolha, jogadorAtual;
    int caixaCobra, caixaBotao;
    char jogarNovamente;

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    do {
        // Mostra as opções de nomes disponíveis
        printf("\nOpcoes de nomes disponiveis:\n");
        for (int i = 0; i < 7; i++) {
            printf("%d - %s\n", i+1, nomes[i]);
        }

        // Jogador 1 escolhe seu nome
        printf("\nJogador 1, escolha seu nome (1-7): ");
        int escolhaNome1;
        scanf("%d", &escolhaNome1);
        while (escolhaNome1 < 1 || escolhaNome1 > 7) {
            printf("Opcao invalida. Escolha um numero entre 1 e 7: ");
            scanf("%d", &escolhaNome1);
        }
        strcpy(jogador1, nomes[escolhaNome1-1]);

        // Jogador 2 escolhe seu nome
        printf("Jogador 2, escolha seu nome (1-7, diferente de %s): ", jogador1);
        int escolhaNome2;
        scanf("%d", &escolhaNome2);
        while (escolhaNome2 < 1 || escolhaNome2 > 7 || strcmp(nomes[escolhaNome2-1], jogador1) == 0) {
            if (escolhaNome2 < 1 || escolhaNome2 > 7) {
                printf("Opcao invalida. Escolha um numero entre 1 e 7: ");
            } else {
                printf("Nome ja escolhido. Escolha outro nome: ");
            }
            scanf("%d", &escolhaNome2);
        }
        strcpy(jogador2, nomes[escolhaNome2-1]);

        printf("\n%s e %s estao presos em uma tumba egipcia!\n", jogador1, jogador2);

        // Sorteia quem começa (0 = Jogador 1, 1 = Jogador 2)
        jogadorAtual = rand() % 2;
        printf("No centro ha 5 caixas. Uma tem o botao para abrir a porta, outra tem uma cobra mortal!\n");
        printf("%s foi sorteado para comecar!\n", jogadorAtual == 0 ? jogador1 : jogador2);

        int jogoAtivo = 1;
        while (jogoAtivo) {
            // Sorteia novas posições para a cobra e o botão a cada turno
            do {
                caixaCobra = rand() % 5 + 1;
                caixaBotao = rand() % 5 + 1;
            } while (caixaCobra == caixaBotao); // Garante que cobra e botão não fiquem na mesma caixa

            printf("\n%s, escolha uma caixa (1 a 5): ", jogadorAtual == 0 ? jogador1 : jogador2);
            scanf("%d", &escolha);

            // Valida a escolha da caixa
            while (escolha < 1 || escolha > 5) {
                printf("Caixa %d nao existe! Escolha uma caixa entre 1 e 5: ", escolha);
                scanf("%d", &escolha);
            }

            if (escolha == caixaCobra) {
                printf("\n%s encontrou a cobra! Fim de jogo. %s perdeu!\n", jogadorAtual == 0 ? jogador1 : jogador2, jogadorAtual == 0 ? jogador1 : jogador2);
                jogoAtivo = 0;
            } else if (escolha == caixaBotao) {
                printf("\n%s encontrou o botao! A porta se abriu, %s venceu!\n", jogadorAtual == 0 ? jogador1 : jogador2, jogadorAtual == 0 ? jogador1 : jogador2);
                jogoAtivo = 0;
            } else {
                printf("\nA caixa estava vazia. As posicoes da cobra e do botao foram alteradas!\n");
                jogadorAtual = 1 - jogadorAtual; // Alterna o jogador
            }
        }

        printf("Desejam jogar novamente? (s/n): ");
        scanf(" %c", &jogarNovamente);
    } while (jogarNovamente == 's' || jogarNovamente == 'S');
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gousmasWar() {
    char reniciar;
    do {
        int furia1 = 1, furia2 = 1, furia3 = 1, furia4 = 1;
        int ativa1 = 1, ativa2 = 1, ativa3 = 1, ativa4 = 1;
        int turno = 0, escolha, atacante, alvo;

        while ((ativa1 || ativa2) && (ativa3 || ativa4)) {
            printf("\nJogador %d, escolha sua acao (1 - Atacar, 2 - Dividir): ", turno + 1);
            scanf("%d", &escolha);

            if (escolha == 1) {
                do {
                    printf("Escolha qual Gousma do jogador %d vai atacar (1 ou 2): ", turno + 1);
                    scanf("%d", &atacante);
                    if ((turno == 0 && ((atacante == 1 && !ativa1) || (atacante == 2 && !ativa2))) ||
                        (turno == 1 && ((atacante == 1 && !ativa3) || (atacante == 2 && !ativa4)))) {
                        printf("Essa Gousma ja foi desintegrada! Escolha outra.\n");
                    } else {
                        break;
                    }
                } while (1);

                printf("Escolha qual Gousma adversaria atacar (1 ou 2): ");
                scanf("%d", &alvo);

                if (turno == 0) {
                    if (atacante == 1 && ativa1 && alvo == 1 && ativa3) {
                        furia3 += furia1;
                    } else if (atacante == 1 && ativa1 && alvo == 2 && ativa4) {
                        furia4 += furia1;
                    } else if (atacante == 2 && ativa2 && alvo == 1 && ativa3) {
                        furia3 += furia2;
                    } else if (atacante == 2 && ativa2 && alvo == 2 && ativa4) {
                        furia4 += furia2;
                    } else {
                        printf("Ataque falhou! Verifique se as Gousmas estao ativas.\n");
                    }
                } else {
                    if (atacante == 1 && ativa3 && alvo == 1 && ativa1) {
                        furia1 += furia3;
                    } else if (atacante == 1 && ativa3 && alvo == 2 && ativa2) {
                        furia2 += furia3;
                    } else if (atacante == 2 && ativa4 && alvo == 1 && ativa1) {
                        furia1 += furia4;
                    } else if (atacante == 2 && ativa4 && alvo == 2 && ativa2) {
                        furia2 += furia4;
                    } else {
                        printf("Ataque falhou! Verifique se as Gousmas estao ativas.\n");
                    }
                }
            }

            if (furia1 > 5) { ativa1 = 0; printf("Gousma 1 do Jogador 1 se desintegrou!\n"); }
            if (furia2 > 5) { ativa2 = 0; printf("Gousma 2 do Jogador 1 se desintegrou!\n"); }
            if (furia3 > 5) { ativa3 = 0; printf("Gousma 1 do Jogador 2 se desintegrou!\n"); }
            if (furia4 > 5) { ativa4 = 0; printf("Gousma 2 do Jogador 2 se desintegrou!\n"); }

            printf("\nFuria atual das Gousmas:\n");
            printf("Jogador 1 \nGousma 1: %d %s\nGousma 2: %d %s\n", furia1, (furia1 > 5 ? "(Desintegrada)" : ""), furia2, (furia2 > 5 ? "(Desintegrada)" : ""));
            printf("\nJogador 2 \nGousma 1: %d %s\nGousma 2: %d %s\n", furia3, (furia3 > 5 ? "(Desintegrada)" : ""), furia4, (furia4 > 5 ? "(Desintegrada)" : ""));

            turno = 1 - turno;
        }

        if (!ativa1 && !ativa2) {
            printf("Jogador 2 venceu!\n");
        } else if (!ativa3 && !ativa4) {
            printf("Jogador 1 venceu!\n");
        }

        printf("Voce deseja jogar novamente? (s/n): ");
        scanf(" %c", &reniciar);
    } while (reniciar == 's' || reniciar == 'S');
}



int main() {
    int opcao;
    do {
        printf("\n=== ARCADE ===\n");
        printf("1 - Pergunta e Resposta\n");
        printf("2 - Cobra na Caixa\n");
        printf("3 - Gousmas War\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                perguntaEResposta();
                break;
            case 2:
                cobraNaCaixa();
                break;
            case 3:
                gousmasWar();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}