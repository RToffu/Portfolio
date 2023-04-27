Implementação simples de uma Pilha por meio de Arranjos
introduzindo os seguintes comportamentos:
 1 - Checar se Pilha esta vazia
 2 - Criar uma Pilha
 3 - Inserir elementos no topo da Pilha
 4 - Imprimir conteudo da Pilha
 5 - Remover elementos no topo da Pilha

 A implementacao de uma Pilha por meio de arranjos tem como propriedade os elementos estarem em posicao contigua na memoria
 Porem, isso nao traz muitas vantagens em questao ao acesso de itens no meio da pilha em tempo constante
 pois o comportamento da Pilha foca em operacoes no Topo da Pilha
 Economiza memoria por ter "declaracao implicita dos ponteiros"
 Facil implementação

 Conteudo:
        - PilhaArranjo.c
        - PilhaArranjo.h
        - MainPilhaArranjo.c
        - Pessoa.c
        - Pessoa.h //onde esta a declaracao dos headers "nativos"
 Compilar:
        gcc -o Programa Pessoa.c PilhaArranjo.c MainPilhaArranjo.c

 Executar:
        ./Programa < sampleInput.txt
