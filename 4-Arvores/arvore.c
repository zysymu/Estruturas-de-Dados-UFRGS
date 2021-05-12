// TEORIA
/*
- A árvore é um tipo especial de grafo, onde qualquer par de vértices está conectado a apenas uma aresta. É um grafo conexo (existe exatamente um caminho entre quaisquer dois de seus vértices) e acíclico (não possui conexões que fazem ciclos).
- Por serem um tipo especial de grafo, são definidas como um conjunto não vazio de vértices (nós) e arestas que satisfazem: vértice = cada uma das entidades representadas na árvore (depende do problema); arestas = conexão entre dois vértices.
- Um exemplo de árvores é a estrutura de diretórios (uma pasta tem várias pastas e arquivos), podendo chegar em qualquer nó partindo de qualquer outro nó.
- São usadas para representar estruturas hierárquicas não lineares.

- Aplicações: relação de descendência, diagrama hierárquico, campeonatos de esportes, taxonomia, estruturas de diretórios, busca de dados armazenados no computador, representação de espaço de soluções, modelagem de algoritmos.

- A forma de representação mais comum é por meio de um grafo, mas também pode ser representada por conjuntos aninhados (diagramas de Venn).
- Existem vários tipos diferentes de árvores que são utilizados em diferentes aplicações.

- Há algumas propriedades: pai = antecessor imediato de um vértice; filho = sucessor imediato de um vértice; raiz = vértice que não possui pai (é desse nó que se inicia a árvore, fica no topo); nós terminais/folhas = qualquer vértice que não possui filhos (nós que ficam no final da árvore, na parte inferior); nós não-terminais/internos: qualquer vértice que possui pelo menos um filho.

- Caminho em uma árvore é a sequência de vértices de modo que existe sempre uma aresta ligando o vértice anterior com o seguinte. Existe exatamente um caminho entre a raiz e cada um dos nós da árvore.

- Sub-árvores: dado um determinado vértice, cada filho seu é a raiz de uma nova sub-árvore. Qualquer vértice é a raiz de uma sub-árvore consistindo dele e dos nós abaixo dele (desconsideramos o vértice inicial). O grau de um vértice é o número de sub-árvores que um vértice tem.
- Altura da árvore/profundidade: é o comprimento do caminho mais longo da raiz até uma das suas folhas.
- Nível: numa árvore, os vértices são classificados em níveis. O nível é o número de nós no caminho entre o vértice e a raiz (a raiz tem nível 0).
*/
