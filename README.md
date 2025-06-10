# projetoForcaBublitz

🎮 Jogo da Forca no Terminal

📌 **Descrição do Projeto**
Este projeto consiste em um jogo da forca desenvolvido em linguagem C, com execução via terminal. Mais do que um simples jogo, ele foi concebido com o objetivo de **promover a atividade cerebral e auxiliar na memória cognitiva, especialmente para idosos**, oferecendo uma experiência interativa e desafiadora. O jogo aplica conceitos de lógica de programação, manipulação de arquivos e estruturação de código para construir uma ferramenta divertida e educativa.

🧩 **Funcionalidades Principais**

🎮 **Modos de Jogo**
* **Modo Clássico**: O jogador deve adivinhar a palavra secreta antes de atingir o limite de erros e "enforcar" o boneco. Um modo mais tranquilo para focar na palavra.
* **Modo Contra o Tempo**: O jogador tem um tempo limitado para descobrir cada palavra, tornando o jogo mais rápido e intenso. Ideal para estimular o raciocínio ágil.

🧠 **Sistema de Dificuldade**
* **Normal**: Palavras de tamanho intermediário com um número moderado de tentativas (6 erros permitidos).
* **Difícil**: Palavras mais longas e complexas, com menos tentativas disponíveis (4 erros permitidos).

🎨 **Experiência Visual Aprimorada**
* Representação gráfica do boneco da forca evoluindo no terminal a cada erro cometido.
* Interface organizada para melhorar a legibilidade e facilitar a jogabilidade, tornando-a acessível a diferentes públicos.

📚 **Escolha de Temas**
No início de cada partida, o jogador pode selecionar uma categoria temática, o que torna cada jogo único e mais divertido. Os temas disponíveis são:
* Animais
* Filmes
* Países
* **Novelas Antigas**: Um tema especialmente adicionado para evocar lembranças e estimular a memória de longo prazo em públicos específicos, como idosos.

🛠 **Tecnologias e Conceitos Utilizados**
* Linguagem C
* Terminal (CLI)
* Lógica de programação
* Manipulação de arquivos
* Estruturas condicionais e de repetição
* Funções e modularização de código

🎯 **Objetivo**
Criar um jogo interativo e envolvente que não apenas consolide conhecimentos em programação C, mas que também sirva como uma ferramenta lúdica para **estimular a memória e a capacidade cognitiva, com foco no público idoso**, promovendo a prática de conceitos fundamentais de forma divertida.

---

### **Como Executar o Projeto**

Para rodar o Jogo da Forca no seu computador, siga os passos abaixo:

**Pré-requisitos:**
* Um compilador C (como o GCC - GNU Compiler Collection).
    * No Windows, você pode instalar o [MinGW-w64](https://mingw-w64.org/doku.php/download).
    * No Linux (Ubuntu/Debian), instale com `sudo apt install build-essential`.
    * No macOS, instale o [Xcode Command Line Tools](https://developer.apple.com/xcode/features/).
* Git (opcional, para clonar o repositório)

**Passo a Passo:**

1.  **Baixar o Projeto:**
    * **Usando Git (recomendado):**
        Abra seu terminal ou prompt de comando e execute:
        ```bash
        git clone [https://github.com/SeuUsuario/projetoForcaBublitz.git](https://github.com/SeuUsuario/projetoForcaBublitz.git)
        cd projetoForcaBublitz
        ```
        *(Substitua `https://github.com/SeuUsuario/projetoForcaBublitz.git` pelo link real do seu repositório, se ele estiver no GitHub.)*
    * **Baixando o ZIP:**
        Se você não usa Git, pode baixar o projeto como um arquivo ZIP do repositório (geralmente há um botão "Code" e "Download ZIP" na página do GitHub, se for o caso). Descompacte o arquivo em uma pasta de sua preferência.

2.  **Compilar o Projeto:**
    * Navegue até a pasta raiz do projeto (onde está o arquivo `Makefile`) no seu terminal ou prompt de comando.
    * Execute o comando `make`:
        ```bash
        make
        ```
        Este comando usará o `Makefile` para compilar todos os arquivos `.c` e criar o executável `forca`. Se tudo ocorrer bem, você verá poucas mensagens de erro e o arquivo `forca` será criado na pasta raiz do projeto.

3.  **Executar o Jogo:**
    * Com o projeto compilado, você pode iniciar o jogo executando o arquivo `forca` no terminal:
        * **Linux/macOS:**
            ```bash
            ./forca
            ```
        * **Windows:**
            ```bash
            forca.exe
            ```

Agora é só seguir as instruções no terminal para escolher o modo, a dificuldade e o tema, e se divertir!
