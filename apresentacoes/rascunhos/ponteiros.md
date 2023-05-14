Ponteiros void em C e C++ são ponteiros genéricos que podem apontar para qualquer tipo de dado, mas não possuem um tipo específico associado a eles. A palavra-chave void é usada para indicar a ausência de tipo.

Aqui estão algumas características importantes dos ponteiros void:

- **Tipo genérico**: Um ponteiro void pode ser usado para apontar para qualquer tipo de dado, seja um inteiro, float, char ou até mesmo uma estrutura complexa.
- **Flexibilidade**: Os ponteiros void permitem a criação de funções genéricas ou estruturas de dados que podem lidar com diferentes tipos de dados. Isso é especialmente útil quando você deseja criar código reutilizável e flexível.
- **Falta de tipo associado**: Por não terem um tipo específico associado, os ponteiros void não podem ser desreferenciados diretamente. Isso significa que você precisa converter o ponteiro void para o tipo correto antes de poder acessar ou manipular o valor apontado.
- **Aplicações comuns**: Os ponteiros void são frequentemente utilizados em situações em que é necessário passar um ponteiro para uma função que não conhece o tipo de dado antecipadamente. Eles também podem ser úteis em casos de alocação dinâmica de memória, quando o tipo exato do dado alocado pode variar.

---

```c
void printData(void* data, char dataType) {
    switch (dataType) {
        case 'i': {
            int* intValue = (int*)data;
            printf("Valor inteiro: %d\n", *intValue);
            break;
        }
        case 'f': {
            float* floatValue = (float*)data;
            printf("Valor float: %.2f\n", *floatValue);
            break;
        }
        case 'c': {
            char* charValue = (char*)data;
            printf("Valor char: %c\n", *charValue);
            break;
        }
    }
}

int main() {
    int intValue = 10;
    float floatValue = 3.14;
    char charValue = 'A';

    printData(&intValue, 'i');
    printData(&floatValue, 'f');
    printData(&charValue, 'c');

    return 0;
}
```
