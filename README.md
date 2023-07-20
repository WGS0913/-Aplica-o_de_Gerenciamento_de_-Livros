**Documentação da Aplicação de Gerenciamento de Livros**

**1. Introdução**
Esta aplicação é um simples sistema de gerenciamento de livros em C, que permite ao usuário adicionar informações de livros (nome, autor e data de lançamento), consultar os livros salvos, remover livros pelo nome e sair do programa. Os dados dos livros são armazenados em um arquivo de texto (livros.txt) para persistência entre as execuções da aplicação.

**2. Funcionalidades**
A aplicação possui as seguintes funcionalidades:

**2.1. Adicionar novo livro**
O usuário pode adicionar um novo livro, informando o nome, autor e data de lançamento. Os dados do livro são salvos em uma estrutura `struct Livro` e, em seguida, adicionados ao arquivo "livros.txt" por meio da função `salvarDadosEmArquivo`.

**2.2. Consultar livros salvos**
O usuário pode visualizar os dados de todos os livros que foram previamente salvos no arquivo "livros.txt". Essa funcionalidade é implementada pela função `consultarDadosNoArquivo`.

**2.3. Remover livro por nome**
O usuário pode remover um livro específico pelo nome. Ele informa o nome do livro que deseja remover e a função `removerLivroPorNome` busca esse nome no arquivo "livros.txt". Caso o livro seja encontrado, sua entrada é removida do arquivo e o restante das entradas é salvo em um arquivo temporário. Em seguida, o arquivo original é substituído pelo temporário, refletindo a remoção do livro.

**2.4. Sair do programa**
O usuário pode sair do programa escolhendo a opção "0". Isso encerrará o loop principal e finalizará a execução do programa.

**3. Uso de Arquivo TXT**
Para garantir a persistência dos dados dos livros entre diferentes execuções da aplicação, as informações dos livros (nome, autor e data de lançamento) são armazenadas em um arquivo de texto chamado "livros.txt". Cada livro é separado por uma linha de traços ("--------------------------") para facilitar a leitura dos dados.

**4. Compilação e Execução**
Para compilar o programa, certifique-se de ter um compilador C instalado no seu sistema. Por exemplo, para compilar usando o GCC (GNU Compiler Collection), execute o seguinte comando no terminal:

```
gcc -o gerenciador_livros gerenciador_livros.c
```

Em seguida, para executar a aplicação, digite:

```
./gerenciador_livros
```

A aplicação mostrará um menu de opções onde o usuário pode escolher as funcionalidades desejadas. Após cada operação, o usuário pode pressionar "Enter" para continuar e exibir o menu novamente.

**5. Considerações Finais**
Esta aplicação básica de gerenciamento de livros em C demonstra como usar arquivos de texto para armazenar e recuperar informações. É importante lembrar que esta é uma implementação simples, e em uma aplicação real, seria necessário adicionar tratamento de erros e outras funcionalidades de validação para garantir a integridade dos dados e uma melhor experiência do usuário. Além disso, em aplicações comerciais, seria necessário considerar a possibilidade de utilizar um banco de dados em vez de um arquivo de texto para uma gestão mais eficiente dos dados.
