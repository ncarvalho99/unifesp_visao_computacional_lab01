# Lista de Exercícios 1 - Laboratório 01 - Visão Computacional 📷

Repositório com a resolução da primeira lista de exercícios do Curso de Visão Computacional, ministrado pelo Prof. Fábio Cappabianco. O foco desta lista é a leitura, visualização e manipulação simples de imagens utilizando a biblioteca OpenCV em C++.

Os tópicos abordados incluem aquisição de imagens, intensidade, amostragem e quantização.

---

## 🛠️ Instalação e Configuração do Ambiente

O ambiente de desenvolvimento foi configurado no Windows seguindo o tutorial da disciplina, utilizando a stack **MSYS2 + UCRT64 + MinGW-w64 + g++**. 

### Passo a passo da instalação sugerida:
1. **MSYS2**: Baixe e instale o ambiente MSYS2 pelo site oficial. Ao terminar, abra o terminal chamado UCRT64.
2. **Atualização**: Atualize o sistema base executando `pacman -Syu`.
3. **Compilador g++**: Instale o compilador C/C++ rodando `pacman -S mingw-w64-ucrt-x86_64-gcc`. Verifique a instalação com `g++ --version`.
4. **OpenCV**: Instale a biblioteca rodando `pacman -S mingw-w64-ucrt-x86_64-opencv`. Verifique com `pkg-config --modversion opencv4`.

## ⚠️ Solução de Problemas (Troubleshooting de DLLs)

Durante a execução dos binários (`.exe`), o terminal pode não retornar nenhum erro visível. Ao executar o `.exe` diretamente pelo Explorador de Arquivos do Windows, caso encontre erros de `.dll` não encontradas, siga os passos abaixo:

1. **Erros de DLLs do C++ e OpenCV (`libgcc_s_seh-1.dll`, `libopencv_core...`, etc.):**
   * **Solução:** O Windows não localiza as bibliotecas do MSYS2 por padrão. Adicione o caminho `C:\msys64\ucrt64\bin` nas **Variáveis de Ambiente** do Windows (na variável `Path`). Após adicionar, reinicie o terminal e a IDE.
2. **Erros de DLLs do Qt6 (`Qt6Core.dll`, `Qt6Gui.dll`, `Qt6OpenGLWidgets.dll`):**
   * **Solução:** O pacote do OpenCV requer o Qt6 para sua interface gráfica. No terminal UCRT64, instale-o rodando: `pacman -S mingw-w64-ucrt-x86_64-qt6-base`.

## 🚀 Como compilar e executar

Todos os códigos utilizam o `pkg-config` para buscar automaticamente os parâmetros de compilação e linkedição. 

Para compilar, abra o terminal UCRT64 na pasta do projeto e execute:
```bash
g++ main.cpp -o exercicio $(pkg-config --cflags --libs opencv4)
```

Para rodar:
```bash
./exercicio.exe
```

---

## 📝 Exercícios Desenvolvidos

### Exercício 1 - Leitura e exibição de imagem
* **Objetivo:** Familiarizar o aluno com `cv::Mat`, `imread`, `imshow` e as dimensões da imagem.
* **Enunciado:** Leia uma imagem colorida do disco, exiba-a em uma janela e mostre no terminal sua largura, altura e número de canais.
* **Entregáveis:** Janela com a imagem original; Mensagem no terminal com resolução e canais.
* **Conceitos:** resolução espacial, imagem colorida, estrutura matricial.

### Exercício 2 - Conversão para escala de cinza
* **Objetivo:** Relacionar imagem colorida com intensidade luminosa em uma imagem monocromática.
* **Enunciado:** Leia uma imagem colorida e gere uma versão em tons de cinza. Exiba a imagem original e a imagem convertida.
* **Entregáveis:** Imagem original; Imagem em tons de cinza.
* **Conceitos:** intensidade, tons de cinza, espaço de cor.

### Exercício 3 - Leitura do valor de um pixel
* **Objetivo:** Entender que a imagem é uma grade de amostras com valores numéricos.
* **Enunciado:** Depois de carregar uma imagem em tons de cinza, peça ao usuário as coordenadas (x, y) e mostre o valor da intensidade naquele pixel.
* **Entregáveis:** Entrada do usuário para x e y; Saída no terminal com a intensidade.
* **Conceitos:** pixel, coordenadas, faixa de intensidades 0-255.

### Exercício 4 - Negativo da imagem
* **Objetivo:** Praticar transformação pontual simples sobre cada pixel.
* **Enunciado:** Gere o negativo de uma imagem em tons de cinza usando a fórmula `novo = 255 - antigo`.
* **Entregáveis:** Imagem original em cinza; Imagem negativa.
* **Conceitos:** transformação pontual, faixa dinâmica, intensidade.

### Exercício 5 - Binarização com limiar fixo
* **Objetivo:** Introduzir a ideia de limiarização e segmentação simples.
* **Enunciado:** Converta uma imagem em tons de cinza para preto e branco usando um limiar fixo, por exemplo 128.
* **Entregáveis:** Imagem binária produzida manualmente ou com threshold.
* **Conceitos:** limiar, imagem binária, contraste.

### Exercício 6 - Redução de níveis de cinza (quantização)
* **Objetivo:** Observar visualmente o efeito da quantização sobre a qualidade da imagem.
* **Enunciado:** A partir de uma imagem em tons de cinza de 256 níveis, gere versões com 128, 64, 16 e 4 níveis de cinza.
* **Entregáveis:** Quatro imagens quantizadas; Breve comparação visual.
* **Conceitos:** quantização, níveis de intensidade, bandas falsas.

### Exercício 7 - Redução de resolução espacial
* **Objetivo:** Relacionar amostragem com perda de detalhes espaciais.
* **Enunciado:** Reduza a imagem para metade da largura e da altura. Depois, amplie a imagem reduzida de volta ao tamanho original para comparar com a imagem inicial.
* **Entregáveis:** Imagem original; Imagem reduzida; Imagem reampliada.
* **Conceitos:** amostragem, resolução espacial, interpolação.

### Exercício 8 - Comparação entre amostragem e quantização
* **Objetivo:** Consolidar a diferença entre perda de resolução espacial e perda de resolução de intensidade.
* **Enunciado:** Produza três imagens a partir da original: uma com resolução reduzida, uma com poucos níveis de cinza e uma com os dois efeitos combinados. Em seguida, escreva uma breve comparação visual.
* **Entregáveis:** Três imagens processadas; Texto curto explicando as diferenças percebidas.
* **Conceitos:** amostragem x quantização, detalhe espacial, suavidade tonal.