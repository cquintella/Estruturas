---
marp: true
author: carlos.quintella@uva.br
paginate: true
theme: gaia
---


<!-- _class: lead -->

# Boas Práticas de Programação Segura #

---

As boas práticas de programação segura são essenciais para garantir que seu código seja confiável e protegido contra vulnerabilidades e ameaças. 

Dicas e técnicas fundamentais para garantir a segurança do seu código:

- Validação de entrada e saída de dados: Sempre valide os dados de entrada do usuário para garantir que eles estejam no formato esperado.

- Use funções de tratamento de strings seguras, como strncpy(), strncat() e snprintf().
Evite a utilização de funções inseguras, como strcpy(), strcat() e sprintf().

```c
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void safe_string_copy(char *destination, const char *source, size_t destination_size) {
    strncpy(destination, source, destination_size - 1);
    destination[destination_size - 1] = '\0';
}

int main() {
    char input[MAX_LENGTH];
    char sanitized_input[MAX_LENGTH];

    printf("Digite uma string (max %d caracteres):\n", MAX_LENGTH - 1);
    fgets(input, MAX_LENGTH, stdin);

    safe_string_copy(sanitized_input, input, MAX_LENGTH);

    printf("String copiada com segurança: %s", sanitized_input);
    return 0;
}
```

---

- Gerenciamento de memória: Use funções seguras de alocação de memória, como calloc(), ao invés de malloc().
- Sempre libere a memória alocada usando a função free().

_Nota_: `calloc()` inicializa a memória com zeros.

---

- Verifique o retorno das funções de alocação: Ao usar funções de alocação de memória, como malloc, calloc ou realloc, sempre verifique o retorno. Se a alocação falhar, essas funções retornarão um ponteiro nulo (NULL).

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int size = 10;
    int *array = (int *)calloc(size, sizeof(int));

    if (!array) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        array[i] = i * 2;
        printf("array[%d] = %d\n", i, array[i]);
    }

    free(array);
    return 0;
}
```

---

- Tratamento de erros: Verifique sempre o retorno das funções e trate os erros adequadamente.
Use mecanismos de tratamento de exceção, como errno e perror().

```c

#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *file = fopen("non_existent_file.txt", "r");

    if (!file) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Restante do código

    fclose(file);
    return 0;
}

```

---

- Proteção de recursos: Use princípios de "menor privilégio" para limitar o acesso a recursos do sistema.

- Garanta que os recursos sejam protegidos com os mecanismos adequados, como criptografia ou autenticação.
Atualização de dependências e bibliotecas.

- Mantenha sempre suas bibliotecas e dependências atualizadas para evitar vulnerabilidades conhecidas.

---

Testes e análise de código
Realize testes de unidade e integração para verificar a segurança e confiabilidade do seu código.

- Use ferramentas de análise estática e dinâmica de código para identificar possíveis vulnerabilidades e erros de programação.
Sugestão de ferramentas de análise de código:

- Estáticas:
- Clang Static Analyzer: Uma ferramenta de análise de código estática baseada no compilador Clang, que identifica problemas no código C e C++.
- Cppcheck: Uma ferramenta de análise estática de código para C/C++ que verifica erros e vulnerabilidades comuns.
- Flawfinder (https://dwheeler.com/flawfinder/): Uma ferramenta de análise estática de código que examina o código-fonte em C e C++ e relata possíveis vulnerabilidades de segurança.
PVS-Studio (https://www.viva64.com/en/pvs-studio/): Uma ferramenta de análise estática de código para C, C++, C#, e Java que ajuda a detectar erros de programação, incluindo problemas de segurança.

Análise dinâmica:

Valgrind (http://valgrind.org/): Uma suíte de ferramentas de análise dinâmica de código para depurar e monitorar a execução de programas escritos em C e C++. A ferramenta principal, Memcheck, detecta problemas de gerenciamento de memória e concorrência.
AddressSanitizer (https://github.com/google/sanitizers/wiki/AddressSanitizer): Uma ferramenta de análise dinâmica de código que ajuda a detectar erros de gerenciamento de memória, como estouro de buffer e uso após liberação, em programas escritos em C e C++.
UndefinedBehaviorSanitizer (https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html): Uma ferramenta de análise dinâmica de código que detecta comportamento indefinido em programas C e C++, como divisão por zero, deslocamento de bit inválido e acesso a memória não inicializada.
Ao utilizar essas boas práticas e ferramentas de análise de código, você estará no caminho certo para desenvolver um software seguro e confiável, protegendo seu projeto contra vulnerabilidades e ameaças comuns. Sempre esteja atento às atualizações de segurança e novas técnicas de programação segura para manter seu código atualizado e protegido.

