# Proposta do Trabalho

Agora que produzimos um trabalho de aquecimento que envolve o caminhamento de matrizes, está na hora de incluir nesse processo execuções mais elaboradas, as quais nos permita analisar o custo computacional de todo o processo. Sendo assim, considere o seguinte problema:

- Um garoto se encontra perdido em um labirinto, o qual é compreendido por nós como sendo uma matriz cujas posição de sua localização é dada por um valor x,y dessa estrutura. Nesse labirinto há paredes que bloqueiam certos passos (#), perigos que consomem parte de sua vida (*) e trajetórias (valores positivos que devem ser subtraídos em 1 a cada passagem).

- Quanto as paredes #, não há muito o que fazer a não ser desviar e continuar a rota. Já os perigos, a cada passada, tende a subtrair 1 de vida de um total de 10. Assim, ao ficar sem pontos de vida o algoritmo deve parar e indicar fim de jogo.

- Ao decorrer do jogo, a cada passo correto sob uma estrada, o garoto consome um item, subtraindo esse do valor que compõe a posição x,y. Gravando nessa o valor resultante. A cada subtração bem sucedida é preciso, essa vai para um banco de vida que cheio (a cada 4 ações bem sucedidas) lhe retorna 1 de vida em seu contador. Contudo, pode haver partes do caminho com zero itens, esses devem continuar sendo utilizados, porém, sem computar pontuação.

- O labirinto deve ser lido do arquivo input.data, o qual apresentará várias matrizes, todas quadráticas conforme exercício anterior. Sua missão é percorrer as matrizes até que todo o caminho percorrido pelo garoto se torne zero ou que ele venha a morrer devido aos perigos enfrentados. No final é preciso apresentar como resultado: (a) quantas casas foram percorridas ao todo; (b) qual a soma de itens consumidos pelo caminho; (c) quantas casas da matriz ficaram sem serem exploradas; (d) quantos perigos foram enfrentados ao decorrer do percurso.

- Para essa atividade, considere selecionar um passo de cada vez de forma aleatória, ou seja, escolha um valor x,y aleatoriamente e vá para ele se possível ou descarte caso seja uma parede. Perigos não são evitados, então, se a posição escolhida for um, enfrente-o. Por fim, a intenção global do problema não é encontrar uma saída, mas sim, tentar consumir o máximo possível de itens até chegar a zerar as possibilidades desse tipo ou morrer tentando.

Qual o custo computacional da sua estratégia randômica? Se mostrou uma boa alternativa de execução?

# Compilação e Execução

O algoritmo disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

<div>

| Comando                |  Função                                                                                           |
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

</div>

# Contato

<div>
<p align="justify"> Eduardo da Silva Torres Grillo </p>
<a href="https://t.me/eduardogrilloo">
<img align="center" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
</div>
