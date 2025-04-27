# Super Trunfo de Países

Este repositório contém uma implementação em C de um jogo de **Super Trunfo** focado em cartas de cidades brasileiras. O programa permite cadastrar duas cartas, ler seus atributos e exibir as informações no console de forma organizada.

---

## 📋 Conteúdo

- **src/**
  - `super_trunfo.c`  
    Código-fonte principal em C, contendo:
    - Definição da `struct Carta` para armazenar atributos.
    - Função `preencherCarta(int num)` que encapsula a lógica de leitura de dados via `fgets`.
    - Exibição formatada de duas cartas cadastradas.

- **README.md**
  - Documentação de uso, estrutura e orientações de compilação.

---

## 🚀 Funcionalidades

- Cadastro de duas cartas com os seguintes campos:
  - **Estado** (A–H)
  - **Código** (ex: A01)
  - **Nome da Cidade**
  - **População** (int)
  - **Área** em km² (float)
  - **PIB** em bilhões de reais (float)
  - **Número de Pontos Turísticos** (int)

- Leitura robusta de strings usando `fgets` e parsing de números com `sscanf`.
- Estrutura de dados (`struct`) para organizar atributos de cada carta.
- Função reutilizável para preencher qualquer carta, retornando a struct pronta.

---

## 🛠️ Pré-requisitos

- **Compilador C** compatível (ex: `gcc`, `clang`).
- Ambiente de desenvolvimento ou terminal Linux/macOS/Windows com suporte C.

---

## ⚙️ Como Compilar e Executar

1. **Clone** este repositório:
   ```bash
   git clone https://github.com/seu-usuario/super-trunfo-paises.git
   cd super-trunfo-paises/src
   ```

2. **Compile** o programa com o `gcc`:
   ```bash
   gcc super_trunfo.c -o super_trunfo
   ```

3. **Execute**:
   ```bash
   ./super_trunfo
   ```

4. **Siga as instruções** no console para cadastrar e visualizar as duas cartas.

---

## 🧩 Estrutura do Código

```plaintext
src/
├── super_trunfo.c    # Código-fonte principal
└── README.md         # Documentação deste projeto
```

- **`super_trunfo.c`**: contém a definição da struct, a função de preenchimento das cartas e o `main()` para controle de fluxo.

---

## 🤝 Contribuição

1. Fork este repositório.
2. Crie uma branch para sua feature ou correção:  
   ```bash
   git checkout -b minha-feature
   ```
3. Faça suas alterações e commite:
   ```bash
   git commit -m "Minha contribuição"
   ```
4. Envie para o seu fork e abra um Pull Request.

---

## 📄 Licença

Este projeto está sob a licença [MIT](LICENSE).

---

## 📬 Contato

Para dúvidas, sugestões e feedback, abra uma issue ou envie um e-mail para `202501056172@alunos.estacio.br`.

