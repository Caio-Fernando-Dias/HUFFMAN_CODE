# Compactando arquivos texto para binário com o código de Huffman

<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>  
</a> 
</div>

<h2><a>Objetivo</a></h2>

<p>Criar  uma árvore binária que utiliza o código de Huffman para comprimir arquivos para isso:

<ol>
  <li>Contabilizar a recorrência de cada palavre RP(Recorrência da palavra) no arquivo.</li>
  <li>Normalizar a contabilização entre 0 e 1 utilizando a formula -> RP / (max(RP) - min(RP)).</li>
  <li>Montar a árvore com as regras apresentadas por Huffman.</li>
  <li>Troque as palavras pela codificação binária (utlizando booleano para representar 0 e 1).</li>
  <li>Salve o arquivo em formato binário e observe qual foi o ganho de espaço obtido.</li>
</ol>

<h2><a>Explicando o código</a></h2>

<h4><a>huffman.hpp</a></h4>

<p align="center">
<img src="imgs/StructARVORE.png"/>
</p>

<p align="center">
<img src="imgs/StructDADOS.png"/>
</p>

<p align="center">
<img src="imgs/declaracaofuncaojuntanosinsertion.png"/>
</p>

<p>Para armazenarmos os dados da nossa árvore e do código de Huffman trabalhamos com duas estruturas uma chamada DADOS onde possui variáveis do tipo string chamanda palavra que armazena as palavras do texto, um float que armazena a normalização de cada palavra e uma string código que armazena o código de huffman.</p>

<p>Já na nossa estrutura árvore contamos com nossa estrutura DADOS e mais variáveis do tipo árvore que são seus respectivos filhos direito e esquedo como também o seu pai.</p>

<p>Declaração duas funções uma que utilizamos para juntar os nos e outra que é um InsertionSort na qual vou explicar mais para frente.</p>

<h4><a>huffman.cpp</a></h4>

<p align="center">
<img src="imgs/InsertionShort.png"/>
</p>

<p align="center">
<img src="imgs/Funcao_JuntaNos.png"/>
</p>

<p><strong>InsertionShort</strong> -> Na nossa função InsertionShort recebemos o nosso vector do tipo árvore, o intuito dessa função é ordenar o nosso vetor deixando as palavras que tiveram maior recorrência no começo do vetor e as menores no final.</p>

<p><strong>Juntanos</strong> -> Na função Juntanos recebemos nosso vector do tipo árvore declarado na main, o objetivo dessa função é juntar nosso nos da árvore em apenas uma única posição no vetor.</p>

<h4><a>fila.hpp</a></h4>

<p align="center">
<img src="imgs/Declaracao_Fila.png"/>
</p>

<p>Aqui declaramos um simples fila que usaremos para estruturar nossos dados</p>

<p align="center">
<img src="imgs/Funcoes_Aux.png"/>
</p>

<p>Declaração das funções printlargua, geracod, buscapalavracod, jog</p>

<p align="center">
<img src="imgs/Declaracaofuncoestratamento.png"/>
</p>

<h4><a>fila.cpp</a></h4>

<p align="center">
<img src="imgs/Implentacao_Funcoes.png"/>
</p>

<p>Implementação da Fila simples no arquivo cpp.</p>

<p align="center">
<img src="imgs/implementacao_funcao_print_largura.png"/>
</p>

<p><strong>PrintLargura</strong> -> Printa nossa árvore em largura facilitanto assim nossa compreesão.</p>

<p align="center">
<img src="imgs/implementacao_funcao_gerarcod.png"/>
</p>

<p><strong>GeraCod</strong> -> Gera um código para cada nó/palavra do texto.</p>

<p align="center">
<img src="imgs/implementacao_funcao_buscapalavracod.png"/>
</p>

<p align="center">
<img src="imgs/implementacao_funcao_jogacodvetor.png"/>
</p>

<p><strong>JogarCodVetor</strong> -> Joga código da palavra em cada posição no vetor.<p>

<p align="center">
<img src="imgs/implementacao_funcao_buscapalavracod.png"/>
</p>

<p><strong>BuscaPalavraCod</strong> -> Nossa função BuscaPalavraCod é a função que vai ter a palavra do texto e vai retornar o seu respectivo código.</p>

<p align="center">
<img src="imgs/implementacao_funcao_letra1carac.png"/>
</p>

<p><strong>Letra_1carac</strong> -> Lê meu texto e retira todas palavra que possui somento um caracter.</p>

<p align="center">
<img src="imgs/implementacao_funcao_tratastring.png"/>
</p>

<p><strong>TratamentoString</strong> -> Trata nosso texto retirando todos os caracteres especiais.</p>

<h4><a>main.cpp</a></h4>

<p align="center">
<img src="imgs/declaracao_de_vector_e_has.png"/>
</p>

<p>Na nossa main criação uma hash com a função unordered_map onde seu primeiro dado é uma string e o seu segundo um float que armazenam as palavra e suas normalizações.</p>

<p align="center">
<img src="imgs/leituraarquivoetratamento.png">
</p>

<p>Essa parte do código abre o arquivo .txt e lê ele tokenizando com o espaço em cada palavra, por fim filtramos o texto retirando palavras de 1 caracter e caracteres especiais.</p>

<p align="center">
<img src="imgs/passavetorpalavrasphash.png"/>
</p>

<p>Na função seguinte armazenamos nosso vector com as plavras do arquivo txt na hash.</p>

<p align="center">
<img src="imgs/menoremaiorparacalculo.png"/>
</p>

<p>Para facilitar o cálculo de normalização procuramos a palavra com mais recorrência no texto e a palavra com menos recorrência.</p>

<p align="center">
<img src="imgs/passandominhahashparastruct.png"/>
</p>

<p align="center">
<img src="imgs/chamafuncoesmain.png"/>
</p>

<p align="center">
<img src="imgs/criaarquivobinario.png"/>
</p>

<h2><a>Funcionamento</a></h2>

<p align="center">
<img src="imgs/impressao_arvore.png"/>
</p>

<p>Aqui temos a impressão da árvore criada.</p>

<p align="center">
<img src="imgs/tamanhoarquivotxt.png"/>
</p>

<p>Aqui o temanho do arquivo texto.</p>

<p align="center">
<img src="imgs/tamanhoarquivobinario.png"/>
</p>

<p>Aqui temos o arquivo binário compactado gerado reduzindo em 25x o tamanho arquivo texto.</p>

<h2><a>Conclusão</a></h2>


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

<h2><a>Dados</a></h2>

<p>Disciplina: Algoritmos e Estrutura De Dados II 2022-2

Aluno: Caio Fernando Dias

Professor: Michel Pires

Data: 22/09/2022</p>

<h2><a>Contato</a></h2>

<div> 
  <a href="https://www.instagram.com/caio_fer_dias/" target="_blank"><img src="https://img.shields.io/badge/-Instagram-%23E4405F?style=for-the-badge&logo=instagram&logoColor=white" target="_blank"></a>
  <a href = "mailto:caiodias200109@gmail.com"><img src="https://img.shields.io/badge/-Gmail-%23333?style=for-the-badge&logo=gmail&logoColor=white" target="_blank"></a>
  <a href="https://www.linkedin.com/in/caio-dias-8a4962246/" target="_blank"><img src="https://img.shields.io/badge/-LinkedIn-%230077B5?style=for-the-badge&logo=linkedin&logoColor=white" target="_blank"></a>
  <a href="https://t.me/caio_fer_dias" target="_blank"><img src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"></a>
  <a href="https://www.facebook.com/caiofernando.dias.77"><img src="https://img.shields.io/badge/Facebook-1877F2?style=for-the-badge&logo=facebook&logoColor=white"></a>
  <a href="https://github.com/Caio-Fernando-Dias"><img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white"></a>
</div>

