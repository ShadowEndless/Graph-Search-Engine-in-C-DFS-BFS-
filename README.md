# 📊 Grafos em C: DFS e BFS

## 📖 Descrição

Este projeto é uma implementação em C de algoritmos clássicos de teoria dos grafos: **Depth-First Search (DFS)** e **Breadth-First Search (BFS)**.

O programa permite ao usuário:

- Criar grafos **orientados (dígrafos)** ou **não orientados**
- Escolher entre execução automática (grafo pré-definido) ou manual (entrada personalizada)
- Testar caminhos entre vértices utilizando DFS ou BFS
- Visualizar o grafo em formato de **matriz de adjacência**

O objetivo principal é didático: reforçar conceitos fundamentais de estruturas de dados, algoritmos e análise de complexidade.

---

## 🧠 Conceitos abordados

- Representação de grafos com matriz de adjacência
- Busca em profundidade (DFS) com recursão
- Busca em largura (BFS) com fila
- Estruturas de dados (fila implementada manualmente)
- Controle de memória em C
- Análise de complexidade: **O(V + E)**

---

## 🏗️ Estrutura do Programa

O programa é dividido em três partes principais:

### 1. ⚙️ Configuração inicial
O usuário escolhe:
- Qual algoritmo usar (DFS ou BFS)
- Se deseja usar um grafo automático ou inserir manualmente

### 2. 🔧 Construção do grafo
- Automático: um grafo fixo com 7 vértices é criado
- Manual: o usuário define vértices e arestas

### 3. 🚀 Execução dos testes
- O usuário pode testar múltiplos caminhos entre vértices
- O programa informa se existe ou não caminho

---

## 🖥️ Como compilar e executar

### 📌 Requisitos
- Compilador C (gcc recomendado)

### ⚡ Compilação
```bash
gcc graph.c -o graph
```

### ▶️ Execução
```bash
./graph
```

---

## 📸 Exemplo de uso
<img width="592" height="686" alt="image" src="https://github.com/user-attachments/assets/2175e0ad-7d7d-4ae7-b24c-7556e3ffb976" />
Figura 1: Rodando o código usando o modo automático. <br><br>

1. Escolha o algoritmo:
```
0 -> DFS
1 -> BFS
```

2. Escolha o modo:
```
0 -> Grafo automático
1 -> Grafo personalizado
```

3. Insira vértices e arestas (caso manual)

4. Teste caminhos informando origem e destino

---

## 🧩 Implementações importantes

### 🔍 DFS (Depth-First Search)
- Implementado de forma recursiva
- Utiliza o call stack da linguagem C
- Marca vértices visitados para evitar loops

### 🌐 BFS (Breadth-First Search)
- Implementado com uma fila manual
- Percorre o grafo em níveis
- Garante menor caminho em grafos não ponderados

### 📦 Fila
Estrutura criada manualmente com:
- Vetor dinâmico
- Controle de início e fim
- Operações de inserção e remoção

---

## ⚙️ Pontos técnicos relevantes

- Uso de **alocação dinâmica de memória**
- Implementação manual de tipo booleano
- Controle de limites de entrada do usuário
- Tratamento de erros (vértices inválidos, loops, etc.)
- Separação de responsabilidades em funções

---

## 🔮 Melhorias futuras

- Implementação com lista de adjacência
- Adição de pesos nas arestas
- Implementação de algoritmos como Dijkstra ou A* em C

---

## 🎯 Objetivo educacional

Este projeto foi desenvolvido com foco em aprendizado prático de:

- Estruturas de dados em baixo nível
- Funcionamento interno de algoritmos clássicos
- Controle manual de memória
- Desenvolvimento de raciocínio lógico e algorítmico

---

## 📄 Licença

Este projeto pode ser utilizado para fins educacionais e de estudo.
